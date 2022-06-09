#ifndef INCLUDED_blue_BLexer
#define INCLUDED_blue_BLexer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_592fe0dd445f45d4_33_new)
HX_DECLARE_CLASS1(blue,BLexer)
HX_DECLARE_CLASS1(blue,BToken)

namespace blue{


class HXCPP_CLASS_ATTRIBUTES BLexer_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef BLexer_obj OBJ_;
		BLexer_obj();

	public:
		enum { _hx_ClassId = 0x57b05c84 };

		void __construct(::String content);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="blue.BLexer")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"blue.BLexer"); }

		inline static ::hx::ObjectPtr< BLexer_obj > __new(::String content) {
			::hx::ObjectPtr< BLexer_obj > __this = new BLexer_obj();
			__this->__construct(content);
			return __this;
		}

		inline static ::hx::ObjectPtr< BLexer_obj > __alloc(::hx::Ctx *_hx_ctx,::String content) {
			BLexer_obj *__this = (BLexer_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(BLexer_obj), true, "blue.BLexer"));
			*(void **)__this = BLexer_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_592fe0dd445f45d4_33_new)
HXLINE(  42)		( ( ::blue::BLexer)(__this) )->number = ((Float)0);
HXLINE(  37)		( ( ::blue::BLexer)(__this) )->end = null();
HXLINE(  51)		::blue::BLexer_obj::content = content;
HXLINE(  52)		::blue::BLexer_obj::enumContent(content);
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~BLexer_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("BLexer",6a,da,1f,69); }

		static void __boot();
		static ::String current;
		static ::String _hx_char;
		static ::String content;
		static bool last;
		static ::cpp::VirtualArray tokensToParse;
		static ::Array< ::String > completeSyntax;
		static void enumContent(::String contentToEnum);
		static ::Dynamic enumContent_dyn();

		static void buildAST( ::blue::BToken input);
		static ::Dynamic buildAST_dyn();

		::String end;
		Float number;
};

} // end namespace blue

#endif /* INCLUDED_blue_BLexer */ 
