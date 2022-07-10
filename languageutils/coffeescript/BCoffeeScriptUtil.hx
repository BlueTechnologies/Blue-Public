package languageutils.coffeescript;

#if sys
import sys.io.File;
import sys.FileSystem;
#end
import lexing.BLexer.BToken;

using StringTools;

class BCoffeeScriptUtil {
	public static var coffeeScriptData:Array<String> = ["class"];
	static var specificValues:Array<Dynamic> = [];
	static var oldValues:Array<Dynamic> = [];
	static public var extension:Dynamic = null;
	public static var fileName:String = null;

	public static function toCoffeeScript(AST:Dynamic) {
		coffeeScriptData[0] = 'class ${fileName.replace(".bl", '')}';
		var parsedAST = haxe.Json.parse(AST);
		if (parsedAST.label == "Variable") {
			if (!coffeeScriptData.join('\n').contains(parsedAST.name)) {
				Std.string(parsedAST.name)
					.replace("|", ":")
					.replace("\n", "") + ' = ' + Std.string(parsedAST.value).replace("/", ".").replace("div", "/").replace("mult", "*");
			} else {
				coffeeScriptData.push(parsedAST.name.replace("public var", "")
					+ '='
					+ Std.string(parsedAST.value).replace("/", ".").replace("div", "/").replace("mult", "*"));
			}
		}

		if (parsedAST.label == "Method") {
			if (parsedAST.args[0] == null) {
				coffeeScriptData.push('${parsedAST.name} = ->');
			} else {
				coffeeScriptData.push(('${parsedAST.name}(${parsedAST.args[0].join(", ")}) = ->').replace("()", "()"));
			}
		}
		if (parsedAST.label == "Throw") {
			coffeeScriptData.push('throw ${Std.string(parsedAST.value)}');
		}
		if (parsedAST.label == "End") {
			coffeeScriptData.push('}');
		}
		if (parsedAST.label == "Try") {
			coffeeScriptData.push('try');
		}
		if (parsedAST.label == "Catch") {
			coffeeScriptData.push('catch(${Std.string(parsedAST.value)})');
		}
		if (parsedAST.label == "If") {
			coffeeScriptData.push('if ${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}');
		}
		if (parsedAST.label == "Otherwise If") {
			coffeeScriptData.push('else if ${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")}');
		}
		if (parsedAST.label == "For") {
			coffeeScriptData.push('${parsedAST.iterator} for (${parsedAST.iterator} in [${parsedAST.numberOne}...${parsedAST.numberTwo}])');
		}
		if (parsedAST.label == "Return") {
			coffeeScriptData.push('return ${Std.string(parsedAST.value)}');
		}
		if (parsedAST.label == "Comment") {
			coffeeScriptData.push('// ${Std.string(parsedAST.value)}');
		}
		if (parsedAST.label == "Main") {
			if (parsedAST.args[0] == null) {
				coffeeScriptData.push('main = ->');
			} else {
				coffeeScriptData.push(('main(${parsedAST.args.join(", ")}) = ->').replace("()", "()"));
			}
		}
		if (parsedAST.label == "New") {
			if (parsedAST.args[0] == null) {
				coffeeScriptData.push('new ${Std.string(parsedAST.value)}');
			} else {
				coffeeScriptData.push(('new ${Std.string(parsedAST.value)}(${parsedAST.args[0].join(", ")})').replace("()", "()"));
			}
		}
		if (parsedAST.label == "Constructor") {
			if (parsedAST.args[0] == null) {
				coffeeScriptData.push('constructor: args -> ');
			} else {
				coffeeScriptData.push(('constructor: args(${parsedAST.args[0].join(", ")}) ->').replace("()", "()"));
			}
		}
		if (parsedAST.label == "Else") {
			coffeeScriptData.push('else');
		}
		if (parsedAST.label == "FunctionCall") {
			coffeeScriptData.push('${Std.string(parsedAST.value)})');
		}

		if (parsedAST.label == "Super") {
			if (parsedAST.args[0] == null) {
				coffeeScriptData.push('super');
			} else {
				coffeeScriptData.push(('super(${parsedAST.args[0].join(", ")})').replace("()", "()"));
			}
		}

		for (i in 0...coffeeScriptData.length) {
			if (coffeeScriptData[i].contains("[") && coffeeScriptData[i].contains("]") && !coffeeScriptData[i].contains(",")) {
				coffeeScriptData[i] = coffeeScriptData[i].replace(coffeeScriptData[i].split("[")[1].split("]")[0],
					coffeeScriptData[i].split("[")[1].split("]")[0].replace("1", "0")
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

	static public function buildCoffeeScriptFile() {
		FileSystem.createDirectory("export/coffeescriptsrc");
		sys.io.File.write('export/coffeescriptsrc/${fileName.replace(".bl", ".coffee")}', false);
		sys.io.File.saveContent('export/coffeescriptsrc/${fileName.replace(".bl", ".coffee")}',
			coffeeScriptData.join('\n')
				.replace("/", ".")
				.replace('\n{\n}', "\n{")
				.replace('mult', '*')
				.replace('div', '/')
				.replace("not ", "!")
				.replace("outof", "%"));
	}
}
