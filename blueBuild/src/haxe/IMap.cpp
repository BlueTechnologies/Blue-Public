#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif

namespace haxe{


::hx::Class IMap_obj::__mClass;

void IMap_obj::__register()
{
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("haxe.IMap",1b,07,35,eb);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TIsInterface< (int)0x09c2bd39 >;
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace haxe
