package blue;

import blue.BLexer.BToken;

typedef ASTStruct = {
	var token:BToken;
	var iterator:Dynamic;
	var numberOne:String;
	var numberTwo:String;
	var valueOne:Dynamic;
	var valueTwo:Dynamic;
	var condition:Dynamic;
	var name:String;
	var args:Array<Dynamic>;
	var value:Dynamic;
	var a:Dynamic;
	var b:Dynamic;
	var entries:Array<Dynamic>;
	var label:String;
	var stringValue:String;
}

class BParser {
	static var token:BToken;
	static var iterator:Dynamic;
	static var numberOne:String;
	static var numberTwo:String;
	static var valueOne:Dynamic;
	static var valueTwo:Dynamic;
	static var condition:Dynamic;
	static var name:String;
	static var args:Array<Dynamic>;
	static var value:Dynamic;
	static var a:Dynamic;
	static var b:Dynamic;
	static var entries:Array<Dynamic>;
	static var label:String;
	static var stringValue:String;

	public static function parse(input:Dynamic) {
		switch (input) {
			case BToken.Variable(name, value):
				BParser.name = name;
				BParser.value = value;
				BParser.label = "Variable";

			case BToken.Method(name, args):
				BParser.name = name;
				BParser.args = args;
				BParser.label = "Method";

			case BToken.IfStatement(condition):
				BParser.condition = condition;
				BParser.label = "If";

			case BToken.ForStatement(iterator, numberOne, numberTwo):
				BParser.iterator = iterator;
				BParser.numberOne = numberOne;
				BParser.numberTwo = numberTwo;
				BParser.label = "For";

			case BToken.Array(entries):
				BParser.entries = entries;
				BParser.label = "Array";

			case BToken.Divide(a, b):
				BParser.a = a;
				BParser.b = b;
				BParser.label = "Div";

			case BToken.Multiply(a, b):
				BParser.a = a;
				BParser.b = b;
				BParser.label = "Mult";

			case BToken.End:
				BParser.label = "End";

			case BToken.Use(value):
				BParser.value = value;
				BParser.label = "Use";

			case BToken.Try:
				BParser.label = "Try";

			case BToken.Catch(value):
				BParser.value = value;
				BParser.label = "Catch";

			case BToken.Print(stringToPrint):
				BParser.value = stringToPrint;
				BParser.label = "Print";

			case BToken.Return(value):
				BParser.value = value;
				BParser.label = "Return";

			case BToken.MainMethod:
				BParser.label = "Main";

			case BToken.Throw(value):
				BParser.value = value;
				BParser.label = "Throw";

			case BToken.New(value, args):
				BParser.value = value;
				BParser.args = args;
				BParser.label = "New";

			case BToken.Constructor(args):
				BParser.args = args;
				BParser.label = "Constructor";

			case BToken.Else:
				BParser.label = "Else";

			case BToken.ArrayIndex(value):
				BParser.value = value;
				BParser.label = "ArrayIndex";

			case BToken.FunctionC(value):
				BParser.value = value;
				BParser.label = "FunctionCall";

			case BToken.Property(a, b):
				BParser.a = a;
				BParser.b = b;
				BParser.label = "Property";

			default:
				return;
		}
		var astStructure:ASTStruct = {
			token: input,
			iterator: iterator,
			numberOne: numberOne,
			numberTwo: numberTwo,
			valueOne: valueOne,
			valueTwo: valueTwo,
			condition: condition,
			value: value,
			args: args,
			name: name,
			entries: entries,
			a: a,
			b: b,
			label: label,
			stringValue: Std.string(value)
		};

		var serializedResult = haxe.Json.stringify(astStructure);
		BHaxeUtil.toHaxe(serializedResult);
		BHaxeUtil.buildHaxeFile();
	}
}
