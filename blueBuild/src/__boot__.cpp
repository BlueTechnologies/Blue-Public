#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Encoding
#include <haxe/io/Encoding.h>
#endif
#ifndef INCLUDED_blue_BToken
#include <blue/BToken.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif
#ifndef INCLUDED_blue_Blue
#include <blue/Blue.h>
#endif
#ifndef INCLUDED_blue_BLexer
#include <blue/BLexer.h>
#endif
#ifndef INCLUDED_blue_BHaxeUtil
#include <blue/BHaxeUtil.h>
#endif
#ifndef INCLUDED_haxe_SysTools
#include <haxe/SysTools.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_haxe_iterators_ArrayIterator
#include <haxe/iterators/ArrayIterator.h>
#endif
#ifndef INCLUDED_haxe_io_Path
#include <haxe/io/Path.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_format_JsonPrinter
#include <haxe/format/JsonPrinter.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
#ifndef INCLUDED_haxe_exceptions_NotImplementedException
#include <haxe/exceptions/NotImplementedException.h>
#endif
#ifndef INCLUDED_haxe_exceptions_PosException
#include <haxe/exceptions/PosException.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_ValueException
#include <haxe/ValueException.h>
#endif
#ifndef INCLUDED_haxe_NativeStackTrace
#include <haxe/NativeStackTrace.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_blue_BParser
#include <blue/BParser.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Date
#include <Date.h>
#endif

void __files__boot();

void __boot_all()
{
__files__boot();
::hx::RegisterResources( ::hx::GetResources() );
::haxe::io::Error_obj::__register();
::haxe::io::Encoding_obj::__register();
::blue::BToken_obj::__register();
::ValueType_obj::__register();
::blue::Blue_obj::__register();
::blue::BLexer_obj::__register();
::blue::BHaxeUtil_obj::__register();
::haxe::SysTools_obj::__register();
::sys::io::FileOutput_obj::__register();
::sys::io::File_obj::__register();
::sys::FileSystem_obj::__register();
::haxe::iterators::ArrayIterator_obj::__register();
::haxe::io::Path_obj::__register();
::haxe::io::Output_obj::__register();
::haxe::io::Bytes_obj::__register();
::haxe::format::JsonPrinter_obj::__register();
::haxe::format::JsonParser_obj::__register();
::haxe::exceptions::NotImplementedException_obj::__register();
::haxe::exceptions::PosException_obj::__register();
::haxe::ds::StringMap_obj::__register();
::haxe::ValueException_obj::__register();
::haxe::NativeStackTrace_obj::__register();
::haxe::Exception_obj::__register();
::haxe::IMap_obj::__register();
::blue::BParser_obj::__register();
::Type_obj::__register();
::Sys_obj::__register();
::StringTools_obj::__register();
::StringBuf_obj::__register();
::Std_obj::__register();
::Reflect_obj::__register();
::EReg_obj::__register();
::Date_obj::__register();
::haxe::io::Error_obj::__boot();
::haxe::io::Encoding_obj::__boot();
::blue::BToken_obj::__boot();
::ValueType_obj::__boot();
::haxe::SysTools_obj::__boot();
::blue::BHaxeUtil_obj::__boot();
::blue::BLexer_obj::__boot();
::blue::Blue_obj::__boot();
}

