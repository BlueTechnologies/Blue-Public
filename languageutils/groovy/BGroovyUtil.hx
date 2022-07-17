package languageutils.groovy;

#if sys
import sys.FileSystem;
#end

using StringTools;

class BGroovyUtil {
	public static var groovyData:Array<String> = ["", "", "class", "{"];
	static var specificValues:Array<Dynamic> = [];
	static var oldValues:Array<Dynamic> = [];
	static public var extension:Dynamic = null;
	public static var fileName:String = null;

	public static function toGroovy(AST:Dynamic) {
		for (i in 0...groovyData.length) {
			if (groovyData[i] == "class") {
				groovyData[i] = 'class ${fileName.replace(".bl", '')}';
				break;
			}
		}
		var parsedAST = haxe.Json.parse(AST);
		if (parsedAST.label == "Variable") {
			if ((!groovyData.join('\n').contains(parsedAST.name + " = ") && !parsedAST.name.contains("/"))
				|| (groovyData.join('\n').contains(~/[A-Z0-9]/ + parsedAST.name)
					|| groovyData.join('\n').contains(parsedAST.name + ~/[A-Z0-9]/))) {
				groovyData.push(('def'
					+ " "
					+ Std.string(parsedAST.name).replace("|", ":").replace("\n", "")
					+ ' = '
					+ parsedAST.value).replace("/", ".").replace("div", "/").replace("mult", "*"));
			} else if (groovyData.join('\n').contains(parsedAST.name + " = ")
				&& !groovyData.join('\n').contains(~/[A-Z0-9]/ + parsedAST.name)
				&& !groovyData.join('\n').contains(parsedAST.name + ~/[A-Z0-9]/)
				|| parsedAST.name.contains("/")) {
				groovyData.push(parsedAST.name.replace("public var", "") + '=' + parsedAST.value.replace("/", ".").replace("div", "/").replace("mult", "*"));
			}
		}

		if (parsedAST.label == "Method") {
			if (parsedAST.args[0] == null) {
				groovyData.push('def ${parsedAST.name}() {');
			} else {
				groovyData.push(('def ${parsedAST.name}(${parsedAST.args[0].join(", ")}) {\n').replace("()", "()"));
			}
		}
		if (parsedAST.label == "Throw") {
			groovyData.push('throw(${parsedAST.value})');
		}
		if (parsedAST.label == "End") {
			groovyData.push('}');
		}
		if (parsedAST.label == "Try") {
			groovyData.push('try {');
		}
		if (parsedAST.label == "Catch") {
			groovyData.push('catch(${parsedAST.value}) {');
		}
		if (parsedAST.label == "Continue") {
			groovyData.push('continue');
		}
		if (parsedAST.label == "Stop") {
			groovyData.push('break');
		}
		if (parsedAST.label == "If") {
			groovyData.push('if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}) {');
		}
		if (parsedAST.label == "Otherwise If") {
			groovyData.push('else if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}) {');
		}
		if (parsedAST.label == "For") {
			groovyData.push(('for (${parsedAST.iterator} = ${parsedAST.numberOne}; ${parsedAST.iterator} < ${parsedAST.numberTwo}; ${parsedAST.iterator}++) {')
				.replace("\n", "")
				.replace("\r", ""));
		}
		if (parsedAST.label == "Return") {
			groovyData.push('return ${parsedAST.value}');
		}
		if (parsedAST.label == "Main") {
			if (parsedAST.args[0] == null) {
				groovyData.push('static def main() {');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push(parsedAST.args[0][i]);
					}
				}
				groovyData.push(('static def main(${args.join(", ")}) {').replace("()", "()"));
			}
		}
		if (parsedAST.label == "New") {
			if (parsedAST.args[0] == null) {
				groovyData.push('new ${parsedAST.value}()');
			} else {
				groovyData.push(('new ${parsedAST.value}(${parsedAST.args[0].join(", ")})').replace("()", "()"));
			}
		}
		if (parsedAST.label == "Constructor") {
			if (parsedAST.args[0] == null) {
				groovyData.push('public ${fileName.replace(".bl", "")}() {');
			} else {
				var args = [];
				if (parsedAST.args[0] != null && parsedAST.args[0].length > 0) {
					for (i in 0...parsedAST.args[0].length) {
						args.push(parsedAST.args[0][i]);
					}
				}
				groovyData.push(('public ${fileName.replace(".bl", "")}(${args.join(", ")}) {').replace("()", "()"));
			}
		}
		if (parsedAST.label == "Else") {
			groovyData.push('else {');
		}
		if (parsedAST.label == "FunctionCall") {
			groovyData.push('${parsedAST.value})');
		}

		if (parsedAST.label == "Super") {
			if (parsedAST.args[0] == null) {
				groovyData.push('super()');
			} else {
				groovyData.push(('super(${parsedAST.args[0].join(", ")})').replace("()", "()"));
			}
		}

		if (parsedAST.label == "Static") {
			groovyData.push("static");
		}
		if (groovyData[groovyData.length - 1].contains("static")) {
			groovyData[groovyData.length] = "static " + groovyData[groovyData.length];
			groovyData.remove(groovyData[groovyData.length - 1]);
		}

		for (i in 0...groovyData.length) {
			if (groovyData[i].contains("[") && groovyData[i].contains("]") && !groovyData[i].contains(",")) {
				groovyData[i] = groovyData[i].replace(groovyData[i].split("[")[1].split("]")[0],
					groovyData[i].split("[")[1].split("]")[0].replace("1", "0")
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
			groovyData.push('print ${parsedAST.value}');
		}
	}

	static public function buildGroovyFile() {
		FileSystem.createDirectory("export/groovysrc");
		sys.io.File.write('export/groovysrc/${fileName.replace(".bl", ".groovy")}', false);
		sys.io.File.saveContent('export/groovysrc/${fileName.replace(".bl", ".groovy")}',
			groovyData.join('\n')
				.replace("/", ".")
				.replace('\n{\n}', "\n{")
				.replace('mult', '*')
				.replace('div', '/')
				.replace("not ", "!") + "\n}".replace("outof", "%"));
	}
}
