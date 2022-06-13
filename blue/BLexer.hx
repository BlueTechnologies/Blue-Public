package blue;

using StringTools;

enum BToken {
	Method(name:String, args:Array<Dynamic>);
	MainMethod();
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
		"method", "loop", "if", "+", "-", "mult", "div", "end", "otherwise", "stop", "continue", "then", "not", "=", "use", "try", "catch", "print", "return",
		"***", "main method()", "throw", "new", "constructor method", "or", "[", "/", "(", "superClass(", "@Override", "@Static"
	];

	public function new(content:String) {
		BLexer.content = content;
		enumContent(content);
	}

	public static function enumContent(contentToEnum:String) {
		var currentToken:BToken = null;
		for (j in 0...contentToEnum.split("\n").length) {
			current = contentToEnum.split("\n")[j];
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
										args.push([current.split('method ')[1].split('(')[1].split(')')[0]]);
									}
								}
								if (args != null) {
									currentToken = BToken.Method(contentToEnum.split('method ')[1].split('(')[0], args);
								} else {
									currentToken = BToken.Method(contentToEnum.split('method ')[1].split('(')[0], null);
								}
								tokensToParse.push(currentToken);
							}

						case 'main method()':
							currentToken = BToken.MainMethod;
							tokensToParse.push(currentToken);

						case '=':
							if (!current.contains('if ')) {
								currentToken = BToken.Variable(current.split('=')[0].replace(' ', ''),
									current.split('=')[1].split('\n')[0].replace(' ', '').replace('\r', ';').replace("new", "new "));
								tokensToParse.push(currentToken);
							}

						case 'loop':
							currentToken = BToken.ForStatement(contentToEnum.split('loop ')[1].split('in')[0].replace(' ', ''),
								contentToEnum.split('loop ')[1].split('in')[1].replace(' ', '').split('until')[0].replace(' ', ''),
								contentToEnum.split('loop ')[1].split('in')[1].replace(' ', '')
								.split('until')[1].replace(' ', '').split('\n')[0].replace(' ', ''));
							tokensToParse.push(currentToken);

						case "if":
							currentToken = BToken.IfStatement(contentToEnum.split('if ')[1].split('then')[0]);
							tokensToParse.push(currentToken);

						case "end":
							currentToken = BToken.End;
							tokensToParse.push(currentToken);

						case "print":
							if (current.contains("print(")) {
								currentToken = BToken.Print(current.split('print(')[1].split(")")[0]);
								tokensToParse.push(currentToken);
							}

						case "try":
							currentToken = BToken.Try;
							tokensToParse.push(currentToken);

						case "catch":
							currentToken = BToken.Catch(current.split('catch(')[1].split(')')[0]);
							tokensToParse.push(currentToken);

						case "return":
							currentToken = BToken.Return(current.split('return ')[1].split('\n')[0].replace(' ', '').replace('\r', ";"));
							tokensToParse.push(currentToken);

						case "***":
							currentToken = BToken.Comment(current.split('*** ')[1].split('***')[0]);
							tokensToParse.push(currentToken);

						case "throw":
							currentToken = BToken.Throw(current.split('throw(')[1].split(')')[0]);
							tokensToParse.push(currentToken);

						case "new":
							if (!current.contains("=")) {
								var args = [];
								for (i in 0...current.split('new ')[1].split('(')[1].split(')').length) {
									if (current.split('new ')[1].split('(')[1].split(')')[i] != null
										&& current.split('new ')[1].split('(')[1].split(')')[i].contains(',')) {
										args.push(current.split('new ')[1].split('(')[1].split(')')[i].split(','));
									} else if (current.split('new ')[1].split('(')[1].split(')')[i] != null
										&& !current.split('new ')[1].split('(')[1].split(')')[i].contains(',')) {
										args.push([current.split('new ')[1].split('(')[1].split(')')[0]]);
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
									args.push([current.split('constructor method')[1].split('(')[1].split(')')[0]]);
								}
							}
							if (args != null) {
								currentToken = BToken.Constructor(args);
							} else {
								currentToken = BToken.Constructor(null);
							}
							tokensToParse.push(currentToken);

						case 'otherwise':
							currentToken = BToken.Else;
							tokensToParse.push(currentToken);

						case '(':
							if (!current.contains('method') && !current.contains('print') && !current.contains('@') && !current.contains('=')
								&& !current.contains('superClass(')) {
								currentToken = BToken.FunctionC(current.split(')')[0]);
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
									args.push([current.split('superClass')[1].split('(')[1].split(')')[0]]);
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
		BParser.parse(input);
	}
}
