#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_4da882ff114ca894_35_field,"Reflect","field",0x54b04da9,"Reflect.field","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Reflect.hx",35,0x487b3827)
HX_LOCAL_STACK_FRAME(_hx_pos_4da882ff114ca894_40_setField,"Reflect","setField",0x71684429,"Reflect.setField","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Reflect.hx",40,0x487b3827)
HX_LOCAL_STACK_FRAME(_hx_pos_4da882ff114ca894_67_fields,"Reflect","fields",0xc593a6aa,"Reflect.fields","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Reflect.hx",67,0x487b3827)
HX_LOCAL_STACK_FRAME(_hx_pos_4da882ff114ca894_77_isFunction,"Reflect","isFunction",0x0f1541d3,"Reflect.isFunction","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Reflect.hx",77,0x487b3827)
HX_LOCAL_STACK_FRAME(_hx_pos_4da882ff114ca894_93_isObject,"Reflect","isObject",0xd04960ba,"Reflect.isObject","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Reflect.hx",93,0x487b3827)

void Reflect_obj::__construct() { }

Dynamic Reflect_obj::__CreateEmpty() { return new Reflect_obj; }

void *Reflect_obj::_hx_vtable = 0;

Dynamic Reflect_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Reflect_obj > _hx_result = new Reflect_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Reflect_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x769a515d;
}

 ::Dynamic Reflect_obj::field( ::Dynamic o,::String field){
            	HX_STACKFRAME(&_hx_pos_4da882ff114ca894_35_field)
HXDLIN(  35)		return ::hx::IsNull( o ) ? null() : o->__Field(field,::hx::paccNever);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Reflect_obj,field,return )

void Reflect_obj::setField( ::Dynamic o,::String field, ::Dynamic value){
            	HX_STACKFRAME(&_hx_pos_4da882ff114ca894_40_setField)
HXDLIN(  40)		if (::hx::IsNotNull( o )) {
HXLINE(  41)			o->__SetField(field,value,::hx::paccNever);
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Reflect_obj,setField,(void))

::Array< ::String > Reflect_obj::fields( ::Dynamic o){
            	HX_STACKFRAME(&_hx_pos_4da882ff114ca894_67_fields)
HXLINE(  68)		if (::hx::IsNull( o )) {
HXLINE(  69)			return ::Array_obj< ::String >::__new();
            		}
HXLINE(  70)		::Array< ::String > a = ::Array_obj< ::String >::__new(0);
HXLINE(  71)		o->__GetFields(a);
HXLINE(  72)		return a;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,fields,return )

bool Reflect_obj::isFunction( ::Dynamic f){
            	HX_STACKFRAME(&_hx_pos_4da882ff114ca894_77_isFunction)
HXDLIN(  77)		return (::hx::IsNotNull( f ) && ::hx::IsEq( f->__GetType(),6 ));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,isFunction,return )

bool Reflect_obj::isObject( ::Dynamic v){
            	HX_STACKFRAME(&_hx_pos_4da882ff114ca894_93_isObject)
HXLINE(  94)		if (::hx::IsNull( v )) {
HXLINE(  95)			return false;
            		}
HXLINE(  96)		int t = ( (int)(v->__GetType()) );
HXLINE(  97)		return ((((t == 4) || (t == 8)) || (t == 3)) || (t == 5));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,isObject,return )


Reflect_obj::Reflect_obj()
{
}

bool Reflect_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"field") ) { outValue = field_dyn(); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"fields") ) { outValue = fields_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setField") ) { outValue = setField_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"isObject") ) { outValue = isObject_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isFunction") ) { outValue = isFunction_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Reflect_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Reflect_obj_sStaticStorageInfo = 0;
#endif

::hx::Class Reflect_obj::__mClass;

static ::String Reflect_obj_sStaticFields[] = {
	HX_("field",ba,94,93,00),
	HX_("setField",b8,fd,c7,0e),
	HX_("fields",79,8e,8e,80),
	HX_("isFunction",22,bd,01,8f),
	HX_("isObject",49,1a,a9,6d),
	::String(null())
};

void Reflect_obj::__register()
{
	Reflect_obj _hx_dummy;
	Reflect_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Reflect",1d,ac,7a,b6);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Reflect_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Reflect_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Reflect_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Reflect_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Reflect_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

