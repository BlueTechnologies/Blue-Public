package blue;

#if sys
import sys.io.File;
import sys.FileSystem;
#end
import blue.BLexer.BToken;

using StringTools;

class BHaxeUtil {
	static var haxeData:Array<Dynamic> = ["package export.hxsrc;", "using StringTools;", "class", "{"];
	static var specificValues:Array<Dynamic> = [];
	static var oldValues:Array<Dynamic> = [];

	public static var fileName:String = null;

	public static function toHaxe(AST:Dynamic) {
		haxeData[2] = 'class ${fileName.replace(".bl", '')}';
		var parsedAST = haxe.Json.parse(AST);
		if (parsedAST.label == "Variable") {
			haxeData.push(('public static var'
				+ " "
				+ Std.string(parsedAST.name).replace("|", ":").replace("\n", "")
				+ ':Dynamic = '
				+ parsedAST.value).replace("/", ".").replace("div", "/").replace("mult", "*"));
		}

		if (parsedAST.label == "Method") {
			if (parsedAST.args[0] == null) {
				haxeData.push('public static function ${parsedAST.name}():Dynamic {');
			} else {
				haxeData.push('public static function ${parsedAST.name}(${parsedAST.args[0].join(":Dynamic, ") + ":Dynamic"}):Dynamic {\n');
			}
		}
		if (parsedAST.label == "End") {
			haxeData.push('}');
		}
		if (parsedAST.label == "Try") {
			haxeData.push('try {');
		}
		if (parsedAST.label == "Catch") {
			haxeData.push('catch(${parsedAST.value}) {');
		}
		if (parsedAST.label == "Continue") {
			haxeData.push('continue;');
		}
		if (parsedAST.label == "Stop") {
			haxeData.push('break;');
		}
		if (parsedAST.label == "If") {
			haxeData.push('if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||")}) {');
		}
		if (parsedAST.label == "For") {
			haxeData.push('for (${parsedAST.iterator} in ${parsedAST.numberOne}...${parsedAST.numberTwo}) {');
		}
		if (parsedAST.label == "Print") {
			haxeData.push('trace(${parsedAST.value});');
		}
		if (parsedAST.label == "Return") {
			haxeData.push('return ${parsedAST.value}');
		}
		if (parsedAST.label == "Comment") {
			haxeData.push('// ${parsedAST.value}');
		}
		if (parsedAST.label == "Main") {
			haxeData.push('public static function main() {');
		}
		if (parsedAST.label == "New") {
			if (parsedAST.args[0] == null) {
				haxeData.push('new ${parsedAST.value}();');
			} else {
				haxeData.push(('new ${parsedAST.value}(${parsedAST.args[0].join(":Dynamic, ") + ":Dynamic"});').replace("(:Dynamic)", "()"));
			}
		}
		if (parsedAST.label == "Constructor") {
			if (parsedAST.args[0] == null) {
				haxeData.push('public function new() {');
			} else {
				haxeData.push('public function new(${parsedAST.args[0].join(":Dynamic, ") + ":Dynamic"}) {');
			}
		}
		if (parsedAST.label == "Else") {
			haxeData.push('else {');
		}
		if (parsedAST.label == "ArrayIndex") {
			haxeData.push('[${Std.parseFloat(parsedAST.value) - 1}]');
		}
		if (parsedAST.label == "Property") {
			haxeData.push('${parsedAST.a}.${parsedAST.b}');
		}
		if (parsedAST.label == "FunctionCall") {
			haxeData.push('${parsedAST.value});');
		}
	}

	public static function buildHaxeFile() {
		if (!FileSystem.exists("export")) {
			FileSystem.createDirectory("export");
			FileSystem.createDirectory("export/hxsrc");
		}
		sys.io.File.write('export/hxsrc/${fileName.replace(".bl", ".hx")}', false);
		sys.io.File.saveContent('export/hxsrc/${fileName.replace(".bl", ".hx")}', haxeData.join('\n') + "\n}");
	}
}
