package blue;

import languageutils.lua.BLuaUtil;
import languageutils.julia.BJuliaUtil;
import languageutils.js.BJSUtil;
import languageutils.go.BGoUtil;
import languageutils.cpp.BCPPUtil;
import languageutils.coffeescript.BCoffeeScriptUtil;
import languageutils.cs.BCSUtil;
import languageutils.c.BCUtil;
import languageutils.haxe.BHaxeUtil;
import languageutils.groovy.BGroovyUtil;
#if sys
import sys.FileSystem;
import sys.io.File;
#end

using StringTools;

class Blue {
	public static var target:String = "Haxe";
	public static var supportedTargets:Array<String> = [
		"c", "cpp", "cs", "coffeescript", "go", "groovy", "haxe", "javascript", "julia", "lua"
	];

	public static var targetUtilityClass:Dynamic = BHaxeUtil;

	private static var currentMappedFiles:Array<String> = [];
	private static var currentMappedLines:Array<Array<String>> = [];
	public static var directory:String = "";

	static var mainFile = "Main";
	static var libs = [];

	static var buildCommand:String = "haxe -cp src --main " + "export.hxsrc.Main" + " --cpp export/bin";

	static var completeSyntax:Array<String> = [
		"method", "loop", "if", "+", "-", "mult", "div", "end", "otherwise", "stop", "continue", "then", "not", "=", "use", "try", "catch", "print", "return",
		"***", "main method()", "throw", "new", "constructor method", "or", "[", "/", "(", "superClass(", "@Override", "@Static"
	];

	public static function main() {
		if (Sys.args()[1] != null) {
			var target = Sys.args()[1];
			if (supportedTargets.contains(target)) {
				Blue.target = target;
			} else {
				Sys.println('$target is not a supported target, type: "blue targetlist", to see a list of supported targets');
			}
		}
		if (Sys.args()[0] != null) {
			var folder = Sys.args()[0];
			if (folder == "targetlist") {
				Sys.println("Supported targets as of Blue v1.1: " + supportedTargets.join(", "));
			} else if (FileSystem.exists(folder) && FileSystem.isDirectory(folder)) {
				mapSource(folder);
			} else {
				Sys.println("Error: " + folder + "either does not exist or is not a directory");
			}
		} else {
			Sys.println("Usage: blue 'source-folder-name' 'target'");
		}
	}

	public static function mapSource(directory:String) {
		Blue.directory = directory;
		var files = [];
		if (FileSystem.exists(directory) && FileSystem.isDirectory(directory)) {
			Sys.println('Compiling source folder: ' + directory);
			for (file in FileSystem.readDirectory(directory)) {
				if (!FileSystem.isDirectory(file) && file.endsWith(".bl")) {
					files.push(file);
				}
			}
			for (file in FileSystem.readDirectory(directory)) {
				if (!FileSystem.isDirectory(file) && file.endsWith(".bl")) {
					if (!checkForErrors(File.getContent(directory + "/" + file))) {
						switch (target) {
							case 'c':
								Sys.println("- " + file.replace(".bl", ".c"));
							case "coffeescript":
								Sys.println("- " + file.replace(".bl", ".coffee"));
							case "cs":
								Sys.println("- " + file.replace(".bl", ".cs"));
							case "cpp":
								Sys.println("- " + file.replace(".bl", ".cpp"));
							case "go":
								Sys.println("- " + file.replace(".bl", ".go"));
							case "groovy":
								Sys.println("- " + file.replace(".bl", ".groovy"));
							case "haxe":
								Sys.println("- " + file.replace(".bl", ".hx"));
							case "javascript":
								Sys.println("- " + file.replace(".bl", ".js"));
							case "julia":
								Sys.println("- " + file.replace(".bl", ".jl"));
							case "lua":
								Sys.println("- " + file.replace(".bl", ".lua"));
						}
						var rawContent = File.getContent(directory + "/" + file);
						mapFile(directory + "/" + file);
						switch (target) {
							case 'c':
								BCUtil.fileName = file;
							case "coffeescript":
								BCoffeeScriptUtil.fileName = file;
							case "cs":
								BCSUtil.fileName = file;
							case "cpp":
								BCPPUtil.fileName = file;
							case "go":
								BGoUtil.fileName = file;
							case "groovy":
								BGroovyUtil.fileName = file;
							case "haxe":
								BHaxeUtil.fileName = file;
							case "javascript":
								BJSUtil.fileName = file;
							case "julia":
								BJuliaUtil.fileName = file;
							case "lua":
								BLuaUtil.fileName = file;
						}
						for (i in 0...rawContent.split("\n").length) {
							var line = rawContent.split("\n")[i];
							if (line.contains("@BuildCommand(")) {
								buildCommand = line.split("@BuildCommand('")[1].split("')")[0];
								Sys.println("Warning: You are using a custom build command! The program is not guaranteed to successfully compile!");
							}
						}
						if (target == "c" || target == "cpp" || target == "haxe") {
							for (i in 0...rawContent.split("\n").length) {
								var line = rawContent.split("\n")[i];
								if (line.contains("@Extends(")) {
									BHaxeUtil.extension = (line.split("@Extends(")[1].split(")")[0]);
								}
							}
						}
						if (target == "haxe" || target == "go") {
							for (i in 0...rawContent.split("\n").length) {
								var line = rawContent.split("\n")[i];
								if (line.contains("@Package(")) {
									BHaxeUtil.haxeData[0] = 'package ' + (line.split("@Package(")[1].split(")")[0]) + ';';
								}
							}
						}

						lexSourceFile(rawContent);
						FileSystem.createDirectory("export/bin");
						switch (target) {
							case 'c':
								if (FileSystem.exists("export/csrc") && FileSystem.readDirectory("export/csrc").length == files.length) {
									buildCommand = 'gcc -o export/bin/$mainFile export/csrc/$mainFile.c';
									Sys.command(buildCommand);
									Sys.exit(0);
								}
							case "coffeescript":
								if (FileSystem.exists("export/coffeescriptsrc")
									&& FileSystem.readDirectory("export/coffeescriptsrc").length == files.length) {
									buildCommand = 'coffee --compile export/bin/$mainFile.coffee';
									Sys.command(buildCommand);
									Sys.exit(0);
								}
							case "cs":
								if (FileSystem.exists("export/cssrc") && FileSystem.readDirectory("export/cssrc").length == files.length) {
									buildCommand = 'csc "export/bin/$mainFile.cs"';
									Sys.command(buildCommand);
									Sys.exit(0);
								}
							case "cpp":
								if (FileSystem.exists("export/cppsrc")
									&& FileSystem.readDirectory("export/cppsrc").length == files.length) {
									buildCommand = 'gcc -o export/bin/$mainFile export/cppsrc/$mainFile.cpp';
									Sys.command(buildCommand);
									Sys.exit(0);
								}
							case "go":
								FileSystem.deleteDirectory("export/bin");
								if (!FileSystem.exists("export/gosrc/go.mod")
									&& FileSystem.exists("export/gosrc")
									&& FileSystem.readDirectory("export/gosrc").length == files.length) {
									Sys.setCwd(Sys.getCwd() + '/export/gosrc');
									Sys.command('go mod init export/gosrc');
									buildCommand = 'go build -o export/bin/$mainFile.exe';
									Sys.command(buildCommand);
									Sys.setCwd(Sys.getCwd().split('/$directory')[0]);
									Sys.exit(0);
								} else if (FileSystem.exists("export/gosrc/go.mod")
									&& FileSystem.exists("export/gosrc")
									&& FileSystem.readDirectory("export/gosrc").length == files.length + 1) {
									Sys.setCwd(Sys.getCwd() + '/export/gosrc');
									Sys.command('go mod init export/gosrc');
									buildCommand = 'go build -o export/bin/$mainFile.exe';
									Sys.command(buildCommand);
									Sys.setCwd(Sys.getCwd().split('/$directory')[0]);
									Sys.exit(0);
								}
							case "groovy":
								if (FileSystem.exists("export/groovysrc")
									&& FileSystem.readDirectory("export/groovysrc").length == files.length) {
									buildCommand = 'groovyc export/bin/$mainFile.groovy';
									Sys.command(buildCommand);
									Sys.exit(0);
								}
							case "haxe":
								if (FileSystem.exists("export/hxsrc") && FileSystem.readDirectory("export/hxsrc").length == files.length) {
									buildCommand = 'haxe -cp src --main "export.hxsrc.Main" --cpp export/bin';
									Sys.command(buildCommand);
									Sys.exit(0);
								}
							case "julia":
								if (FileSystem.exists("export/juliasrc")
									&& FileSystem.readDirectory("export/juliasrc").length == files.length) {
									buildCommand = 'julia export/juliasrc/$mainFile.jl';
									for (file in FileSystem.readDirectory(directory)) {
										if (file.endsWith('.exe')) {
											File.copy('$file', 'export/bin/$mainFile.exe');
											FileSystem.deleteFile('$file');
										}
									}
									Sys.command(buildCommand);
									Sys.exit(0);
								}
							case "lua":
								FileSystem.deleteDirectory("export/bin");
								if (FileSystem.exists("export/luasrc")
									&& FileSystem.readDirectory("export/luasrc").length == files.length) {
									buildCommand = 'lua export/luasrc/$mainFile.lua';
									Sys.command(buildCommand);
									Sys.exit(0);
								}
						}
					}
				}
			}
		} else {
			Sys.println("Error: Source folder '" + directory + "' does not exist or is not a directory");
		}
	}

	public static function mapFile(input:String) {
		currentMappedFiles.push(input);
	}

	public static function lexSourceFile(content:String) {
		new lexing.BLexer(content);
	}

	public static function checkForErrors(input:String):Bool {
		if (input.contains("\n")) {
			for (i in 0...input.split("\n").length) {
				var line = input.split("\n")[i];
				if (line.contains("if") && !line.contains("then")) {
					Sys.println("Error: Expected 'then' at the end of line " + i);
					return true;
				}
				if (line.contains("new ") && FileSystem.exists(line.split("new ")[1].split("(")[0] + ".bl")) {
					if (!File.getContent(line.split("new ")[1].split("(")[0] + ".bl").contains("constructor method()")) {
						Sys.println("Error: Source File: " + line.split("new ")[1].split("(")[0] + " has no constructor method at line " + i);
						return true;
					}
				}

				if (line.contains("constructor method()") && input.split("constructor method()")[1].split("end")[0].contains("return ")) {
					Sys.println("Error: Constructor methods cannot have a return value at line " + i);
					return true;
				}
				for (file in FileSystem.readDirectory(directory)) {
					if (!FileSystem.isDirectory(file) && file.endsWith(".bl")) {
						if (file != "Main.bl" && File.getContent(directory + "/" + file).contains("main method()")) {
							Sys.println("Error: Only the main file can contain a main method at line " + i);
							return true;
						}
					}
				}
				if (line.contains("[0]")) {
					Sys.println("Error: Array index's start at '1' at line " + i);
					return true;
				}

				if (line.contains("method ") && !line.contains("(") && !line.contains(")")) {
					Sys.println("Error: Method: "
						+ line.split("method ")[1].split("(")[0].replace(' ', '') + "is missing it's parameter brackets at line " + i);
					return true;
				}

				if (line.contains(".") && !line.contains("1") || line.contains(".") && !line.contains("2") || line.contains(".") && !line.contains("3")
					|| line.contains(".") && !line.contains("4") || line.contains(".") && !line.contains("5") || line.contains(".") && !line.contains("6")
					|| line.contains(".") && !line.contains("7") || line.contains(".") && !line.contains("8") || line.contains(".") && !line.contains("9")) {
					Sys.println("Error: Unknown character: . at line " + i);
					return true;
				}
				if (line.contains("@Override") && input.split("@Override")[1].contains("\n")) {
					if (!input.split("@Override")[1].split("\n")[1].split('\n')[0].contains("method")) {
						Sys.println("Error: 'Override' compiler tag was not given a method below it to override at line" + i);
						return true;
					}
				}
				if (line.contains("***") && !line.split("***")[1].contains("***")) {
					Sys.println("Error: Expected '***' to end comment at line" + i);
					return true;
				}
			}

			return false;
		}
		return false;
	}
}
