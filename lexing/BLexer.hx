package lexing;

import blue.Blue;

using StringTools;

enum BToken {
	Method(name:String, args:Array<Dynamic>);
	MainMethod(args:Array<Dynamic>);
	Array(entries:Array<Dynamic>);
	Variable(name:String, value:Dynamic);
	ForStatement(iterator:Dynamic, numberOne:String, numberTwo:String);
	IfStatement(condition:Dynamic);
	Use(value:Dynamic);
	Add(a:Dynamic, b:Dynamic);
	Subtract(a:Dynamic, b:Dynamic);
	Multiply(a:Dynamic, b:Dynamic);
	Divide(a:Dynamic, b:Dynamic);
	End;
	Try;
	Catch(value:Dynamic);
	Continue;
	Stop;
	Property(a:Dynamic, b:Dynamic);
	Print(stringToPrint:Dynamic);
	Return(value:Dynamic);
	Comment(value:Dynamic);
	Throw(value:Dynamic);
	New(value:Dynamic, args:Array<Dynamic>);
	Constructor(args:Array<Dynamic>);
	Else;
	FunctionC(value:Dynamic);
	Super(args:Dynamic);
	OverrideTag;
	StaticTag;
	OtherwiseIf(condition:Dynamic);
}

class BLexer {
	private static var current:String = null;
	private static var char:String = null;

	private var end:String = null;

	public static var content:String;
	static var last:Bool = false;

	private var number:Float = 0;

	static var tokensToParse:Array<Dynamic> = [];
	static var completeSyntax:Array<String> = [
		"method", "loop ", "if", "+", "-", "mult", "div", "end", "otherwise", "stop", "continue", "then", "not", "=", "use", "try", "catch", "print",
		"return", "***", "main method()", "throw", "new", "constructor method", "or", "[", "/", "(", "superClass(", "@Override", "@Static", "otherwise if"
	];

	public function new(content:String) {
		BLexer.content = content;
		enumContent(content);
	}

	public static function enumContent(contentToEnum:String) {
		var currentToken:BToken = null;
		for (j in 0...contentToEnum.split("\n").length) {
			current = contentToEnum.split("\n")[j];
			if (current.contains("<<haxe>>") && Blue.target != "haxe") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<haxe>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<c>>") && Blue.target != "c") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<c>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<coffeescript>>") && Blue.target != "coffeescript") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<coffeescript>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<cpp>>") && Blue.target != "cpp") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<cpp>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<cpp>>") && Blue.target != "cpp") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<cpp>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<cs>>") && Blue.target != "cs") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<cs>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<go>>") && Blue.target != "go") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<go>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<groovy>>") && Blue.target != "groovy") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<groovy>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<java>>") && Blue.target != "java") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<java>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<js>>") && Blue.target != "js") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<js>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<julia>>") && Blue.target != "julia") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<julia>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<lua>>") && Blue.target != "lua") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<lua>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<rust>>") && Blue.target != "rust") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<rust>>')[1].split('<<end>>')[0], "");
			}
			for (i in 0...completeSyntax.length) {
				if (current.contains(completeSyntax[i])) {
					switch (completeSyntax[i]) {
						case 'method':
							if (!current.contains('main method()') && !current.contains('constructor method()')) {
								var args = [];
								for (i in 0...current.split('method ')[1].split('(')[1].split(')').length) {
									if (current.split('method ')[1].split('(')[1].split(')')[i] != null
										&& current.split('method ')[1].split('(')[1].split(')')[i].contains(',')) {
										args.push(current.split('method ')[1].split('(')[1].split(')')[i].split(','));
									} else if (current.split('method ')[1].split('(')[1].split(')')[i] != null
										&& !current.split('method ')[1].split('(')[1].split(')')[i].contains(',')) {
										args.push([current.split('method ')[1].split('(')[1].split(')\r')[0]]);
									}
								}
								if (args != null) {
									currentToken = BToken.Method(current.split('method ')[1].split('(')[0], args);
								} else {
									currentToken = BToken.Method(current.split('method ')[1].split('(')[0], null);
								}
								tokensToParse.push(currentToken);
							}

						case 'main method()':
							var args = [];
							for (i in 0...current.split('main method')[1].split('(')[1].split(')').length) {
								if (current.split('main method')[1].split('(')[1].split(')')[i] != null
									&& current.split('main method')[1].split('(')[1].split(')')[i].contains(',')) {
									args.push(current.split('main method')[1].split('(')[1].split(')')[i].split(','));
								} else if (current.split('main method')[1].split('(')[1].split(')')[i] != null
									&& !current.split('main method')[1].split('(')[1].split(')')[i].contains(',')) {
									args.push([current.split('main method')[1].split('(')[1].split(')\r')[0]]);
								}
							}
							if (args != null) {
								currentToken = BToken.MainMethod(args);
							} else {
								currentToken = BToken.MainMethod(null);
							}
							tokensToParse.push(currentToken);

						case '=':
							if (!current.contains('if ')) {
								currentToken = BToken.Variable(current.split('=')[0].replace(' ', ''),
									current.split('=')[1].split('\n')[0].replace(' ', '').replace('\r', ';').replace("new", "new "));
								tokensToParse.push(currentToken);
							}

						case 'loop ':
							currentToken = BToken.ForStatement(current.split('loop ')[1].split('in')[0].replace(' ', ''),
								current.split('loop ')[1].split('in')[1].replace(' ', '').split('until')[0].replace(' ', ''),
								current.split('loop ')[1].split('in')[1].replace(' ', '').split('until')[1].replace(' ', '').split('\n')[0].replace(' ', ''));
							tokensToParse.push(currentToken);

						case "if":
							if (!current.contains('otherwise if')) {
								currentToken = BToken.IfStatement(current.split('if ')[1].split('then')[0]);
								tokensToParse.push(currentToken);
							}

						case "end":
							if (!current.contains('<<')) {
								currentToken = BToken.End;
								tokensToParse.push(currentToken);
							}

						case "print":
							if (current.contains("print(")) {
								currentToken = BToken.Print(current.split('print(')[1].split(")")[0]);
								tokensToParse.push(currentToken);
							}

						case "try":
							currentToken = BToken.Try;
							tokensToParse.push(currentToken);

						case "catch":
							currentToken = BToken.Catch(current.split('catch(')[1].split(')\r')[0]);
							tokensToParse.push(currentToken);

						case "return":
							currentToken = BToken.Return(current.split('return ')[1].split('\n')[0].replace(' ', '').replace('\r', ";"));
							tokensToParse.push(currentToken);

						case "***":
							currentToken = BToken.Comment(current.split('*** ')[1].split('***')[0]);
							tokensToParse.push(currentToken);

						case "throw":
							currentToken = BToken.Throw(current.split('throw(')[1].split(')\r')[0]);
							tokensToParse.push(currentToken);

						case "new":
							if (!current.contains("=") || !current.contains("throw")) {
								var args = [];
								for (i in 0...current.split('new ')[1].split('(')[1].split(')').length) {
									if (current.split('new ')[1].split('(')[1].split(')')[i] != null
										&& current.split('new ')[1].split('(')[1].split(')')[i].contains(',')) {
										args.push(current.split('new ')[1].split('(')[1].split(')')[i].split(','));
									} else if (current.split('new ')[1].split('(')[1].split(')')[i] != null
										&& !current.split('new ')[1].split('(')[1].split(')')[i].contains(',')) {
										args.push([current.split('new ')[1].split('(')[1].split(')\r')[0]]);
									}
								}
								if (args != null) {
									currentToken = BToken.New(current.split('new ')[1].split('(')[0], args);
								} else {
									currentToken = BToken.New(current.split('new ')[1].split('(')[0], null);
								}
								tokensToParse.push(currentToken);
							}

						case "constructor method":
							var args = [];
							for (i in 0...current.split('constructor method')[1].split('(')[1].split(')').length) {
								if (current.split('constructor method')[1].split('(')[1].split(')')[i] != null
									&& current.split('constructor method')[1].split('(')[1].split(')')[i].contains(',')) {
									args.push(current.split('constructor method')[1].split('(')[1].split(')')[i].split(','));
								} else if (current.split('constructor method')[1].split('(')[1].split(')')[i] != null
									&& !current.split('constructor method')[1].split('(')[1].split(')')[i].contains(',')) {
									args.push([current.split('constructor method')[1].split('(')[1].split(')\r')[0]]);
								}
							}
							if (args != null) {
								currentToken = BToken.Constructor(args);
							} else {
								currentToken = BToken.Constructor(null);
							}
							tokensToParse.push(currentToken);

						case 'otherwise if':
							currentToken = BToken.OtherwiseIf(current.split('if ')[1].split('then')[0]);
							tokensToParse.push(currentToken);

						case 'otherwise':
							if (!current.contains('otherwise if')) {
								currentToken = BToken.Else;
								tokensToParse.push(currentToken);
							}

						case '(':
							if (!current.contains('method') && !current.contains('loop ') && !current.contains('if') && !current.contains('otherwise if')
								&& !current.contains('print(') && !current.contains('@') && !current.contains('=') && !current.contains('superClass(')) {
								currentToken = BToken.FunctionC(current.split(')\r')[0]);
								tokensToParse.push(currentToken);
							}

						case 'superClass(':
							var args = [];
							for (i in 0...current.split('superClass')[1].split('(')[1].split(')').length) {
								if (current.split('superClass')[1].split('(')[1].split(')')[i] != null
									&& current.split('superClass')[1].split('(')[1].split(')')[i].contains(',')) {
									args.push(current.split('superClass')[1].split('(')[1].split(')')[i].split(','));
								} else if (current.split('superClass')[1].split('(')[1].split(')')[i] != null
									&& !current.split('superClass')[1].split('(')[1].split(')')[i].contains(',')) {
									args.push([current.split('superClass')[1].split('(')[1].split(')\r')[0]]);
								}
							}
							if (args != null) {
								currentToken = BToken.Super(args);
							} else {
								currentToken = BToken.Super(null);
							}
							tokensToParse.push(currentToken);

						case '@Override':
							currentToken = BToken.OverrideTag;
							tokensToParse.push(currentToken);

						case '@Static':
							currentToken = BToken.StaticTag;
							tokensToParse.push(currentToken);
					}
				}
			}
		}
		if (tokensToParse != null) {
			for (i in 0...tokensToParse.length) {
				buildAST(tokensToParse[i]);
			}
		}

		tokensToParse = [];
	}

	public static function buildAST(input:BToken) {
		parsing.BParser.parse(input);
	}
}
