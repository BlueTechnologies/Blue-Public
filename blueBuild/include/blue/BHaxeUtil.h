#ifndef INCLUDED_blue_BHaxeUtil
#define INCLUDED_blue_BHaxeUtil

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(blue,BHaxeUtil)

namespace blue{


class HXCPP_CLASS_ATTRIBUTES BHaxeUtil_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef BHaxeUtil_obj OBJ_;
		BHaxeUtil_obj();

	public:
		enum { _hx_ClassId = 0x1f3edbd0 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="blue.BHaxeUtil")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"blue.BHaxeUtil"); }

		inline static ::hx::ObjectPtr< BHaxeUtil_obj > __new() {
			::hx::ObjectPtr< BHaxeUtil_obj > __this = new BHaxeUtil_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< BHaxeUtil_obj > __alloc(::hx::Ctx *_hx_ctx) {
			BHaxeUtil_obj *__this = (BHaxeUtil_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(BHaxeUtil_obj), false, "blue.BHaxeUtil"));
			*(void **)__this = BHaxeUtil_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~BHaxeUtil_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("BHaxeUtil",aa,91,e2,94); }

		static void __boot();
		static ::cpp::VirtualArray haxeData;
		static ::cpp::VirtualArray specificValues;
		static ::cpp::VirtualArray oldValues;
		static ::String fileName;
		static void toHaxe( ::Dynamic AST);
		static ::Dynamic toHaxe_dyn();

		static void buildHaxeFile();
		static ::Dynamic buildHaxeFile_dyn();

};

} // end namespace blue

#endif /* INCLUDED_blue_BHaxeUtil */ 
