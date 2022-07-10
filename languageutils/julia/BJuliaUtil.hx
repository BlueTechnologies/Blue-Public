package languageutils.julia;

#if sys
import sys.FileSystem;
#end

using StringTools;

class BJuliaUtil {
	public static var juliaData:Array<String> = ["package export.hxsrc;", "", "class", "{"];
	static var specificValues:Array<Dynamic> = [];
	static var oldValues:Array<Dynamic> = [];
	static public var extension:Dynamic = null;
	public static var fileName:String = null;

	public static function toJulia(AST:Dynamic) {
		juliaData[2] = 'class ${fileName.replace(".bl", '')}';
		if (extension != null) {
			juliaData[2] = juliaData[2] + " extends " + extension;
		}
		var parsedAST = haxe.Json.parse(AST);
		if (parsedAST.label == "Variable") {
			if (!juliaData.join('\n').contains(parsedAST.name)) {
				juliaData.push((Std.string(parsedAST.name).replace("|", ":").replace("\n", "")
					+ ' = '
					+ parsedAST.value).replace("/", ".").replace("div", "/").replace("mult", "*"));
			} else {
				juliaData.push(parsedAST.name.replace("public var", "") + '=' + parsedAST.value.replace("/", ".").replace("div", "/").replace("mult", "*"));
			}
		}

		if (parsedAST.label == "Method") {
			if (parsedAST.args[0] == null) {
				juliaData.push('function ${parsedAST.name}() ');
			} else {
				juliaData.push(('function ${parsedAST.name}(${parsedAST.args[0].join(", ")}) ').replace("()", "()"));
			}
		}
		if (parsedAST.label == "Throw") {
			juliaData.push('throw(${parsedAST.value})');
		}
		if (parsedAST.label == "End") {
			juliaData.push('end');
		}
		if (parsedAST.label == "Try") {
			juliaData.push('try');
		}
		if (parsedAST.label == "Catch") {
			juliaData.push('catch ${parsedAST.value}');
		}
		if (parsedAST.label == "Continue") {
			juliaData.push('continue');
		}
		if (parsedAST.label == "Stop") {
			juliaData.push('break');
		}
		if (parsedAST.label == "If") {
			juliaData.push('if (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")})');
		}
		if (parsedAST.label == "Otherwise If") {
			juliaData.push('elseif (${Std.string(parsedAST.condition).replace("not ", "!").replace("=", "==").replace("!==", "!=").replace("greater than", ">").replace("less than", "<").replace("or", "||").replace("and", "&&")})');
		}
		if (parsedAST.label == "For") {
			juliaData.push('for ${parsedAST.iterator} in ${parsedAST.numberOne}:${parsedAST.numberTwo}');
		}
		if (parsedAST.label == "Return") {
			juliaData.push('return ${parsedAST.value}');
		}
		if (parsedAST.label == "Else") {
			juliaData.push('else ');
		}
		if (parsedAST.label == "FunctionCall") {
			juliaData.push('${parsedAST.value})');
		}
		for (i in 0...juliaData.length) {
			if (juliaData[i].contains("[") && juliaData[i].contains("]") && !juliaData[i].contains(",")) {
				juliaData[i] = juliaData[i].replace(juliaData[i].split("[")[1].split("]")[0],
					juliaData[i].split("[")[1].split("]")[0].replace("1", "0")
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

	static public function buildJuliaFile() {
		FileSystem.createDirectory("export/juliasrc");
		sys.io.File.write('export/juliasrc/${fileName.replace(".bl", ".jl")}', false);
		sys.io.File.saveContent('export/juliasrc/${fileName.replace(".bl", ".jl")}',
			juliaData.join('\n')
				.replace("/", ".")
				.replace('\n{\n}', "\n{")
				.replace('mult', '*')
				.replace('div', '/')
				.replace("not ", "!")
				.replace("outof", "%"));
	}
}
