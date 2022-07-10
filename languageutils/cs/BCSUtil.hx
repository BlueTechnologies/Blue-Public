package languageutils.cs;

#if sys
import sys.io.File;
import sys.FileSystem;
#end
import lexing.BLexer.BToken;

using StringTools;

class BCSUtil {
	public static var csData:Array<String> = ["class", "{"];
	static var specificValues:Array<Dynamic> = [];
	static var oldValues:Array<Dynamic> = [];
	static public var extension:Dynamic = null;
	public static var fileName:String = null;

	public static function toCS(AST:Dynamic) {
		csData[0] = 'public class ${fileName.replace(".bl", '')}';
		if (extension != null) {
			csData[0] = csData[0] + " : " + extension;
		}
		var parsedAST = haxe.Json.parse(AST);
		if (parsedAST.label == "Variable") {
			if (!csData.join('\n').contains(parsedAST.name)) {
				csData.push(('dynamic?'
					+ " "
					+ Std.string(parsedAST.name).replace("|", ":").replace("\n", "")
					+ ' = '
					+ parsedAST.value).replace("/", ".").replace("div", "/").replace("mult", "*"));
			} else {
				csData.push(parsedAST.name.replace("public var", "") + '=' + parsedAST.value.replace("/", ".").replace("div", "/").replace("mult", "*"));
			}
		}

		if (parsedAST.label == "Method") {
			if (parsedAST.args[0] == null) {
				csData.push('dynamic ${parsedAST.name}() {');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push("dynamic? " + parsedAST.args[0][i]);
					}
				}
				if (args.length > 0) {
					csData.push(('dynamic ${parsedAST.name}(${args.join(", ")}) {\n').replace("(dynamic? )", "()"));
				}
			}
		}
		if (parsedAST.label == "Throw") {
			csData.push('throw ${parsedAST.value};');
		}
		if (parsedAST.label == "End") {
			csData.push('}');
		}
		if (parsedAST.label == "Try") {
			csData.push('try {');
		}
		if (parsedAST.label == "Catch") {
			csData.push('catch(${parsedAST.value}) {');
		}
		if (parsedAST.label == "Continue") {
			csData.push('continue;');
		}
		if (parsedAST.label == "Stop") {
			csData.push('break;');
		}
		if (parsedAST.label == "If") {
			csData.push('if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}) {');
		}
		if (parsedAST.label == "Otherwise If") {
			csData.push('else if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}) {');
		}
		if (parsedAST.label == "For") {
			csData.push('for (${parsedAST.iterator} = ${parsedAST.numberOne}; ${parsedAST.iterator} < ${parsedAST.numberTwo}; ${parsedAST.iterator}++) {');
		}
		if (parsedAST.label == "Return") {
			csData.push('return ${parsedAST.value}');
		}
		if (parsedAST.label == "Comment") {
			csData.push('// ${parsedAST.value}');
		}
		if (parsedAST.label == "Main") {
			if (parsedAST.args[0] != null) {
				csData.push('public static void main() {');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push("dynamic? " + parsedAST.args[0][i]);
					}
				}
				csData.push(('public static void main(${args.join(", ")}) {').replace("(dynamic? )", "()"));
			}
		}
		if (parsedAST.label == "New") {
			if (parsedAST.args[0] == null) {
				csData.push('new ${parsedAST.value}();');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push("dynamic? " + parsedAST.args[0][i]);
					}
				}
				csData.push(('new ${parsedAST.value}(${args.join(", ")});').replace("(dynamic? )", "()"));
			}
		}
		if (parsedAST.label == "Constructor") {
			if (parsedAST.args[0] == null) {
				csData.push('public ${fileName.replace(".bl", "")}() {');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push("dynamic? " + parsedAST.args[i]);
					}
				}
				csData.push(('public ${fileName.replace(".bl", "")}(${args.join(", ")}) {').replace("(dynamic? )", "()"));
			}
		}
		if (parsedAST.label == "Else") {
			csData.push('else {');
		}
		if (parsedAST.label == "FunctionCall") {
			csData.push('${parsedAST.value});');
		}

		if (parsedAST.label == "Super") {
			if (parsedAST.args[0] == null) {
				csData.push('super();');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push("dynamic? " + parsedAST.args[0][i]);
					}
				}
				csData.push(('super(${args.join(", ")});').replace("(dynamic? )", "()"));
			}
		}

		if (parsedAST.label == "Override") {
			csData.push("override");
		}

		if (parsedAST.label == "Static") {
			csData.push("static");
		}
		if (csData[csData.length - 1].contains("static")) {
			csData[csData.length] = "static " + csData[csData.length];
			csData.remove(csData[csData.length - 1]);
		}

		for (i in 0...csData.length) {
			if (csData[i].contains("[") && csData[i].contains("]") && !csData[i].contains(",")) {
				csData[i] = csData[i].replace(csData[i].split("[")[1].split("]")[0],
					csData[i].split("[")[1].split("]")[0].replace("1", "0")
					.replace("2", "1")
					.replace("3", "2")
					.replace("4", "3")
					.replace("5", "4")
					.replace("6", "5")
					.replace("7", "6")
					.replace("8", "7")
					.replace("9", "8"));
			}
			if (csData[i - 1].contains("override")) {
				csData[i] = "override " + csData[i].replace("static ", "");
				csData.remove(csData[i - 1]);
			}
		}
	}

	static public function buildCSFile() {
		FileSystem.createDirectory("export/cssrc");
		sys.io.File.write('export/cssrc/${fileName.replace(".bl", ".cs")}', false);
		sys.io.File.saveContent('export/cssrc/${fileName.replace(".bl", ".cs")}',
			csData.join('\n')
				.replace("/", ".")
				.replace('\n{\n}', "\n{")
				.replace('method', 'function')
				.replace('mult', '*')
				.replace('div', '/')
				.replace("not ", "!") + "\n}".replace("outof", "%"));
	}
}
