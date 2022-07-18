package blue;

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
	public static var supportedTargets:Array<String> = ["c", "cpp", "cs", "coffeescript", "go", "groovy", "haxe", "javascript"];

	public static var targetUtilityClass:Dynamic = BHaxeUtil;

	private static var currentMappedFiles:Array<String> = [];
	private static var currentMappedLines:Array<Array<String>> = [];
	public static var directory:String = "";

	static var mainFile = "Main";
	static var libs = [];

	static var gotErrors:Bool = false;

	public static var currentFile:String = "";

	public static var currentFile_Noerr:String = "";

	static var buildCommand:String = "";

	static var completeSyntax:Array<String> = [
		"method", "loop", "if", "+", "-", "mult", "div", "end", "otherwise", "stop", "continue", "then", "not", "=", "use", "try", "catch", "print", "return",
		"***", "main method()", "throw", "new", "constructor method", "or", "[", "/", "(", "superClass(", "@Override", "@Static", "otherwise if"
	];

	public static function main() {
		if (Sys.args()[1] != null) {
			var target = Sys.args()[1];
			if (supportedTargets.contains(target)) {
				Blue.target = target;
			} else {
				Sys.println('$target is not a supported target, type: "blue targetlist", to see a list of supported targets');
				Sys.exit(0);
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
				Sys.exit(0);
			}
		} else {
			Sys.println("Usage: blue 'source-folder-name' 'target'");
			Sys.exit(0);
		}
	}

	static var projectConfig:String = '
	{
		"build_commands":{
		   "c":{
			  "command":"gcc -w -o export/bin/Main export/csrc/Main.c"
		   },
		   "coffeescript":{
			  "command":"coffee --compile export/coffeescriptsrc/."
		   },
		   "cpp":{
			  "command":"g++ -w -o export/bin/Main export/cppsrc/Main.cpp"
		   },
		   "go":{
			  "command":"go build -o bin/Main.exe"
		   },
		   "groovy":{
			  "command":"groovyc export/groovysrc/Main.groovy"
		   },
		   "haxe":{
			  "command":"haxe -cp src --main'
		+ "'export.hxsrc.Main'"
		+ '--cpp export/bin"
		   }
		}
	 }';

	public static function mapSource(directory:String) {
		if (!FileSystem.exists("project_config.json")) {
			File.saveContent("project_config.json", projectConfig);
		}
		Blue.directory = directory;
		var files = [];
		if (FileSystem.exists(directory) && FileSystem.isDirectory(directory)) {
			for (file in FileSystem.readDirectory(directory)) {
				if (!FileSystem.isDirectory(file) && file.endsWith(".bl")) {
					currentFile = file;
					if ((checkForSyntaxErrors(File.getContent(directory + "/" + file))
						&& lexing.BLexer.enumContent(File.getContent(directory + "/" + file), true))
						|| (!checkForSyntaxErrors(File.getContent(directory + "/" + file))
							&& lexing.BLexer.enumContent(File.getContent(directory + "/" + file), true))
						|| (checkForSyntaxErrors(File.getContent(directory + "/" + file))
							&& !lexing.BLexer.enumContent(File.getContent(directory + "/" + file), true))) {
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
					currentFile_Noerr = file;
					if (!gotErrors) {
						if (!checkForSyntaxErrors(File.getContent(directory + "/" + file), true)
							&& !lexing.BLexer.enumContent(File.getContent(directory + "/" + file), true)) {
							switch (target) {
								case 'c':
									Sys.println("- " + currentFile_Noerr.replace(".bl", ".c"));
								case "coffeescript":
									Sys.println("- " + currentFile_Noerr.replace(".bl", ".coffee"));
								case "cs":
									Sys.println("- " + currentFile_Noerr.replace(".bl", ".cs"));
								case "cpp":
									Sys.println("- " + currentFile_Noerr.replace(".bl", ".cpp"));
								case "go":
									Sys.println("- " + currentFile_Noerr.replace(".bl", ".go"));
								case "groovy":
									Sys.println("- " + currentFile_Noerr.replace(".bl", ".groovy"));
								case "haxe":
									Sys.println("- " + currentFile_Noerr.replace(".bl", ".hx"));
								case "javascript":
									Sys.println("- " + currentFile_Noerr.replace(".bl", ".js"));
							}
							var rawContent = File.getContent(directory + "/" + file);
							mapFile(directory + "/" + file);
							switch (target) {
								case 'c':
									BCUtil.fileName = file;
									BCUtil.CData.insert(0, '#include ' + '"System.c"' + '');
									BCUtil.CData.insert(0, '#include ' + '"File.c"' + '');
									BCUtil.CData.insert(0, '#include ' + '"MathTools.c"' + '');
									for (includeFile in FileSystem.readDirectory(directory)) {
										if (includeFile.endsWith(".bl")) {
											if (includeFile != file && includeFile == "Main.bl") {
												BCUtil.CData.insert(0, '#include ' + '"${includeFile.replace(".bl", ".c")}"' + '');
											}
										}
									}
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
											File.copy(Sys.programPath().replace("Blue.exe", "") + "stdlib/coffeescript/" + file,
												'export/coffeescriptsrc/$file');
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
									BCPPUtil.cppData.insert(0, '#include ' + '"System.cpp"' + '');
									BCPPUtil.cppData.insert(0, '#include ' + '"File.cpp"' + '');
									BCPPUtil.cppData.insert(0, '#include ' + '"MathTools.cpp"' + '');
									for (includeFile in FileSystem.readDirectory(directory)) {
										if (includeFile.endsWith(".bl")) {
											if (includeFile != file && includeFile == "Main.bl") {
												BCPPUtil.cppData.insert(0, '#include ' + '"${includeFile.replace(".bl", ".cpp")}"' + '');
											}
										}
									}
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
									for (includeFile in FileSystem.readDirectory(directory)) {
										if (includeFile.endsWith(".bl")) {
											if (includeFile != file) {
												BHaxeUtil.haxeData.insert(1, 'import export.hxsrc.' + '${includeFile.replace(".bl", "")}' + ';');
											}
										}
									};
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
										if (target == "haxe") {
											BHaxeUtil.haxeData[0] = 'package ' + (line.split("@Package(")[1].split(")")[0]) + ';';
										} else if (target == "go") {
											BHaxeUtil.haxeData[0] = 'package ' + (line.split("@Package(")[1].split(")")[0]) + ';';
										}
									}
								}
							}

							FileSystem.createDirectory("export/bin");
							var parsedConf = haxe.Json.parse(File.getContent("project_config.json"));
							switch (target) {
								case 'c':
									if (FileSystem.exists("export/csrc")
										&& FileSystem.readDirectory("export/csrc").length == files.length + 3) {
										buildCommand = parsedConf.build_commands.c.command;
										Sys.command(buildCommand);
									}
								case "coffeescript":
									if (FileSystem.exists("export/coffeescriptsrc")
										&& (FileSystem.readDirectory("export/coffeescriptsrc").length == files.length + 3
											|| FileSystem.readDirectory("export/coffeescriptsrc").length == (files.length + 6 + files.length))) {
										buildCommand = parsedConf.build_commands.coffeescript.command;
										Sys.command(buildCommand);
									}
								case "cpp":
									if (FileSystem.exists("export/cppsrc")
										&& FileSystem.readDirectory("export/cppsrc").length == files.length + 3) {
										buildCommand = parsedConf.build_commands.cpp.command;
										Sys.command(buildCommand);
									}
								case "go":
									if (FileSystem.exists("export/gosrc")
										&& (FileSystem.readDirectory("export/gosrc").length == files.length + 3
											|| FileSystem.readDirectory("export/gosrc").length == files.length + 4)) {
										Sys.setCwd(Sys.getCwd() + '/export/gosrc');
										Sys.command('go mod init export/gosrc');
										buildCommand = parsedConf.build_commands.go.command;
										Sys.command(buildCommand);
										Sys.setCwd(Sys.getCwd().split('export/gosrc')[0]);
									}
								case "groovy":
									if (FileSystem.exists("export/groovysrc")
										&& FileSystem.readDirectory("export/groovysrc").length == files.length + 3) {
										buildCommand = parsedConf.build_commands.groovy.command;
										Sys.command(buildCommand);
									}
								case "haxe":
									if (FileSystem.exists("export/hxsrc")
										&& FileSystem.readDirectory("export/hxsrc").length == files.length + 3) {
										buildCommand = parsedConf.build_commands.haxe.command;
										Sys.command(buildCommand);
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
		lexing.BLexer.enumContent(content, false);
	}

	public static function checkForSyntaxErrors(input:String, reportErrors:Bool = false):Bool {
		var hasCondition = false;
		if (input.contains("\n") && reportErrors) {
			for (i in 0...input.split("\n").length) {
				var line = input.split("\n")[i];
				var linenum = i + 1;
				var letters = "abcdefghijklmnopqrstuvwusyz";
				var chars = "#$%^&?|`~:';";

				if (line.contains("<<") && !line.contains("<<end>>")) {
					hasCondition = true;
				}
				if (line.contains("<<end>>")) {
					hasCondition = false;
				}
				if (line.contains("if") && !line.contains("then")) {
					Sys.println(currentFile_Noerr + " - " + "Error: Expected 'then' at the end of line " + (i + 1));
					return true;
				}

				for (n in 0...chars.split("").length) {
					if (line.contains(chars.split("")[n])
						&& !completeSyntax[i].contains(chars.split("")[n])
						&& !(line.split(chars.split("")[n])[1].contains('"'))
						&& !line.split(chars.split("")[n])[0].contains('"')) {
						Sys.println(currentFile_Noerr + " - " + "Error: Unknown character: " + chars.split("")[n] + " at line " + (i + 1));
						return true;
					}
				}

				if (line.contains(".") && !line.split(".")[0].contains("0") && !line.split(".")[1].contains("0") && !line.split(".")[0].contains("1")
					&& !line.split(".")[1].contains("1") && !line.split(".")[0].contains("2") && !line.split(".")[1].contains("2")
					&& !line.split(".")[0].contains("3") && !line.split(".")[1].contains("3") && !line.split(".")[0].contains("4")
					&& !line.split(".")[1].contains("4") && !line.split(".")[0].contains("4") && !line.split(".")[1].contains("5")
					&& !line.split(".")[0].contains("5") && !line.split(".")[1].contains("6") && !line.split(".")[0].contains("6")
					&& !line.split(".")[1].contains("7") && !line.split(".")[0].contains("7") && !line.split(".")[1].contains("8")
					&& !line.split(".")[0].contains("8") && !line.split(".")[1].contains("9") && !line.split(".")[0].contains("9")
					&& !line.split(".")[1].contains('"') && !line.split(".")[0].contains('"')) {
					Sys.println(currentFile_Noerr + " - " + "Error: Unknown character: " + "." + " at line " + (i + 1));
					return true;
				}

				if (line.contains("method") && line.contains(":")) {
					Sys.println(currentFile_Noerr + " - " + "Error: Unknown character: ':'" + " at line " + (i + 1));
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
					Sys.println(currentFile_Noerr + " - " + "Error: Constructor methods cannot have a return value at line " + (i + 1));
					return true;
				}

				if (line.contains("main method()") && input.split("main method()")[1].split("end")[0].contains("return ")) {
					Sys.println(currentFile_Noerr + " - " + "Error: The main method cannot have a return value at line " + (i + 1));
					return true;
				}

				for (file in FileSystem.readDirectory(directory)) {
					if (!FileSystem.isDirectory(file) && file.endsWith(".bl")) {
						if (file != mainFile + ".bl" && File.getContent(directory + "/" + file).contains("main method()")) {
							Sys.println(currentFile_Noerr + " - " + "Error: Only the main file can contain a main method at line " + (i + 1));
							return true;
						}
					}
				}
				if (line.contains("[0]")) {
					Sys.println(currentFile_Noerr + " - " + "Error: Array index's start at '1' at line " + (i + 1));
					return true;
				}

				if (!line.contains("=") && line.contains("method ") && !line.contains("(") && !line.contains(")")) {
					Sys.println(currentFile
						+ " - "
						+ "Error: Method: "
						+ line.split("method ")[1].split(" ")[0].replace(' ', '') + "is missing it's parameter brackets at line " + (i + 1));
					return true;
				}

				if (target != "coffeescript") {
					if (line.contains("method ") && !input.split(line)[1].contains("end")) {
						Sys.println(currentFile
							+ " - "
							+ "Error: Method: "
							+ line.split("method ")[1].split(" ")[0].replace(' ', '') + "is missing it's enclosing 'end' block at line " + (i + 1));
						return true;
					}

					if (line.contains("loop ") && !input.split(line)[1].contains("end")) {
						Sys.println(currentFile
							+ " - "
							+ "Error: Loop: "
							+ line.split("loop ")[1].split(" ")[0].replace(' ', '') + "is missing it's enclosing 'end' block at line " + (i + 1));
						return true;
					}

					if (line.contains("if ") && !input.split(line)[1].contains("end")) {
						Sys.println(currentFile_Noerr + " - " + "Error: An if statement is missing it's enclosing 'end' block at line " + (i + 1));
						return true;
					}

					if (line.contains("otherwise") && !input.split(line)[1].contains("end")) {
						Sys.println(currentFile_Noerr + " - " + "Error: An else statement is missing it's enclosing 'end' block at line " + (i + 1));
						return true;
					}
				}
				if (line.contains("::") && !line.split("::")[1].contains('"') && !line.split("::")[0].contains('"')) {
					Sys.println(currentFile_Noerr + " - " + "Error: Unknown character: '::'" + " at line " + (i + 1));
					return true;
				}

				if (line.contains("<<")
					&& !line.contains("<<!")
					&& !supportedTargets.contains(line.split("<<")[1].split(">>")[0])
					&& line.split("<<")[1].split(">>")[0] != "end") {
					Sys.println(currentFile_Noerr
						+ " - "
						+ "Error: Unknown target: '"
						+ line.split("<<")[1].split(">>")[0]
							+ "'"
							+ " at line "
							+ (i + 1));
					return true;
				}
				if (line.contains("<<!")
					&& !supportedTargets.contains(line.split("<<!")[1].split(">>")[0])
					&& line.split("<<!")[1].split(">>")[0] != "end") {
					Sys.println(currentFile_Noerr
						+ " - "
						+ "Error: Unknown target: '"
						+ line.split("<<!")[1].split(">>")[0]
							+ "'"
							+ " at line "
							+ (i + 1));
					return true;
				}

				if (line.contains(">>") && !line.contains("<<")) {
					Sys.println(currentFile_Noerr + " - " + "Error: Expected conditional compilation block at line " + (i + 1));
					return true;
				}

				if (!line.contains(">>") && line.contains("<<")) {
					Sys.println(currentFile_Noerr + " - " + "Error: Expected conditional compilation block at line " + (i + 1));
					return true;
				}
				var letreg = ~/[A-Z]/;
				var numreg = ~/[0-9]/;
				if (line.contains("loop ")
					&& line.contains(" in ")
					&& line.contains(" until ")
					&& !letreg.match(line.split("loop ")[1].split(" in")[0])
					&& !numreg.match(line.split("in ")[1].split(" until")[0])
					&& !numreg.match(line.split("until ")[1])) {
					Sys.println(currentFile_Noerr + " - " + "Error: Invalid loop definition at line " + (i + 1));
					return true;
				}

				if (line.contains("loop ") && !line.contains(" in ") && !line.contains(" until ")) {
					Sys.println(currentFile_Noerr + " - " + "Error: Invalid loop definition at line " + (i + 1));
					return true;
				}
				var reg = ~/\b(_*[A-Z]\w*)\b/;
				if (reg.match(line) && !line.contains("@") && !line.contains('"') && !line.contains("'") && line.contains("/")) {
					if (!line.contains('MathTools')
						&& !new EReg("[A-Z0-9]" + "MathTools", "").match(line)
						&& !new EReg("MathTools" + "[A-Z0-9]", "").match(line)
						&& !line.contains('File')
						&& !new EReg("[A-Z0-9]" + "File", "").match(line)
						&& !new EReg("File" + "[A-Z0-9]", "").match(line)
						&& !line.contains('System')
						&& !new EReg("[A-Z0-9]" + "System", "").match(line)
						&& !new EReg("System" + "[A-Z0-9]", "").match(line)
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].replace(" ", "") + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("(")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("if ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("in ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("and ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("or ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("until ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("= ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split("not ")[1] + ".bl")
						&& !FileSystem.exists(directory + "/" + line.split("/")[0].split(" ")[1] + ".bl")) {
						Sys.println(currentFile_Noerr + " - " + "Error: Unknown class at line " + (i + 1));
						return true;
					}
				}
				if (line.contains("***") && !line.split("***")[1].contains("***")) {
					Sys.println(currentFile_Noerr + " - " + "Error: Expected '***' to end comment at line " + (i + 1));
					return true;
				}
				if (line.contains("[") && line.contains("]") && line.contains(~/[A-Z0-9]/ + " = " + "[")) {
					if (!line.split("[")[1].split("]")[0].replace(" ", "").contains(~/[A-Z0-9]/ + ",")
						&& !line.split("[")[1].split("]")[0].replace(" ", "").contains(~/[A-Z0-9]/ + "")
						&& line.split("[")[1].split("]")[0].replace(" ", "") != "") {
						Sys.println(currentFile_Noerr + " - " + "Error: Invalid array definition at line " + (i + 1));
						return true;
					}
				}
				if (!hasCondition) {
					if (line.contains("@Extends") && target != "haxe" && target != "cs" && target != "coffeescript") {
						Sys.println(currentFile
							+ " - "
							+ "Error: You cannot use the '@Extends' compiler tag while targetting "
							+ target
							+ " at line "
							+ (i + 1));
						return true;
					}
					if (line.contains("@Override") && target != "haxe" && target != "cs") {
						Sys.println(currentFile
							+ " - "
							+ "Error: You cannot use the '@Override' compiler tag while targetting "
							+ target
							+ " at line "
							+ (i + 1));
						return true;
					}
					if (line.contains("@Package") && target != "haxe" && target != "go") {
						Sys.println(currentFile
							+ " - "
							+ "Error: You cannot use the '@Override' compiler tag while targetting "
							+ target
							+ " at line "
							+ (i + 1));
						return true;
					}
					if (line.contains(" and ") && target == "lua") {
						Sys.println(currentFile_Noerr + " - " + "Error: You cannot use the 'and' keyword while targetting " + target + " at line " + (i + 1));
						return true;
					}
					if (line.contains(" or ") && target == "lua") {
						Sys.println(currentFile_Noerr + " - " + "Error: You cannot use the 'or' keyword while targetting " + target + " at line " + (i + 1));
						return true;
					}
					if (line.contains("@Static") && target != "haxe" && target != "cs" && target != "groovy") {
						Sys.println(currentFile
							+ " - "
							+ "Error: You cannot use the '@Static' compiler tag while targetting "
							+ target
							+ " at line "
							+ (i + 1));
						return true;
					}
					if (line.contains("constructor method()")
						&& (target == "c" || target == "cpp" || target == "go" || target == "js" || target == "julia" || target == "lua")) {
						Sys.println(currentFile_Noerr
							+ " - "
							+ "Error: You cannot use constructor methods while targetting "
							+ target
							+ " at line "
							+ (i + 1));
						return true;
					}
					if (line.contains("main method()")
						&& (target == "coffeescript" || target == "js" || target == "julia" || target == "lua")) {
						Sys.println(currentFile_Noerr + " - " + "Error: You cannot use main methods while targetting " + target + " at line " + (i + 1));
						return true;
					}
					if (line.contains("new ")
						&& (target == "c" || target == "cpp" || target == "go" || target == "js" || target == "julia" || target == "lua")) {
						Sys.println(currentFile_Noerr + " - " + "Error: You cannot use the 'new' keyword while targetting " + target + " at line " + (i + 1));
						return true;
					}
					if (line.contains("throw(") && (target == "c" || target == "cpp" || target == "go" || target == "lua")) {
						Sys.println(currentFile_Noerr
							+ " - "
							+ "Error: You cannot use the 'throw' method while targetting "
							+ target
							+ " at line "
							+ (i + 1));
						return true;
					}
					if (line.contains("try") && (target == "c" || target == "cpp" || target == "go" || target == "lua")) {
						Sys.println(currentFile_Noerr + " - " + "Error: You cannot use the 'try' keyword while targetting " + target + " at line " + (i + 1));
						return true;
					}
					if (line.contains("catch") && (target == "c" || target == "cpp" || target == "go" || target == "lua")) {
						Sys.println(currentFile_Noerr
							+ " - "
							+ "Error: You cannot use the 'catch' keyword while targetting "
							+ target
							+ " at line "
							+ (i + 1));
						return true;
					}
					if (line.contains("end") && !line.contains("<<end>>") && target == "coffeescript") {
						Sys.println(currentFile_Noerr + " - " + "Error: You cannot use the 'end' keyword while targetting " + target + " at line " + (i + 1));
						return true;
					}
					if (reg.match(line) && !line.contains("@") && !line.contains('"') && !line.contains("'") && line.contains("/")
						&& (target == "c" || target == "cpp")) {
						if ((line.contains('MathTools')
							&& !new EReg("[A-Z0-9]" + "MathTools", "").match(line)
							&& !new EReg("MathTools" + "[A-Z0-9]", "").match(line))
							|| (line.contains('File')
								&& !new EReg("[A-Z0-9]" + "File", "").match(line)
								&& !new EReg("File" + "[A-Z0-9]", "").match(line))
							|| (line.contains('System')
								&& !new EReg("[A-Z0-9]" + "System", "").match(line)
								&& !new EReg("System" + "[A-Z0-9]", "").match(line))
							|| FileSystem.exists(directory + "/" + line.split("/")[0] + ".bl")
							|| FileSystem.exists(directory + "/" + line.split("/")[0].split("(")[1] + ".bl")
							|| FileSystem.exists(directory + "/" + line.split("/")[0].split("if ")[1] + ".bl")
							|| FileSystem.exists(directory + "/" + line.split("/")[0].split("in ")[1] + ".bl")
							|| FileSystem.exists(directory + "/" + line.split("/")[0].split("and ")[1] + ".bl")
							|| FileSystem.exists(directory + "/" + line.split("/")[0].split("or ")[1] + ".bl")
							|| FileSystem.exists(directory + "/" + line.split("/")[0].split("until ")[1] + ".bl")
							|| FileSystem.exists(directory + "/" + line.split("/")[0].split("= ")[1] + ".bl")
							|| FileSystem.exists(directory + "/" + line.split("/")[0].split("not ")[1] + ".bl")
							|| FileSystem.exists(directory + "/" + line.split("/")[0].split(" ")[1] + ".bl")) {
							Sys.println(currentFile_Noerr
								+ " - "
								+ "Error: You cannot reference other classes while targetting "
								+ target
								+ " at line "
								+ (i + 1));
							return true;
						}
					}
				}
				if (line.contains("<") && !line.contains("<<")) {
					Sys.println(currentFile_Noerr + " - " + "Error: Unknown character: '<'" + " at line " + (i + 1));
					return true;
				}
				if (line.contains("!") && !line.contains("<<")) {
					Sys.println(currentFile_Noerr + " - " + "Error: Unknown character: '!'" + " at line " + (i + 1));
					return true;
				}
				if (line.contains(">") && !line.contains(">>")) {
					Sys.println(currentFile_Noerr + " - " + "Error: Unknown character: '>'" + " at line " + (i + 1));
					return true;
				}
				if (line.contains("=") && !line.split("=")[1].contains(" ")) {
					Sys.println(currentFile_Noerr + " - " + "Error: The '=' operator must be seperated with a space" + " at line " + (i + 1));
					return true;
				}
				if (line.contains("=") && !line.split("=")[0].contains(" ")) {
					Sys.println(currentFile_Noerr + " - " + "Error: The '=' operator must be seperated with a space" + " at line " + (i + 1));
					return true;
				}
			}
		} else if (input.contains("\n") && reportErrors) {
			Sys.println(currentFile_Noerr + " - " + "No newline found on file at line 1");
			return true;
			Sys.exit(0);
		}
		return false;
	}
}
