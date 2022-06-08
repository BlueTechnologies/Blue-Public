#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Encoding
#include <haxe/io/Encoding.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_57691c97f4384ed7_30_getContent,"sys.io.File","getContent",0xb28b4a0e,"sys.io.File.getContent","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/io/File.hx",30,0xd489c8a1)
HX_LOCAL_STACK_FRAME(_hx_pos_57691c97f4384ed7_38_saveContent,"sys.io.File","saveContent",0xa5557651,"sys.io.File.saveContent","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/io/File.hx",38,0xd489c8a1)
HX_LOCAL_STACK_FRAME(_hx_pos_57691c97f4384ed7_55_write,"sys.io.File","write",0xfec8a9f4,"sys.io.File.write","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/io/File.hx",55,0xd489c8a1)
namespace sys{
namespace io{

void File_obj::__construct() { }

Dynamic File_obj::__CreateEmpty() { return new File_obj; }

void *File_obj::_hx_vtable = 0;

Dynamic File_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< File_obj > _hx_result = new File_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool File_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x645a6147;
}

::String File_obj::getContent(::String path){
            	HX_STACKFRAME(&_hx_pos_57691c97f4384ed7_30_getContent)
HXDLIN(  30)		return _hx_std_file_contents_string(path);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(File_obj,getContent,return )

void File_obj::saveContent(::String path,::String content){
            	HX_STACKFRAME(&_hx_pos_57691c97f4384ed7_38_saveContent)
HXLINE(  39)		 ::sys::io::FileOutput f = ::sys::io::File_obj::write(path,null());
HXLINE(  40)		f->writeString(content,null());
HXLINE(  41)		f->close();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,saveContent,(void))

 ::sys::io::FileOutput File_obj::write(::String path,::hx::Null< bool >  __o_binary){
            		bool binary = __o_binary.Default(true);
            	HX_GC_STACKFRAME(&_hx_pos_57691c97f4384ed7_55_write)
HXDLIN(  55)		::String _hx_tmp;
HXDLIN(  55)		if (binary) {
HXDLIN(  55)			_hx_tmp = HX_("wb",0b,68,00,00);
            		}
            		else {
HXDLIN(  55)			_hx_tmp = HX_("w",77,00,00,00);
            		}
HXDLIN(  55)		return  ::sys::io::FileOutput_obj::__alloc( HX_CTX ,_hx_std_file_open(path,_hx_tmp));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,write,return )


File_obj::File_obj()
{
}

bool File_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"write") ) { outValue = write_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getContent") ) { outValue = getContent_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"saveContent") ) { outValue = saveContent_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *File_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *File_obj_sStaticStorageInfo = 0;
#endif

::hx::Class File_obj::__mClass;

static ::String File_obj_sStaticFields[] = {
	HX_("getContent",43,13,d9,68),
	HX_("saveContent",7c,bb,17,73),
	HX_("write",df,6c,59,d0),
	::String(null())
};

void File_obj::__register()
{
	File_obj _hx_dummy;
	File_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("sys.io.File",c3,ef,8d,eb);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &File_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(File_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< File_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = File_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = File_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace sys
} // end namespace io
