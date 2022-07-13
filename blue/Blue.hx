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

	static var gotErrors:Bool = false;

	static var currentFile:String = "";

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
				Sys.println("Error: " + folder + " either does not exist or is not a directory");
			}
		} else {
			Sys.println("Usage: blue 'source-folder-name' 'target'");
		}
	}

	public static function mapSource(directory:String) {
		Blue.directory = directory;
		var files = [];
		if (FileSystem.exists(directory) && FileSystem.isDirectory(directory)) {
			for (file in FileSystem.readDirectory(directory)) {
				if (!FileSystem.isDirectory(file) && file.endsWith(".bl")) {
					currentFile = file;
					if (checkForErrors(File.getContent(directory + "/" + file))) {
						gotErrors = true;
						break;
						Sys.exit(0);
					} else {
						files.push(file);
					}
				}
			}
			for (file in FileSystem.readDirectory(directory)) {
				if (!FileSystem.isDirectory(file) && file.endsWith(".bl")) {
					if (!gotErrors) {
						if (checkForErrors(File.getContent(directory + "/" + file))) {
							break;
							Sys.exit(0);
						} else if (!checkForErrors(File.getContent(directory + "/" + file))) {
							Sys.println('Compiling source folder: ' + directory);
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
									BCUtil.CData.insert(0, '#include ' + '"System.c"' + '');
									BCUtil.CData.insert(0, '#include ' + '"File.c"' + '');
									BCUtil.CData.insert(0, '#include ' + '"MathTools.c"' + '');
									lexSourceFile(rawContent);
									if (FileSystem.exists(Sys.programPath().replace("Blue.exe", "") + "stdlib/c")) {
										for (file in FileSystem.readDirectory(Sys.programPath().replace("Blue.exe", "") + "stdlib/c")) {
											File.copy(Sys.programPath().replace("Blue.exe", "") + "stdlib/c/" + file, 'export/csrc/$file');
										}
									}
								case "coffeescript":
									BCoffeeScriptUtil.fileName = file;
									lexSourceFile(rawContent);
									if (FileSystem.exists(Sys.programPath().replace("Blue.exe", "") + "stdlib/coffeescript")) {
										for (file in FileSystem.readDirectory(Sys.programPath().replace("Blue.exe", "") + "stdlib/coffeescript")) {
											File.copy(Sys.programPath().replace("Blue.exe", "") + "stdlib/julia/" + file, 'export/coffeescriptsrc/$file');
										}
									}
								case "cs":
									BCSUtil.fileName = file;
									lexSourceFile(rawContent);
									if (FileSystem.exists(Sys.programPath().replace("Blue.exe", "") + "stdlib/cs")) {
										for (file in FileSystem.readDirectory(Sys.programPath().replace("Blue.exe", "") + "stdlib/cs")) {
											File.copy(Sys.programPath().replace("Blue.exe", "") + "stdlib/cs/" + file, 'export/cssrc/$file');
										}
									}
								case "cpp":
									BCPPUtil.fileName = file;
									BCUtil.CData.insert(0, '#include ' + '"System.cpp"' + '');
									BCUtil.CData.insert(0, '#include ' + '"File.cpp"' + '');
									BCUtil.CData.insert(0, '#include ' + '"MathTools.cpp"' + '');
									lexSourceFile(rawContent);
									if (FileSystem.exists(Sys.programPath().replace("Blue.exe", "") + "stdlib/cpp")) {
										for (file in FileSystem.readDirectory(Sys.programPath().replace("Blue.exe", "") + "stdlib/cpp")) {
											File.copy(Sys.programPath().replace("Blue.exe", "") + "stdlib/cpp/" + file, 'export/cppsrc/$file');
										}
									}
								case "go":
									BGoUtil.fileName = file;
									BGoUtil.goData.insert(0, 'package main');
									lexSourceFile(rawContent);
									if (FileSystem.exists(Sys.programPath().replace("Blue.exe", "") + "stdlib/go")) {
										for (file in FileSystem.readDirectory(Sys.programPath().replace("Blue.exe", "") + "stdlib/go")) {
											File.copy(Sys.programPath().replace("Blue.exe", "") + "stdlib/go/" + file, 'export/gosrc/$file');
										}
									}
								case "groovy":
									BGroovyUtil.fileName = file;
									lexSourceFile(rawContent);
									if (FileSystem.exists(Sys.programPath().replace("Blue.exe", "") + "stdlib/groovy")) {
										for (file in FileSystem.readDirectory(Sys.programPath().replace("Blue.exe", "") + "stdlib/groovy")) {
											File.copy(Sys.programPath().replace("Blue.exe", "") + "stdlib/groovy/" + file, 'export/groovysrc/$file');
										}
									}
								case "haxe":
									BHaxeUtil.fileName = file;
									BHaxeUtil.haxeData.insert(0, 'package export.hxsrc;');
									BHaxeUtil.haxeData.insert(1, 'import export.hxsrc.' + "File" + ';');
									BHaxeUtil.haxeData.insert(1, 'import export.hxsrc.' + "System" + ';');
									BHaxeUtil.haxeData.insert(1, 'import export.hxsrc.' + "MathTools" + ';');
									lexSourceFile(rawContent);
									if (FileSystem.exists(Sys.programPath().replace("Blue.exe", "") + "stdlib/haxe")) {
										for (file in FileSystem.readDirectory(Sys.programPath().replace("Blue.exe", "") + "stdlib/haxe")) {
											File.copy(Sys.programPath().replace("Blue.exe", "") + "stdlib/haxe/" + file, 'export/hxsrc/$file');
										}
									}
								case "javascript":
									BJSUtil.fileName = file;
									lexSourceFile(rawContent);
									if (FileSystem.exists(Sys.programPath().replace("Blue.exe", "") + "stdlib/js")) {
										for (file in FileSystem.readDirectory(Sys.programPath().replace("Blue.exe", "") + "stdlib/js")) {
											File.copy(Sys.programPath().replace("Blue.exe", "") + "stdlib/js/" + file, 'export/jssrc/$file');
										}
									}
								case "julia":
									BJuliaUtil.fileName = file;
									BJuliaUtil.juliaData.insert(0, 'import "' + "File" + '"');
									BJuliaUtil.juliaData.insert(0, 'import "' + "System" + '"');
									BJuliaUtil.juliaData.insert(0, 'import "' + "Math" + '"');
									lexSourceFile(rawContent);
									if (FileSystem.exists(Sys.programPath().replace("Blue.exe", "") + "stdlib/julia")) {
										for (file in FileSystem.readDirectory(Sys.programPath().replace("Blue.exe", "") + "stdlib/julia")) {
											File.copy(Sys.programPath().replace("Blue.exe", "") + "stdlib/julia/" + file, 'export/juliasrc/$file');
										}
									}
								case "lua":
									BLuaUtil.fileName = file;
									BLuaUtil.luaData.insert(0, 'require"' + "System.lua" + '"');
									BLuaUtil.luaData.insert(0, 'require"' + "File.lua" + '"');
									BLuaUtil.luaData.insert(0, 'require"' + "MathTools.lua" + '"');
									lexSourceFile(rawContent);
									if (FileSystem.exists(Sys.programPath().replace("Blue.exe", "") + "stdlib/lua")) {
										for (file in FileSystem.readDirectory(Sys.programPath().replace("Blue.exe", "") + "stdlib/lua")) {
											File.copy(Sys.programPath().replace("Blue.exe", "") + "stdlib/lua/" + file, 'export/luasrc/$file');
										}
									}
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

							FileSystem.createDirectory("export/bin");
							switch (target) {
								case 'c':
									if (FileSystem.exists("export/csrc")
										&& FileSystem.readDirectory("export/csrc").length == files.length + 3) {
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
									if (FileSystem.exists("export/cssrc")
										&& FileSystem.readDirectory("export/cssrc").length == files.length + 3) {
										buildCommand = 'csc "export/bin/$mainFile.cs"';
										Sys.command(buildCommand);
										Sys.exit(0);
									}
								case "cpp":
									if (FileSystem.exists("export/cppsrc")
										&& FileSystem.readDirectory("export/cppsrc").length == files.length + 3) {
										buildCommand = 'gcc -o export/bin/$mainFile export/cppsrc/$mainFile.cpp';
										Sys.command(buildCommand);
										Sys.exit(0);
									}
								case "go":
									FileSystem.deleteDirectory("export/bin");
									if (!FileSystem.exists("export/gosrc/go.mod")
										&& FileSystem.exists("export/gosrc")
										&& FileSystem.readDirectory("export/gosrc").length == files.length + 3) {
										Sys.setCwd(Sys.getCwd() + '/export/gosrc');
										Sys.command('go mod init export/gosrc');
										buildCommand = 'go build -o export/bin/$mainFile.exe';
										Sys.command(buildCommand);
										Sys.setCwd(Sys.getCwd().split('/$directory')[0]);
										Sys.exit(0);
									} else if (FileSystem.exists("export/gosrc/go.mod")
										&& FileSystem.exists("export/gosrc")
										&& FileSystem.readDirectory("export/gosrc").length == files.length + 4) {
										Sys.setCwd(Sys.getCwd() + '/export/gosrc');
										Sys.command('go mod init export/gosrc');
										buildCommand = 'go build -o export/bin/$mainFile.exe';
										Sys.command(buildCommand);
										Sys.setCwd(Sys.getCwd().split('/$directory')[0]);
										Sys.exit(0);
									}
								case "groovy":
									if (FileSystem.exists("export/groovysrc")
										&& FileSystem.readDirectory("export/groovysrc").length == files.length + 3) {
										buildCommand = 'groovyc export/bin/$mainFile.groovy';
										Sys.command(buildCommand);
										Sys.exit(0);
									}
								case "haxe":
									if (FileSystem.exists("export/hxsrc")
										&& FileSystem.readDirectory("export/hxsrc").length == files.length + 3) {
										buildCommand = 'haxe -cp src --main "export.hxsrc.Main" --cpp export/bin';
										Sys.command(buildCommand);
										Sys.exit(0);
									}
								case "julia":
									if (FileSystem.exists("export/juliasrc")
										&& FileSystem.readDirectory("export/juliasrc").length == files.length + 3) {
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
										&& FileSystem.readDirectory("export/luasrc").length == files.length + 3) {
										buildCommand = 'lua export/luasrc/$mainFile.lua';
										Sys.command(buildCommand);
										Sys.exit(0);
									}
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
				var letters = "abcdefghijklmnopqrstuvwusyz";
				var chars = "#$%^&?|!`~.";
				if (line.contains("if") && !line.contains("then")) {
					Sys.println(currentFile + " - " + "Error: Expected 'then' at the end of line " + (i + 1));
					return true;
				}

				for (n in 0...chars.split("").length) {
					if (line.contains(chars.split("")[n]) && !completeSyntax[i].contains(chars.split("")[n])) {
						Sys.println(currentFile + " - " + "Error: Unknown character: " + chars.split("")[n] + " at line " + (i + 1));
						return true;
					}
				}

				if (line.contains("method") && line.contains(":")) {
					Sys.println(currentFile + " - " + "Error: Unknown character: ':'" + " at line " + (i + 1));
					return true;
				}
				if (line.contains("new ") && FileSystem.exists(line.split("new ")[1].split("(")[0])) {
					if (!File.getContent(line.split("new ")[1].split("(")[0]).contains("constructor method()")) {
						Sys.println(currentFile
							+ " - "
							+ "Error: Source File: "
							+ line.split("new ")[1].split("(")[0] + " has no constructor method at line " + (i + 1));
						return true;
					}
				}

				if (line.contains("constructor method()") && input.split("constructor method()")[1].split("end")[0].contains("return ")) {
					Sys.println(currentFile + " - " + "Error: Constructor methods cannot have a return value at line " + (i + 1));
					return true;
				}

				if (line.contains("main method()") && input.split("main method()")[1].split("end")[0].contains("return ")) {
					Sys.println(currentFile + " - " + "Error: The main method cannot have a return value at line " + (i + 1));
					return true;
				}

				for (file in FileSystem.readDirectory(directory)) {
					if (!FileSystem.isDirectory(file) && file.endsWith(".bl")) {
						if (file != mainFile + ".bl" && File.getContent(directory + "/" + file).contains("main method()")) {
							Sys.println(currentFile + " - " + "Error: Only the main file can contain a main method at line " + (i + 1));
							return true;
						}
					}
				}
				if (line.contains("[0]")) {
					Sys.println(currentFile + " - " + "Error: Array index's start at '1' at line " + (i + 1));
					return true;
				}

				if (!line.contains("=") && line.contains("method") && !line.contains("(") && !line.contains(")")) {
					Sys.println(currentFile
						+ " - "
						+ "Error: Method: "
						+ line.split("method ")[1].split("(")[0].replace(' ', '') + "is missing it's parameter brackets at line " + (i + 1));
					return true;
				}

				if (line.contains("method ") && !input.split(line)[1].contains("end")) {
					Sys.println(currentFile
						+ " - "
						+ "Error: Method: "
						+ line.split("method ")[1].split("(")[0].replace(' ', '') + "is missing it's enclosing 'end' block at line " + (i + 1));
					return true;
				}

				if (line.contains("loop ") && !input.split(line)[1].contains("end")) {
					Sys.println(currentFile
						+ " - "
						+ "Error: Loop: "
						+ line.split("loop ")[1].split("(")[0].replace(' ', '') + "is missing it's enclosing 'end' block at line " + (i + 1));
					return true;
				}

				if (line.contains("if ") && !input.split(line)[1].contains("end")) {
					Sys.println(currentFile + " - " + "Error: An if statement is missing it's enclosing 'end' block at line " + (i + 1));
					return true;
				}

				if (line.contains("otherwise") && !input.split(line)[1].contains("end")) {
					Sys.println(currentFile + " - " + "Error: An else statement is missing it's enclosing 'end' block at line " + (i + 1));
					return true;
				}

				if (line.contains("::")) {
					Sys.println(currentFile + " - " + "Error: Unknown character: '::'" + " at line " + (i + 1));
					return true;
				}

				if (line.contains("<<")
					&& !supportedTargets.contains(line.split("<<")[1].split(">>")[0])
					&& line.split("<<")[1].split(">>")[0] != "end") {
					Sys.println(currentFile + " - " + "Error: Unknown target: '" + line.split("<<")[1].split(">>")[0] + "'" + " at line " + (i + 1));
					return true;
				}

				if (line.contains(">>") && !line.contains("<<")) {
					Sys.println(currentFile + " - " + "Error: Expected conditional compilation block at line " + (i + 1));
					return true;
				}

				if (!line.contains(">>") && line.contains("<<")) {
					Sys.println(currentFile + " - " + "Error: Expected conditional compilation block at line " + (i + 1));
					return true;
				}

				var reg = ~/\b(_*[A-Z]\w*)\b/;
				if (reg.match(line) && !line.contains("@") && !line.contains('"') && !line.contains("'") && line.contains("/")) {
					if (!line.contains('MathTools')
						&& !line.contains('File')
						&& !line.contains('System')
						&& !FileSystem.exists(directory + "/" + line.split("/")[0] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("(")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("if ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("in ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("and ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("or ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("until ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("= ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("not ")[1] + ".bl")) {
						Sys.println(currentFile + " - " + "Error: Unknown class at line " + (i + 1));
						return true;
						Sys.exit(0);
					}
				}
			}
		} else {
			Sys.println(currentFile + " - " + "No newline found on file at line 1");
			return true;
			Sys.exit(0);
		}
		return false;
	}
}
