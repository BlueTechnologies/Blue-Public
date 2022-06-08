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

HX_DEFINE_STACK_FRAME(_hx_pos_592fe0dd445f45d4_34_new,"blue.BLexer","new",0x89332db0,"blue.BLexer.new","blue/BLexer.hx",34,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_56_enumContent,"blue.BLexer","enumContent",0xbfcd4988,"blue.BLexer.enumContent","blue/BLexer.hx",56,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_224_buildAST,"blue.BLexer","buildAST",0x6f85d164,"blue.BLexer.buildAST","blue/BLexer.hx",224,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_35_boot,"blue.BLexer","boot",0x7badcce2,"blue.BLexer.boot","blue/BLexer.hx",35,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_36_boot,"blue.BLexer","boot",0x7badcce2,"blue.BLexer.boot","blue/BLexer.hx",36,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_41_boot,"blue.BLexer","boot",0x7badcce2,"blue.BLexer.boot","blue/BLexer.hx",41,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_45_boot,"blue.BLexer","boot",0x7badcce2,"blue.BLexer.boot","blue/BLexer.hx",45,0x58708f9f)
HX_LOCAL_STACK_FRAME(_hx_pos_592fe0dd445f45d4_46_boot,"blue.BLexer","boot",0x7badcce2,"blue.BLexer.boot","blue/BLexer.hx",46,0x58708f9f)
static const ::String _hx_array_data_4fc6d5be_15[] = {
	HX_("method",e1,f6,5a,09),HX_("loop",64,a6,b7,47),HX_("if",dd,5b,00,00),HX_("+",2b,00,00,00),HX_("-",2d,00,00,00),HX_("mult",f0,67,65,48),HX_("div",51,3d,4c,00),HX_("end",db,03,4d,00),HX_("otherwise",f4,83,f2,9a),HX_("stop",02,f0,5b,4c),HX_("continue",67,e0,c8,31),HX_("then",dd,02,fc,4c),HX_("not",13,d9,53,00),HX_("=",3d,00,00,00),HX_("use",47,2c,59,00),HX_("try",3b,69,58,00),HX_("catch",3b,7c,21,41),HX_("print",2d,58,8b,c8),HX_("return",b0,a4,2d,09),HX_("***",6a,03,20,00),HX_("main method()",e9,ec,13,c5),HX_("throw",26,5d,90,0f),HX_("new",60,d0,53,00),HX_("constructor method()",08,d8,4a,0a),HX_("or",23,61,00,00),HX_("[",5b,00,00,00),HX_("/",2f,00,00,00),HX_("(",28,00,00,00),
};
namespace blue{

void BLexer_obj::__construct(::String content){
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_34_new)
HXLINE(  43)		this->number = ((Float)0);
HXLINE(  38)		this->end = null();
HXLINE(  52)		::blue::BLexer_obj::content = content;
HXLINE(  53)		::blue::BLexer_obj::enumContent(content);
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
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_56_enumContent)
HXLINE(  57)		 ::blue::BToken currentToken = null();
HXLINE(  58)		{
HXLINE(  58)			int _g = 0;
HXDLIN(  58)			int _g1 = contentToEnum.split(HX_("\n",0a,00,00,00))->length;
HXDLIN(  58)			while((_g < _g1)){
HXLINE(  58)				_g = (_g + 1);
HXDLIN(  58)				int j = (_g - 1);
HXLINE(  59)				::blue::BLexer_obj::current = contentToEnum.split(HX_("\n",0a,00,00,00))->__get(j);
HXLINE(  60)				{
HXLINE(  60)					int _g1 = 0;
HXDLIN(  60)					int _g2 = ::blue::BLexer_obj::completeSyntax->length;
HXDLIN(  60)					while((_g1 < _g2)){
HXLINE(  60)						_g1 = (_g1 + 1);
HXDLIN(  60)						int i = (_g1 - 1);
HXLINE(  61)						if ((::blue::BLexer_obj::current.indexOf(::blue::BLexer_obj::completeSyntax->__get(i),null()) != -1)) {
HXLINE(  62)							::String _hx_switch_0 = ::blue::BLexer_obj::completeSyntax->__get(i);
            							if (  (_hx_switch_0==HX_("(",28,00,00,00)) ){
HXLINE( 203)								bool _hx_tmp;
HXDLIN( 203)								bool _hx_tmp1;
HXDLIN( 203)								bool _hx_tmp2;
HXDLIN( 203)								if ((::blue::BLexer_obj::current.indexOf(HX_("method",e1,f6,5a,09),null()) == -1)) {
HXLINE( 203)									_hx_tmp2 = (::blue::BLexer_obj::current.indexOf(HX_("print",2d,58,8b,c8),null()) == -1);
            								}
            								else {
HXLINE( 203)									_hx_tmp2 = false;
            								}
HXDLIN( 203)								if (_hx_tmp2) {
HXLINE( 203)									_hx_tmp1 = (::blue::BLexer_obj::current.indexOf(HX_("/",2f,00,00,00),null()) == -1);
            								}
            								else {
HXLINE( 203)									_hx_tmp1 = false;
            								}
HXDLIN( 203)								if (_hx_tmp1) {
HXLINE( 203)									_hx_tmp = (::blue::BLexer_obj::current.indexOf(HX_("new",60,d0,53,00),null()) == -1);
            								}
            								else {
HXLINE( 203)									_hx_tmp = false;
            								}
HXDLIN( 203)								if (_hx_tmp) {
HXLINE( 204)									currentToken = ::blue::BToken_obj::FunctionC(::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_(")",29,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)));
HXLINE( 205)									::blue::BLexer_obj::tokensToParse->push(currentToken);
            								}
HXLINE( 203)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("***",6a,03,20,00)) ){
HXLINE( 151)								currentToken = ::blue::BToken_obj::Comment(::blue::BLexer_obj::current.split(HX_("*** ",76,f9,e2,1b))->__get(1).split(HX_("***",6a,03,20,00))->__get(0));
HXLINE( 152)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 150)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("+",2b,00,00,00)) ){
HXLINE( 106)								::String currentToken1 = ::StringTools_obj::replace(::StringTools_obj::replace(contentToEnum.split(HX_("+",2b,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("\n",0a,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXDLIN( 106)								currentToken = ::blue::BToken_obj::Add(currentToken1,::StringTools_obj::replace(contentToEnum.split(HX_("+",2b,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_(" ",20,00,00,00))->__get(0));
HXLINE( 108)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 105)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("-",2d,00,00,00)) ){
HXLINE( 111)								::String currentToken1 = ::StringTools_obj::replace(::StringTools_obj::replace(contentToEnum.split(HX_("-",2d,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("\n",0a,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXDLIN( 111)								currentToken = ::blue::BToken_obj::Subtract(currentToken1,::StringTools_obj::replace(contentToEnum.split(HX_("-",2d,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_(" ",20,00,00,00))->__get(0));
HXLINE( 113)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 110)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("/",2f,00,00,00)) ){
HXLINE( 209)								::String currentToken1 = ::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_("/",2f,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXDLIN( 209)								currentToken = ::blue::BToken_obj::Property(currentToken1,::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_("/",2f,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("/",2f,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)),HX_("\r",0d,00,00,00),HX_(";",3b,00,00,00)));
HXLINE( 211)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 208)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("=",3d,00,00,00)) ){
HXLINE(  88)								if ((::blue::BLexer_obj::current.indexOf(HX_("if ",a3,05,50,00),null()) == -1)) {
HXLINE(  89)									::String currentToken1 = ::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_("=",3d,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXDLIN(  89)									currentToken = ::blue::BToken_obj::Variable(currentToken1,::StringTools_obj::replace(::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_("=",3d,00,00,00))->__get(1).split(HX_("\n",0a,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)),HX_("\r",0d,00,00,00),HX_(";",3b,00,00,00)));
HXLINE(  91)									::blue::BLexer_obj::tokensToParse->push(currentToken);
            								}
HXLINE(  88)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("[",5b,00,00,00)) ){
HXLINE( 199)								currentToken = ::blue::BToken_obj::ArrayIndex(::blue::BLexer_obj::current.split(HX_("[",5b,00,00,00))->__get(1).split(HX_("]",5d,00,00,00))->__get(0));
HXLINE( 200)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 198)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("catch",3b,7c,21,41)) ){
HXLINE( 143)								currentToken = ::blue::BToken_obj::Catch(::blue::BLexer_obj::current.split(HX_("catch(",8d,37,2b,bc))->__get(1).split(HX_(")",29,00,00,00))->__get(0));
HXLINE( 144)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 142)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("constructor method()",08,d8,4a,0a)) ){
HXLINE( 177)								::Array< ::Dynamic> args = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 178)								{
HXLINE( 178)									int _g = 0;
HXDLIN( 178)									int _g1 = ::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->length;
HXDLIN( 178)									while((_g < _g1)){
HXLINE( 178)										_g = (_g + 1);
HXDLIN( 178)										int i = (_g - 1);
HXLINE( 179)										bool _hx_tmp;
HXDLIN( 179)										if (::hx::IsNotNull( ::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i) )) {
HXLINE( 179)											_hx_tmp = (::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).indexOf(HX_(",",2c,00,00,00),null()) != -1);
            										}
            										else {
HXLINE( 179)											_hx_tmp = false;
            										}
HXDLIN( 179)										if (_hx_tmp) {
HXLINE( 181)											args->push(::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).split(HX_(",",2c,00,00,00)));
            										}
            										else {
HXLINE( 182)											bool _hx_tmp;
HXDLIN( 182)											if (::hx::IsNotNull( ::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i) )) {
HXLINE( 182)												_hx_tmp = (::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).indexOf(HX_(",",2c,00,00,00),null()) == -1);
            											}
            											else {
HXLINE( 182)												_hx_tmp = false;
            											}
HXDLIN( 182)											if (_hx_tmp) {
HXLINE( 184)												args->push(::Array_obj< ::String >::__new(1)->init(0,::blue::BLexer_obj::current.split(HX_("constructor method ",f9,08,1d,2f))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0)));
            											}
            										}
            									}
            								}
HXLINE( 187)								if (::hx::IsNotNull( args )) {
HXLINE( 188)									currentToken = ::blue::BToken_obj::Constructor(args);
            								}
            								else {
HXLINE( 190)									currentToken = ::blue::BToken_obj::Constructor(null());
            								}
HXLINE( 192)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 176)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("div",51,3d,4c,00)) ){
HXLINE( 116)								::String currentToken1 = ::StringTools_obj::replace(::StringTools_obj::replace(contentToEnum.split(HX_("div",51,3d,4c,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("\n",0a,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXDLIN( 116)								currentToken = ::blue::BToken_obj::Multiply(currentToken1,::StringTools_obj::replace(contentToEnum.split(HX_("div",51,3d,4c,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_(" ",20,00,00,00))->__get(0));
HXLINE( 118)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 115)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("end",db,03,4d,00)) ){
HXLINE( 125)								currentToken = ::blue::BToken_obj::End_dyn();
HXLINE( 126)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 124)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("if",dd,5b,00,00)) ){
HXLINE( 102)								currentToken = ::blue::BToken_obj::IfStatement(contentToEnum.split(HX_("if ",a3,05,50,00))->__get(1).split(HX_("then",dd,02,fc,4c))->__get(0));
HXLINE( 103)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 101)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("loop",64,a6,b7,47)) ){
HXLINE(  95)								::String currentToken1 = ::StringTools_obj::replace(contentToEnum.split(HX_("loop ",3c,f1,f9,78))->__get(1).split(HX_("in",e5,5b,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXLINE(  96)								::String currentToken2 = ::StringTools_obj::replace(::StringTools_obj::replace(contentToEnum.split(HX_("loop ",3c,f1,f9,78))->__get(1).split(HX_("in",e5,5b,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("until",9e,b8,ef,a6))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXLINE(  95)								currentToken = ::blue::BToken_obj::ForStatement(currentToken1,currentToken2,::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(contentToEnum.split(HX_("loop ",3c,f1,f9,78))->__get(1).split(HX_("in",e5,5b,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("until",9e,b8,ef,a6))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("\n",0a,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)));
HXLINE(  99)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE(  94)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("main method()",e9,ec,13,c5)) ){
HXLINE(  84)								currentToken = ::blue::BToken_obj::MainMethod_dyn();
HXLINE(  85)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE(  83)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("method",e1,f6,5a,09)) ){
HXLINE(  64)								if ((::blue::BLexer_obj::current.indexOf(HX_("main method()",e9,ec,13,c5),null()) == -1)) {
HXLINE(  65)									::Array< ::Dynamic> args = ::Array_obj< ::Dynamic>::__new(0);
HXLINE(  66)									{
HXLINE(  66)										int _g = 0;
HXDLIN(  66)										int _g1 = ::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->length;
HXDLIN(  66)										while((_g < _g1)){
HXLINE(  66)											_g = (_g + 1);
HXDLIN(  66)											int i = (_g - 1);
HXLINE(  67)											bool _hx_tmp;
HXDLIN(  67)											if (::hx::IsNotNull( ::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i) )) {
HXLINE(  67)												_hx_tmp = (::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).indexOf(HX_(",",2c,00,00,00),null()) != -1);
            											}
            											else {
HXLINE(  67)												_hx_tmp = false;
            											}
HXDLIN(  67)											if (_hx_tmp) {
HXLINE(  69)												args->push(::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).split(HX_(",",2c,00,00,00)));
            											}
            											else {
HXLINE(  70)												bool _hx_tmp;
HXDLIN(  70)												if (::hx::IsNotNull( ::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i) )) {
HXLINE(  70)													_hx_tmp = (::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).indexOf(HX_(",",2c,00,00,00),null()) == -1);
            												}
            												else {
HXLINE(  70)													_hx_tmp = false;
            												}
HXDLIN(  70)												if (_hx_tmp) {
HXLINE(  72)													args->push(::Array_obj< ::String >::__new(1)->init(0,::blue::BLexer_obj::current.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0)));
            												}
            											}
            										}
            									}
HXLINE(  75)									if (::hx::IsNotNull( args )) {
HXLINE(  76)										currentToken = ::blue::BToken_obj::Method(contentToEnum.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(0),args);
            									}
            									else {
HXLINE(  78)										currentToken = ::blue::BToken_obj::Method(contentToEnum.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(0),null());
            									}
HXLINE(  80)									::blue::BLexer_obj::tokensToParse->push(currentToken);
            								}
HXLINE(  64)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("mult",f0,67,65,48)) ){
HXLINE( 121)								::String currentToken1 = ::StringTools_obj::replace(::StringTools_obj::replace(contentToEnum.split(HX_("mult",f0,67,65,48))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_("\n",0a,00,00,00))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00));
HXDLIN( 121)								currentToken = ::blue::BToken_obj::Divide(currentToken1,::StringTools_obj::replace(contentToEnum.split(HX_("mult",f0,67,65,48))->__get(1),HX_(" ",20,00,00,00),HX_("",00,00,00,00)).split(HX_(" ",20,00,00,00))->__get(0));
HXLINE( 123)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 120)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("new",60,d0,53,00)) ){
HXLINE( 159)								::Array< ::Dynamic> args = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 160)								{
HXLINE( 160)									int _g = 0;
HXDLIN( 160)									int _g1 = ::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->length;
HXDLIN( 160)									while((_g < _g1)){
HXLINE( 160)										_g = (_g + 1);
HXDLIN( 160)										int i = (_g - 1);
HXLINE( 161)										bool _hx_tmp;
HXDLIN( 161)										if (::hx::IsNotNull( ::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i) )) {
HXLINE( 161)											_hx_tmp = (::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).indexOf(HX_(",",2c,00,00,00),null()) != -1);
            										}
            										else {
HXLINE( 161)											_hx_tmp = false;
            										}
HXDLIN( 161)										if (_hx_tmp) {
HXLINE( 163)											args->push(::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).split(HX_(",",2c,00,00,00)));
            										}
            										else {
HXLINE( 164)											bool _hx_tmp;
HXDLIN( 164)											if (::hx::IsNotNull( ::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i) )) {
HXLINE( 164)												_hx_tmp = (::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(i).indexOf(HX_(",",2c,00,00,00),null()) == -1);
            											}
            											else {
HXLINE( 164)												_hx_tmp = false;
            											}
HXDLIN( 164)											if (_hx_tmp) {
HXLINE( 166)												args->push(::Array_obj< ::String >::__new(1)->init(0,::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0)));
            											}
            										}
            									}
            								}
HXLINE( 169)								if (::hx::IsNotNull( args )) {
HXLINE( 170)									currentToken = ::blue::BToken_obj::New(::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0),args);
            								}
            								else {
HXLINE( 172)									currentToken = ::blue::BToken_obj::New(::blue::BLexer_obj::current.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0),null());
            								}
HXLINE( 174)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 158)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("otherwise",f4,83,f2,9a)) ){
HXLINE( 195)								currentToken = ::blue::BToken_obj::Else_dyn();
HXLINE( 196)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 194)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("print",2d,58,8b,c8)) ){
HXLINE( 133)								if ((::blue::BLexer_obj::current.indexOf(HX_("print(",5b,cf,61,b1),null()) != -1)) {
HXLINE( 134)									currentToken = ::blue::BToken_obj::Print(::blue::BLexer_obj::current.split(HX_("print(",5b,cf,61,b1))->__get(1).split(HX_(")",29,00,00,00))->__get(0));
HXLINE( 135)									::blue::BLexer_obj::tokensToParse->push(currentToken);
            								}
HXLINE( 133)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("return",b0,a4,2d,09)) ){
HXLINE( 147)								currentToken = ::blue::BToken_obj::Return(::StringTools_obj::replace(::StringTools_obj::replace(::blue::BLexer_obj::current.split(HX_("return ",70,75,c2,fe))->__get(1).split(HX_("\n",0a,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)),HX_("\r",0d,00,00,00),HX_(";",3b,00,00,00)));
HXLINE( 148)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 146)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("throw",26,5d,90,0f)) ){
HXLINE( 155)								currentToken = ::blue::BToken_obj::Throw(::blue::BLexer_obj::current.split(HX_("throw(",42,24,c1,8e))->__get(1).split(HX_(")",29,00,00,00))->__get(0));
HXLINE( 156)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 154)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("try",3b,69,58,00)) ){
HXLINE( 139)								currentToken = ::blue::BToken_obj::Try_dyn();
HXLINE( 140)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 138)								goto _hx_goto_3;
            							}
            							if (  (_hx_switch_0==HX_("use",47,2c,59,00)) ){
HXLINE( 129)								currentToken = ::blue::BToken_obj::Use(::blue::BLexer_obj::current.split(HX_("use ",f9,91,ad,4d))->__get(1).split(HX_("\n",0a,00,00,00))->__get(0));
HXLINE( 130)								::blue::BLexer_obj::tokensToParse->push(currentToken);
HXLINE( 128)								goto _hx_goto_3;
            							}
            							_hx_goto_3:;
            						}
            					}
            				}
            			}
            		}
HXLINE( 216)		if (::hx::IsNotNull( ::blue::BLexer_obj::tokensToParse )) {
HXLINE( 217)			int _g = 0;
HXDLIN( 217)			int _g1 = ::blue::BLexer_obj::tokensToParse->get_length();
HXDLIN( 217)			while((_g < _g1)){
HXLINE( 217)				_g = (_g + 1);
HXDLIN( 217)				int i = (_g - 1);
HXLINE( 218)				::blue::BLexer_obj::buildAST(::blue::BLexer_obj::tokensToParse->__get(i));
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BLexer_obj,enumContent,(void))

void BLexer_obj::buildAST( ::blue::BToken input){
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_224_buildAST)
HXDLIN( 224)		::blue::BParser_obj::parse(input);
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
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_35_boot)
HXDLIN(  35)		current = null();
            	}
{
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_36_boot)
HXDLIN(  36)		_hx_char = null();
            	}
{
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_41_boot)
HXDLIN(  41)		last = false;
            	}
{
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_45_boot)
HXDLIN(  45)		tokensToParse = ::cpp::VirtualArray_obj::__new(0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_46_boot)
HXDLIN(  46)		completeSyntax = ::Array_obj< ::String >::fromData( _hx_array_data_4fc6d5be_15,28);
            	}
}

} // end namespace blue
