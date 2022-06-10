package blue;

#if sys
import sys.FileSystem;
import sys.io.File;
import sys.io.Process;
#end

using StringTools;

class Blue {
	private static var currentMappedFiles:Array<String> = [];
	private static var currentMappedLines:Array<Array<String>> = [];
	public static var directory:String = "";

	static var mainFile = "";
	static var libs = [];

	static var buildCommand:String = 'haxe -cp src --main "export.hxsrc.Main" --cpp export/bin';

	static var completeSyntax:Array<String> = [
		"method", "loop", "if", "+", "-", "mult", "div", "end", "otherwise", "stop", "continue", "then", "not", "=", "use", "try", "catch", "print", "return",
		"***", "main method()", "throw", "new", "constructor method", "or", "[", "/", "(", "superClass(", "@Override"
	];

	public static function main() {
		mapSource(Sys.getCwd());
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
						Sys.println(file.replace(".bl", ".hx"));
						var rawContent = File.getContent(directory + "/" + file);
						mapFile(directory + "/" + file);
						BHaxeUtil.fileName = file;
						BHaxeUtil.haxeData = ["package export.hxsrc;", "using StringTools;", "class", "{"];
						for (i in 0...rawContent.split("\n").length) {
							var line = rawContent.split("\n")[i];
							if (line.contains("@BuildCommand(")) {
								buildCommand = line.split("@BuildCommand('")[1].split("')")[0];
								Sys.println("Warning: You are using a custom build command! The program is not guaranteed to successfully compile!");
							}
						}
						for (i in 0...rawContent.split("\n").length) {
							var line = rawContent.split("\n")[i];
							if (line.contains("@IncludeLib(")) {
								libs.push(line.split("@IncludeLib('")[1].split("')")[0]);
							}
						}
						for (i in 0...rawContent.split("\n").length) {
							var line = rawContent.split("\n")[i];
							if (line.contains("@Extends(")) {
								BHaxeUtil.extension = (line.split("@Extends(")[1].split(")")[0]);
							}
						}
						for (i in 0...rawContent.split("\n").length) {
							var line = rawContent.split("\n")[i];
							if (line.contains("@Package(")) {
								BHaxeUtil.haxeData[0] = 'package ' + (line.split("@Package(")[1].split(")")[0]) + ';';
							}
						}
		
						lexSourceFile(rawContent);
						if (FileSystem.exists("export/hxsrc") && FileSystem.readDirectory("export/hxsrc").length == files.length) {
							if (libs != null && buildCommand.contains('haxe -cp src --main "export.hxsrc.Main" --cpp export/bin')) {
								buildCommand = 'haxe -cp src --main "export.hxsrc.Main" --library ' + libs.join(" --library") + buildCommand.split('"export.hxsrc.Main"')[1];
							}
							Sys.command(buildCommand);
							Sys.exit(0);
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
		new BLexer(content);
	}

	public static function checkForErrors(input:String):Bool {
		if (input.contains("\n")) {
			for (i in 0...input.split("\n").length) {
				var line = input.split("\n")[i];
				var letters = "abcdefghijklmnopqrstuvwusyz";
				var chars = "#$%^&_{}:><?|;";
				if (line.contains("if") && !line.contains("then")) {
					Sys.println("Error: Expected 'then' at the end of line " + i);
					return true;
				} else {
					for (n in 0...chars.split("").length) {
						if (line.contains(chars.split("")[n]) && !completeSyntax[i].contains(chars.split("")[n])) {
							Sys.println("Error: Unknown character: " + chars.split("")[n] + " at line " + i);
							return true;
						}
					}
				}

				if (line.contains("method") && line.contains(":")) {
					Sys.println("Error: Unknown character: ':'" + " at line " + i);
					return true;
				}
				if (line.contains("(") && line.split("(")[1].split(")")[0].contains(",")) {
					if (input.contains(line.split("(")[0].replace(' ', '')) && input.split("(")[1].split(")")[0].contains(",")) {
						if (line.split("(")[1].split(")")[0].split(",").length > input.split("(")[1].split(")")[0].split(",").length) {
							Sys.println("Error: Too many parameters for method: " + line.split("(")[0].replace(' ', '') + " at line " + i);
							return true;
						} else if (line.split("(")[1].split(")")[0].split(",").length < input.split("(")[1].split(")")[0].split(",").length) {
							Sys.println("Error: Not enough parameters for method: " + line.split("(")[0].replace(' ', '') + " at line " + i);
							return true;
						}
					}
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

				if (line.contains("main method()") && input.split("main method()")[1].split("end")[0].contains("return ")) {
					Sys.println("Error: The main method cannot have a return value at line " + i);
					return true;
				}
				for (file in FileSystem.readDirectory(directory)) {
					if (!FileSystem.isDirectory(file) && file.endsWith(".bl")) {
						if (file != mainFile && File.getContent(directory + "/" + file).contains("main method()")) {
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

				if (line.contains("method ") && !input.split("method ")[1].contains("end")) {
					Sys.println("Error: Method: "
						+ line.split("method ")[1].split("(")[0].replace(' ', '') + "is missing it's enclosing 'end' block at line " + i);
					return true;
				}

				if (line.contains("loop ") && !input.split("loop ")[1].contains("end")) {
					Sys.println("Error: Loop: "
						+ line.split("loop ")[1].split("(")[0].replace(' ', '') + "is missing it's enclosing 'end' block at line " + i);
					return true;
				}

				if (line.contains("if ") && !input.split("if ")[1].contains("end")) {
					Sys.println("Error: An if statement is missing it's enclosing 'end' block at line " + i);
					return true;
				}

				if (line.contains("otherwise") && !input.split("otherwise")[1].contains("end")) {
					Sys.println("Error: An else statement is missing it's enclosing 'end' block at line " + i);
					return true;
				}

				if (line.contains(".") && line.contains("1") || line.contains("2") || line.contains("3") || line.contains("4") || line.contains("5") || line.contains("6") || line.contains("7") || line.contains("8") || line.contains("9"))  {
					Sys.println("Error: Unknown character: . at line " + i);
					return true;
				}
				if (line.contains("@Override") && input.split("@Override")[1].contains("\n")) {
					if (!input.split("@Override")[1].split("\n")[1].split('\n')[0].contains("method")) {
						Sys.println("Error: 'Override' compiler tag was not given a method below it to override at line" + i);
						return true;
					}
				}
			}

			return false;
		}
		return false;
	}
}
