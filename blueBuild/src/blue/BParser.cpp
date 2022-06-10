#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_blue_BHaxeUtil
#include <blue/BHaxeUtil.h>
#endif
#ifndef INCLUDED_blue_BParser
#include <blue/BParser.h>
#endif
#ifndef INCLUDED_blue_BToken
#include <blue/BToken.h>
#endif
#ifndef INCLUDED_haxe_format_JsonPrinter
#include <haxe/format/JsonPrinter.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_dfb761f66489164a_40_parse,"blue.BParser","parse",0x0b16b5f2,"blue.BParser.parse","blue/BParser.hx",40,0xc1182332)
namespace blue{

void BParser_obj::__construct() { }

Dynamic BParser_obj::__CreateEmpty() { return new BParser_obj; }

void *BParser_obj::_hx_vtable = 0;

Dynamic BParser_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< BParser_obj > _hx_result = new BParser_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool BParser_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x79571383;
}

 ::blue::BToken BParser_obj::token;

 ::Dynamic BParser_obj::iterator;

::String BParser_obj::numberOne;

::String BParser_obj::numberTwo;

 ::Dynamic BParser_obj::valueOne;

 ::Dynamic BParser_obj::valueTwo;

 ::Dynamic BParser_obj::condition;

::String BParser_obj::name;

::cpp::VirtualArray BParser_obj::args;

 ::Dynamic BParser_obj::value;

 ::Dynamic BParser_obj::a;

 ::Dynamic BParser_obj::b;

::cpp::VirtualArray BParser_obj::entries;

::String BParser_obj::label;

::String BParser_obj::stringValue;

void BParser_obj::parse( ::Dynamic input){
            	HX_STACKFRAME(&_hx_pos_dfb761f66489164a_40_parse)
HXLINE(  41)		::blue::BParser_obj::token = null();
HXLINE(  42)		::blue::BParser_obj::iterator = null();
HXLINE(  43)		::blue::BParser_obj::numberTwo = null();
HXLINE(  44)		::blue::BParser_obj::numberOne = null();
HXLINE(  45)		::blue::BParser_obj::valueOne = null();
HXLINE(  46)		::blue::BParser_obj::valueTwo = null();
HXLINE(  47)		::blue::BParser_obj::condition = null();
HXLINE(  48)		::blue::BParser_obj::name = null();
HXLINE(  49)		::blue::BParser_obj::args = null();
HXLINE(  50)		::blue::BParser_obj::value = null();
HXLINE(  51)		::blue::BParser_obj::a = null();
HXLINE(  52)		::blue::BParser_obj::b = null();
HXLINE(  53)		::blue::BParser_obj::entries = null();
HXLINE(  54)		::blue::BParser_obj::label = null();
HXLINE(  55)		::blue::BParser_obj::stringValue = null();
HXLINE(  56)		switch((int)(input.StaticCast< ::hx::EnumBase >()->_hx_getIndex())){
            			case (int)0: {
HXLINE(  62)				::String name = input.StaticCast< ::hx::EnumBase >()->_hx_getString(0);
HXDLIN(  62)				::cpp::VirtualArray args = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(1).StaticCast< ::cpp::VirtualArray >();
HXDLIN(  62)				{
HXLINE(  63)					::blue::BParser_obj::name = name;
HXLINE(  64)					::blue::BParser_obj::args = args;
HXLINE(  65)					::blue::BParser_obj::label = HX_("Method",01,6b,ef,3d);
            				}
            			}
            			break;
            			case (int)1: {
HXLINE( 114)				::blue::BParser_obj::label = HX_("Main",59,64,2f,33);
            			}
            			break;
            			case (int)2: {
HXLINE(  77)				::cpp::VirtualArray entries = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0).StaticCast< ::cpp::VirtualArray >();
HXDLIN(  77)				{
HXLINE(  78)					::blue::BParser_obj::entries = entries;
HXLINE(  79)					::blue::BParser_obj::label = HX_("Array",79,dd,bc,b8);
            				}
            			}
            			break;
            			case (int)3: {
HXLINE(  57)				::String name = input.StaticCast< ::hx::EnumBase >()->_hx_getString(0);
HXDLIN(  57)				 ::Dynamic value = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(1);
HXDLIN(  57)				{
HXLINE(  58)					::blue::BParser_obj::name = name;
HXLINE(  59)					::blue::BParser_obj::value = value;
HXLINE(  60)					::blue::BParser_obj::label = HX_("Variable",5c,ce,be,42);
            				}
            			}
            			break;
            			case (int)4: {
HXLINE(  71)				 ::Dynamic iterator = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN(  71)				::String numberOne = input.StaticCast< ::hx::EnumBase >()->_hx_getString(1);
HXDLIN(  71)				::String numberTwo = input.StaticCast< ::hx::EnumBase >()->_hx_getString(2);
HXDLIN(  71)				{
HXLINE(  72)					::blue::BParser_obj::iterator = iterator;
HXLINE(  73)					::blue::BParser_obj::numberOne = numberOne;
HXLINE(  74)					::blue::BParser_obj::numberTwo = numberTwo;
HXLINE(  75)					::blue::BParser_obj::label = HX_("For",e9,7e,35,00);
            				}
            			}
            			break;
            			case (int)5: {
HXLINE(  67)				 ::Dynamic condition = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN(  67)				{
HXLINE(  68)					::blue::BParser_obj::condition = condition;
HXLINE(  69)					::blue::BParser_obj::label = HX_("If",fd,3f,00,00);
            				}
            			}
            			break;
            			case (int)6: {
HXLINE(  94)				 ::Dynamic value = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN(  94)				{
HXLINE(  95)					::blue::BParser_obj::value = value;
HXLINE(  96)					::blue::BParser_obj::label = HX_("Use",27,e4,40,00);
            				}
            			}
            			break;
            			case (int)9: {
HXLINE(  86)				 ::Dynamic a = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN(  86)				 ::Dynamic b = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(1);
HXDLIN(  86)				{
HXLINE(  87)					::blue::BParser_obj::a = a;
HXLINE(  88)					::blue::BParser_obj::b = b;
HXLINE(  89)					::blue::BParser_obj::label = HX_("Mult",10,94,3e,33);
            				}
            			}
            			break;
            			case (int)10: {
HXLINE(  81)				 ::Dynamic a = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN(  81)				 ::Dynamic b = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(1);
HXDLIN(  81)				{
HXLINE(  82)					::blue::BParser_obj::a = a;
HXLINE(  83)					::blue::BParser_obj::b = b;
HXLINE(  84)					::blue::BParser_obj::label = HX_("Div",31,f5,33,00);
            				}
            			}
            			break;
            			case (int)11: {
HXLINE(  92)				::blue::BParser_obj::label = HX_("End",bb,bb,34,00);
            			}
            			break;
            			case (int)12: {
HXLINE(  99)				::blue::BParser_obj::label = HX_("Try",1b,21,40,00);
            			}
            			break;
            			case (int)13: {
HXLINE( 101)				 ::Dynamic value = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN( 101)				{
HXLINE( 102)					::blue::BParser_obj::value = value;
HXLINE( 103)					::blue::BParser_obj::label = HX_("Catch",1b,ec,4e,d4);
            				}
            			}
            			break;
            			case (int)16: {
HXLINE( 136)				 ::Dynamic a = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN( 136)				 ::Dynamic b = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(1);
HXDLIN( 136)				{
HXLINE( 137)					::blue::BParser_obj::a = a;
HXLINE( 138)					::blue::BParser_obj::b = b;
HXLINE( 139)					::blue::BParser_obj::label = HX_("Property",75,04,ea,85);
            				}
            			}
            			break;
            			case (int)17: {
HXLINE( 105)				 ::Dynamic stringToPrint = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN( 105)				{
HXLINE( 106)					::blue::BParser_obj::value = stringToPrint;
HXLINE( 107)					::blue::BParser_obj::label = HX_("Print",0d,c8,b8,5b);
            				}
            			}
            			break;
            			case (int)18: {
HXLINE( 109)				 ::Dynamic value = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN( 109)				{
HXLINE( 110)					::blue::BParser_obj::value = value;
HXLINE( 111)					::blue::BParser_obj::label = HX_("Return",d0,18,c2,3d);
            				}
            			}
            			break;
            			case (int)20: {
HXLINE( 116)				 ::Dynamic value = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN( 116)				{
HXLINE( 117)					::blue::BParser_obj::value = value;
HXLINE( 118)					::blue::BParser_obj::label = HX_("Throw",06,cd,bd,a2);
            				}
            			}
            			break;
            			case (int)21: {
HXLINE( 120)				 ::Dynamic value = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN( 120)				::cpp::VirtualArray args = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(1).StaticCast< ::cpp::VirtualArray >();
HXDLIN( 120)				{
HXLINE( 121)					::blue::BParser_obj::value = value;
HXLINE( 122)					::blue::BParser_obj::args = args;
HXLINE( 123)					::blue::BParser_obj::label = HX_("New",40,88,3b,00);
            				}
            			}
            			break;
            			case (int)22: {
HXLINE( 125)				::cpp::VirtualArray args = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0).StaticCast< ::cpp::VirtualArray >();
HXDLIN( 125)				{
HXLINE( 126)					::blue::BParser_obj::args = args;
HXLINE( 127)					::blue::BParser_obj::label = HX_("Constructor",da,c4,f7,7b);
            				}
            			}
            			break;
            			case (int)23: {
HXLINE( 130)				::blue::BParser_obj::label = HX_("Else",d9,10,ee,2d);
            			}
            			break;
            			case (int)24: {
HXLINE( 132)				 ::Dynamic value = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN( 132)				{
HXLINE( 133)					::blue::BParser_obj::value = value;
HXLINE( 134)					::blue::BParser_obj::label = HX_("FunctionCall",f6,a7,c7,f0);
            				}
            			}
            			break;
            			case (int)25: {
HXLINE( 141)				 ::Dynamic args = input.StaticCast< ::hx::EnumBase >()->_hx_getObject(0);
HXDLIN( 141)				{
HXLINE( 142)					::blue::BParser_obj::args = ( (::cpp::VirtualArray)(args) );
HXLINE( 143)					::blue::BParser_obj::label = HX_("Super",5b,71,ed,17);
            				}
            			}
            			break;
            			default:{
HXLINE( 146)				return;
            			}
            		}
HXLINE( 150)		 ::Dynamic astStructure = ::blue::BParser_obj::iterator;
HXLINE( 151)		::String astStructure1 = ::blue::BParser_obj::numberOne;
HXLINE( 152)		::String astStructure2 = ::blue::BParser_obj::numberTwo;
HXLINE( 153)		 ::Dynamic astStructure3 = ::blue::BParser_obj::valueOne;
HXLINE( 154)		 ::Dynamic astStructure4 = ::blue::BParser_obj::valueTwo;
HXLINE( 155)		 ::Dynamic astStructure5 = ::blue::BParser_obj::condition;
HXLINE( 156)		 ::Dynamic astStructure6 = ::blue::BParser_obj::value;
HXLINE( 157)		::cpp::VirtualArray astStructure7 = ::blue::BParser_obj::args;
HXLINE( 158)		::String astStructure8 = ::blue::BParser_obj::name;
HXLINE( 159)		::cpp::VirtualArray astStructure9 = ::blue::BParser_obj::entries;
HXLINE( 160)		 ::Dynamic astStructure10 = ::blue::BParser_obj::a;
HXLINE( 161)		 ::Dynamic astStructure11 = ::blue::BParser_obj::b;
HXLINE( 162)		::String astStructure12 = ::blue::BParser_obj::label;
HXLINE( 148)		 ::Dynamic astStructure13 =  ::Dynamic(::hx::Anon_obj::Create(15)
            			->setFixed(0,HX_("iterator",ee,49,9a,93),astStructure)
            			->setFixed(1,HX_("valueOne",75,4f,4e,ee),astStructure3)
            			->setFixed(2,HX_("valueTwo",9b,22,52,ee),astStructure4)
            			->setFixed(3,HX_("condition",9b,e9,33,fc),astStructure5)
            			->setFixed(4,HX_("a",61,00,00,00),astStructure10)
            			->setFixed(5,HX_("b",62,00,00,00),astStructure11)
            			->setFixed(6,HX_("token",f9,82,2b,14),input)
            			->setFixed(7,HX_("numberOne",1d,6f,75,1e),astStructure1)
            			->setFixed(8,HX_("numberTwo",43,42,79,1e),astStructure2)
            			->setFixed(9,HX_("value",71,7f,b8,31),astStructure6)
            			->setFixed(10,HX_("stringValue",e0,30,bb,3c),::Std_obj::string(::blue::BParser_obj::value))
            			->setFixed(11,HX_("args",5d,8d,74,40),astStructure7)
            			->setFixed(12,HX_("name",4b,72,ff,48),astStructure8)
            			->setFixed(13,HX_("label",f4,0d,af,6f),astStructure12)
            			->setFixed(14,HX_("entries",50,2d,5f,79),astStructure9));
HXLINE( 166)		 ::Dynamic replacer = null();
HXDLIN( 166)		::String space = null();
HXDLIN( 166)		::String serializedResult = ::haxe::format::JsonPrinter_obj::print(astStructure13,replacer,space);
HXLINE( 167)		::blue::BHaxeUtil_obj::toHaxe(serializedResult);
HXLINE( 168)		::blue::BHaxeUtil_obj::buildHaxeFile();
HXLINE( 170)		::blue::BParser_obj::token = null();
HXLINE( 171)		::blue::BParser_obj::iterator = null();
HXLINE( 172)		::blue::BParser_obj::numberTwo = null();
HXLINE( 173)		::blue::BParser_obj::numberOne = null();
HXLINE( 174)		::blue::BParser_obj::valueOne = null();
HXLINE( 175)		::blue::BParser_obj::valueTwo = null();
HXLINE( 176)		::blue::BParser_obj::condition = null();
HXLINE( 177)		::blue::BParser_obj::name = null();
HXLINE( 178)		::blue::BParser_obj::args = null();
HXLINE( 179)		::blue::BParser_obj::value = null();
HXLINE( 180)		::blue::BParser_obj::a = null();
HXLINE( 181)		::blue::BParser_obj::b = null();
HXLINE( 182)		::blue::BParser_obj::entries = null();
HXLINE( 183)		::blue::BParser_obj::label = null();
HXLINE( 184)		::blue::BParser_obj::stringValue = null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BParser_obj,parse,(void))


BParser_obj::BParser_obj()
{
}

bool BParser_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"a") ) { outValue = ( a ); return true; }
		if (HX_FIELD_EQ(inName,"b") ) { outValue = ( b ); return true; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { outValue = ( name ); return true; }
		if (HX_FIELD_EQ(inName,"args") ) { outValue = ( args ); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"token") ) { outValue = ( token ); return true; }
		if (HX_FIELD_EQ(inName,"value") ) { outValue = ( value ); return true; }
		if (HX_FIELD_EQ(inName,"label") ) { outValue = ( label ); return true; }
		if (HX_FIELD_EQ(inName,"parse") ) { outValue = parse_dyn(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"entries") ) { outValue = ( entries ); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { outValue = ( iterator ); return true; }
		if (HX_FIELD_EQ(inName,"valueOne") ) { outValue = ( valueOne ); return true; }
		if (HX_FIELD_EQ(inName,"valueTwo") ) { outValue = ( valueTwo ); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"numberOne") ) { outValue = ( numberOne ); return true; }
		if (HX_FIELD_EQ(inName,"numberTwo") ) { outValue = ( numberTwo ); return true; }
		if (HX_FIELD_EQ(inName,"condition") ) { outValue = ( condition ); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"stringValue") ) { outValue = ( stringValue ); return true; }
	}
	return false;
}

bool BParser_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"a") ) { a=ioValue.Cast<  ::Dynamic >(); return true; }
		if (HX_FIELD_EQ(inName,"b") ) { b=ioValue.Cast<  ::Dynamic >(); return true; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=ioValue.Cast< ::String >(); return true; }
		if (HX_FIELD_EQ(inName,"args") ) { args=ioValue.Cast< ::cpp::VirtualArray >(); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"token") ) { token=ioValue.Cast<  ::blue::BToken >(); return true; }
		if (HX_FIELD_EQ(inName,"value") ) { value=ioValue.Cast<  ::Dynamic >(); return true; }
		if (HX_FIELD_EQ(inName,"label") ) { label=ioValue.Cast< ::String >(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"entries") ) { entries=ioValue.Cast< ::cpp::VirtualArray >(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { iterator=ioValue.Cast<  ::Dynamic >(); return true; }
		if (HX_FIELD_EQ(inName,"valueOne") ) { valueOne=ioValue.Cast<  ::Dynamic >(); return true; }
		if (HX_FIELD_EQ(inName,"valueTwo") ) { valueTwo=ioValue.Cast<  ::Dynamic >(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"numberOne") ) { numberOne=ioValue.Cast< ::String >(); return true; }
		if (HX_FIELD_EQ(inName,"numberTwo") ) { numberTwo=ioValue.Cast< ::String >(); return true; }
		if (HX_FIELD_EQ(inName,"condition") ) { condition=ioValue.Cast<  ::Dynamic >(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"stringValue") ) { stringValue=ioValue.Cast< ::String >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *BParser_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo BParser_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::blue::BToken */ ,(void *) &BParser_obj::token,HX_("token",f9,82,2b,14)},
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &BParser_obj::iterator,HX_("iterator",ee,49,9a,93)},
	{::hx::fsString,(void *) &BParser_obj::numberOne,HX_("numberOne",1d,6f,75,1e)},
	{::hx::fsString,(void *) &BParser_obj::numberTwo,HX_("numberTwo",43,42,79,1e)},
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &BParser_obj::valueOne,HX_("valueOne",75,4f,4e,ee)},
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &BParser_obj::valueTwo,HX_("valueTwo",9b,22,52,ee)},
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &BParser_obj::condition,HX_("condition",9b,e9,33,fc)},
	{::hx::fsString,(void *) &BParser_obj::name,HX_("name",4b,72,ff,48)},
	{::hx::fsObject /* ::cpp::VirtualArray */ ,(void *) &BParser_obj::args,HX_("args",5d,8d,74,40)},
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &BParser_obj::value,HX_("value",71,7f,b8,31)},
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &BParser_obj::a,HX_("a",61,00,00,00)},
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &BParser_obj::b,HX_("b",62,00,00,00)},
	{::hx::fsObject /* ::cpp::VirtualArray */ ,(void *) &BParser_obj::entries,HX_("entries",50,2d,5f,79)},
	{::hx::fsString,(void *) &BParser_obj::label,HX_("label",f4,0d,af,6f)},
	{::hx::fsString,(void *) &BParser_obj::stringValue,HX_("stringValue",e0,30,bb,3c)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void BParser_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BParser_obj::token,"token");
	HX_MARK_MEMBER_NAME(BParser_obj::iterator,"iterator");
	HX_MARK_MEMBER_NAME(BParser_obj::numberOne,"numberOne");
	HX_MARK_MEMBER_NAME(BParser_obj::numberTwo,"numberTwo");
	HX_MARK_MEMBER_NAME(BParser_obj::valueOne,"valueOne");
	HX_MARK_MEMBER_NAME(BParser_obj::valueTwo,"valueTwo");
	HX_MARK_MEMBER_NAME(BParser_obj::condition,"condition");
	HX_MARK_MEMBER_NAME(BParser_obj::name,"name");
	HX_MARK_MEMBER_NAME(BParser_obj::args,"args");
	HX_MARK_MEMBER_NAME(BParser_obj::value,"value");
	HX_MARK_MEMBER_NAME(BParser_obj::a,"a");
	HX_MARK_MEMBER_NAME(BParser_obj::b,"b");
	HX_MARK_MEMBER_NAME(BParser_obj::entries,"entries");
	HX_MARK_MEMBER_NAME(BParser_obj::label,"label");
	HX_MARK_MEMBER_NAME(BParser_obj::stringValue,"stringValue");
};

#ifdef HXCPP_VISIT_ALLOCS
static void BParser_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BParser_obj::token,"token");
	HX_VISIT_MEMBER_NAME(BParser_obj::iterator,"iterator");
	HX_VISIT_MEMBER_NAME(BParser_obj::numberOne,"numberOne");
	HX_VISIT_MEMBER_NAME(BParser_obj::numberTwo,"numberTwo");
	HX_VISIT_MEMBER_NAME(BParser_obj::valueOne,"valueOne");
	HX_VISIT_MEMBER_NAME(BParser_obj::valueTwo,"valueTwo");
	HX_VISIT_MEMBER_NAME(BParser_obj::condition,"condition");
	HX_VISIT_MEMBER_NAME(BParser_obj::name,"name");
	HX_VISIT_MEMBER_NAME(BParser_obj::args,"args");
	HX_VISIT_MEMBER_NAME(BParser_obj::value,"value");
	HX_VISIT_MEMBER_NAME(BParser_obj::a,"a");
	HX_VISIT_MEMBER_NAME(BParser_obj::b,"b");
	HX_VISIT_MEMBER_NAME(BParser_obj::entries,"entries");
	HX_VISIT_MEMBER_NAME(BParser_obj::label,"label");
	HX_VISIT_MEMBER_NAME(BParser_obj::stringValue,"stringValue");
};

#endif

::hx::Class BParser_obj::__mClass;

static ::String BParser_obj_sStaticFields[] = {
	HX_("token",f9,82,2b,14),
	HX_("iterator",ee,49,9a,93),
	HX_("numberOne",1d,6f,75,1e),
	HX_("numberTwo",43,42,79,1e),
	HX_("valueOne",75,4f,4e,ee),
	HX_("valueTwo",9b,22,52,ee),
	HX_("condition",9b,e9,33,fc),
	HX_("name",4b,72,ff,48),
	HX_("args",5d,8d,74,40),
	HX_("value",71,7f,b8,31),
	HX_("a",61,00,00,00),
	HX_("b",62,00,00,00),
	HX_("entries",50,2d,5f,79),
	HX_("label",f4,0d,af,6f),
	HX_("stringValue",e0,30,bb,3c),
	HX_("parse",33,90,55,bd),
	::String(null())
};

void BParser_obj::__register()
{
	BParser_obj _hx_dummy;
	BParser_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("blue.BParser",ed,9c,1a,c6);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &BParser_obj::__GetStatic;
	__mClass->mSetStaticField = &BParser_obj::__SetStatic;
	__mClass->mMarkFunc = BParser_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(BParser_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< BParser_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = BParser_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = BParser_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = BParser_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace blue
