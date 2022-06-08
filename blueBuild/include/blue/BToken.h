#ifndef INCLUDED_blue_BToken
#define INCLUDED_blue_BToken

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(blue,BToken)
namespace blue{


class BToken_obj : public ::hx::EnumBase_obj
{
	typedef ::hx::EnumBase_obj super;
		typedef BToken_obj OBJ_;

	public:
		BToken_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		static bool __GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::String GetEnumName( ) const { return HX_("blue.BToken",ab,be,8d,f1); }
		::String __ToString() const { return HX_("BToken.",f7,28,04,7f) + _hx_tag; }

		static ::blue::BToken Add( ::Dynamic a, ::Dynamic b);
		static ::Dynamic Add_dyn();
		static ::blue::BToken Array(::cpp::VirtualArray entries);
		static ::Dynamic Array_dyn();
		static ::blue::BToken ArrayIndex( ::Dynamic value);
		static ::Dynamic ArrayIndex_dyn();
		static ::blue::BToken Catch( ::Dynamic value);
		static ::Dynamic Catch_dyn();
		static ::blue::BToken Comment( ::Dynamic value);
		static ::Dynamic Comment_dyn();
		static ::blue::BToken Constructor(::cpp::VirtualArray args);
		static ::Dynamic Constructor_dyn();
		static ::blue::BToken Continue;
		static inline ::blue::BToken Continue_dyn() { return Continue; }
		static ::blue::BToken Divide( ::Dynamic a, ::Dynamic b);
		static ::Dynamic Divide_dyn();
		static ::blue::BToken Else;
		static inline ::blue::BToken Else_dyn() { return Else; }
		static ::blue::BToken End;
		static inline ::blue::BToken End_dyn() { return End; }
		static ::blue::BToken ForStatement( ::Dynamic iterator,::String numberOne,::String numberTwo);
		static ::Dynamic ForStatement_dyn();
		static ::blue::BToken FunctionC( ::Dynamic value);
		static ::Dynamic FunctionC_dyn();
		static ::blue::BToken IfStatement( ::Dynamic condition);
		static ::Dynamic IfStatement_dyn();
		static ::blue::BToken MainMethod;
		static inline ::blue::BToken MainMethod_dyn() { return MainMethod; }
		static ::blue::BToken Method(::String name,::cpp::VirtualArray args);
		static ::Dynamic Method_dyn();
		static ::blue::BToken Multiply( ::Dynamic a, ::Dynamic b);
		static ::Dynamic Multiply_dyn();
		static ::blue::BToken New( ::Dynamic value,::cpp::VirtualArray args);
		static ::Dynamic New_dyn();
		static ::blue::BToken Print( ::Dynamic stringToPrint);
		static ::Dynamic Print_dyn();
		static ::blue::BToken Property( ::Dynamic a, ::Dynamic b);
		static ::Dynamic Property_dyn();
		static ::blue::BToken Return( ::Dynamic value);
		static ::Dynamic Return_dyn();
		static ::blue::BToken Stop;
		static inline ::blue::BToken Stop_dyn() { return Stop; }
		static ::blue::BToken Subtract( ::Dynamic a, ::Dynamic b);
		static ::Dynamic Subtract_dyn();
		static ::blue::BToken Throw( ::Dynamic value);
		static ::Dynamic Throw_dyn();
		static ::blue::BToken Try;
		static inline ::blue::BToken Try_dyn() { return Try; }
		static ::blue::BToken Use( ::Dynamic value);
		static ::Dynamic Use_dyn();
		static ::blue::BToken Variable(::String name, ::Dynamic value);
		static ::Dynamic Variable_dyn();
};

} // end namespace blue

#endif /* INCLUDED_blue_BToken */ 
