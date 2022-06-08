#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_2cd113ad60e10261_28_new,"EReg","new",0x8b859e81,"EReg.new","C:\\HaxeToolkit\\haxe\\std/cpp/_std/EReg.hx",28,0xa4513ee9)
HX_LOCAL_STACK_FRAME(_hx_pos_2cd113ad60e10261_36_match,"EReg","match",0x18fda1a6,"EReg.match","C:\\HaxeToolkit\\haxe\\std/cpp/_std/EReg.hx",36,0xa4513ee9)

void EReg_obj::__construct(::String r,::String opt){
            	HX_STACKFRAME(&_hx_pos_2cd113ad60e10261_28_new)
HXLINE(  29)		::Array< ::String > a = opt.split(HX_("g",67,00,00,00));
HXLINE(  30)		this->global = (a->length > 1);
HXLINE(  31)		if (this->global) {
HXLINE(  32)			opt = a->join(HX_("",00,00,00,00));
            		}
HXLINE(  33)		this->r = _hx_regexp_new_options(r,opt);
            	}

Dynamic EReg_obj::__CreateEmpty() { return new EReg_obj; }

void *EReg_obj::_hx_vtable = 0;

Dynamic EReg_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< EReg_obj > _hx_result = new EReg_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool EReg_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x022d4033;
}

bool EReg_obj::match(::String s){
            	HX_STACKFRAME(&_hx_pos_2cd113ad60e10261_36_match)
HXLINE(  37)		bool p = _hx_regexp_match(this->r,s,0,s.length);
HXLINE(  38)		if (p) {
HXLINE(  39)			this->last = s;
            		}
            		else {
HXLINE(  41)			this->last = null();
            		}
HXLINE(  42)		return p;
            	}


HX_DEFINE_DYNAMIC_FUNC1(EReg_obj,match,return )


EReg_obj::EReg_obj()
{
}

void EReg_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EReg);
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(last,"last");
	HX_MARK_MEMBER_NAME(global,"global");
	HX_MARK_END_CLASS();
}

void EReg_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(r,"r");
	HX_VISIT_MEMBER_NAME(last,"last");
	HX_VISIT_MEMBER_NAME(global,"global");
}

::hx::Val EReg_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return ::hx::Val( r ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"last") ) { return ::hx::Val( last ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"match") ) { return ::hx::Val( match_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"global") ) { return ::hx::Val( global ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val EReg_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"last") ) { last=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"global") ) { global=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EReg_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("r",72,00,00,00));
	outFields->push(HX_("last",56,0a,ad,47));
	outFields->push(HX_("global",63,31,b2,a7));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo EReg_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(EReg_obj,r),HX_("r",72,00,00,00)},
	{::hx::fsString,(int)offsetof(EReg_obj,last),HX_("last",56,0a,ad,47)},
	{::hx::fsBool,(int)offsetof(EReg_obj,global),HX_("global",63,31,b2,a7)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *EReg_obj_sStaticStorageInfo = 0;
#endif

static ::String EReg_obj_sMemberFields[] = {
	HX_("r",72,00,00,00),
	HX_("last",56,0a,ad,47),
	HX_("global",63,31,b2,a7),
	HX_("match",45,49,23,03),
	::String(null()) };

::hx::Class EReg_obj::__mClass;

void EReg_obj::__register()
{
	EReg_obj _hx_dummy;
	EReg_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("EReg",0f,4a,da,2d);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(EReg_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< EReg_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = EReg_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = EReg_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

