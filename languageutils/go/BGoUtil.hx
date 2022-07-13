package languageutils.go;

#if sys
import sys.FileSystem;
#end

using StringTools;

class BGoUtil {
	public static var goData:Array<String> = ['import (\n"fmt"\n"main"\n)', "type dynamic = interface{}"];
	static var specificValues:Array<Dynamic> = [];
	static var oldValues:Array<Dynamic> = [];
	static public var extension:Dynamic = null;
	public static var fileName:String = null;

	public static function toGo(AST:Dynamic) {
		var parsedAST = haxe.Json.parse(AST);
		if (parsedAST.label == "Variable") {
			if (!goData.join('\n').contains(parsedAST.name) && !parsedAST.name.contains("/")) {
				goData.push(('var'
					+ " "
					+ Std.string(parsedAST.name).replace("|", ":").replace("\n", "")
					+ ' = '
					+ parsedAST.value).replace("/", ".").replace("div", "/").replace("mult", "*").replace("[", "{").replace("]", "}"));
			} else if (goData.join('\n').contains(parsedAST.name)
				&& !goData.join('\n').contains(~/[A-Z0-9]/ + parsedAST.name + "=")
				&& !goData.join('\n').contains(parsedAST.name + ~/[A-Z0-9]/)) {
				goData.push(parsedAST.name.replace("public var", "")
					+ '='
					+ parsedAST.value.replace("/", ".").replace("div", "/").replace("mult", "*").replace("[", "{").replace("]", "}"));
			}
		}

		if (parsedAST.label == "Method") {
			if (parsedAST.args[0] == null) {
				goData.push('func ${parsedAST.name}() dynamic {');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push(parsedAST.args[0][i]);
					}
				}
				goData.push(('func ${parsedAST.name}(${args.join(" dynamic, ") + " dynamic"}) dynamic {\n').replace("( dynamic)", "()"));
			}
		}
		if (parsedAST.label == "End") {
			goData.push('}');
		}
		if (parsedAST.label == "Continue") {
			goData.push('continue');
		}
		if (parsedAST.label == "Stop") {
			goData.push('break');
		}
		if (parsedAST.label == "If") {
			goData.push('if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}) {');
		}
		if (parsedAST.label == "Otherwise If") {
			goData.push('else if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}) {');
		}
		if (parsedAST.label == "For") {
			goData.push(('for ${parsedAST.iterator} := ${parsedAST.numberOne}; ${parsedAST.iterator} < ${parsedAST.numberTwo}; ${parsedAST.iterator}++ {')
				.replace("\n", "")
				.replace("\r", ""));
		}
		if (parsedAST.label == "Return") {
			goData.push('return ${parsedAST.value}');
		}

		if (parsedAST.label == "Main") {
			if (parsedAST.args[0] == null) {
				goData.push('func main()\nfmt.Print(0) {');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push(parsedAST.args[0][i]);
					}
				}
				goData.push(('func main(${args.join(" dynamic, ") + " dynamic"}) {').replace("( dynamic)", "()") + "\nfmt.Print(0)");
			}
		}
		if (parsedAST.label == "Else") {
			goData.push('else {');
		}
		if (parsedAST.label == "FunctionCall") {
			goData.push('${parsedAST.value})');
		}

		for (i in 0...goData.length) {
			if (goData[i].contains("[") && goData[i].contains("]") && !goData[i].contains(",")) {
				goData[i] = goData[i].replace(goData[i].split("[")[1].split("]")[0],
					goData[i].split("[")[1].split("]")[0].replace("1", "0")
					.replace("2", "1")
					.replace("3", "2")
					.replace("4", "3")
					.replace("5", "4")
					.replace("6", "5")
					.replace("7", "6")
					.replace("8", "7")
					.replace("9", "8"));
			}
		}

		if (parsedAST.label == "Print") {
			goData.push('fmt.print(${parsedAST.value})');
		}
	}

	static public function buildGoFile() {
		FileSystem.createDirectory("export/gosrc");
		sys.io.File.write('export/gosrc/${fileName.replace(".bl", ".go")}', false);
		sys.io.File.saveContent('export/gosrc/${fileName.replace(".bl", ".go")}',
			goData.join('\n')
				.replace("/", ".")
				.replace('\n{\n}', "\n{")
				.replace('mult', '*')
				.replace('div', '/')
				.replace("not ", "!")
				.replace("outof", "%"));
	}
}
