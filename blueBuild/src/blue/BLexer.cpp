#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_blue_BLexer
#include <blue/BLexer.h>
#endif
#ifndef INCLUDED_blue_BParser
#include <blue/BParser.h>
#endif
#ifndef INCLUDED_blue_BToken
#include <blue/BToken.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_592fe0dd445f45d4_33_new,"blue.BLexer","new",0x89332db0,"blue.BLexer.new","blue/BLexer.hx",33,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_55_enumContent,"blue.BLexer","enumContent",0xbfcd4988,"blue.BLexer.enumContent","blue/BLexer.hx",55,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_221_buildAST,"blue.BLexer","buildAST",0x6f85d164,"blue.BLexer.buildAST","blue/BLexer.hx",221,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_34_boot,"blue.BLexer","boot",0x7badcce2,"blue.BLexer.boot","blue/BLexer.hx",34,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_35_boot,"blue.BLexer","boot",0x7badcce2,"blue.BLexer.boot","blue/BLexer.hx",35,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_40_boot,"blue.BLexer","boot",0x7badcce2,"blue.BLexer.boot","blue/BLexer.hx",40,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_44_boot,"blue.BLexer","boot",0x7badcce2,"blue.BLexer.boot","blue/BLexer.hx",44,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_45_boot,"blue.BLexer","boot",0x7badcce2,"blue.BLexer.boot","blue/BLexer.hx",45,0x58708f9f)
static const ::String _hx_array_data_4fc6d5be_15[] = {
	HX_("method",e1,f6,5a,09),HX_("loop",64,a6,b7,47),HX_("if",dd,5b,00,00),HX_("+",2b,00,00,00),HX_("-",2d,00,00,00),HX_("mult",f0,67,65,48),HX_("div",51,3d,4c,00),HX_("end",db,03,4d,00),HX_("otherwise",f4,83,f2,9a),HX_("stop",02,f0,5b,4c),HX_("continue",67,e0,c8,31),HX_("then",dd,02,fc,4c),HX_("not",13,d9,53,00),HX_("=",3d,00,00,00),HX_("use",47,2c,59,00),HX_("try",3b,69,58,00),HX_("catch",3b,7c,21,41),HX_("print",2d,58,8b,c8),HX_("return",b0,a4,2d,09),HX_("***",6a,03,20,00),HX_("main method()",e9,ec,13,c5),HX_("throw",26,5d,90,0f),HX_("new",60,d0,53,00),HX_("constructor method()",08,d8,4a,0a),HX_("or",23,61,00,00),HX_("[",5b,00,00,00),HX_("/",2f,00,00,00),HX_("(",28,00,00,00),
};
namespace blue{

void BLexer_obj::__construct(::String content){
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_33_new)
HXLINE(  42)		this->number = ((Float)0);
HXLINE(  37)		this->end = null();
HXLINE(  51)		::blue::BLexer_obj::content = content;
HXLINE(  52)		::blue::BLexer_obj::enumContent(content);
            	}

Dynamic BLexer_obj::__CreateEmpty() { return new BLexer_obj; }

void *BLexer_obj::_hx_vtable = 0;

Dynamic BLexer_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< BLexer_obj > _hx_result = new BLexer_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool BLexer_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x57b05c84;
}

::String BLexer_obj::current;

::String BLexer_obj::_hx_char;

::String BLexer_obj::content;

bool BLexer_obj::last;

::cpp::VirtualArray BLexer_obj::tokensToParse;

::Array< ::String > BLexer_obj::completeSyntax;

void BLexer_obj::enumContent(::String contentToEnum){
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_55_enumContent)
HXLINE(  56)		 ::blue::BToken currentToken = null();
HXLINE(  57)		{
HXLINE(  57)			int _g = 0;
HXDLIN(  57)			int _g1 = contentToEnum.split(HX_("\n",0a,00,00,00))->length;
HXDLIN(  57)			while((_g < _g1)){
HXLINE(  57)				_g = (_g + 1);
HXDLIN(  57)				int j = (_g - 1);
HXLINE(  58)				::blue::BLexer_obj::current = contentToEnum.split(HX_("\n",0a,00,00,00))->__get(j);
HXLINE(  59)				{
HXLINE(  59)					int _g1 = 0;
HXDLIN(  59)					int _g2 = ::blue::BLexer_obj::completeSyntax->length;
HXDLIN(  59)					while((_g1 < _g2)){
HXLINE(  59)						_g1 = (_g1 + 1);
HXDLIN(  59)						int i = (_g1 - 1);
HXLINE(  60)						if ((::blue::BLexer_obj::current.indexOf(::blue::BLexer_obj::completeSyntax->__get(i),null()) != -1)) {
HXLINE(  61)							::String _hx_switch_0 = ::blue::BLexer_obj::completeSyntax->__get(i);
            							if (  (_hx_switch_0==HX_("(",28,00,00,00)) ){
HXLINE( 198)								bool _hx_tmp;
HXDLIN( 198)								bool _hx_tmp1;
HXDLIN( 198)								bool _hx_tmp2;
HXDLIN( 198)								if ((::blue::BLexer_obj::current.indexOf(HX_("method",e1,f6,5a,09),null()) == -1)) {
HXLINE( 198)									_hx_tmp2 = (::blue::BLexer_obj::current.indexOf(HX_("print",2d,58,8b,c8),null()) == -1);
            								}
            								else {
HXLINE( 198)									_hx_tmp2 = false;
            								}
HXDLIN( 198)								if (_hx_tmp2) {
HXLINE( 198)									_hx_tmp1 = (::blue::BLexer_obj::current.indexOf(HX_("/",2f,00,00,00),null()) == -1);
            								}
            								else {
HXLINE( 198)									_hx_tmp1 = false;
            								}
HXDLIN( 198)								if (_hx_tmp1) {
HXLINE( 198)									_hx_tmp = (::blue::BLexer_obj::current.indexOf(HX_("new",60,d0,53,00),null()) == -1);
            								}
            								else {
HXLINE( 198)									_hx_tmp = false;
            								}
HXDLIN( 198)								if (_hx_tmp) {
HXLINE( 199)									currentToken = ::blue::BToken_obj::FunctionC(::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_(")",29,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)));
HXLINE( 200)									::blue::BLexer_obj::tokensToParse->push(currentToken);
            								}
HXLINE( 198)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("***",6a,03,20,00)) ){
HXLINE( 150)								currentToken = ::blue::BToken_obj::Comment(::blue::BLexer_obj::current.split(HX_("*** ",76,f9,e2,1b))->__get(1).split(HX_("***",6a,03,20,00))->__get(0));
HXLINE( 151)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 149)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("+",2b,00,00,00)) ){
HXLINE( 105)								::String currentToken1 = ::StringTools_obj::replace(::StringTools_obj::replace(contentToEnum.split(HX_("+",2b,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("\n",0a,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXDLIN( 105)								currentToken = ::blue::BToken_obj::Add(currentToken1,::StringTools_obj::replace(contentToEnum.split(HX_("+",2b,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_(" ",20,00,00,00))->__get(0));
HXLINE( 107)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 104)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("-",2d,00,00,00)) ){
HXLINE( 110)								::String currentToken1 = ::StringTools_obj::replace(::StringTools_obj::replace(contentToEnum.split(HX_("-",2d,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("\n",0a,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXDLIN( 110)								currentToken = ::blue::BToken_obj::Subtract(currentToken1,::StringTools_obj::replace(contentToEnum.split(HX_("-",2d,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_(" ",20,00,00,00))->__get(0));
HXLINE( 112)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 109)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("/",2f,00,00,00)) ){
HXLINE( 204)								bool _hx_tmp;
HXDLIN( 204)								if ((::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_("/",2f,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).indexOf(HX_("\"",22,00,00,00),null()) == -1)) {
HXLINE( 204)									_hx_tmp = (::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_("/",2f,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).indexOf(HX_("\"",22,00,00,00),null()) == -1);
            								}
            								else {
HXLINE( 204)									_hx_tmp = false;
            								}
HXDLIN( 204)								if (_hx_tmp) {
HXLINE( 205)									::String currentToken1 = ::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_("/",2f,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXDLIN( 205)									currentToken = ::blue::BToken_obj::Property(currentToken1,::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_("/",2f,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("/",2f,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)),HX_("\r",0d,00,00,00),HX_(";",3b,00,00,00)));
HXLINE( 207)									::blue::BLexer_obj::tokensToParse->push(currentToken);
            								}
HXLINE( 204)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("=",3d,00,00,00)) ){
HXLINE(  87)								if ((::blue::BLexer_obj::current.indexOf(HX_("if ",a3,05,50,00),null()) == -1)) {
HXLINE(  88)									::String currentToken1 = ::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_("=",3d,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXDLIN(  88)									currentToken = ::blue::BToken_obj::Variable(currentToken1,::StringTools_obj::replace(::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_("=",3d,00,00,00))->__get(1).split(HX_("\n",0a,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)),HX_("\r",0d,00,00,00),HX_(";",3b,00,00,00)));
HXLINE(  90)									::blue::BLexer_obj::tokensToParse->push(currentToken);
            								}
HXLINE(  87)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("catch",3b,7c,21,41)) ){
HXLINE( 142)								currentToken = ::blue::BToken_obj::Catch(::blue::BLexer_obj::current.split(HX_("catch(",8d,37,2b,bc))->__get(1).split(HX_(")",29,00,00,00))->__get(0));
HXLINE( 143)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 141)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("constructor method()",08,d8,4a,0a)) ){
HXLINE( 176)								::Array< ::Dynamic> args = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 177)								{
HXLINE( 177)									int _g = 0;
HXDLIN( 177)									int _g1 = ::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->length;
HXDLIN( 177)									while((_g < _g1)){
HXLINE( 177)										_g = (_g + 1);
HXDLIN( 177)										int i = (_g - 1);
HXLINE( 178)										bool _hx_tmp;
HXDLIN( 178)										if (::hx::IsNotNull( ::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i) )) {
HXLINE( 178)											_hx_tmp = (::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).indexOf(HX_(",",2c,00,00,00),null()) != -1);
            										}
            										else {
HXLINE( 178)											_hx_tmp = false;
            										}
HXDLIN( 178)										if (_hx_tmp) {
HXLINE( 180)											args->push(::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).split(HX_(",",2c,00,00,00)));
            										}
            										else {
HXLINE( 181)											bool _hx_tmp;
HXDLIN( 181)											if (::hx::IsNotNull( ::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i) )) {
HXLINE( 181)												_hx_tmp = (::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).indexOf(HX_(",",2c,00,00,00),null()) == -1);
            											}
            											else {
HXLINE( 181)												_hx_tmp = false;
            											}
HXDLIN( 181)											if (_hx_tmp) {
HXLINE( 183)												args->push(::Array_obj< ::String >::__new(1)->init(0,::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0)));
            											}
            										}
            									}
            								}
HXLINE( 186)								if (::hx::IsNotNull( args )) {
HXLINE( 187)									currentToken = ::blue::BToken_obj::Constructor(args);
            								}
            								else {
HXLINE( 189)									currentToken = ::blue::BToken_obj::Constructor(null());
            								}
HXLINE( 191)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 175)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("div",51,3d,4c,00)) ){
HXLINE( 115)								::String currentToken1 = ::StringTools_obj::replace(::StringTools_obj::replace(contentToEnum.split(HX_("div",51,3d,4c,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("\n",0a,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXDLIN( 115)								currentToken = ::blue::BToken_obj::Multiply(currentToken1,::StringTools_obj::replace(contentToEnum.split(HX_("div",51,3d,4c,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_(" ",20,00,00,00))->__get(0));
HXLINE( 117)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 114)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("end",db,03,4d,00)) ){
HXLINE( 124)								currentToken = ::blue::BToken_obj::End_dyn();
HXLINE( 125)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 123)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("if",dd,5b,00,00)) ){
HXLINE( 101)								currentToken = ::blue::BToken_obj::IfStatement(contentToEnum.split(HX_("if ",a3,05,50,00))->__get(1).split(HX_("then",dd,02,fc,4c))->__get(0));
HXLINE( 102)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 100)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("loop",64,a6,b7,47)) ){
HXLINE(  94)								::String currentToken1 = ::StringTools_obj::replace(contentToEnum.split(HX_("loop ",3c,f1,f9,78))->__get(1).split(HX_("in",e5,5b,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXLINE(  95)								::String currentToken2 = ::StringTools_obj::replace(::StringTools_obj::replace(contentToEnum.split(HX_("loop ",3c,f1,f9,78))->__get(1).split(HX_("in",e5,5b,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("until",9e,b8,ef,a6))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXLINE(  94)								currentToken = ::blue::BToken_obj::ForStatement(currentToken1,currentToken2,::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(contentToEnum.split(HX_("loop ",3c,f1,f9,78))->__get(1).split(HX_("in",e5,5b,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("until",9e,b8,ef,a6))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("\n",0a,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)));
HXLINE(  98)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE(  93)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("main method()",e9,ec,13,c5)) ){
HXLINE(  83)								currentToken = ::blue::BToken_obj::MainMethod_dyn();
HXLINE(  84)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE(  82)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("method",e1,f6,5a,09)) ){
HXLINE(  63)								if ((::blue::BLexer_obj::current.indexOf(HX_("main method()",e9,ec,13,c5),null()) == -1)) {
HXLINE(  64)									::Array< ::Dynamic> args = ::Array_obj< ::Dynamic>::__new(0);
HXLINE(  65)									{
HXLINE(  65)										int _g = 0;
HXDLIN(  65)										int _g1 = ::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->length;
HXDLIN(  65)										while((_g < _g1)){
HXLINE(  65)											_g = (_g + 1);
HXDLIN(  65)											int i = (_g - 1);
HXLINE(  66)											bool _hx_tmp;
HXDLIN(  66)											if (::hx::IsNotNull( ::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i) )) {
HXLINE(  66)												_hx_tmp = (::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).indexOf(HX_(",",2c,00,00,00),null()) != -1);
            											}
            											else {
HXLINE(  66)												_hx_tmp = false;
            											}
HXDLIN(  66)											if (_hx_tmp) {
HXLINE(  68)												args->push(::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).split(HX_(",",2c,00,00,00)));
            											}
            											else {
HXLINE(  69)												bool _hx_tmp;
HXDLIN(  69)												if (::hx::IsNotNull( ::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i) )) {
HXLINE(  69)													_hx_tmp = (::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).indexOf(HX_(",",2c,00,00,00),null()) == -1);
            												}
            												else {
HXLINE(  69)													_hx_tmp = false;
            												}
HXDLIN(  69)												if (_hx_tmp) {
HXLINE(  71)													args->push(::Array_obj< ::String >::__new(1)->init(0,::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0)));
            												}
            											}
            										}
            									}
HXLINE(  74)									if (::hx::IsNotNull( args )) {
HXLINE(  75)										currentToken = ::blue::BToken_obj::Method(contentToEnum.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(0),args);
            									}
            									else {
HXLINE(  77)										currentToken = ::blue::BToken_obj::Method(contentToEnum.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(0),null());
            									}
HXLINE(  79)									::blue::BLexer_obj::tokensToParse->push(currentToken);
            								}
HXLINE(  63)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("mult",f0,67,65,48)) ){
HXLINE( 120)								::String currentToken1 = ::StringTools_obj::replace(::StringTools_obj::replace(contentToEnum.split(HX_("mult",f0,67,65,48))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("\n",0a,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXDLIN( 120)								currentToken = ::blue::BToken_obj::Divide(currentToken1,::StringTools_obj::replace(contentToEnum.split(HX_("mult",f0,67,65,48))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_(" ",20,00,00,00))->__get(0));
HXLINE( 122)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 119)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("new",60,d0,53,00)) ){
HXLINE( 158)								::Array< ::Dynamic> args = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 159)								{
HXLINE( 159)									int _g = 0;
HXDLIN( 159)									int _g1 = ::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->length;
HXDLIN( 159)									while((_g < _g1)){
HXLINE( 159)										_g = (_g + 1);
HXDLIN( 159)										int i = (_g - 1);
HXLINE( 160)										bool _hx_tmp;
HXDLIN( 160)										if (::hx::IsNotNull( ::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i) )) {
HXLINE( 160)											_hx_tmp = (::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).indexOf(HX_(",",2c,00,00,00),null()) != -1);
            										}
            										else {
HXLINE( 160)											_hx_tmp = false;
            										}
HXDLIN( 160)										if (_hx_tmp) {
HXLINE( 162)											args->push(::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).split(HX_(",",2c,00,00,00)));
            										}
            										else {
HXLINE( 163)											bool _hx_tmp;
HXDLIN( 163)											if (::hx::IsNotNull( ::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i) )) {
HXLINE( 163)												_hx_tmp = (::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).indexOf(HX_(",",2c,00,00,00),null()) == -1);
            											}
            											else {
HXLINE( 163)												_hx_tmp = false;
            											}
HXDLIN( 163)											if (_hx_tmp) {
HXLINE( 165)												args->push(::Array_obj< ::String >::__new(1)->init(0,::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0)));
            											}
            										}
            									}
            								}
HXLINE( 168)								if (::hx::IsNotNull( args )) {
HXLINE( 169)									currentToken = ::blue::BToken_obj::New(::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0),args);
            								}
            								else {
HXLINE( 171)									currentToken = ::blue::BToken_obj::New(::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0),null());
            								}
HXLINE( 173)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 157)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("otherwise",f4,83,f2,9a)) ){
HXLINE( 194)								currentToken = ::blue::BToken_obj::Else_dyn();
HXLINE( 195)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 193)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("print",2d,58,8b,c8)) ){
HXLINE( 132)								if ((::blue::BLexer_obj::current.indexOf(HX_("print(",5b,cf,61,b1),null()) != -1)) {
HXLINE( 133)									currentToken = ::blue::BToken_obj::Print(::blue::BLexer_obj::current.split(HX_("print(",5b,cf,61,b1))->__get(1).split(HX_(")",29,00,00,00))->__get(0));
HXLINE( 134)									::blue::BLexer_obj::tokensToParse->push(currentToken);
            								}
HXLINE( 132)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("return",b0,a4,2d,09)) ){
HXLINE( 146)								currentToken = ::blue::BToken_obj::Return(::StringTools_obj::replace(::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_("return ",70,75,c2,fe))->__get(1).split(HX_("\n",0a,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)),HX_("\r",0d,00,00,00),HX_(";",3b,00,00,00)));
HXLINE( 147)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 145)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("throw",26,5d,90,0f)) ){
HXLINE( 154)								currentToken = ::blue::BToken_obj::Throw(::blue::BLexer_obj::current.split(HX_("throw(",42,24,c1,8e))->__get(1).split(HX_(")",29,00,00,00))->__get(0));
HXLINE( 155)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 153)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("try",3b,69,58,00)) ){
HXLINE( 138)								currentToken = ::blue::BToken_obj::Try_dyn();
HXLINE( 139)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 137)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("use",47,2c,59,00)) ){
HXLINE( 128)								currentToken = ::blue::BToken_obj::Use(::blue::BLexer_obj::current.split(HX_("use ",f9,91,ad,4d))->__get(1).split(HX_("\n",0a,00,00,00))->__get(0));
HXLINE( 129)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 127)								goto _hx_goto_3;
            							}
            							_hx_goto_3:;
            						}
            					}
            				}
            			}
            		}
HXLINE( 213)		if (::hx::IsNotNull( ::blue::BLexer_obj::tokensToParse )) {
HXLINE( 214)			int _g = 0;
HXDLIN( 214)			int _g1 = ::blue::BLexer_obj::tokensToParse->get_length();
HXDLIN( 214)			while((_g < _g1)){
HXLINE( 214)				_g = (_g + 1);
HXDLIN( 214)				int i = (_g - 1);
HXLINE( 215)				::blue::BLexer_obj::buildAST(::blue::BLexer_obj::tokensToParse->__get(i));
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BLexer_obj,enumContent,(void))

void BLexer_obj::buildAST( ::blue::BToken input){
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_221_buildAST)
HXDLIN( 221)		::blue::BParser_obj::parse(input);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BLexer_obj,buildAST,(void))


BLexer_obj::BLexer_obj()
{
}

void BLexer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BLexer);
	HX_MARK_MEMBER_NAME(end,"end");
	HX_MARK_MEMBER_NAME(number,"number");
	HX_MARK_END_CLASS();
}

void BLexer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(end,"end");
	HX_VISIT_MEMBER_NAME(number,"number");
}

::hx::Val BLexer_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"end") ) { return ::hx::Val( end ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"number") ) { return ::hx::Val( number ); }
	}
	return super::__Field(inName,inCallProp);
}

bool BLexer_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"char") ) { outValue = ( _hx_char ); return true; }
		if (HX_FIELD_EQ(inName,"last") ) { outValue = ( last ); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { outValue = ( current ); return true; }
		if (HX_FIELD_EQ(inName,"content") ) { outValue = ( content ); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"buildAST") ) { outValue = buildAST_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"enumContent") ) { outValue = enumContent_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"tokensToParse") ) { outValue = ( tokensToParse ); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"completeSyntax") ) { outValue = ( completeSyntax ); return true; }
	}
	return false;
}

::hx::Val BLexer_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"end") ) { end=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"number") ) { number=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool BLexer_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"char") ) { _hx_char=ioValue.Cast< ::String >(); return true; }
		if (HX_FIELD_EQ(inName,"last") ) { last=ioValue.Cast< bool >(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { current=ioValue.Cast< ::String >(); return true; }
		if (HX_FIELD_EQ(inName,"content") ) { content=ioValue.Cast< ::String >(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"tokensToParse") ) { tokensToParse=ioValue.Cast< ::cpp::VirtualArray >(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"completeSyntax") ) { completeSyntax=ioValue.Cast< ::Array< ::String > >(); return true; }
	}
	return false;
}

void BLexer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("end",db,03,4d,00));
	outFields->push(HX_("number",c9,86,7a,a1));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo BLexer_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(BLexer_obj,end),HX_("end",db,03,4d,00)},
	{::hx::fsFloat,(int)offsetof(BLexer_obj,number),HX_("number",c9,86,7a,a1)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo BLexer_obj_sStaticStorageInfo[] = {
	{::hx::fsString,(void *) &BLexer_obj::current,HX_("current",39,9c,e3,cb)},
	{::hx::fsString,(void *) &BLexer_obj::_hx_char,HX_("char",d6,5e,bf,41)},
	{::hx::fsString,(void *) &BLexer_obj::content,HX_("content",39,8d,77,19)},
	{::hx::fsBool,(void *) &BLexer_obj::last,HX_("last",56,0a,ad,47)},
	{::hx::fsObject /* ::cpp::VirtualArray */ ,(void *) &BLexer_obj::tokensToParse,HX_("tokensToParse",7e,ec,20,84)},
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &BLexer_obj::completeSyntax,HX_("completeSyntax",fc,c7,f3,b6)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String BLexer_obj_sMemberFields[] = {
	HX_("end",db,03,4d,00),
	HX_("number",c9,86,7a,a1),
	::String(null()) };

static void BLexer_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BLexer_obj::current,"current");
	HX_MARK_MEMBER_NAME(BLexer_obj::_hx_char,"char");
	HX_MARK_MEMBER_NAME(BLexer_obj::content,"content");
	HX_MARK_MEMBER_NAME(BLexer_obj::last,"last");
	HX_MARK_MEMBER_NAME(BLexer_obj::tokensToParse,"tokensToParse");
	HX_MARK_MEMBER_NAME(BLexer_obj::completeSyntax,"completeSyntax");
};

#ifdef HXCPP_VISIT_ALLOCS
static void BLexer_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BLexer_obj::current,"current");
	HX_VISIT_MEMBER_NAME(BLexer_obj::_hx_char,"char");
	HX_VISIT_MEMBER_NAME(BLexer_obj::content,"content");
	HX_VISIT_MEMBER_NAME(BLexer_obj::last,"last");
	HX_VISIT_MEMBER_NAME(BLexer_obj::tokensToParse,"tokensToParse");
	HX_VISIT_MEMBER_NAME(BLexer_obj::completeSyntax,"completeSyntax");
};

#endif

::hx::Class BLexer_obj::__mClass;

static ::String BLexer_obj_sStaticFields[] = {
	HX_("current",39,9c,e3,cb),
	HX_("char",d6,5e,bf,41),
	HX_("content",39,8d,77,19),
	HX_("last",56,0a,ad,47),
	HX_("tokensToParse",7e,ec,20,84),
	HX_("completeSyntax",fc,c7,f3,b6),
	HX_("enumContent",38,1c,58,21),
	HX_("buildAST",b4,70,a9,53),
	::String(null())
};

void BLexer_obj::__register()
{
	BLexer_obj _hx_dummy;
	BLexer_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("blue.BLexer",be,d5,c6,4f);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &BLexer_obj::__GetStatic;
	__mClass->mSetStaticField = &BLexer_obj::__SetStatic;
	__mClass->mMarkFunc = BLexer_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(BLexer_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(BLexer_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< BLexer_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = BLexer_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = BLexer_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = BLexer_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void BLexer_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_34_boot)
HXDLIN(  34)		current = null();
            	}
{
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_35_boot)
HXDLIN(  35)		_hx_char = null();
            	}
{
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_40_boot)
HXDLIN(  40)		last = false;
            	}
{
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_44_boot)
HXDLIN(  44)		tokensToParse = ::cpp::VirtualArray_obj::__new(0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_45_boot)
HXDLIN(  45)		completeSyntax = ::Array_obj< ::String >::fromData( _hx_array_data_4fc6d5be_15,28);
            	}
}

} // end namespace blue
