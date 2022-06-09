#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_blue_BHaxeUtil
#include <blue/BHaxeUtil.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_7651d1f60270261f_18_toHaxe,"blue.BHaxeUtil","toHaxe",0x7b6839d9,"blue.BHaxeUtil.toHaxe","blue/BHaxeUtil.hx",18,0x4a304729)
HX_LOCAL_STACK_FRAME(_hx_pos_7651d1f60270261f_113_buildHaxeFile,"blue.BHaxeUtil","buildHaxeFile",0x98861778,"blue.BHaxeUtil.buildHaxeFile","blue/BHaxeUtil.hx",113,0x4a304729)
HX_LOCAL_STACK_FRAME(_hx_pos_7651d1f60270261f_12_boot,"blue.BHaxeUtil","boot",0xd335c8ca,"blue.BHaxeUtil.boot","blue/BHaxeUtil.hx",12,0x4a304729)
static const ::String _hx_array_data_fa1062d6_4[] = {
	HX_("package export.hxsrc;",87,95,b1,6f),HX_("using StringTools;",ed,61,db,f1),HX_("class",38,78,58,48),HX_("{",7b,00,00,00),
};
HX_LOCAL_STACK_FRAME(_hx_pos_7651d1f60270261f_13_boot,"blue.BHaxeUtil","boot",0xd335c8ca,"blue.BHaxeUtil.boot","blue/BHaxeUtil.hx",13,0x4a304729)
HX_LOCAL_STACK_FRAME(_hx_pos_7651d1f60270261f_14_boot,"blue.BHaxeUtil","boot",0xd335c8ca,"blue.BHaxeUtil.boot","blue/BHaxeUtil.hx",14,0x4a304729)
HX_LOCAL_STACK_FRAME(_hx_pos_7651d1f60270261f_15_boot,"blue.BHaxeUtil","boot",0xd335c8ca,"blue.BHaxeUtil.boot","blue/BHaxeUtil.hx",15,0x4a304729)
HX_LOCAL_STACK_FRAME(_hx_pos_7651d1f60270261f_16_boot,"blue.BHaxeUtil","boot",0xd335c8ca,"blue.BHaxeUtil.boot","blue/BHaxeUtil.hx",16,0x4a304729)
namespace blue{

void BHaxeUtil_obj::__construct() { }

Dynamic BHaxeUtil_obj::__CreateEmpty() { return new BHaxeUtil_obj; }

void *BHaxeUtil_obj::_hx_vtable = 0;

Dynamic BHaxeUtil_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< BHaxeUtil_obj > _hx_result = new BHaxeUtil_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool BHaxeUtil_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x1f3edbd0;
}

::Array< ::String > BHaxeUtil_obj::haxeData;

::cpp::VirtualArray BHaxeUtil_obj::specificValues;

::cpp::VirtualArray BHaxeUtil_obj::oldValues;

 ::Dynamic BHaxeUtil_obj::extension;

::String BHaxeUtil_obj::fileName;

void BHaxeUtil_obj::toHaxe( ::Dynamic AST){
            	HX_GC_STACKFRAME(&_hx_pos_7651d1f60270261f_18_toHaxe)
HXLINE(  19)		::blue::BHaxeUtil_obj::haxeData[2] = (HX_("class ",e8,b8,10,05) + ::StringTools_obj::replace(::blue::BHaxeUtil_obj::fileName,HX_(".bl",78,3d,23,00),HX_("",00,00,00,00)));
HXLINE(  20)		if (::hx::IsNotNull( ::blue::BHaxeUtil_obj::extension )) {
HXLINE(  21)			::String _hx_tmp = (::blue::BHaxeUtil_obj::haxeData->__get(2) + HX_(" extends ",c7,00,04,3f));
HXDLIN(  21)			::blue::BHaxeUtil_obj::haxeData[2] = (_hx_tmp + ::Std_obj::string(::blue::BHaxeUtil_obj::extension));
            		}
HXLINE(  23)		 ::Dynamic parsedAST =  ::haxe::format::JsonParser_obj::__alloc( HX_CTX ,( (::String)(AST) ))->doParse();
HXLINE(  24)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Variable",5c,ce,be,42) )) {
HXLINE(  25)			::Array< ::String > _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN(  25)			::String _hx_tmp1 = (((HX_("public static var",8c,c4,3c,2e) + HX_(" ",20,00,00,00)) + ::StringTools_obj::replace(::StringTools_obj::replace(::Std_obj::string( ::Dynamic(parsedAST->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic))),HX_("|",7c,00,00,00),HX_(":",3a,00,00,00)),HX_("\n",0a,00,00,00),HX_("",00,00,00,00))) + HX_(":Dynamic = ",1e,a8,17,9b));
HXDLIN(  25)			_hx_tmp->push(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(( (::String)((_hx_tmp1 + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic))) ),HX_("/",2f,00,00,00),HX_(".",2e,00,00,00)),HX_("div",51,3d,4c,00),HX_("/",2f,00,00,00)),HX_("mult",f0,67,65,48),HX_("*",2a,00,00,00)));
            		}
HXLINE(  32)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Method",01,6b,ef,3d) )) {
HXLINE(  33)			if (::hx::IsNull(  ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0) )) {
HXLINE(  34)				::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((HX_("public static function ",6d,39,f5,f7) + parsedAST->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) + HX_("():Dynamic {",41,30,96,3a))));
            			}
            			else {
HXLINE(  36)				::Array< ::String > _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN(  36)				::String _hx_tmp1 = ( (::String)(((HX_("public static function ",6d,39,f5,f7) + parsedAST->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) + HX_("(",28,00,00,00))) );
HXDLIN(  36)				_hx_tmp->push(::StringTools_obj::replace(((_hx_tmp1 + ( ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0)->__Field(HX_("join",ea,33,65,46),::hx::paccDynamic)(HX_(":Dynamic, ",19,ec,0d,51)) + HX_(":Dynamic",65,a2,d4,f8))) + HX_("):Dynamic {\n",81,6c,c0,22)),HX_("(:Dynamic)",fc,30,dc,cc),HX_("()",01,23,00,00)));
            			}
            		}
HXLINE(  39)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("End",bb,bb,34,00) )) {
HXLINE(  40)			::blue::BHaxeUtil_obj::haxeData->push(HX_("}",7d,00,00,00));
            		}
HXLINE(  42)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Try",1b,21,40,00) )) {
HXLINE(  43)			::blue::BHaxeUtil_obj::haxeData->push(HX_("try {",56,8a,31,16));
            		}
HXLINE(  45)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Catch",1b,ec,4e,d4) )) {
HXLINE(  46)			::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((HX_("catch(",8d,37,2b,bc) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_(") {",c4,38,1f,00))));
            		}
HXLINE(  48)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Continue",87,9c,7a,0b) )) {
HXLINE(  49)			::blue::BHaxeUtil_obj::haxeData->push(HX_("continue;",f4,79,fb,5d));
            		}
HXLINE(  51)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Stop",22,1c,35,37) )) {
HXLINE(  52)			::blue::BHaxeUtil_obj::haxeData->push(HX_("break;",9c,02,b4,15));
            		}
HXLINE(  54)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("If",fd,3f,00,00) )) {
HXLINE(  55)			::Array< ::String > _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN(  55)			_hx_tmp->push(((HX_("if (",25,e9,b4,45) + ::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::Std_obj::string( ::Dynamic(parsedAST->__Field(HX_("condition",9b,e9,33,fc),::hx::paccDynamic))),HX_("not ",ad,17,0a,49),HX_("!",21,00,00,00)),HX_("=",3d,00,00,00),HX_("==",60,35,00,00)),HX_("!==",c1,3f,19,00),HX_("!=",fc,1c,00,00)),HX_("greater than",47,34,3c,43),HX_(">",3e,00,00,00)),HX_("less than",88,b9,bc,f1),HX_("<",3c,00,00,00)),HX_("or",23,61,00,00),HX_("||",80,6c,00,00))) + HX_(") {",c4,38,1f,00)));
            		}
HXLINE(  57)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("For",e9,7e,35,00) )) {
HXLINE(  58)			::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((((((HX_("for (",51,77,94,04) + parsedAST->__Field(HX_("iterator",ee,49,9a,93),::hx::paccDynamic)) + HX_(" in ",7b,e0,76,15)) + parsedAST->__Field(HX_("numberOne",1d,6f,75,1e),::hx::paccDynamic)) + HX_("...",ee,0f,23,00)) + parsedAST->__Field(HX_("numberTwo",43,42,79,1e),::hx::paccDynamic)) + HX_(") {",c4,38,1f,00))));
            		}
HXLINE(  60)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Print",0d,c8,b8,5b) )) {
HXLINE(  61)			::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((HX_("trace(",03,26,7d,45) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_(");",f2,23,00,00))));
            		}
HXLINE(  63)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Return",d0,18,c2,3d) )) {
HXLINE(  64)			::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic((HX_("return ",70,75,c2,fe) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic))));
            		}
HXLINE(  66)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Comment",3f,a2,c1,4e) )) {
HXLINE(  67)			::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic((HX_("// ",00,d3,23,00) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic))));
            		}
HXLINE(  69)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Main",59,64,2f,33) )) {
HXLINE(  70)			::blue::BHaxeUtil_obj::haxeData->push(HX_("public static function main() {",c2,f8,58,8e));
            		}
HXLINE(  72)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("New",40,88,3b,00) )) {
HXLINE(  73)			if (::hx::IsNull(  ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0) )) {
HXLINE(  74)				::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((HX_("new ",c0,83,02,49) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_("();",1a,7e,1e,00))));
            			}
            			else {
HXLINE(  76)				::Array< ::String > _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN(  76)				::String _hx_tmp1 = ( (::String)(((HX_("new ",c0,83,02,49) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_("(",28,00,00,00))) );
HXDLIN(  76)				_hx_tmp->push(::StringTools_obj::replace(((_hx_tmp1 +  ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0)->__Field(HX_("join",ea,33,65,46),::hx::paccDynamic)(HX_(", ",74,26,00,00))) + HX_(");",f2,23,00,00)),HX_("(:Dynamic)",fc,30,dc,cc),HX_("()",01,23,00,00)));
            			}
            		}
HXLINE(  79)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Constructor",da,c4,f7,7b) )) {
HXLINE(  80)			if (::hx::IsNull(  ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0) )) {
HXLINE(  81)				::blue::BHaxeUtil_obj::haxeData->push(HX_("public function new() {",4b,7a,78,d5));
            			}
            			else {
HXLINE(  83)				::Array< ::String > _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN(  83)				_hx_tmp->push(::StringTools_obj::replace(((HX_("public function new(",19,94,61,61) + ( ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0)->__Field(HX_("join",ea,33,65,46),::hx::paccDynamic)(HX_(":Dynamic, ",19,ec,0d,51)) + HX_(":Dynamic",65,a2,d4,f8))) + HX_(") {",c4,38,1f,00)),HX_("(:Dynamic)",fc,30,dc,cc),HX_("()",01,23,00,00)));
            			}
            		}
HXLINE(  86)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Else",d9,10,ee,2d) )) {
HXLINE(  87)			::blue::BHaxeUtil_obj::haxeData->push(HX_("else {",54,61,a2,dd));
            		}
HXLINE(  89)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("FunctionCall",f6,a7,c7,f0) )) {
HXLINE(  90)			if ((( (::String)(parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) ).indexOf(HX_("new ",c0,83,02,49),null()) == -1)) {
HXLINE(  91)				::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((HX_("",00,00,00,00) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_(");",f2,23,00,00))));
            			}
            			else {
HXLINE(  94)				::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((HX_("",00,00,00,00) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_("));",5b,40,1f,00))));
            			}
            		}
HXLINE(  98)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Super",5b,71,ed,17) )) {
HXLINE(  99)			if (::hx::IsNull(  ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0) )) {
HXLINE( 100)				::blue::BHaxeUtil_obj::haxeData->push(HX_("super();",7f,5b,e2,ed));
            			}
            			else {
HXLINE( 102)				::Array< ::String > _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN( 102)				_hx_tmp->push(::StringTools_obj::replace(((HX_("super(",4d,4a,41,a3) +  ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0)->__Field(HX_("join",ea,33,65,46),::hx::paccDynamic)(HX_(", ",74,26,00,00))) + HX_(");",f2,23,00,00)),HX_("(:Dynamic)",fc,30,dc,cc),HX_("()",01,23,00,00)));
            			}
            		}
HXLINE( 106)		{
HXLINE( 106)			int _g = 0;
HXDLIN( 106)			int _g1 = ::blue::BHaxeUtil_obj::haxeData->length;
HXDLIN( 106)			while((_g < _g1)){
HXLINE( 106)				_g = (_g + 1);
HXDLIN( 106)				int i = (_g - 1);
HXLINE( 107)				bool _hx_tmp;
HXDLIN( 107)				bool _hx_tmp1;
HXDLIN( 107)				if ((::blue::BHaxeUtil_obj::haxeData->__get(i).indexOf(HX_("[",5b,00,00,00),null()) != -1)) {
HXLINE( 107)					_hx_tmp1 = (::blue::BHaxeUtil_obj::haxeData->__get(i).indexOf(HX_("]",5d,00,00,00),null()) != -1);
            				}
            				else {
HXLINE( 107)					_hx_tmp1 = false;
            				}
HXDLIN( 107)				if (_hx_tmp1) {
HXLINE( 107)					_hx_tmp = (::blue::BHaxeUtil_obj::haxeData->__get(i).indexOf(HX_(",",2c,00,00,00),null()) == -1);
            				}
            				else {
HXLINE( 107)					_hx_tmp = false;
            				}
HXDLIN( 107)				if (_hx_tmp) {
HXLINE( 108)					::Array< ::String > _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN( 108)					::String _hx_tmp1 = ::blue::BHaxeUtil_obj::haxeData->__get(i);
HXDLIN( 108)					::String _hx_tmp2 = ::blue::BHaxeUtil_obj::haxeData->__get(i).split(HX_("[",5b,00,00,00))->__get(1).split(HX_("]",5d,00,00,00))->__get(0);
HXDLIN( 108)					_hx_tmp[i] = ::StringTools_obj::replace(_hx_tmp1,_hx_tmp2,::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::blue::BHaxeUtil_obj::haxeData->__get(i).split(HX_("[",5b,00,00,00))->__get(1).split(HX_("]",5d,00,00,00))->__get(0),HX_("1",31,00,00,00),HX_("0",30,00,00,00)),HX_("2",32,00,00,00),HX_("1",31,00,00,00)),HX_("3",33,00,00,00),HX_("2",32,00,00,00)),HX_("4",34,00,00,00),HX_("3",33,00,00,00)),HX_("5",35,00,00,00),HX_("4",34,00,00,00)),HX_("6",36,00,00,00),HX_("5",35,00,00,00)),HX_("7",37,00,00,00),HX_("6",36,00,00,00)),HX_("8",38,00,00,00),HX_("7",37,00,00,00)),HX_("9",39,00,00,00),HX_("8",38,00,00,00)));
            				}
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BHaxeUtil_obj,toHaxe,(void))

void BHaxeUtil_obj::buildHaxeFile(){
            	HX_STACKFRAME(&_hx_pos_7651d1f60270261f_113_buildHaxeFile)
HXLINE( 114)		if (!(::sys::FileSystem_obj::exists(HX_("export",74,91,7d,c4)))) {
HXLINE( 115)			::sys::FileSystem_obj::createDirectory(HX_("export",74,91,7d,c4));
HXLINE( 116)			::sys::FileSystem_obj::createDirectory(HX_("export/hxsrc",b9,ab,55,3c));
            		}
HXLINE( 118)		::sys::io::File_obj::write((HX_("export/hxsrc/",56,96,a0,8e) + ::StringTools_obj::replace(::blue::BHaxeUtil_obj::fileName,HX_(".bl",78,3d,23,00),HX_(".hx",be,42,23,00))),false);
HXLINE( 119)		::String _hx_tmp = (HX_("export/hxsrc/",56,96,a0,8e) + ::StringTools_obj::replace(::blue::BHaxeUtil_obj::fileName,HX_(".bl",78,3d,23,00),HX_(".hx",be,42,23,00)));
HXDLIN( 119)		::sys::io::File_obj::saveContent(_hx_tmp,(::StringTools_obj::replace(::StringTools_obj::replace(::blue::BHaxeUtil_obj::haxeData->join(HX_("\n",0a,00,00,00)),HX_("/",2f,00,00,00),HX_(".",2e,00,00,00)),HX_("{\n}",6e,5e,5d,00),HX_("{",7b,00,00,00)) + HX_("\n}",33,09,00,00)));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(BHaxeUtil_obj,buildHaxeFile,(void))


BHaxeUtil_obj::BHaxeUtil_obj()
{
}

bool BHaxeUtil_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"toHaxe") ) { outValue = toHaxe_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"haxeData") ) { outValue = ( haxeData ); return true; }
		if (HX_FIELD_EQ(inName,"fileName") ) { outValue = ( fileName ); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"oldValues") ) { outValue = ( oldValues ); return true; }
		if (HX_FIELD_EQ(inName,"extension") ) { outValue = ( extension ); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"buildHaxeFile") ) { outValue = buildHaxeFile_dyn(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"specificValues") ) { outValue = ( specificValues ); return true; }
	}
	return false;
}

bool BHaxeUtil_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"haxeData") ) { haxeData=ioValue.Cast< ::Array< ::String > >(); return true; }
		if (HX_FIELD_EQ(inName,"fileName") ) { fileName=ioValue.Cast< ::String >(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"oldValues") ) { oldValues=ioValue.Cast< ::cpp::VirtualArray >(); return true; }
		if (HX_FIELD_EQ(inName,"extension") ) { extension=ioValue.Cast<  ::Dynamic >(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"specificValues") ) { specificValues=ioValue.Cast< ::cpp::VirtualArray >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *BHaxeUtil_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo BHaxeUtil_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &BHaxeUtil_obj::haxeData,HX_("haxeData",70,c1,a8,4d)},
	{::hx::fsObject /* ::cpp::VirtualArray */ ,(void *) &BHaxeUtil_obj::specificValues,HX_("specificValues",34,4a,21,b8)},
	{::hx::fsObject /* ::cpp::VirtualArray */ ,(void *) &BHaxeUtil_obj::oldValues,HX_("oldValues",e9,87,a2,5a)},
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &BHaxeUtil_obj::extension,HX_("extension",7f,93,10,e5)},
	{::hx::fsString,(void *) &BHaxeUtil_obj::fileName,HX_("fileName",e7,5a,43,62)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void BHaxeUtil_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BHaxeUtil_obj::haxeData,"haxeData");
	HX_MARK_MEMBER_NAME(BHaxeUtil_obj::specificValues,"specificValues");
	HX_MARK_MEMBER_NAME(BHaxeUtil_obj::oldValues,"oldValues");
	HX_MARK_MEMBER_NAME(BHaxeUtil_obj::extension,"extension");
	HX_MARK_MEMBER_NAME(BHaxeUtil_obj::fileName,"fileName");
};

#ifdef HXCPP_VISIT_ALLOCS
static void BHaxeUtil_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BHaxeUtil_obj::haxeData,"haxeData");
	HX_VISIT_MEMBER_NAME(BHaxeUtil_obj::specificValues,"specificValues");
	HX_VISIT_MEMBER_NAME(BHaxeUtil_obj::oldValues,"oldValues");
	HX_VISIT_MEMBER_NAME(BHaxeUtil_obj::extension,"extension");
	HX_VISIT_MEMBER_NAME(BHaxeUtil_obj::fileName,"fileName");
};

#endif

::hx::Class BHaxeUtil_obj::__mClass;

static ::String BHaxeUtil_obj_sStaticFields[] = {
	HX_("haxeData",70,c1,a8,4d),
	HX_("specificValues",34,4a,21,b8),
	HX_("oldValues",e9,87,a2,5a),
	HX_("extension",7f,93,10,e5),
	HX_("fileName",e7,5a,43,62),
	HX_("toHaxe",41,9f,c1,7a),
	HX_("buildHaxeFile",10,af,d1,49),
	::String(null())
};

void BHaxeUtil_obj::__register()
{
	BHaxeUtil_obj _hx_dummy;
	BHaxeUtil_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("blue.BHaxeUtil",d6,62,10,fa);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &BHaxeUtil_obj::__GetStatic;
	__mClass->mSetStaticField = &BHaxeUtil_obj::__SetStatic;
	__mClass->mMarkFunc = BHaxeUtil_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(BHaxeUtil_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< BHaxeUtil_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = BHaxeUtil_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = BHaxeUtil_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = BHaxeUtil_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void BHaxeUtil_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_7651d1f60270261f_12_boot)
HXDLIN(  12)		haxeData = ::Array_obj< ::String >::fromData( _hx_array_data_fa1062d6_4,4);
            	}
{
            	HX_STACKFRAME(&_hx_pos_7651d1f60270261f_13_boot)
HXDLIN(  13)		specificValues = ::cpp::VirtualArray_obj::__new(0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_7651d1f60270261f_14_boot)
HXDLIN(  14)		oldValues = ::cpp::VirtualArray_obj::__new(0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_7651d1f60270261f_15_boot)
HXDLIN(  15)		extension = null();
            	}
{
            	HX_STACKFRAME(&_hx_pos_7651d1f60270261f_16_boot)
HXDLIN(  16)		fileName = null();
            	}
}

} // end namespace blue
