#include <hxcpp.h>

#ifndef INCLUDED_blue_BToken
#include <blue/BToken.h>
#endif
namespace blue{

::blue::BToken BToken_obj::Add( ::Dynamic a, ::Dynamic b)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Add",01,aa,31,00),7,2)->_hx_init(0,a)->_hx_init(1,b);
}

::blue::BToken BToken_obj::Array(::cpp::VirtualArray entries)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Array",79,dd,bc,b8),2,1)->_hx_init(0,entries);
}

::blue::BToken BToken_obj::Catch( ::Dynamic value)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Catch",1b,ec,4e,d4),13,1)->_hx_init(0,value);
}

::blue::BToken BToken_obj::Comment( ::Dynamic value)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Comment",3f,a2,c1,4e),19,1)->_hx_init(0,value);
}

::blue::BToken BToken_obj::Constructor(::cpp::VirtualArray args)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Constructor",da,c4,f7,7b),22,1)->_hx_init(0,args);
}

::blue::BToken BToken_obj::Continue;

::blue::BToken BToken_obj::Divide( ::Dynamic a, ::Dynamic b)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Divide",99,a3,a6,f3),10,2)->_hx_init(0,a)->_hx_init(1,b);
}

::blue::BToken BToken_obj::Else;

::blue::BToken BToken_obj::End;

::blue::BToken BToken_obj::ForStatement( ::Dynamic iterator,::String numberOne,::String numberTwo)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("ForStatement",06,54,ec,5d),4,3)->_hx_init(0,iterator)->_hx_init(1,numberOne)->_hx_init(2,numberTwo);
}

::blue::BToken BToken_obj::FunctionC( ::Dynamic value)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("FunctionC",0b,ea,d5,55),24,1)->_hx_init(0,value);
}

::blue::BToken BToken_obj::IfStatement( ::Dynamic condition)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("IfStatement",72,d0,12,3f),5,1)->_hx_init(0,condition);
}

::blue::BToken BToken_obj::MainMethod;

::blue::BToken BToken_obj::Method(::String name,::cpp::VirtualArray args)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Method",01,6b,ef,3d),0,2)->_hx_init(0,name)->_hx_init(1,args);
}

::blue::BToken BToken_obj::Multiply( ::Dynamic a, ::Dynamic b)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Multiply",44,9e,3e,74),9,2)->_hx_init(0,a)->_hx_init(1,b);
}

::blue::BToken BToken_obj::New( ::Dynamic value,::cpp::VirtualArray args)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("New",40,88,3b,00),21,2)->_hx_init(0,value)->_hx_init(1,args);
}

::blue::BToken BToken_obj::Print( ::Dynamic stringToPrint)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Print",0d,c8,b8,5b),17,1)->_hx_init(0,stringToPrint);
}

::blue::BToken BToken_obj::Property( ::Dynamic a, ::Dynamic b)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Property",75,04,ea,85),16,2)->_hx_init(0,a)->_hx_init(1,b);
}

::blue::BToken BToken_obj::Return( ::Dynamic value)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Return",d0,18,c2,3d),18,1)->_hx_init(0,value);
}

::blue::BToken BToken_obj::Stop;

::blue::BToken BToken_obj::Subtract( ::Dynamic a, ::Dynamic b)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Subtract",34,31,c3,d1),8,2)->_hx_init(0,a)->_hx_init(1,b);
}

::blue::BToken BToken_obj::Super( ::Dynamic args)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Super",5b,71,ed,17),25,1)->_hx_init(0,args);
}

::blue::BToken BToken_obj::Throw( ::Dynamic value)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Throw",06,cd,bd,a2),20,1)->_hx_init(0,value);
}

::blue::BToken BToken_obj::Try;

::blue::BToken BToken_obj::Use( ::Dynamic value)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Use",27,e4,40,00),6,1)->_hx_init(0,value);
}

::blue::BToken BToken_obj::Variable(::String name, ::Dynamic value)
{
	return ::hx::CreateEnum< BToken_obj >(HX_("Variable",5c,ce,be,42),3,2)->_hx_init(0,name)->_hx_init(1,value);
}

bool BToken_obj::__GetStatic(const ::String &inName, ::Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("Add",01,aa,31,00)) { outValue = BToken_obj::Add_dyn(); return true; }
	if (inName==HX_("Array",79,dd,bc,b8)) { outValue = BToken_obj::Array_dyn(); return true; }
	if (inName==HX_("Catch",1b,ec,4e,d4)) { outValue = BToken_obj::Catch_dyn(); return true; }
	if (inName==HX_("Comment",3f,a2,c1,4e)) { outValue = BToken_obj::Comment_dyn(); return true; }
	if (inName==HX_("Constructor",da,c4,f7,7b)) { outValue = BToken_obj::Constructor_dyn(); return true; }
	if (inName==HX_("Continue",87,9c,7a,0b)) { outValue = BToken_obj::Continue; return true; }
	if (inName==HX_("Divide",99,a3,a6,f3)) { outValue = BToken_obj::Divide_dyn(); return true; }
	if (inName==HX_("Else",d9,10,ee,2d)) { outValue = BToken_obj::Else; return true; }
	if (inName==HX_("End",bb,bb,34,00)) { outValue = BToken_obj::End; return true; }
	if (inName==HX_("ForStatement",06,54,ec,5d)) { outValue = BToken_obj::ForStatement_dyn(); return true; }
	if (inName==HX_("FunctionC",0b,ea,d5,55)) { outValue = BToken_obj::FunctionC_dyn(); return true; }
	if (inName==HX_("IfStatement",72,d0,12,3f)) { outValue = BToken_obj::IfStatement_dyn(); return true; }
	if (inName==HX_("MainMethod",1a,18,b8,55)) { outValue = BToken_obj::MainMethod; return true; }
	if (inName==HX_("Method",01,6b,ef,3d)) { outValue = BToken_obj::Method_dyn(); return true; }
	if (inName==HX_("Multiply",44,9e,3e,74)) { outValue = BToken_obj::Multiply_dyn(); return true; }
	if (inName==HX_("New",40,88,3b,00)) { outValue = BToken_obj::New_dyn(); return true; }
	if (inName==HX_("Print",0d,c8,b8,5b)) { outValue = BToken_obj::Print_dyn(); return true; }
	if (inName==HX_("Property",75,04,ea,85)) { outValue = BToken_obj::Property_dyn(); return true; }
	if (inName==HX_("Return",d0,18,c2,3d)) { outValue = BToken_obj::Return_dyn(); return true; }
	if (inName==HX_("Stop",22,1c,35,37)) { outValue = BToken_obj::Stop; return true; }
	if (inName==HX_("Subtract",34,31,c3,d1)) { outValue = BToken_obj::Subtract_dyn(); return true; }
	if (inName==HX_("Super",5b,71,ed,17)) { outValue = BToken_obj::Super_dyn(); return true; }
	if (inName==HX_("Throw",06,cd,bd,a2)) { outValue = BToken_obj::Throw_dyn(); return true; }
	if (inName==HX_("Try",1b,21,40,00)) { outValue = BToken_obj::Try; return true; }
	if (inName==HX_("Use",27,e4,40,00)) { outValue = BToken_obj::Use_dyn(); return true; }
	if (inName==HX_("Variable",5c,ce,be,42)) { outValue = BToken_obj::Variable_dyn(); return true; }
	return super::__GetStatic(inName, outValue, inCallProp);
}

HX_DEFINE_CREATE_ENUM(BToken_obj)

int BToken_obj::__FindIndex(::String inName)
{
	if (inName==HX_("Add",01,aa,31,00)) return 7;
	if (inName==HX_("Array",79,dd,bc,b8)) return 2;
	if (inName==HX_("Catch",1b,ec,4e,d4)) return 13;
	if (inName==HX_("Comment",3f,a2,c1,4e)) return 19;
	if (inName==HX_("Constructor",da,c4,f7,7b)) return 22;
	if (inName==HX_("Continue",87,9c,7a,0b)) return 14;
	if (inName==HX_("Divide",99,a3,a6,f3)) return 10;
	if (inName==HX_("Else",d9,10,ee,2d)) return 23;
	if (inName==HX_("End",bb,bb,34,00)) return 11;
	if (inName==HX_("ForStatement",06,54,ec,5d)) return 4;
	if (inName==HX_("FunctionC",0b,ea,d5,55)) return 24;
	if (inName==HX_("IfStatement",72,d0,12,3f)) return 5;
	if (inName==HX_("MainMethod",1a,18,b8,55)) return 1;
	if (inName==HX_("Method",01,6b,ef,3d)) return 0;
	if (inName==HX_("Multiply",44,9e,3e,74)) return 9;
	if (inName==HX_("New",40,88,3b,00)) return 21;
	if (inName==HX_("Print",0d,c8,b8,5b)) return 17;
	if (inName==HX_("Property",75,04,ea,85)) return 16;
	if (inName==HX_("Return",d0,18,c2,3d)) return 18;
	if (inName==HX_("Stop",22,1c,35,37)) return 15;
	if (inName==HX_("Subtract",34,31,c3,d1)) return 8;
	if (inName==HX_("Super",5b,71,ed,17)) return 25;
	if (inName==HX_("Throw",06,cd,bd,a2)) return 20;
	if (inName==HX_("Try",1b,21,40,00)) return 12;
	if (inName==HX_("Use",27,e4,40,00)) return 6;
	if (inName==HX_("Variable",5c,ce,be,42)) return 3;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC2(BToken_obj,Add,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BToken_obj,Array,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BToken_obj,Catch,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BToken_obj,Comment,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BToken_obj,Constructor,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(BToken_obj,Divide,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(BToken_obj,ForStatement,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BToken_obj,FunctionC,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BToken_obj,IfStatement,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(BToken_obj,Method,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(BToken_obj,Multiply,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(BToken_obj,New,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BToken_obj,Print,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(BToken_obj,Property,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BToken_obj,Return,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(BToken_obj,Subtract,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BToken_obj,Super,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BToken_obj,Throw,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BToken_obj,Use,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(BToken_obj,Variable,return)

int BToken_obj::__FindArgCount(::String inName)
{
	if (inName==HX_("Add",01,aa,31,00)) return 2;
	if (inName==HX_("Array",79,dd,bc,b8)) return 1;
	if (inName==HX_("Catch",1b,ec,4e,d4)) return 1;
	if (inName==HX_("Comment",3f,a2,c1,4e)) return 1;
	if (inName==HX_("Constructor",da,c4,f7,7b)) return 1;
	if (inName==HX_("Continue",87,9c,7a,0b)) return 0;
	if (inName==HX_("Divide",99,a3,a6,f3)) return 2;
	if (inName==HX_("Else",d9,10,ee,2d)) return 0;
	if (inName==HX_("End",bb,bb,34,00)) return 0;
	if (inName==HX_("ForStatement",06,54,ec,5d)) return 3;
	if (inName==HX_("FunctionC",0b,ea,d5,55)) return 1;
	if (inName==HX_("IfStatement",72,d0,12,3f)) return 1;
	if (inName==HX_("MainMethod",1a,18,b8,55)) return 0;
	if (inName==HX_("Method",01,6b,ef,3d)) return 2;
	if (inName==HX_("Multiply",44,9e,3e,74)) return 2;
	if (inName==HX_("New",40,88,3b,00)) return 2;
	if (inName==HX_("Print",0d,c8,b8,5b)) return 1;
	if (inName==HX_("Property",75,04,ea,85)) return 2;
	if (inName==HX_("Return",d0,18,c2,3d)) return 1;
	if (inName==HX_("Stop",22,1c,35,37)) return 0;
	if (inName==HX_("Subtract",34,31,c3,d1)) return 2;
	if (inName==HX_("Super",5b,71,ed,17)) return 1;
	if (inName==HX_("Throw",06,cd,bd,a2)) return 1;
	if (inName==HX_("Try",1b,21,40,00)) return 0;
	if (inName==HX_("Use",27,e4,40,00)) return 1;
	if (inName==HX_("Variable",5c,ce,be,42)) return 2;
	return super::__FindArgCount(inName);
}

::hx::Val BToken_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("Add",01,aa,31,00)) return Add_dyn();
	if (inName==HX_("Array",79,dd,bc,b8)) return Array_dyn();
	if (inName==HX_("Catch",1b,ec,4e,d4)) return Catch_dyn();
	if (inName==HX_("Comment",3f,a2,c1,4e)) return Comment_dyn();
	if (inName==HX_("Constructor",da,c4,f7,7b)) return Constructor_dyn();
	if (inName==HX_("Continue",87,9c,7a,0b)) return Continue;
	if (inName==HX_("Divide",99,a3,a6,f3)) return Divide_dyn();
	if (inName==HX_("Else",d9,10,ee,2d)) return Else;
	if (inName==HX_("End",bb,bb,34,00)) return End;
	if (inName==HX_("ForStatement",06,54,ec,5d)) return ForStatement_dyn();
	if (inName==HX_("FunctionC",0b,ea,d5,55)) return FunctionC_dyn();
	if (inName==HX_("IfStatement",72,d0,12,3f)) return IfStatement_dyn();
	if (inName==HX_("MainMethod",1a,18,b8,55)) return MainMethod;
	if (inName==HX_("Method",01,6b,ef,3d)) return Method_dyn();
	if (inName==HX_("Multiply",44,9e,3e,74)) return Multiply_dyn();
	if (inName==HX_("New",40,88,3b,00)) return New_dyn();
	if (inName==HX_("Print",0d,c8,b8,5b)) return Print_dyn();
	if (inName==HX_("Property",75,04,ea,85)) return Property_dyn();
	if (inName==HX_("Return",d0,18,c2,3d)) return Return_dyn();
	if (inName==HX_("Stop",22,1c,35,37)) return Stop;
	if (inName==HX_("Subtract",34,31,c3,d1)) return Subtract_dyn();
	if (inName==HX_("Super",5b,71,ed,17)) return Super_dyn();
	if (inName==HX_("Throw",06,cd,bd,a2)) return Throw_dyn();
	if (inName==HX_("Try",1b,21,40,00)) return Try;
	if (inName==HX_("Use",27,e4,40,00)) return Use_dyn();
	if (inName==HX_("Variable",5c,ce,be,42)) return Variable_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String BToken_obj_sStaticFields[] = {
	HX_("Method",01,6b,ef,3d),
	HX_("MainMethod",1a,18,b8,55),
	HX_("Array",79,dd,bc,b8),
	HX_("Variable",5c,ce,be,42),
	HX_("ForStatement",06,54,ec,5d),
	HX_("IfStatement",72,d0,12,3f),
	HX_("Use",27,e4,40,00),
	HX_("Add",01,aa,31,00),
	HX_("Subtract",34,31,c3,d1),
	HX_("Multiply",44,9e,3e,74),
	HX_("Divide",99,a3,a6,f3),
	HX_("End",bb,bb,34,00),
	HX_("Try",1b,21,40,00),
	HX_("Catch",1b,ec,4e,d4),
	HX_("Continue",87,9c,7a,0b),
	HX_("Stop",22,1c,35,37),
	HX_("Property",75,04,ea,85),
	HX_("Print",0d,c8,b8,5b),
	HX_("Return",d0,18,c2,3d),
	HX_("Comment",3f,a2,c1,4e),
	HX_("Throw",06,cd,bd,a2),
	HX_("New",40,88,3b,00),
	HX_("Constructor",da,c4,f7,7b),
	HX_("Else",d9,10,ee,2d),
	HX_("FunctionC",0b,ea,d5,55),
	HX_("Super",5b,71,ed,17),
	::String(null())
};

::hx::Class BToken_obj::__mClass;

Dynamic __Create_BToken_obj() { return new BToken_obj; }

void BToken_obj::__register()
{

::hx::Static(__mClass) = ::hx::_hx_RegisterClass(HX_("blue.BToken",ab,be,8d,f1), ::hx::TCanCast< BToken_obj >,BToken_obj_sStaticFields,0,
	&__Create_BToken_obj, &__Create,
	&super::__SGetClass(), &CreateBToken_obj, 0
#ifdef HXCPP_VISIT_ALLOCS
    , 0
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
	__mClass->mGetStaticField = &BToken_obj::__GetStatic;
}

void BToken_obj::__boot()
{
Continue = ::hx::CreateConstEnum< BToken_obj >(HX_("Continue",87,9c,7a,0b),14);
Else = ::hx::CreateConstEnum< BToken_obj >(HX_("Else",d9,10,ee,2d),23);
End = ::hx::CreateConstEnum< BToken_obj >(HX_("End",bb,bb,34,00),11);
MainMethod = ::hx::CreateConstEnum< BToken_obj >(HX_("MainMethod",1a,18,b8,55),1);
Stop = ::hx::CreateConstEnum< BToken_obj >(HX_("Stop",22,1c,35,37),15);
Try = ::hx::CreateConstEnum< BToken_obj >(HX_("Try",1b,21,40,00),12);
}


} // end namespace blue
