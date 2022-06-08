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
HX_LOCAL_STACK_FRAME(_hx_pos_7651d1f60270261f_97_buildHaxeFile,"blue.BHaxeUtil","buildHaxeFile",0x98861778,"blue.BHaxeUtil.buildHaxeFile","blue/BHaxeUtil.hx",97,0x4a304729)
HX_LOCAL_STACK_FRAME(_hx_pos_7651d1f60270261f_12_boot,"blue.BHaxeUtil","boot",0xd335c8ca,"blue.BHaxeUtil.boot","blue/BHaxeUtil.hx",12,0x4a304729)
HX_LOCAL_STACK_FRAME(_hx_pos_7651d1f60270261f_13_boot,"blue.BHaxeUtil","boot",0xd335c8ca,"blue.BHaxeUtil.boot","blue/BHaxeUtil.hx",13,0x4a304729)
HX_LOCAL_STACK_FRAME(_hx_pos_7651d1f60270261f_14_boot,"blue.BHaxeUtil","boot",0xd335c8ca,"blue.BHaxeUtil.boot","blue/BHaxeUtil.hx",14,0x4a304729)
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

::cpp::VirtualArray BHaxeUtil_obj::haxeData;

::cpp::VirtualArray BHaxeUtil_obj::specificValues;

::cpp::VirtualArray BHaxeUtil_obj::oldValues;

::String BHaxeUtil_obj::fileName;

void BHaxeUtil_obj::toHaxe( ::Dynamic AST){
            	HX_GC_STACKFRAME(&_hx_pos_7651d1f60270261f_18_toHaxe)
HXLINE(  19)		::blue::BHaxeUtil_obj::haxeData->set(2,(HX_("class ",e8,b8,10,05) + ::StringTools_obj::replace(::blue::BHaxeUtil_obj::fileName,HX_(".bl",78,3d,23,00),HX_("",00,00,00,00))));
HXLINE(  20)		 ::Dynamic parsedAST =  ::haxe::format::JsonParser_obj::__alloc( HX_CTX ,( (::String)(AST) ))->doParse();
HXLINE(  21)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Variable",5c,ce,be,42) )) {
HXLINE(  22)			::cpp::VirtualArray _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN(  22)			::String _hx_tmp1 = (((HX_("public static var",8c,c4,3c,2e) + HX_(" ",20,00,00,00)) + ::StringTools_obj::replace(::StringTools_obj::replace(::Std_obj::string( ::Dynamic(parsedAST->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic))),HX_("|",7c,00,00,00),HX_(":",3a,00,00,00)),HX_("\n",0a,00,00,00),HX_("",00,00,00,00))) + HX_(":Any = ",d1,79,36,0f));
HXDLIN(  22)			_hx_tmp->push(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(( (::String)((_hx_tmp1 + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic))) ),HX_("/",2f,00,00,00),HX_(".",2e,00,00,00)),HX_("div",51,3d,4c,00),HX_("/",2f,00,00,00)),HX_("mult",f0,67,65,48),HX_("*",2a,00,00,00)));
            		}
HXLINE(  29)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Method",01,6b,ef,3d) )) {
HXLINE(  30)			if (::hx::IsNull(  ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0) )) {
HXLINE(  31)				::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((HX_("public static function ",6d,39,f5,f7) + parsedAST->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) + HX_("():Any {",6e,e1,a1,7f))));
            			}
            			else {
HXLINE(  33)				::cpp::VirtualArray _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN(  33)				::String _hx_tmp1 = ( (::String)(((HX_("public static function ",6d,39,f5,f7) + parsedAST->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) + HX_("(",28,00,00,00))) );
HXDLIN(  33)				_hx_tmp->push(((_hx_tmp1 + ( ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0)->__Field(HX_("join",ea,33,65,46),::hx::paccDynamic)(HX_(":Dynamic, ",19,ec,0d,51)) + HX_(":Dynamic",65,a2,d4,f8))) + HX_("):Any {\n",b4,f6,4a,38)));
            			}
            		}
HXLINE(  36)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("End",bb,bb,34,00) )) {
HXLINE(  37)			::blue::BHaxeUtil_obj::haxeData->push(HX_("}",7d,00,00,00));
            		}
HXLINE(  39)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Try",1b,21,40,00) )) {
HXLINE(  40)			::blue::BHaxeUtil_obj::haxeData->push(HX_("try {",56,8a,31,16));
            		}
HXLINE(  42)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Catch",1b,ec,4e,d4) )) {
HXLINE(  43)			::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((HX_("catch(",8d,37,2b,bc) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_(") {",c4,38,1f,00))));
            		}
HXLINE(  45)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Continue",87,9c,7a,0b) )) {
HXLINE(  46)			::blue::BHaxeUtil_obj::haxeData->push(HX_("continue;",f4,79,fb,5d));
            		}
HXLINE(  48)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Stop",22,1c,35,37) )) {
HXLINE(  49)			::blue::BHaxeUtil_obj::haxeData->push(HX_("break;",9c,02,b4,15));
            		}
HXLINE(  51)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("If",fd,3f,00,00) )) {
HXLINE(  52)			::cpp::VirtualArray _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN(  52)			_hx_tmp->push(((HX_("if (",25,e9,b4,45) + ::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::StringTools_obj::replace(::Std_obj::string( ::Dynamic(parsedAST->__Field(HX_("condition",9b,e9,33,fc),::hx::paccDynamic))),HX_("not ",ad,17,0a,49),HX_("!",21,00,00,00)),HX_("=",3d,00,00,00),HX_("==",60,35,00,00)),HX_("!==",c1,3f,19,00),HX_("!=",fc,1c,00,00)),HX_("greater than",47,34,3c,43),HX_(">",3e,00,00,00)),HX_("less than",88,b9,bc,f1),HX_("<",3c,00,00,00)),HX_("or",23,61,00,00),HX_("||",80,6c,00,00))) + HX_(") {",c4,38,1f,00)));
            		}
HXLINE(  54)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("For",e9,7e,35,00) )) {
HXLINE(  55)			::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((((((HX_("for (",51,77,94,04) + parsedAST->__Field(HX_("iterator",ee,49,9a,93),::hx::paccDynamic)) + HX_(" in ",7b,e0,76,15)) + parsedAST->__Field(HX_("numberOne",1d,6f,75,1e),::hx::paccDynamic)) + HX_("...",ee,0f,23,00)) + parsedAST->__Field(HX_("numberTwo",43,42,79,1e),::hx::paccDynamic)) + HX_(") {",c4,38,1f,00))));
            		}
HXLINE(  57)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Print",0d,c8,b8,5b) )) {
HXLINE(  58)			::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((HX_("trace(",03,26,7d,45) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_(");",f2,23,00,00))));
            		}
HXLINE(  60)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Return",d0,18,c2,3d) )) {
HXLINE(  61)			::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic((HX_("return ",70,75,c2,fe) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic))));
            		}
HXLINE(  63)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Comment",3f,a2,c1,4e) )) {
HXLINE(  64)			::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic((HX_("// ",00,d3,23,00) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic))));
            		}
HXLINE(  66)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Main",59,64,2f,33) )) {
HXLINE(  67)			::blue::BHaxeUtil_obj::haxeData->push(HX_("public static function main() {",c2,f8,58,8e));
            		}
HXLINE(  69)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("New",40,88,3b,00) )) {
HXLINE(  70)			if (::hx::IsNull(  ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0) )) {
HXLINE(  71)				::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((HX_("new ",c0,83,02,49) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_("();",1a,7e,1e,00))));
            			}
            			else {
HXLINE(  73)				::cpp::VirtualArray _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN(  73)				::String _hx_tmp1 = ( (::String)(((HX_("new ",c0,83,02,49) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_("(",28,00,00,00))) );
HXDLIN(  73)				_hx_tmp->push(((_hx_tmp1 + ( ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0)->__Field(HX_("join",ea,33,65,46),::hx::paccDynamic)(HX_(":Dynamic, ",19,ec,0d,51)) + HX_(":Dynamic",65,a2,d4,f8))) + HX_(");",f2,23,00,00)));
            			}
            		}
HXLINE(  76)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Constructor",da,c4,f7,7b) )) {
HXLINE(  77)			if (::hx::IsNull(  ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0) )) {
HXLINE(  78)				::blue::BHaxeUtil_obj::haxeData->push(HX_("public function new() {",4b,7a,78,d5));
            			}
            			else {
HXLINE(  80)				::cpp::VirtualArray _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN(  80)				_hx_tmp->push(((HX_("public function new(",19,94,61,61) + ( ::Dynamic(parsedAST->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic))->__GetItem(0)->__Field(HX_("join",ea,33,65,46),::hx::paccDynamic)(HX_(":Dynamic, ",19,ec,0d,51)) + HX_(":Dynamic",65,a2,d4,f8))) + HX_(") {",c4,38,1f,00)));
            			}
            		}
HXLINE(  83)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Else",d9,10,ee,2d) )) {
HXLINE(  84)			::blue::BHaxeUtil_obj::haxeData->push(HX_("else {",54,61,a2,dd));
            		}
HXLINE(  86)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("ArrayIndex",d9,b6,f2,ae) )) {
HXLINE(  87)			::cpp::VirtualArray _hx_tmp = ::blue::BHaxeUtil_obj::haxeData;
HXDLIN(  87)			_hx_tmp->push(((HX_("[",5b,00,00,00) + (::Std_obj::parseFloat(( (::String)(parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) )) - ( (Float)(1) ))) + HX_("]",5d,00,00,00)));
            		}
HXLINE(  89)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("Property",75,04,ea,85) )) {
HXLINE(  90)			::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic((((HX_("",00,00,00,00) + parsedAST->__Field(HX_("a",61,00,00,00),::hx::paccDynamic)) + HX_(".",2e,00,00,00)) + parsedAST->__Field(HX_("b",62,00,00,00),::hx::paccDynamic))));
            		}
HXLINE(  92)		if (::hx::IsEq( parsedAST->__Field(HX_("label",f4,0d,af,6f),::hx::paccDynamic),HX_("FunctionCall",f6,a7,c7,f0) )) {
HXLINE(  93)			::blue::BHaxeUtil_obj::haxeData->push( ::Dynamic(((HX_("",00,00,00,00) + parsedAST->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_(");",f2,23,00,00))));
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BHaxeUtil_obj,toHaxe,(void))

void BHaxeUtil_obj::buildHaxeFile(){
            	HX_STACKFRAME(&_hx_pos_7651d1f60270261f_97_buildHaxeFile)
HXLINE(  98)		if (!(::sys::FileSystem_obj::exists(HX_("export",74,91,7d,c4)))) {
HXLINE(  99)			::sys::FileSystem_obj::createDirectory(HX_("export",74,91,7d,c4));
HXLINE( 100)			::sys::FileSystem_obj::createDirectory(HX_("export/hxsrc",b9,ab,55,3c));
            		}
HXLINE( 102)		::sys::io::File_obj::write((HX_("export/hxsrc/",56,96,a0,8e) + ::StringTools_obj::replace(::blue::BHaxeUtil_obj::fileName,HX_(".bl",78,3d,23,00),HX_(".hx",be,42,23,00))),false);
HXLINE( 103)		::String _hx_tmp = (HX_("export/hxsrc/",56,96,a0,8e) + ::StringTools_obj::replace(::blue::BHaxeUtil_obj::fileName,HX_(".bl",78,3d,23,00),HX_(".hx",be,42,23,00)));
HXDLIN( 103)		::sys::io::File_obj::saveContent(_hx_tmp,(::blue::BHaxeUtil_obj::haxeData->join(HX_("\n",0a,00,00,00)) + HX_("\n}",33,09,00,00)));
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
		if (HX_FIELD_EQ(inName,"haxeData") ) { haxeData=ioValue.Cast< ::cpp::VirtualArray >(); return true; }
		if (HX_FIELD_EQ(inName,"fileName") ) { fileName=ioValue.Cast< ::String >(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"oldValues") ) { oldValues=ioValue.Cast< ::cpp::VirtualArray >(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"specificValues") ) { specificValues=ioValue.Cast< ::cpp::VirtualArray >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *BHaxeUtil_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo BHaxeUtil_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /* ::cpp::VirtualArray */ ,(void *) &BHaxeUtil_obj::haxeData,HX_("haxeData",70,c1,a8,4d)},
	{::hx::fsObject /* ::cpp::VirtualArray */ ,(void *) &BHaxeUtil_obj::specificValues,HX_("specificValues",34,4a,21,b8)},
	{::hx::fsObject /* ::cpp::VirtualArray */ ,(void *) &BHaxeUtil_obj::oldValues,HX_("oldValues",e9,87,a2,5a)},
	{::hx::fsString,(void *) &BHaxeUtil_obj::fileName,HX_("fileName",e7,5a,43,62)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void BHaxeUtil_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BHaxeUtil_obj::haxeData,"haxeData");
	HX_MARK_MEMBER_NAME(BHaxeUtil_obj::specificValues,"specificValues");
	HX_MARK_MEMBER_NAME(BHaxeUtil_obj::oldValues,"oldValues");
	HX_MARK_MEMBER_NAME(BHaxeUtil_obj::fileName,"fileName");
};

#ifdef HXCPP_VISIT_ALLOCS
static void BHaxeUtil_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BHaxeUtil_obj::haxeData,"haxeData");
	HX_VISIT_MEMBER_NAME(BHaxeUtil_obj::specificValues,"specificValues");
	HX_VISIT_MEMBER_NAME(BHaxeUtil_obj::oldValues,"oldValues");
	HX_VISIT_MEMBER_NAME(BHaxeUtil_obj::fileName,"fileName");
};

#endif

::hx::Class BHaxeUtil_obj::__mClass;

static ::String BHaxeUtil_obj_sStaticFields[] = {
	HX_("haxeData",70,c1,a8,4d),
	HX_("specificValues",34,4a,21,b8),
	HX_("oldValues",e9,87,a2,5a),
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
HXDLIN(  12)		haxeData = ::cpp::VirtualArray_obj::__new(4)->init(0,HX_("package export.hxsrc;",87,95,b1,6f))->init(1,HX_("using StringTools;",ed,61,db,f1))->init(2,HX_("class",38,78,58,48))->init(3,HX_("{",7b,00,00,00));
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
            	HX_STACKFRAME(&_hx_pos_7651d1f60270261f_16_boot)
HXDLIN(  16)		fileName = null();
            	}
}

} // end namespace blue
