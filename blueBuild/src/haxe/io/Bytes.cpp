#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Encoding
#include <haxe/io/Encoding.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_464b3142acc6d207_34_new,"haxe.io.Bytes","new",0x3938d57d,"haxe.io.Bytes.new","C:\\HaxeToolkit\\haxe\\std/haxe/io/Bytes.hx",34,0x20b05d0c)
HX_LOCAL_STACK_FRAME(_hx_pos_464b3142acc6d207_580_ofString,"haxe.io.Bytes","ofString",0x6e53bb0b,"haxe.io.Bytes.ofString","C:\\HaxeToolkit\\haxe\\std/haxe/io/Bytes.hx",580,0x20b05d0c)
namespace haxe{
namespace io{

void Bytes_obj::__construct(int length,::Array< unsigned char > b){
            	HX_STACKFRAME(&_hx_pos_464b3142acc6d207_34_new)
HXLINE(  35)		this->length = length;
HXLINE(  36)		this->b = b;
            	}

Dynamic Bytes_obj::__CreateEmpty() { return new Bytes_obj; }

void *Bytes_obj::_hx_vtable = 0;

Dynamic Bytes_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Bytes_obj > _hx_result = new Bytes_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool Bytes_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x195c64b7;
}

 ::haxe::io::Bytes Bytes_obj::ofString(::String s, ::haxe::io::Encoding encoding){
            	HX_GC_STACKFRAME(&_hx_pos_464b3142acc6d207_580_ofString)
HXLINE( 591)		::Array< unsigned char > a = ::Array_obj< unsigned char >::__new();
HXLINE( 592)		 ::__hxcpp_bytes_of_string(a,s);
HXLINE( 593)		return  ::haxe::io::Bytes_obj::__alloc( HX_CTX ,a->length,a);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,ofString,return )


Bytes_obj::Bytes_obj()
{
}

void Bytes_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bytes);
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_END_CLASS();
}

void Bytes_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(b,"b");
}

::hx::Val Bytes_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return ::hx::Val( b ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return ::hx::Val( length ); }
	}
	return super::__Field(inName,inCallProp);
}

bool Bytes_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"ofString") ) { outValue = ofString_dyn(); return true; }
	}
	return false;
}

::hx::Val Bytes_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< ::Array< unsigned char > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bytes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("length",e6,94,07,9f));
	outFields->push(HX_("b",62,00,00,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Bytes_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(Bytes_obj,length),HX_("length",e6,94,07,9f)},
	{::hx::fsObject /* ::Array< unsigned char > */ ,(int)offsetof(Bytes_obj,b),HX_("b",62,00,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Bytes_obj_sStaticStorageInfo = 0;
#endif

static ::String Bytes_obj_sMemberFields[] = {
	HX_("length",e6,94,07,9f),
	HX_("b",62,00,00,00),
	::String(null()) };

::hx::Class Bytes_obj::__mClass;

static ::String Bytes_obj_sStaticFields[] = {
	HX_("ofString",48,69,31,a4),
	::String(null())
};

void Bytes_obj::__register()
{
	Bytes_obj _hx_dummy;
	Bytes_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("haxe.io.Bytes",0b,53,6f,9f);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Bytes_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Bytes_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Bytes_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Bytes_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Bytes_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Bytes_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace haxe
} // end namespace io
