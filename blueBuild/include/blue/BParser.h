#ifndef INCLUDED_blue_BParser
#define INCLUDED_blue_BParser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(blue,BParser)
HX_DECLARE_CLASS1(blue,BToken)

namespace blue{


class HXCPP_CLASS_ATTRIBUTES BParser_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef BParser_obj OBJ_;
		BParser_obj();

	public:
		enum { _hx_ClassId = 0x79571383 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="blue.BParser")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"blue.BParser"); }

		inline static ::hx::ObjectPtr< BParser_obj > __new() {
			::hx::ObjectPtr< BParser_obj > __this = new BParser_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< BParser_obj > __alloc(::hx::Ctx *_hx_ctx) {
			BParser_obj *__this = (BParser_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(BParser_obj), false, "blue.BParser"));
			*(void **)__this = BParser_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~BParser_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("BParser",c1,ae,a5,da); }

		static  ::blue::BToken token;
		static  ::Dynamic iterator;
		static ::String numberOne;
		static ::String numberTwo;
		static  ::Dynamic valueOne;
		static  ::Dynamic valueTwo;
		static  ::Dynamic condition;
		static ::String name;
		static ::cpp::VirtualArray args;
		static  ::Dynamic value;
		static  ::Dynamic a;
		static  ::Dynamic b;
		static ::cpp::VirtualArray entries;
		static ::String label;
		static ::String stringValue;
		static void parse( ::Dynamic input);
		static ::Dynamic parse_dyn();

};

} // end namespace blue

#endif /* INCLUDED_blue_BParser */ 
