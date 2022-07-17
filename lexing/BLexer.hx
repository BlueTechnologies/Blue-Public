package lexing;

import blue.Blue;
#if sys
import sys.FileSystem;
import sys.io.File;
#end
import languageutils.lua.BLuaUtil;
import languageutils.js.BJSUtil;
import languageutils.go.BGoUtil;
import languageutils.cpp.BCPPUtil;
import languageutils.coffeescript.BCoffeeScriptUtil;
import languageutils.cs.BCSUtil;
import languageutils.c.BCUtil;
import languageutils.haxe.BHaxeUtil;
import languageutils.groovy.BGroovyUtil;

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

	private static var localVars:Array<Dynamic> = [];

	private static var localMethods:Array<Dynamic> = [
		"write", "read", "runcmd", "get", "exit", "arcsine", "arccos", "cosine", "power", "sine", "floorValue"
	];

	private static var gotErrors:Bool = false;

	public static var content:String;
	static var last:Bool = false;

	private var number:Float = 0;

	private static var reg = ~/\b(_*[A-Z]\w*)\b/;

	static var tokensToParse:Array<Dynamic> = [];
	static var completeSyntax:Array<String> = [
		"method", "loop ", "if", "+", "-", "mult", "div", "end", "otherwise", "stop", "continue", "then", "not", "=", "use", "try", "catch", "print",
		"return", "***", "main method()", "throw", "new", "constructor method", "or", "[", "/", "(", "superClass(", "@Override", "@Static", "otherwise if"
	];

	public static function enumContent(contentToEnum:String, testLex:Bool = false):Bool {
		var currentToken:BToken = null;
		for (j in 0...contentToEnum.split("\n").length) {
			var linenum = j + 1;
			current = contentToEnum.split("\n")[j];
			contentToEnum = contentToEnum + "\n";
			if (current.contains("<<haxe>>") && Blue.target != "haxe") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<haxe>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<c>>") && Blue.target != "c") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<c>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<coffeescript>>") && Blue.target != "coffeescript") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<coffeescript>>')[1].split('<<end>>')[0], "");
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
			} else if (current.contains("<<!haxe>>") && Blue.target == "haxe") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<!haxe>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<!c>>") && Blue.target == "c") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<!c>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<!coffeescript>>") && Blue.target == "coffeescript") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<!coffeescript>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<!cpp>>") && Blue.target == "cpp") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<!cpp>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<!cs>>") && Blue.target == "cs") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<!cs>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<!go>>") && Blue.target == "go") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<!go>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<!groovy>>") && Blue.target == "groovy") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<!groovy>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<!java>>") && Blue.target == "java") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<!java>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<!js>>") && Blue.target == "js") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<!js>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<!julia>>") && Blue.target == "julia") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<!julia>>')[1].split('<<end>>')[0], "");
			} else if (current.contains("<<!lua>>") && Blue.target == "lua") {
				contentToEnum = contentToEnum.replace(contentToEnum.split('<<!lua>>')[1].split('<<end>>')[0], "");
			}
			for (i in 0...completeSyntax.length) {
				if (current.contains(completeSyntax[i])) {
					switch (completeSyntax[i]) {
						case 'method':
							if (!current.contains('main method()') && !current.contains('constructor method()')) {
								var args = [];
								if (current.contains(")\r")) {
									for (i in 0...current.split('method ')[1].split('(')[1].split(')').length) {
										if (current.split('method ')[1].split('(')[1].split(')')[i] != null
											&& current.split('method ')[1].split('(')[1].split(')')[i].contains(',')) {
											args.push(current.split('method ')[1].split('(')[1].split(')')[i].split(','));
										} else if (current.split('method ')[1].split('(')[1].split(')')[i] != null
											&& !current.split('method ')[1].split('(')[1].split(')')[i].contains(',')) {
											args.push([current.split('method ')[1].split('(')[1].split(')\r')[0]]);
										}
									}
								} else {
									Sys.println(Blue.currentFile + " - " + "Error: Methods must be ended with a ')' and a new at line " + (linenum));
									gotErrors = true;
									Sys.exit(0);
								}
								if (args != null) {
									for (i in 0...args[0].length) {
										if (args[0][i].replace(" ", "") != "") {
											localVars.push(args[0][i]);
										}
									}
									currentToken = BToken.Method(current.split('method ')[1].split('(')[0], args);
								} else {
									currentToken = BToken.Method(current.split('method ')[1].split('(')[0], null);
								}
								if (contentToEnum.split(contentToEnum.split('\n')[j - 1])[0].contains("method " + current.split('method ')[1].split('(')[0])
									|| contentToEnum.split(current)[1].contains("method " + current.split('method ')[1].split('(')[0])) {
									Sys.println(Blue.currentFile
										+ " - "
										+ "Error: Method: "
										+ current.split('method ')[1].split('(')[0] + " was defined twice at line " + (j + 1));
									gotErrors = true;
									Sys.exit(0);
								}
								for (j in 0...contentToEnum.split("\n").length) {
									if (contentToEnum.split("\n")[j] != current) {
										var linealt = contentToEnum.split("\n")[j];
										if (linealt.contains(current.split('method ')[1].split('(')[0])
											&& !new EReg("[A-Z0-9]" + current.split('method ')[1].split('(')[0], "").match(linealt)) {
											localMethods.push(current.split('method ')[1].split('(')[0].replace(' ', ''));
										}
									}
								}

								if (!testLex) {
									tokensToParse.push(currentToken);
								}
							}

						case 'main method()':
							var args = [];
							if (current.contains(")\r")) {
								for (i in 0...current.split('main method')[1].split('(')[1].split(')').length) {
									if (current.split('main method')[1].split('(')[1].split(')')[i] != null
										&& current.split('main method')[1].split('(')[1].split(')')[i].contains(',')) {
										args.push(current.split('main method')[1].split('(')[1].split(')')[i].split(','));
									} else if (current.split('main method')[1].split('(')[1].split(')')[i] != null
										&& !current.split('main method')[1].split('(')[1].split(')')[i].contains(',')) {
										args.push([current.split('main method')[1].split('(')[1].split(')\r')[0]]);
									}
								}
							} else {
								Sys.println(Blue.currentFile + " - " + "Error: Main methods must be ended with a ')' and a newline at line " + (linenum));
								gotErrors = true;
								Sys.exit(0);
							}
							if (args != null) {
								for (i in 0...args[0].length) {
									if (args[0][i].replace(" ", "") != "") {
										localVars.push(args[0][i]);
									}
								}
								currentToken = BToken.MainMethod(args);
							} else {
								currentToken = BToken.MainMethod(null);
							}
							if (!testLex) {
								tokensToParse.push(currentToken);
							}

						case '=':
							if (!current.contains('if ')) {
								currentToken = BToken.Variable(current.split('=')[0].replace(' ', ''),
									current.split('=')[1].split('\n')[0].replace(' ', '').replace('\r', ';').replace("new", "new "));
								for (j in 0...contentToEnum.split("\n").length) {
									var linealt = contentToEnum.split("\n")[j];
									if (linealt.contains(current.split('=')[0].replace(' ', '') + " =")
										&& !new EReg("[A-Z0-9]" + current.split('=')[0].replace(' ', '') + " =", "").match(linealt)) {
										localVars.push(current.split('=')[0].replace(' ', ''));
									}
								}

								if (reg.match(current) && current.contains("/")) {
									if (FileSystem.exists(Blue.directory + "/" + current.split('/')[0].replace(' ', '') + ".bl")) {
										if (!File.getContent(Blue.directory + "/" + current.split('/')[0].replace(' ', '') + ".bl")
											.contains(current.split('=')[0].split("/")[1].replace(' ', '') + " =")) {
											Sys.println(Blue.currentFile
												+ " - "
												+ "Error: Class: "
												+ current.split('/')[0].replace(' ',
													'') + " does not contain variable: " + current.split('=')[0].split("/")[1].replace(' ',
													'') + " at line " + (linenum));
											gotErrors = true;
											Sys.exit(0);
										}
									}
								}
								if (!testLex) {
									tokensToParse.push(currentToken);
								}
							}

						case 'loop ':
							currentToken = BToken.ForStatement(current.split('loop ')[1].split('in')[0].replace(' ', ''),
								current.split('loop ')[1].split('in')[1].replace(' ', '').split('until')[0].replace(' ', ''),
								current.split('until')[1].replace(' ', ''));
							if (!testLex) {
								tokensToParse.push(currentToken);
							}
							localVars.push(current.split('loop ')[1].split(' in')[0]);

						case "if":
							var linenum = j + 1;
							var symbols:String = "|~#$%()*+-:;<=>@[]^_.,'!?";
							if (!current.contains('otherwise if')) {
								currentToken = BToken.IfStatement(current.split('if ')[1].split('then')[0]);

								for (j in 0...current.split('if ')[1].split('then')[0].split(' ').length) {
									for (k in 0...symbols.split('').length) {
										var whitespacesplit = current.split('if ')[1].split('then')[0].split(' ')[j].replace("(", "").replace(")", "");
										if (!completeSyntax.contains(whitespacesplit)
											&& Math.isNaN(Std.parseFloat(whitespacesplit))
											&& whitespacesplit != symbols.split('')[k]
											&& whitespacesplit != ""
											&& whitespacesplit != " "
											&& whitespacesplit != 'and'
											&& whitespacesplit != 'outof'
											&& whitespacesplit != 'or'
											&& whitespacesplit != 'greater'
											&& whitespacesplit != 'less'
											&& whitespacesplit != 'than'
											&& !whitespacesplit.contains('"')
											&& !whitespacesplit.contains('"'))
											if (!localVars.contains(whitespacesplit)) {
												Sys.println(Blue.currentFile + " - " + "Error: Unknown variable at line " + (linenum));
												gotErrors = true;
												Sys.exit(0);
											}
									}
								}
								if (!testLex) {
									tokensToParse.push(currentToken);
								}
							}

						case "end":
							if (!current.contains("<<")) {
								currentToken = BToken.End;
								if (!testLex) {
									tokensToParse.push(currentToken);
								}
							}

						case "print":
							var symbols:String = "|~#$%()*+-:;<=>@[]^_.,'!?";
							if (current.contains("print(")) {
								currentToken = BToken.Print(current.split('print(')[1].split(")")[0]);

								for (k in 0...symbols.split('').length) {
									var whitespacesplit = current.split('print(')[1].split(")")[0];
									if (!completeSyntax.contains(whitespacesplit)
										&& Math.isNaN(Std.parseFloat(whitespacesplit))
										&& whitespacesplit != symbols.split('')[k]
										&& whitespacesplit != ""
										&& whitespacesplit != " "
										&& whitespacesplit != 'and'
										&& whitespacesplit != 'outof'
										&& whitespacesplit != 'or'
										&& whitespacesplit != 'greater'
										&& whitespacesplit != 'less'
										&& whitespacesplit != 'than'
										&& !whitespacesplit.contains('"')
										&& !whitespacesplit.contains('"'))
										if (!localVars.contains(whitespacesplit)) {
											Sys.println(Blue.currentFile + " - " + "Error: Unknown variable at line " + (linenum));
											gotErrors = true;
											Sys.exit(0);
										}
								}
								if (!testLex) {
									tokensToParse.push(currentToken);
								}
							}

						case "try":
							currentToken = BToken.Try;
							if (!testLex) {
								tokensToParse.push(currentToken);
							}

						case "catch":
							if (current.contains(")\r")) {
								currentToken = BToken.Catch(current.split('catch(')[1].split(')\r')[0]);
							} else {
								Sys.println(Blue.currentFile + " - " + "Error: Catch statements must be ended with a ')' and a newline at line " + (linenum));
								gotErrors = true;
								Sys.exit(0);
							}
							if (!testLex) {
								tokensToParse.push(currentToken);
							}

						case "return":
							currentToken = BToken.Return(current.split('return ')[1].split('\n')[0].replace(' ', '').replace('\r', ";"));
							if (!testLex) {
								tokensToParse.push(currentToken);
							}

						case "***":
							currentToken = BToken.Comment(current.split('*** ')[1].split('***')[0]);
							if (!testLex) {
								tokensToParse.push(currentToken);
							}

						case "throw":
							if (current.contains(")\r")) {
								currentToken = BToken.Throw(current.split('throw(')[1].split(')\r')[0]);
							} else {
								Sys.println(Blue.currentFile + " - " + "Error: Throw statements must be ended with a ')' and a newline at line " + (linenum));
								gotErrors = true;
								Sys.exit(0);
							}
							if (!testLex) {
								tokensToParse.push(currentToken);
							}

						case "new":
							if (!current.contains("=") || !current.contains("throw")) {
								var args = [];
								if (current.contains(")\r")) {
									for (i in 0...current.split('new ')[1].split('(')[1].split(')').length) {
										if (current.split('new ')[1].split('(')[1].split(')')[i] != null
											&& current.split('new ')[1].split('(')[1].split(')')[i].contains(',')) {
											args.push(current.split('new ')[1].split('(')[1].split(')')[i].split(','));
										} else if (current.split('new ')[1].split('(')[1].split(')')[i] != null
											&& !current.split('new ')[1].split('(')[1].split(')')[i].contains(',')) {
											args.push([current.split('new ')[1].split('(')[1].split(')\r')[0]]);
										}
									}
								} else {
									Sys.println(Blue.currentFile
										+ " - "
										+ "Error: New statements must be ended with a ')' and a newline at line "
										+ (linenum));
									gotErrors = true;
									Sys.exit(0);
								}
								if (args != null) {
									currentToken = BToken.New(current.split('new ')[1].split('(')[0], args);
								} else {
									currentToken = BToken.New(current.split('new ')[1].split('(')[0], null);
								}
								if (!testLex) {
									tokensToParse.push(currentToken);
								}
							}

						case "constructor method":
							var args = [];
							if (current.contains(")\r")) {
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
									for (i in 0...args[0].length) {
										if (args[0][i].replace(" ", "") != "") {
											localVars.push(args[0][i]);
										}
									}
									currentToken = BToken.Constructor(args);
								} else {
									currentToken = BToken.Constructor(null);
								}
								if (!testLex) {
									tokensToParse.push(currentToken);
								}
							}

						case 'otherwise if':
							var symbols:String = "|~#$%()*+-:;<=>@[]^_.,'!?";
							currentToken = BToken.OtherwiseIf(current.split('if ')[1].split('then')[0]);

							for (n in 0...current.split('if ')[1].split('then')[0].split(' ').length) {
								for (k in 0...symbols.split('').length) {
									var whitespacesplit = current.split('otherwise if ')[1].split('then')[0].split(' ')[n].replace("(", "").replace(")", "");
									if (!completeSyntax.contains(whitespacesplit)
										&& Math.isNaN(Std.parseFloat(whitespacesplit))
										&& whitespacesplit != symbols.split('')[k]
										&& whitespacesplit != ''
										&& whitespacesplit != ' '
										&& whitespacesplit != 'and'
										&& whitespacesplit != 'outof'
										&& whitespacesplit != 'or'
										&& whitespacesplit != 'greater'
										&& whitespacesplit != 'less'
										&& whitespacesplit != 'than'
										&& !whitespacesplit.contains('"'))
										if (!localVars.contains(whitespacesplit)) {
											Sys.println(Blue.currentFile + " - " + "Error: Unknown variable at line " + (j + 1));
											gotErrors = true;
											Sys.exit(0);
										}
									break;
								}
								if (!testLex) {
									tokensToParse.push(currentToken);
								}
							}

						case 'otherwise':
							if (!current.contains('otherwise if')) {
								currentToken = BToken.Else;
								if (!testLex) {
									tokensToParse.push(currentToken);
								}
							}

						case '(':
							var linenum = j + 1;
							var currentSymbol = null;
							var whitespacesplit = current.split(")\r")[0];
							var symbols:String = "|~#$%()*+-:;<=>@[]^_.,'!?";
							if (!current.contains('method') && !current.contains('loop ') && !current.contains('if') && !current.contains('otherwise if')
								&& !current.contains('print(') && !current.contains('@') && !current.contains('=') && !current.contains('superClass(')) {
								if (current.contains(')\r')) {
									currentToken = BToken.FunctionC(current.split(')\r')[0]);
									for (k in 0...symbols.split('').length) {
										currentSymbol = symbols.split('')[k];
									}
									if (contentToEnum.split(current)[1].contains("method " + whitespacesplit.replace(" ", "").split("(")[0] + "(")
										&& !contentToEnum.split(contentToEnum.split('\n')[j - 1])[0].contains("method "
											+ whitespacesplit.replace(" ", "").split("(")[0] + "(")) {
										Sys.println(Blue.currentFile + " - " + "Error: Unknown method at line " + (j + 1));
										gotErrors = true;
										Sys.exit(0);
									}
									if (!completeSyntax.contains(whitespacesplit)
										&& Math.isNaN(Std.parseFloat(whitespacesplit))
										&& whitespacesplit != currentSymbol
										&& !whitespacesplit.contains("/")
										&& whitespacesplit != ""
										&& whitespacesplit != " "
										&& whitespacesplit != 'and'
										&& whitespacesplit != 'outof'
										&& whitespacesplit != 'or'
										&& whitespacesplit != 'greater'
										&& whitespacesplit != 'less'
										&& whitespacesplit != 'than'
										&& !whitespacesplit.contains('"')) {
										if (!completeSyntax.contains(whitespacesplit.split("(")[0].replace(" ", ""))
											&& Math.isNaN(Std.parseFloat(whitespacesplit.split("(")[0].replace(" ", "")))
											&& whitespacesplit.split("(")[0].replace(" ", "") != currentSymbol
											&& !whitespacesplit.split("(")[0].replace(" ", "").contains("/")
											&& whitespacesplit.split("(")[0].replace(" ", "") != ""
											&& whitespacesplit.split("(")[0].replace(" ", "") != " "
											&& whitespacesplit.split("(")[0].replace(" ", "") != 'and'
											&& whitespacesplit.split("(")[0].replace(" ", "") != 'outof'
											&& whitespacesplit.split("(")[0].replace(" ", "") != 'or'
											&& whitespacesplit.split("(")[0].replace(" ", "") != 'greater'
											&& whitespacesplit.split("(")[0].replace(" ", "") != 'less'
											&& whitespacesplit.split("(")[0].replace(" ", "") != 'than'
											&& !whitespacesplit.split("(")[1].split("/")[0].replace(" ", "").contains('"')) {
											if (!current.contains('/')
												&& !localMethods.contains(whitespacesplit.split("(")[0].replace(" ", ""))) {
												Sys.println(Blue.currentFile + " - " + "Error: Unknown method at line " + (linenum));
												gotErrors = true;
												Sys.exit(0);
											}
										}
										if (!completeSyntax.contains(whitespacesplit.split("(")[1].split("/")[0].replace(" ", ""))
											&& Math.isNaN(Std.parseFloat(whitespacesplit.split("(")[1].split("/")[0].replace(" ", "")))
											&& whitespacesplit.split("(")[1].split("/")[0].replace(" ", "") != currentSymbol
											&& !whitespacesplit.split("(")[1].split("/")[0].replace(" ", "").contains("/")
											&& whitespacesplit.split("(")[1].split("/")[0].replace(" ", "") != ""
											&& whitespacesplit.split("(")[1].split("/")[0].replace(" ", "") != " "
											&& whitespacesplit.split("(")[1].split("/")[0].replace(" ", "") != 'and'
											&& whitespacesplit.split("(")[1].split("/")[0].replace(" ", "") != 'outof'
											&& whitespacesplit.split("(")[1].split("/")[0].replace(" ", "") != 'or'
											&& whitespacesplit.split("(")[1].split("/")[0].replace(" ", "") != 'greater'
											&& whitespacesplit.split("(")[1].split("/")[0].replace(" ", "") != 'less'
											&& whitespacesplit.split("(")[1].split("/")[0].replace(" ", "") != 'than'
											&& !whitespacesplit.split("(")[1].split("/")[0].replace(" ", "").contains('"')) {
											if (current.contains('/')
												&& !current.split("(")[1].split(")")[0].contains("/")
												&& !localMethods.contains(whitespacesplit.split("(")[1].split("/")[0].replace(" ", ""))) {
												Sys.println(Blue.currentFile + " - " + "Error: Unknown method at line " + (linenum));
												gotErrors = true;
												Sys.exit(0);
											}
										}
										if (!completeSyntax.contains(whitespacesplit.split("(")[1].split(")")[0].replace(" ", ""))
											&& Math.isNaN(Std.parseFloat(whitespacesplit.split("(")[1].split(")")[0].replace(" ", "")))
											&& whitespacesplit.split("(")[1].split(")")[0].replace(" ", "") != currentSymbol
											&& !whitespacesplit.split("(")[1].split(")")[0].replace(" ", "").contains("/")
											&& whitespacesplit.split("(")[1].split(")")[0].replace(" ", "") != ""
											&& whitespacesplit.split("(")[1].split(")")[0].replace(" ", "") != " "
											&& whitespacesplit.split("(")[1].split(")")[0].replace(" ", "") != 'and'
											&& whitespacesplit.split("(")[1].split(")")[0].replace(" ", "") != 'outof'
											&& whitespacesplit.split("(")[1].split(")")[0].replace(" ", "") != 'or'
											&& whitespacesplit.split("(")[1].split(")")[0].replace(" ", "") != 'greater'
											&& whitespacesplit.split("(")[1].split(")")[0].replace(" ", "") != 'less'
											&& whitespacesplit.split("(")[1].split(")")[0].replace(" ", "") != 'than'
											&& !whitespacesplit.split("(")[1].split(")")[0].replace(" ", "").contains('"')) {
											if (!current.contains(',')
												&& !localVars.contains(whitespacesplit.split("(")[1].split(")")[0].replace(" ", ""))) {
												Sys.println(Blue.currentFile + " - " + "Error: Unknown variable at line " + (linenum));
												gotErrors = true;
												Sys.exit(0);
											} else if (current.contains(',')) {
												if (!completeSyntax.contains(whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", ""))
													&& Math.isNaN(Std.parseFloat(whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", "")))
													&& whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", "") != currentSymbol
													&& !whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", "").contains("/")
													&& whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", "") != ""
													&& whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", "") != " "
													&& whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", "") != 'and'
													&& whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", "") != 'outof'
													&& whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", "") != 'or'
													&& whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", "") != 'greater'
													&& whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", "") != 'less'
													&& whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", "") != 'than'
													&& !whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", "").contains('"')) {
													for (i in 0...current.split("(")[1].split(")")[0].split(',').length) {
														if (!localVars.contains(whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", ""))) {
															Sys.println(Blue.currentFile + " - " + "Error: Unknown variable at line " + (linenum));
															gotErrors = true;
															Sys.exit(0);
														}
													}
												}
											}
										}
									} else if (reg.match(current)
										&& !current.contains("File")
										&& !current.contains("MathTools")
										&& !current.contains("System")
										&& current.contains("/")
										&& current.split('/')[0].contains(whitespacesplit)) {
										if (FileSystem.exists(Blue.directory + "/" + current.split('/')[0].replace(' ', '') + ".bl")) {
											if (!File.getContent(Blue.directory + "/" + current.split('/')[0].replace(' ', '') + ".bl")
												.contains("method " + whitespacesplit.split("/")[1].split("(")[0].replace(' ', "") + "(")) {
												Sys.println(Blue.currentFile
													+ " - "
													+ "Error: Class: "
													+ current.split('/')[0].replace(' ',
														'') + " does not contain method: " + whitespacesplit.split("/")[1].split("(")[0].replace(' ',
														"") + " at line " + (linenum));
												gotErrors = true;
												Sys.exit(0);
											}
										}
									}
								} else {
									Sys.println(Blue.currentFile + " - " + "Error: Method calls must be ended with a ')' and a newline at line " + (linenum));
									gotErrors = true;
									Sys.exit(0);
								}

								if (!testLex) {
									tokensToParse.push(currentToken);
								}
							}
						case 'superClass(':
							var linenum = j + 1;
							var whitespacesplit = current.split(")\r")[0];
							var args = [];
							if (current.contains(")\r")) {
								for (i in 0...current.split('superClass')[1].split('(')[1].split(')').length) {
									if (current.split('superClass')[1].split('(')[1].split(')')[i] != null
										&& current.split('superClass')[1].split('(')[1].split(')')[i].contains(',')) {
										args.push(current.split('superClass')[1].split('(')[1].split(')')[i].split(','));
									} else if (current.split('superClass')[1].split('(')[1].split(')')[i] != null
										&& !current.split('superClass')[1].split('(')[1].split(')')[i].contains(',')) {
										args.push([current.split('superClass')[1].split('(')[1].split(')\r')[0]]);
									}
								}
								var symbols:String = "|~#$%()*+-:;<=>@[]^_.,'!?";
								var currentSymbol = null;
								for (k in 0...symbols.split('').length) {
									currentSymbol = symbols.split('')[k];
								}
								if (!completeSyntax.contains(whitespacesplit)
									&& Math.isNaN(Std.parseFloat(whitespacesplit))
									&& whitespacesplit != currentSymbol
									&& whitespacesplit != ""
									&& whitespacesplit != " "
									&& whitespacesplit != 'and'
									&& whitespacesplit != 'outof'
									&& whitespacesplit != 'or'
									&& whitespacesplit != 'greater'
									&& whitespacesplit != 'less'
									&& whitespacesplit != 'than'
									&& !whitespacesplit.contains('"')) {
									if (!current.contains(',')
										&& !localVars.contains(whitespacesplit.split("(")[1].split(")")[0].replace(" ", ""))) {
										Sys.println(Blue.currentFile + " - " + "Error: Unknown variable at line " + (linenum));
										gotErrors = true;
										Sys.exit(0);
									} else if (current.contains(',')) {
										for (i in 0...current.split("(")[1].split(")")[0].split(',').length) {
											if (!localVars.contains(whitespacesplit.split("(")[1].split(")")[0].split(',')[i].replace(" ", ""))) {
												Sys.println(Blue.currentFile + " - " + "Error: Unknown variable at line " + (linenum));
												gotErrors = true;
												Sys.exit(0);
											}
										}
									}
								}
							} else {
								Sys.println(Blue.currentFile + " - " + "Error: Superclass calls must be ended with a ')' and a newline at line " + (linenum));
								gotErrors = true;
								Sys.exit(0);
							}
							if (reg.match(current)
								&& !current.contains("File")
								&& !current.contains("MathTools")
								&& !current.contains("System")
								&& current.contains("/")
								&& current.split('/')[0].contains(whitespacesplit)) {
								if (FileSystem.exists(Blue.directory + "/" + current.split('/')[0].replace(' ', '') + ".bl")) {
									if (!File.getContent(Blue.directory + "/" + current.split('/')[0].replace(' ', '') + ".bl")
										.contains("method " + whitespacesplit.split("/")[1].split("(")[0].replace(" ", '') + "(")) {
										Sys.println(Blue.currentFile
											+ " - "
											+ "Error: Class: "
											+ current.split('/')[0].replace(' ',
												'') + " does not contain method: " + whitespacesplit.split("/")[1].split("(")[0].replace(" ",
												'') + " at line " + (linenum));
										gotErrors = true;
										Sys.exit(0);
									}
								}
							}

							if (args != null) {
								currentToken = BToken.Super(args);
							} else {
								currentToken = BToken.Super(null);
							}
							if (!testLex) {
								tokensToParse.push(currentToken);
							}

						case '@Override':
							currentToken = BToken.OverrideTag;
							if (!testLex) {
								tokensToParse.push(currentToken);
							}

						case '@Static':
							currentToken = BToken.StaticTag;
							if (!testLex) {
								tokensToParse.push(currentToken);
							}
					}
				}
			}
		}
		if (tokensToParse != null && !gotErrors && !testLex) {
			for (i in 0...tokensToParse.length) {
				if (i == tokensToParse.length - 1) {
					buildAST(tokensToParse[i], true);
				} else {
					buildAST(tokensToParse[i], false);
				}
			}
		}
		tokensToParse = [];
		BLexer.content = contentToEnum;
		BCUtil.CData = ["#include <stdlib.h>"];
		BCoffeeScriptUtil.coffeeScriptData = ["class"];
		BCSUtil.csData = ["class", "{"];
		BCPPUtil.cppData = [
			"#include <cstddef>",
			"#include <cstdio>",
			"#include <iostream>",
			"using namespace std;"
		];
		if (Blue.currentFile_Noerr == "Main.bl") {
			BGoUtil.goData = ['import "fmt"', "type dynamic = interface{}"];
		} else {
			BGoUtil.goData = ['import "fmt"'];
		}
		BGroovyUtil.groovyData = ["", "", "class", "{"];
		BHaxeUtil.haxeData = ["", "", "class", "{"];
		BJSUtil.jsData = ["", ""];
		BLuaUtil.luaData = [];
		return gotErrors;
	}

	public static function buildAST(input:BToken, collectGarbage:Bool = false) {
		parsing.BParser.parse(input, collectGarbage);
	}
}
