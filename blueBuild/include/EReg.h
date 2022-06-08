#ifndef INCLUDED_EReg
#define INCLUDED_EReg

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_2cd113ad60e10261_28_new)
HX_DECLARE_CLASS0(EReg)



class HXCPP_CLASS_ATTRIBUTES EReg_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef EReg_obj OBJ_;
		EReg_obj();

	public:
		enum { _hx_ClassId = 0x022d4033 };

		void __construct(::String r,::String opt);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="EReg")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"EReg"); }

		inline static ::hx::ObjectPtr< EReg_obj > __new(::String r,::String opt) {
			::hx::ObjectPtr< EReg_obj > __this = new EReg_obj();
			__this->__construct(r,opt);
			return __this;
		}

		inline static ::hx::ObjectPtr< EReg_obj > __alloc(::hx::Ctx *_hx_ctx,::String r,::String opt) {
			EReg_obj *__this = (EReg_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(EReg_obj), true, "EReg"));
			*(void **)__this = EReg_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_2cd113ad60e10261_28_new)
HXLINE(  29)		::Array< ::String > a = opt.split(HX_("g",67,00,00,00));
HXLINE(  30)		( ( ::EReg)(__this) )->global = (a->length > 1);
HXLINE(  31)		if (( ( ::EReg)(__this) )->global) {
HXLINE(  32)			opt = a->join(HX_("",00,00,00,00));
            		}
HXLINE(  33)		( ( ::EReg)(__this) )->r = _hx_regexp_new_options(r,opt);
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~EReg_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("EReg",0f,4a,da,2d); }

		 ::Dynamic r;
		::String last;
		bool global;
		bool match(::String s);
		::Dynamic match_dyn();

};


#endif /* INCLUDED_EReg */ 
