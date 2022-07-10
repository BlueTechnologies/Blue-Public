package languageutils.cpp;

#if sys
import sys.io.File;
import sys.FileSystem;
#end
import lexing.BLexer.BToken;

using StringTools;

class BCPPUtil {
	private static var variablesToFree:Array<String> = [""];
	public static var cppData:Array<String> = ["#include <cstddef>", "#include <cstdio>", "using namespace std;"];
	static var specificValues:Array<Dynamic> = [];
	static var oldValues:Array<Dynamic> = [];
	static public var extension:Dynamic = null;
	public static var fileName:String = null;

	public static function toCPP(AST:Dynamic) {
		var parsedAST = haxe.Json.parse(AST);
		if (parsedAST.label == "Variable") {
			if (!cppData.join('\n').contains(parsedAST.name)) {
				cppData.push(('auto'
					+ " "
					+ Std.string(parsedAST.name).replace("|", ":").replace("\n", "")
					+ ' = '
					+ parsedAST.value).replace("/", ".").replace("div", "/").replace("mult", "*").replace("[", '{').replace("]", '}'));
				variablesToFree.push("free(&" + Std.string(parsedAST.name).replace("|", ":").replace("\n", "") + ");");
			} else if (cppData.join('\n').contains(parsedAST.name)
				&& !cppData.join('\n').contains(~/[A-Z0-9]/ + parsedAST.name)
				&& !cppData.join('\n').contains(parsedAST.name + ~/[A-Z0-9]/)) {
				cppData.push(parsedAST.name.replace("public var", "")
					+ '='
					+ parsedAST.value.replace("/", ".").replace("div", "/").replace("mult", "*").replace("[", '{').replace("]", '}'));
			}
		}

		if (parsedAST.label == "Method") {
			if (parsedAST.args[0] == null) {
				cppData.push('auto ${parsedAST.name}():Dynamic {');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push("auto " + parsedAST.args[0][i]);
					}
				}
				cppData.push(('auto ${parsedAST.name}(${args.join(", ")}) {\n').replace("(auto)", "()"));
			}
		}
		if (parsedAST.label == "Throw") {
			cppData.push('throw ${parsedAST.value};');
		}
		if (parsedAST.label == "End") {
			cppData.push('}');
		}
		if (parsedAST.label == "Try") {
			cppData.push('try {');
		}
		if (parsedAST.label == "Catch") {
			cppData.push('catch(${parsedAST.value}) {');
		}
		if (parsedAST.label == "Continue") {
			cppData.push('continue;');
		}
		if (parsedAST.label == "Stop") {
			cppData.push('break;');
		}
		if (parsedAST.label == "If") {
			cppData.push('if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}) {');
		}
		if (parsedAST.label == "Otherwise If") {
			cppData.push('else if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}) {');
		}
		if (parsedAST.label == "For") {
			cppData.push('for (${parsedAST.iterator} = ${parsedAST.numberOne}; ${parsedAST.iterator} < ${parsedAST.numberTwo}; ${parsedAST.iterator}++) {');
		}
		if (parsedAST.label == "Return") {
			cppData.push('return ${parsedAST.value}');
		}
		if (parsedAST.label == "Comment") {
			cppData.push('// ${parsedAST.value}');
		}
		if (parsedAST.label == "Main") {
			if (parsedAST.args[0] == null) {
				cppData.push('int main() {');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push("auto " + parsedAST.args[0][i]);
					}
				}
				cppData.push(('int main(${args.join(", ")}) {').replace("(auto )", "()"));
			}
		}
		if (parsedAST.label == "Else") {
			cppData.push('else {');
		}
		if (parsedAST.label == "FunctionCall") {
			cppData.push('${parsedAST.value});');
		}

		for (i in 0...cppData.length) {
			if (cppData[i].contains("[") && cppData[i].contains("]") && !cppData[i].contains(",")) {
				cppData[i] = cppData[i].replace(cppData[i].split("[")[1].split("]")[0],
					cppData[i].split("[")[1].split("]")[0].replace("1", "0")
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
	}

	static public function buildCPPFile() {
		FileSystem.createDirectory("export/cppsrc");
		sys.io.File.write('export/cppsrc/${fileName.replace(".bl", ".cpp")}', false);
		sys.io.File.saveContent('export/cppsrc/${fileName.replace(".bl", ".cpp")}',
			cppData.join('\n')
				.replace("/", ".")
				.replace('\n{\n}', "\n{")
				.replace('mult', '*')
				.replace('div', '/')
				.replace("not ", "!")
				.replace("outof", "%")
				.replace("null", "NULL"));
	}
}
