package languageutils.js;

#if sys
import sys.FileSystem;
#end

using StringTools;

class BJSUtil {
	public static var jsData:Array<String> = ["", ""];
	static var specificValues:Array<Dynamic> = [];
	static var oldValues:Array<Dynamic> = [];
	static public var extension:Dynamic = null;
	public static var fileName:String = null;

	public static function toJs(AST:Dynamic) {
		var parsedAST = haxe.Json.parse(AST);
		if (parsedAST.label == "Variable") {
			if (!jsData.join('\n').contains(parsedAST.name) && !parsedAST.name.contains("/")) {
				jsData.push(('var'
					+ " "
					+ Std.string(parsedAST.name).replace("|", ":").replace("\n", "")
					+ ' = '
					+ parsedAST.value).replace("/", ".").replace("div", "/").replace("mult", "*"));
			} else if (jsData.join('\n').contains(parsedAST.name)
				&& !jsData.join('\n').contains(~/[A-Z0-9]/ + parsedAST.name + "=")
				&& !jsData.join('\n').contains(parsedAST.name + ~/[A-Z0-9]/)) {
				jsData.push(parsedAST.name.replace("public var", "") + '=' + parsedAST.value.replace("/", ".").replace("div", "/").replace("mult", "*"));
			}
		}

		if (parsedAST.label == "Method") {
			if (parsedAST.args[0] == null) {
				jsData.push('function ${parsedAST.name}() {');
			} else {
				jsData.push(('function ${parsedAST.name}(${parsedAST.args[0].join(", ")}) {\n').replace("()", "()"));
			}
		}
		if (parsedAST.label == "Throw") {
			jsData.push('throw ${parsedAST.value};');
		}
		if (parsedAST.label == "End") {
			jsData.push('}');
		}
		if (parsedAST.label == "Try") {
			jsData.push('try {');
		}
		if (parsedAST.label == "Catch") {
			jsData.push('catch(${parsedAST.value}) {');
		}
		if (parsedAST.label == "Continue") {
			jsData.push('continue;');
		}
		if (parsedAST.label == "Stop") {
			jsData.push('break;');
		}
		if (parsedAST.label == "If") {
			jsData.push('if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}) {');
		}
		if (parsedAST.label == "Otherwise If") {
			jsData.push('else if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}) {');
		}
		if (parsedAST.label == "For") {
			jsData.push('for (${parsedAST.iterator} = ${parsedAST.numberOne}; ${parsedAST.iterator} < ${parsedAST.numberTwo}; ${parsedAST.iterator}++) {');
		}
		if (parsedAST.label == "Return") {
			jsData.push('return ${parsedAST.value}');
		}
		if (parsedAST.label == "New") {
			if (parsedAST.args[0] == null) {
				jsData.push('new ${parsedAST.value}();');
			} else {
				jsData.push(('new ${parsedAST.value}(${parsedAST.args[0].join(", ")});').replace("()", "()"));
			}
		}
		if (parsedAST.label == "Constructor") {
			if (parsedAST.args[0] == null) {
				jsData.push('constructor() {');
			} else {
				jsData.push(('constructor(${parsedAST.args[0].join(", ")}) {').replace("()", "()"));
			}
		}
		if (parsedAST.label == "Else") {
			jsData.push('else {');
		}
		if (parsedAST.label == "FunctionCall") {
			jsData.push('${parsedAST.value});');
		}

		for (i in 0...jsData.length) {
			if (jsData[i].contains("[") && jsData[i].contains("]") && !jsData[i].contains(",")) {
				jsData[i] = jsData[i].replace(jsData[i].split("[")[1].split("]")[0],
					jsData[i].split("[")[1].split("]")[0].replace("1", "0")
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
			jsData.push('console.log(${parsedAST.value});');
		}
	}

	static public function buildJsFile() {
		FileSystem.createDirectory("export/jssrc");
		sys.io.File.write('export/jssrc/${fileName.replace(".bl", ".js")}', false);
		sys.io.File.saveContent('export/jssrc/${fileName.replace(".bl", ".js")}',
			jsData.join('\n')
				.replace("/", ".")
				.replace('\n{\n}', "\n{")
				.replace('mult', '*')
				.replace('div', '/')
				.replace("not ", "!")
				.replace("outof", "%"));
	}
}
