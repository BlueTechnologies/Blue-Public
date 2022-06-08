#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_b5269e0ce41f90ec_36_getClass,"Type","getClass",0xc4e49bd6,"Type.getClass","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Type.hx",36,0x00143afe)
HX_LOCAL_STACK_FRAME(_hx_pos_b5269e0ce41f90ec_111_getInstanceFields,"Type","getInstanceFields",0xe970f890,"Type.getInstanceFields","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Type.hx",111,0x00143afe)
HX_LOCAL_STACK_FRAME(_hx_pos_b5269e0ce41f90ec_124_typeof,"Type","typeof",0xd6c51d65,"Type.typeof","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Type.hx",124,0x00143afe)

void Type_obj::__construct() { }

Dynamic Type_obj::__CreateEmpty() { return new Type_obj; }

void *Type_obj::_hx_vtable = 0;

Dynamic Type_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Type_obj > _hx_result = new Type_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Type_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0c3514fe;
}

::hx::Class Type_obj::getClass( ::Dynamic o){
            	HX_STACKFRAME(&_hx_pos_b5269e0ce41f90ec_36_getClass)
HXLINE(  37)		bool _hx_tmp;
HXDLIN(  37)		if (::hx::IsNotNull( o )) {
HXLINE(  37)			_hx_tmp = !(::Reflect_obj::isObject(o));
            		}
            		else {
HXLINE(  37)			_hx_tmp = true;
            		}
HXDLIN(  37)		if (_hx_tmp) {
HXLINE(  38)			return null();
            		}
HXLINE(  39)		 ::Dynamic c = o->__GetClass();
HXLINE(  40)		::String _hx_switch_0 = ( (::String)(c->toString()) );
            		if (  (_hx_switch_0==HX_("Class",18,e8,85,db)) ){
HXLINE(  44)			return null();
HXDLIN(  44)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("__Anon",8c,1a,43,da)) ){
HXLINE(  42)			return null();
HXDLIN(  42)			goto _hx_goto_0;
            		}
            		_hx_goto_0:;
HXLINE(  46)		return c;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getClass,return )

::Array< ::String > Type_obj::getInstanceFields(::hx::Class c){
            	HX_STACKFRAME(&_hx_pos_b5269e0ce41f90ec_111_getInstanceFields)
HXDLIN( 111)		return ( (::Array< ::String >)(c->GetInstanceFields()) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getInstanceFields,return )

 ::ValueType Type_obj::_hx_typeof( ::Dynamic v){
            	HX_STACKFRAME(&_hx_pos_b5269e0ce41f90ec_124_typeof)
HXLINE( 125)		if (::hx::IsNull( v )) {
HXLINE( 126)			return ::ValueType_obj::TNull_dyn();
            		}
HXLINE( 127)		int t = ( (int)(v->__GetType()) );
HXLINE( 128)		switch((int)(t)){
            			case (int)1: {
HXLINE( 134)				return ::ValueType_obj::TFloat_dyn();
            			}
            			break;
            			case (int)2: {
HXLINE( 130)				return ::ValueType_obj::TBool_dyn();
            			}
            			break;
            			case (int)4: {
HXLINE( 138)				return ::ValueType_obj::TObject_dyn();
            			}
            			break;
            			case (int)6: {
HXLINE( 136)				return ::ValueType_obj::TFunction_dyn();
            			}
            			break;
            			case (int)7: {
HXLINE( 140)				return ::ValueType_obj::TEnum(v->__GetClass());
            			}
            			break;
            			case (int)255: {
HXLINE( 132)				return ::ValueType_obj::TInt_dyn();
            			}
            			break;
            			default:{
HXLINE( 142)				return ::ValueType_obj::TClass(v->__GetClass());
            			}
            		}
HXLINE( 128)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,_hx_typeof,return )


Type_obj::Type_obj()
{
}

bool Type_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"typeof") ) { outValue = _hx_typeof_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getClass") ) { outValue = getClass_dyn(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getInstanceFields") ) { outValue = getInstanceFields_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Type_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Type_obj_sStaticStorageInfo = 0;
#endif

::hx::Class Type_obj::__mClass;

static ::String Type_obj_sStaticFields[] = {
	HX_("getClass",c2,87,2f,a8),
	HX_("getInstanceFields",24,2f,97,ed),
	HX_("typeof",51,f6,36,57),
	::String(null())
};

void Type_obj::__register()
{
	Type_obj _hx_dummy;
	Type_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Type",da,1e,e2,37);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Type_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Type_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Type_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Type_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Type_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

