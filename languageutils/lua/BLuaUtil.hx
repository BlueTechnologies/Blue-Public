package languageutils.lua;

#if sys
import sys.FileSystem;
#end

using StringTools;

class BLuaUtil {
	public static var luaData:Array<String> = [];
	static var specificValues:Array<Dynamic> = [];
	static var oldValues:Array<Dynamic> = [];
	static public var extension:Dynamic = null;
	public static var fileName:String = null;

	public static function toLua(AST:Dynamic) {
		var parsedAST = haxe.Json.parse(AST);
		if (parsedAST.label == "Variable") {
			if ((!luaData.join('\n').contains(parsedAST.name + " = ") && !parsedAST.name.contains("/"))
				|| (luaData.join('\n').contains(~/[A-Z0-9]/ + parsedAST.name)
					|| luaData.join('\n').contains(parsedAST.name + ~/[A-Z0-9]/))) {
				luaData.push("global "
					+ (Std.string(parsedAST.name).replace("|", ":").replace("\n", "")
						+ ' = '
						+ parsedAST.value).replace("/", ".").replace("div", "/").replace("mult", "*"));
			} else if (luaData.join('\n').contains(parsedAST.name + " = ")
				&& !luaData.join('\n').contains(~/[A-Z0-9]/ + parsedAST.name)
				&& !luaData.join('\n').contains(parsedAST.name + ~/[A-Z0-9]/)
				|| parsedAST.name.contains("/")) {
				luaData.push(parsedAST.name.replace("public var", "") + '=' + parsedAST.value.replace("/", ".").replace("div", "/").replace("mult", "*"));
			}
		}

		if (parsedAST.label == "Method") {
			if (parsedAST.args[0] == null) {
				luaData.push('global function ${parsedAST.name}()');
			} else {
				luaData.push(('global function ${parsedAST.name}(${parsedAST.args[0].join(", ")})').replace("()", "()"));
			}
		}
		if (parsedAST.label == "End") {
			luaData.push('end');
		}
		if (parsedAST.label == "Stop") {
			luaData.push('break');
		}
		if (parsedAST.label == "If") {
			luaData.push('if ${Std.string(parsedAST.condition).replace("not ", "~").replace("=", "=").replace("greater than", ">").replace("less than", "<").replace("or", "or").replace("and", 'and').replace("~ =", "~=")} then');
		}
		if (parsedAST.label == "Otherwise If") {
			luaData.push('elseif ${Std.string(parsedAST.condition).replace("not ", "~").replace("=", "=").replace("greater than", ">").replace("less than", "<").replace("or", "or").replace("and", "and").replace("~ =", "~=")}');
		}
		if (parsedAST.label == "For") {
			luaData.push(('for ${parsedAST.iterator} = ${parsedAST.numberOne}, ${parsedAST.numberTwo}, 1 do').replace("\n", "").replace("\r", ""));
		}
		if (parsedAST.label == "Return") {
			luaData.push('return ${parsedAST.value}');
		}
		if (parsedAST.label == "Else") {
			luaData.push('else');
		}
		if (parsedAST.label == "FunctionCall") {
			luaData.push('${parsedAST.value})');
		}

		if (parsedAST.label == "Print") {
			luaData.push('print(${parsedAST.value})');
		}
	}

	static public function buildLuaFile() {
		FileSystem.createDirectory("export/luasrc");
		sys.io.File.write('export/luasrc/${fileName.replace(".bl", ".lua")}', false);
		sys.io.File.saveContent('export/luasrc/${fileName.replace(".bl", ".lua")}',
			luaData.join('\n')
				.replace("/", ".")
				.replace('\n{\n}', "\n{")
				.replace('mult', '*')
				.replace('div', '/')
				.replace("not ", "!")
				.replace("outof", "%")
				.replace("null", "nil"));
	}
}
