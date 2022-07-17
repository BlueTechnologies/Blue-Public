package languageutils.c;

#if sys
import sys.FileSystem;
#end

using StringTools;

class BCUtil {
	public static var CData:Array<String> = ["#include <stdlib.h>"];
	private static var variablesToFree:Array<String> = [];
	static var specificValues:Array<Dynamic> = [];
	static var oldValues:Array<Dynamic> = [];
	static public var extension:Dynamic = null;
	public static var fileName:String = null;

	public static function toC(AST:Dynamic) {
		var parsedAST = haxe.Json.parse(AST);
		if (parsedAST.label == "Variable") {
			if ((!CData.join('\n').contains(parsedAST.name + " = ") && !parsedAST.name.contains("/"))
				|| (CData.join('\n').contains(~/[A-Z0-9]/ + parsedAST.name) || CData.join('\n').contains(parsedAST.name + ~/[A-Z0-9]/))) {
				CData.push(("void* "
					+ Std.string(parsedAST.name).replace("|", ":").replace("\n", "")
					+ ' = '
					+ parsedAST.value).replace("/", ".").replace("div", "/").replace("mult", "*").replace("[", '{').replace("]", '}'));
				variablesToFree.push("free(" + Std.string(parsedAST.name).replace("|", ":").replace("\n", "") + ");");
			} else if (CData.join('\n').contains(parsedAST.name + " = ")
				&& !CData.join('\n').contains(~/[A-Z0-9]/ + parsedAST.name)
				&& !CData.join('\n').contains(parsedAST.name + ~/[A-Z0-9]/)
				|| parsedAST.name.contains("/")) {
				CData.push(parsedAST.name.replace("public var", "")
					+ ' = '
					+ parsedAST.value.replace("/", ".").replace("div", "/").replace("mult", "*").replace("[", '{').replace("]", '}'));
			}
		}

		if (parsedAST.label == "Method") {
			if (parsedAST.args[0] == null) {
				CData.push('void* ${parsedAST.name}() {');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push("void* " + parsedAST.args[0][i]);
						variablesToFree.push("free(" + parsedAST.args[0][i] + ");");
					}
				}
				if (args.length > 0) {
					CData.push(('void* ${parsedAST.name}(${args.join(", ")}) {\n').replace("(void* )", "()"));
				}
			}
		}
		if (parsedAST.label == "End") {
			CData.push('}');
		}
		if (parsedAST.label == "Continue") {
			CData.push('continue;');
		}
		if (parsedAST.label == "Stop") {
			CData.push('break;');
		}
		if (parsedAST.label == "If") {
			CData.push('if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}) {');
		}
		if (parsedAST.label == "Otherwise If") {
			CData.push('else if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}) {');
		}
		if (parsedAST.label == "For") {
			CData.push(('for (int ${parsedAST.iterator} = ${parsedAST.numberOne}; ${parsedAST.iterator} < ${parsedAST.numberTwo}; ${parsedAST.iterator}++) {')
				.replace("\n", "")
				.replace("\r", ""));
		}
		if (parsedAST.label == "Return") {
			if (!CData.join('\n').contains('*${parsedAST.value.replace(";", "")}')) {
				CData.push('return ${parsedAST.value}');
			} else {
				CData.push('return ${parsedAST.value}');
			}
		}
		if (parsedAST.label == "Comment") {
			CData.push('// ${parsedAST.value}');
		}
		if (parsedAST.label == "Main") {
			if (parsedAST.args[0] == null) {
				CData.push('int main() {');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push("void* " + parsedAST.args[0][i]);
						variablesToFree.push("free(" + parsedAST.args[0][i] + ");");
					}
				}
				CData.push(('int main(${args.join(", ")}) {').replace("(void* )", "()"));
			}
		}
		if (parsedAST.label == "Else") {
			CData.push('else {');
		}
		if (parsedAST.label == "FunctionCall") {
			CData.push('${parsedAST.value});');
		}
		if (parsedAST.label == "Print") {
			CData.push('printf(${parsedAST.value});');
		}
	}

	static public function buildCFile() {
		FileSystem.createDirectory("export/csrc");
		sys.io.File.write('export/csrc/${fileName.replace(".bl", ".c")}', false);
		sys.io.File.saveContent('export/csrc/${fileName.replace(".bl", ".c")}',
			CData.join('\n')
				.replace("/", ".")
				.replace('\n{\n}', "\n{")
				.replace('mult', '*')
				.replace('div', '/')
				.replace("not ", "!")
				.replace("outof", "%")
				.replace("null", "NULL"));
	}

	static public function startGarbageCollection() {
		for (j in 0...variablesToFree.length) {
			for (i in 0...CData.length) {
				if (CData[i].contains(variablesToFree[j].split("free(")[1].split(")")[0])
					&& !CData[i].contains(variablesToFree[j].split("free(")[1].split(")")[0] + " =")
					&& !CData.join("\n").split(CData[i])[1].contains(variablesToFree[j].split("free(")[1].split(")")[0])) {
					CData.insert(i + 1, variablesToFree[j]);
					break;
				}
			}
		}
	}
}
