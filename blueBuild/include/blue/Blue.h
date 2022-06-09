#ifndef INCLUDED_blue_Blue
#define INCLUDED_blue_Blue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(blue,Blue)

namespace blue{


class HXCPP_CLASS_ATTRIBUTES Blue_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Blue_obj OBJ_;
		Blue_obj();

	public:
		enum { _hx_ClassId = 0x00065654 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="blue.Blue")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"blue.Blue"); }

		inline static ::hx::ObjectPtr< Blue_obj > __new() {
			::hx::ObjectPtr< Blue_obj > __this = new Blue_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Blue_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Blue_obj *__this = (Blue_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Blue_obj), false, "blue.Blue"));
			*(void **)__this = Blue_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Blue_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Blue",ba,6e,f2,2b); }

		static void __boot();
		static ::Array< ::String > currentMappedFiles;
		static ::Array< ::Dynamic> currentMappedLines;
		static ::String directory;
		static ::String mainFile;
		static ::Array< ::String > libs;
		static ::String buildCommand;
		static ::Array< ::String > completeSyntax;
		static void main();
		static ::Dynamic main_dyn();

		static void mapSource(::String directory);
		static ::Dynamic mapSource_dyn();

		static void mapFile(::String input);
		static ::Dynamic mapFile_dyn();

		static void lexSourceFile(::String content);
		static ::Dynamic lexSourceFile_dyn();

		static bool checkForErrors(::String input);
		static ::Dynamic checkForErrors_dyn();

};

} // end namespace blue

#endif /* INCLUDED_blue_Blue */ 
