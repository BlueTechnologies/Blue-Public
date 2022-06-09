#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_blue_BHaxeUtil
#include <blue/BHaxeUtil.h>
#endif
#ifndef INCLUDED_blue_BLexer
#include <blue/BLexer.h>
#endif
#ifndef INCLUDED_blue_Blue
#include <blue/Blue.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_27_main,"blue.Blue","main",0x10d2a799,"blue.Blue.main","blue/Blue.hx",27,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_30_mapSource,"blue.Blue","mapSource",0x0a64e137,"blue.Blue.mapSource","blue/Blue.hx",30,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_63_mapFile,"blue.Blue","mapFile",0x73deefd8,"blue.Blue.mapFile","blue/Blue.hx",63,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_67_lexSourceFile,"blue.Blue","lexSourceFile",0xd6b8d656,"blue.Blue.lexSourceFile","blue/Blue.hx",67,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_70_checkForErrors,"blue.Blue","checkForErrors",0xc9b7810c,"blue.Blue.checkForErrors","blue/Blue.hx",70,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_12_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",12,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_13_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",13,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_14_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",14,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_16_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",16,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_17_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",17,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_19_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",19,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_21_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",21,0xac82a48f)
static const ::String _hx_array_data_ed6e2d0e_17[] = {
	HX_("method",e1,f6,5a,09),HX_("loop",64,a6,b7,47),HX_("if",dd,5b,00,00),HX_("+",2b,00,00,00),HX_("-",2d,00,00,00),HX_("mult",f0,67,65,48),HX_("div",51,3d,4c,00),HX_("end",db,03,4d,00),HX_("otherwise",f4,83,f2,9a),HX_("stop",02,f0,5b,4c),HX_("continue",67,e0,c8,31),HX_("then",dd,02,fc,4c),HX_("not",13,d9,53,00),HX_("=",3d,00,00,00),HX_("use",47,2c,59,00),HX_("try",3b,69,58,00),HX_("catch",3b,7c,21,41),HX_("print",2d,58,8b,c8),HX_("return",b0,a4,2d,09),HX_("***",6a,03,20,00),HX_("main method()",e9,ec,13,c5),HX_("throw",26,5d,90,0f),HX_("new",60,d0,53,00),HX_("constructor method()",08,d8,4a,0a),HX_("or",23,61,00,00),
};
namespace blue{

void Blue_obj::__construct() { }

Dynamic Blue_obj::__CreateEmpty() { return new Blue_obj; }

void *Blue_obj::_hx_vtable = 0;

Dynamic Blue_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Blue_obj > _hx_result = new Blue_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Blue_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x00065654;
}

::Array< ::String > Blue_obj::currentMappedFiles;

::Array< ::Dynamic> Blue_obj::currentMappedLines;

::String Blue_obj::directory;

::String Blue_obj::mainFile;

::Array< ::String > Blue_obj::libs;

::String Blue_obj::buildCommand;

::Array< ::String > Blue_obj::completeSyntax;

void Blue_obj::main(){
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_27_main)
HXDLIN(  27)		::blue::Blue_obj::mapSource(::Sys_obj::getCwd());
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Blue_obj,main,(void))

void Blue_obj::mapSource(::String directory){
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_30_mapSource)
HXLINE(  31)		::blue::Blue_obj::directory = directory;
HXLINE(  32)		int i = 0;
HXLINE(  33)		::Array< ::String > files = ::Array_obj< ::String >::__new(0);
HXLINE(  34)		bool _hx_tmp;
HXDLIN(  34)		if (::sys::FileSystem_obj::exists(directory)) {
HXLINE(  34)			_hx_tmp = ::sys::FileSystem_obj::isDirectory(directory);
            		}
            		else {
HXLINE(  34)			_hx_tmp = false;
            		}
HXDLIN(  34)		if (_hx_tmp) {
HXLINE(  35)			::Sys_obj::println((HX_("Compiling source folder: ",e9,e1,f0,0b) + directory));
HXLINE(  36)			{
HXLINE(  36)				int _g = 0;
HXDLIN(  36)				::Array< ::String > _g1 = ::sys::FileSystem_obj::readDirectory(directory);
HXDLIN(  36)				while((_g < _g1->length)){
HXLINE(  36)					::String file = _g1->__get(_g);
HXDLIN(  36)					_g = (_g + 1);
HXLINE(  37)					bool _hx_tmp;
HXDLIN(  37)					bool _hx_tmp1;
HXDLIN(  37)					bool _hx_tmp2;
HXDLIN(  37)					if (!(::sys::FileSystem_obj::isDirectory(file))) {
HXLINE(  37)						_hx_tmp2 = ::StringTools_obj::endsWith(file,HX_(".bl",78,3d,23,00));
            					}
            					else {
HXLINE(  37)						_hx_tmp2 = false;
            					}
HXDLIN(  37)					if (!(_hx_tmp2)) {
HXLINE(  37)						_hx_tmp1 = ::StringTools_obj::endsWith(file,HX_(".xml",69,3e,c3,1e));
            					}
            					else {
HXLINE(  37)						_hx_tmp1 = true;
            					}
HXDLIN(  37)					if (!(_hx_tmp1)) {
HXLINE(  37)						_hx_tmp = ::StringTools_obj::endsWith(file,HX_(".json",56,f1,d6,c2));
            					}
            					else {
HXLINE(  37)						_hx_tmp = true;
            					}
HXDLIN(  37)					if (_hx_tmp) {
HXLINE(  38)						i = (i + 1);
HXLINE(  39)						files->push(file);
HXLINE(  40)						::Sys_obj::println(file);
HXLINE(  41)						if (!(::blue::Blue_obj::checkForErrors(::sys::io::File_obj::getContent(((directory + HX_("/",2f,00,00,00)) + file))))) {
HXLINE(  42)							::String rawContent = ::sys::io::File_obj::getContent(((directory + HX_("/",2f,00,00,00)) + file));
HXLINE(  43)							::blue::Blue_obj::mapFile(((directory + HX_("/",2f,00,00,00)) + file));
HXLINE(  44)							::blue::BHaxeUtil_obj::fileName = file;
HXLINE(  45)							::blue::Blue_obj::lexSourceFile(rawContent);
HXLINE(  46)							if ((i == files->length)) {
HXLINE(  47)								bool _hx_tmp;
HXDLIN(  47)								if (::hx::IsNotNull( ::blue::Blue_obj::libs )) {
HXLINE(  47)									_hx_tmp = (::blue::Blue_obj::buildCommand == HX_("haxe -cp src --main export.hxsrc.Main --cpp export/bin",27,fb,f9,49));
            								}
            								else {
HXLINE(  47)									_hx_tmp = false;
            								}
HXDLIN(  47)								if (_hx_tmp) {
HXLINE(  48)									::blue::Blue_obj::buildCommand = ((HX_("haxe -cp src --main export.hxsrc --library ",60,2c,8a,c8) + ::blue::Blue_obj::libs->join(HX_(" --library",7b,a7,0c,6b))) + HX_(" --cpp export/bin",c9,2e,e9,89));
            								}
HXLINE(  50)								::Sys_obj::command(::blue::Blue_obj::buildCommand,null());
HXLINE(  51)								::Sys_obj::exit(0);
            							}
            						}
            					}
            				}
            			}
            		}
            		else {
HXLINE(  58)			::Sys_obj::println(((HX_("Error: Source folder '",6c,fd,d1,da) + directory) + HX_("' does not exist or is not a directory",84,e6,8a,70)));
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Blue_obj,mapSource,(void))

void Blue_obj::mapFile(::String input){
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_63_mapFile)
HXDLIN(  63)		::blue::Blue_obj::currentMappedFiles->push(input);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Blue_obj,mapFile,(void))

void Blue_obj::lexSourceFile(::String content){
            	HX_GC_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_67_lexSourceFile)
HXDLIN(  67)		 ::blue::BLexer_obj::__alloc( HX_CTX ,content);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Blue_obj,lexSourceFile,(void))

bool Blue_obj::checkForErrors(::String input){
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_70_checkForErrors)
HXLINE(  71)		if ((input.indexOf(HX_("\n",0a,00,00,00),null()) != -1)) {
HXLINE(  72)			{
HXLINE(  72)				int _g = 0;
HXDLIN(  72)				int _g1 = input.split(HX_("\n",0a,00,00,00))->length;
HXDLIN(  72)				while((_g < _g1)){
HXLINE(  72)					_g = (_g + 1);
HXDLIN(  72)					int i = (_g - 1);
HXLINE(  73)					::String line = input.split(HX_("\n",0a,00,00,00))->__get(i);
HXLINE(  74)					::String letters = HX_("abcdefghijklmnopqrstuvwusyz",2b,b6,72,75);
HXLINE(  75)					::String chars = HX_("#$%^&_{}:><?|;",db,c5,59,e6);
HXLINE(  76)					bool _hx_tmp;
HXDLIN(  76)					if ((line.indexOf(HX_("if",dd,5b,00,00),null()) != -1)) {
HXLINE(  76)						_hx_tmp = (line.indexOf(HX_("then",dd,02,fc,4c),null()) == -1);
            					}
            					else {
HXLINE(  76)						_hx_tmp = false;
            					}
HXDLIN(  76)					if (_hx_tmp) {
HXLINE(  77)						::Sys_obj::println((HX_("Error: Expected 'then' at the end of line ",21,d7,11,f7) + i));
HXLINE(  78)						return true;
            					}
            					else {
HXLINE(  80)						{
HXLINE(  80)							int _g = 0;
HXDLIN(  80)							int _g1 = letters.split(HX_("",00,00,00,00))->length;
HXDLIN(  80)							while((_g < _g1)){
HXLINE(  80)								_g = (_g + 1);
HXDLIN(  80)								int k = (_g - 1);
HXLINE(  81)								{
HXLINE(  81)									int _g1 = 0;
HXDLIN(  81)									int _g2 = ::blue::Blue_obj::completeSyntax->length;
HXDLIN(  81)									while((_g1 < _g2)){
HXLINE(  81)										_g1 = (_g1 + 1);
HXDLIN(  81)										int l = (_g1 - 1);
HXLINE(  82)										bool _hx_tmp;
HXDLIN(  82)										bool _hx_tmp1;
HXDLIN(  82)										bool _hx_tmp2;
HXDLIN(  82)										bool _hx_tmp3;
HXDLIN(  82)										bool _hx_tmp4;
HXDLIN(  82)										bool _hx_tmp5;
HXDLIN(  82)										bool _hx_tmp6;
HXDLIN(  82)										bool _hx_tmp7;
HXDLIN(  82)										bool _hx_tmp8;
HXDLIN(  82)										bool _hx_tmp9;
HXDLIN(  82)										bool _hx_tmp10;
HXDLIN(  82)										bool _hx_tmp11;
HXDLIN(  82)										bool _hx_tmp12;
HXDLIN(  82)										bool _hx_tmp13;
HXDLIN(  82)										bool _hx_tmp14;
HXDLIN(  82)										bool _hx_tmp15;
HXDLIN(  82)										bool _hx_tmp16;
HXDLIN(  82)										bool _hx_tmp17;
HXDLIN(  82)										if ((line.indexOf(letters.split(HX_("",00,00,00,00))->__get(k),null()) != -1)) {
HXLINE(  82)											_hx_tmp17 = (line.indexOf(HX_("=",3d,00,00,00),null()) != -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp17 = false;
            										}
HXDLIN(  82)										if (_hx_tmp17) {
HXLINE(  82)											_hx_tmp16 = (line.indexOf(HX_("if",dd,5b,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp16 = false;
            										}
HXDLIN(  82)										if (_hx_tmp16) {
HXLINE(  82)											_hx_tmp15 = (line.indexOf(HX_("1",31,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp15 = false;
            										}
HXDLIN(  82)										if (_hx_tmp15) {
HXLINE(  82)											_hx_tmp14 = (line.indexOf(HX_("2",32,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp14 = false;
            										}
HXDLIN(  82)										if (_hx_tmp14) {
HXLINE(  82)											_hx_tmp13 = (line.indexOf(HX_("3",33,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp13 = false;
            										}
HXDLIN(  82)										if (_hx_tmp13) {
HXLINE(  82)											_hx_tmp12 = (line.indexOf(HX_("4",34,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp12 = false;
            										}
HXDLIN(  82)										if (_hx_tmp12) {
HXLINE(  82)											_hx_tmp11 = (line.indexOf(HX_("5",35,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp11 = false;
            										}
HXDLIN(  82)										if (_hx_tmp11) {
HXLINE(  82)											_hx_tmp10 = (line.indexOf(HX_("6",36,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp10 = false;
            										}
HXDLIN(  82)										if (_hx_tmp10) {
HXLINE(  82)											_hx_tmp9 = (line.indexOf(HX_("7",37,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp9 = false;
            										}
HXDLIN(  82)										if (_hx_tmp9) {
HXLINE(  82)											_hx_tmp8 = (line.indexOf(HX_("8",38,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp8 = false;
            										}
HXDLIN(  82)										if (_hx_tmp8) {
HXLINE(  82)											_hx_tmp7 = (line.indexOf(HX_("9",39,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp7 = false;
            										}
HXDLIN(  82)										if (_hx_tmp7) {
HXLINE(  82)											_hx_tmp6 = (line.indexOf(HX_("true",4e,a7,03,4d),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp6 = false;
            										}
HXDLIN(  82)										if (_hx_tmp6) {
HXLINE(  82)											_hx_tmp5 = (line.indexOf(HX_("false",a3,35,4f,fb),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp5 = false;
            										}
HXDLIN(  82)										if (_hx_tmp5) {
HXLINE(  82)											_hx_tmp4 = (line.indexOf(HX_("'",27,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp4 = false;
            										}
HXDLIN(  82)										if (_hx_tmp4) {
HXLINE(  82)											_hx_tmp3 = (line.indexOf(HX_("\"",22,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp3 = false;
            										}
HXDLIN(  82)										if (_hx_tmp3) {
HXLINE(  82)											_hx_tmp2 = (line.indexOf(HX_("[",5b,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp2 = false;
            										}
HXDLIN(  82)										if (_hx_tmp2) {
HXLINE(  82)											_hx_tmp1 = (line.indexOf(HX_("]",5d,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp1 = false;
            										}
HXDLIN(  82)										if (_hx_tmp1) {
HXLINE(  82)											_hx_tmp = (line.indexOf(HX_("null",87,9e,0e,49),null()) == -1);
            										}
            										else {
HXLINE(  82)											_hx_tmp = false;
            										}
HXDLIN(  82)										if (_hx_tmp) {
HXLINE(  86)											::Sys_obj::println((HX_("Error: Values assigned to variables can only be 'Bool', 'Int', 'Float', 'String', or 'Array', Which was not found at line ",95,91,54,be) + i));
HXLINE(  88)											return true;
            										}
HXLINE(  91)										bool _hx_tmp18;
HXDLIN(  91)										bool _hx_tmp19;
HXDLIN(  91)										bool _hx_tmp20;
HXDLIN(  91)										bool _hx_tmp21;
HXDLIN(  91)										bool _hx_tmp22;
HXDLIN(  91)										bool _hx_tmp23;
HXDLIN(  91)										bool _hx_tmp24;
HXDLIN(  91)										bool _hx_tmp25;
HXDLIN(  91)										bool _hx_tmp26;
HXDLIN(  91)										bool _hx_tmp27;
HXDLIN(  91)										bool _hx_tmp28;
HXDLIN(  91)										bool _hx_tmp29;
HXDLIN(  91)										bool _hx_tmp30;
HXDLIN(  91)										bool _hx_tmp31;
HXDLIN(  91)										bool _hx_tmp32;
HXDLIN(  91)										bool _hx_tmp33;
HXDLIN(  91)										bool _hx_tmp34;
HXDLIN(  91)										bool _hx_tmp35;
HXDLIN(  91)										bool _hx_tmp36;
HXDLIN(  91)										bool _hx_tmp37;
HXDLIN(  91)										if ((line.indexOf(letters.split(HX_("",00,00,00,00))->__get(k),null()) != -1)) {
HXLINE(  91)											_hx_tmp37 = (line.indexOf(HX_("if",dd,5b,00,00),null()) != -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp37 = false;
            										}
HXDLIN(  91)										if (_hx_tmp37) {
HXLINE(  91)											_hx_tmp36 = (line.indexOf(HX_("1",31,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp36 = false;
            										}
HXDLIN(  91)										if (_hx_tmp36) {
HXLINE(  91)											_hx_tmp35 = (line.indexOf(HX_("2",32,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp35 = false;
            										}
HXDLIN(  91)										if (_hx_tmp35) {
HXLINE(  91)											_hx_tmp34 = (line.indexOf(HX_("3",33,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp34 = false;
            										}
HXDLIN(  91)										if (_hx_tmp34) {
HXLINE(  91)											_hx_tmp33 = (line.indexOf(HX_("4",34,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp33 = false;
            										}
HXDLIN(  91)										if (_hx_tmp33) {
HXLINE(  91)											_hx_tmp32 = (line.indexOf(HX_("5",35,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp32 = false;
            										}
HXDLIN(  91)										if (_hx_tmp32) {
HXLINE(  91)											_hx_tmp31 = (line.indexOf(HX_("6",36,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp31 = false;
            										}
HXDLIN(  91)										if (_hx_tmp31) {
HXLINE(  91)											_hx_tmp30 = (line.indexOf(HX_("7",37,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp30 = false;
            										}
HXDLIN(  91)										if (_hx_tmp30) {
HXLINE(  91)											_hx_tmp29 = (line.indexOf(HX_("8",38,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp29 = false;
            										}
HXDLIN(  91)										if (_hx_tmp29) {
HXLINE(  91)											_hx_tmp28 = (line.indexOf(HX_("9",39,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp28 = false;
            										}
HXDLIN(  91)										if (_hx_tmp28) {
HXLINE(  91)											_hx_tmp27 = (line.indexOf(HX_("true",4e,a7,03,4d),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp27 = false;
            										}
HXDLIN(  91)										if (_hx_tmp27) {
HXLINE(  91)											_hx_tmp26 = (line.indexOf(HX_("false",a3,35,4f,fb),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp26 = false;
            										}
HXDLIN(  91)										if (_hx_tmp26) {
HXLINE(  91)											_hx_tmp25 = (line.indexOf(HX_("'",27,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp25 = false;
            										}
HXDLIN(  91)										if (_hx_tmp25) {
HXLINE(  91)											_hx_tmp24 = (line.indexOf(HX_("\"",22,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp24 = false;
            										}
HXDLIN(  91)										if (_hx_tmp24) {
HXLINE(  91)											_hx_tmp23 = (line.indexOf(HX_("=",3d,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp23 = false;
            										}
HXDLIN(  91)										if (_hx_tmp23) {
HXLINE(  91)											_hx_tmp22 = (line.indexOf(HX_("greater than",47,34,3c,43),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp22 = false;
            										}
HXDLIN(  91)										if (_hx_tmp22) {
HXLINE(  91)											_hx_tmp21 = (line.indexOf(HX_("less than",88,b9,bc,f1),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp21 = false;
            										}
HXDLIN(  91)										if (_hx_tmp21) {
HXLINE(  91)											_hx_tmp20 = (line.indexOf(HX_("div",51,3d,4c,00),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp20 = false;
            										}
HXDLIN(  91)										if (_hx_tmp20) {
HXLINE(  91)											_hx_tmp19 = (line.indexOf(HX_("mult",f0,67,65,48),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp19 = false;
            										}
HXDLIN(  91)										if (_hx_tmp19) {
HXLINE(  91)											_hx_tmp18 = (line.indexOf(HX_("null",87,9e,0e,49),null()) == -1);
            										}
            										else {
HXLINE(  91)											_hx_tmp18 = false;
            										}
HXDLIN(  91)										if (_hx_tmp18) {
HXLINE(  96)											::Sys_obj::println((HX_("Error: A valid 'if' condition was not found at line ",92,e4,43,51) + i));
HXLINE(  97)											return true;
            										}
HXLINE( 100)										bool _hx_tmp38;
HXDLIN( 100)										bool _hx_tmp39;
HXDLIN( 100)										bool _hx_tmp40;
HXDLIN( 100)										bool _hx_tmp41;
HXDLIN( 100)										bool _hx_tmp42;
HXDLIN( 100)										bool _hx_tmp43;
HXDLIN( 100)										bool _hx_tmp44;
HXDLIN( 100)										bool _hx_tmp45;
HXDLIN( 100)										bool _hx_tmp46;
HXDLIN( 100)										bool _hx_tmp47;
HXDLIN( 100)										bool _hx_tmp48;
HXDLIN( 100)										bool _hx_tmp49;
HXDLIN( 100)										bool _hx_tmp50;
HXDLIN( 100)										bool _hx_tmp51;
HXDLIN( 100)										bool _hx_tmp52;
HXDLIN( 100)										bool _hx_tmp53;
HXDLIN( 100)										bool _hx_tmp54;
HXDLIN( 100)										bool _hx_tmp55;
HXDLIN( 100)										bool _hx_tmp56;
HXDLIN( 100)										bool _hx_tmp57;
HXDLIN( 100)										bool _hx_tmp58;
HXDLIN( 100)										bool _hx_tmp59;
HXDLIN( 100)										if ((line.indexOf(letters.split(HX_("",00,00,00,00))->__get(k),null()) != -1)) {
HXLINE( 100)											_hx_tmp59 = (line.indexOf(HX_("loop",64,a6,b7,47),null()) != -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp59 = false;
            										}
HXDLIN( 100)										if (_hx_tmp59) {
HXLINE( 100)											_hx_tmp58 = (line.indexOf(HX_("1",31,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp58 = false;
            										}
HXDLIN( 100)										if (_hx_tmp58) {
HXLINE( 100)											_hx_tmp57 = (line.indexOf(HX_("2",32,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp57 = false;
            										}
HXDLIN( 100)										if (_hx_tmp57) {
HXLINE( 100)											_hx_tmp56 = (line.indexOf(HX_("3",33,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp56 = false;
            										}
HXDLIN( 100)										if (_hx_tmp56) {
HXLINE( 100)											_hx_tmp55 = (line.indexOf(HX_("4",34,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp55 = false;
            										}
HXDLIN( 100)										if (_hx_tmp55) {
HXLINE( 100)											_hx_tmp54 = (line.indexOf(HX_("5",35,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp54 = false;
            										}
HXDLIN( 100)										if (_hx_tmp54) {
HXLINE( 100)											_hx_tmp53 = (line.indexOf(HX_("6",36,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp53 = false;
            										}
HXDLIN( 100)										if (_hx_tmp53) {
HXLINE( 100)											_hx_tmp52 = (line.indexOf(HX_("7",37,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp52 = false;
            										}
HXDLIN( 100)										if (_hx_tmp52) {
HXLINE( 100)											_hx_tmp51 = (line.indexOf(HX_("8",38,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp51 = false;
            										}
HXDLIN( 100)										if (_hx_tmp51) {
HXLINE( 100)											_hx_tmp50 = (line.indexOf(HX_("9",39,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp50 = false;
            										}
HXDLIN( 100)										if (_hx_tmp50) {
HXLINE( 100)											_hx_tmp49 = (line.indexOf(HX_("true",4e,a7,03,4d),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp49 = false;
            										}
HXDLIN( 100)										if (_hx_tmp49) {
HXLINE( 100)											_hx_tmp48 = (line.indexOf(HX_("false",a3,35,4f,fb),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp48 = false;
            										}
HXDLIN( 100)										if (_hx_tmp48) {
HXLINE( 100)											_hx_tmp47 = (line.indexOf(HX_("'",27,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp47 = false;
            										}
HXDLIN( 100)										if (_hx_tmp47) {
HXLINE( 100)											_hx_tmp46 = (line.indexOf(HX_("\"",22,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp46 = false;
            										}
HXDLIN( 100)										if (_hx_tmp46) {
HXLINE( 100)											_hx_tmp45 = (line.indexOf(HX_("=",3d,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp45 = false;
            										}
HXDLIN( 100)										if (_hx_tmp45) {
HXLINE( 100)											_hx_tmp44 = (line.indexOf(HX_("greater than",47,34,3c,43),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp44 = false;
            										}
HXDLIN( 100)										if (_hx_tmp44) {
HXLINE( 100)											_hx_tmp43 = (line.indexOf(HX_("less than",88,b9,bc,f1),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp43 = false;
            										}
HXDLIN( 100)										if (_hx_tmp43) {
HXLINE( 100)											_hx_tmp42 = (line.indexOf(HX_("div",51,3d,4c,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp42 = false;
            										}
HXDLIN( 100)										if (_hx_tmp42) {
HXLINE( 100)											_hx_tmp41 = (line.indexOf(HX_("mult",f0,67,65,48),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp41 = false;
            										}
HXDLIN( 100)										if (_hx_tmp41) {
HXLINE( 100)											_hx_tmp40 = (line.indexOf(HX_("until",9e,b8,ef,a6),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp40 = false;
            										}
HXDLIN( 100)										if (_hx_tmp40) {
HXLINE( 100)											_hx_tmp39 = (line.indexOf(HX_("in",e5,5b,00,00),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp39 = false;
            										}
HXDLIN( 100)										if (_hx_tmp39) {
HXLINE( 100)											_hx_tmp38 = (line.indexOf(HX_("null",87,9e,0e,49),null()) == -1);
            										}
            										else {
HXLINE( 100)											_hx_tmp38 = false;
            										}
HXDLIN( 100)										if (_hx_tmp38) {
HXLINE( 105)											::Sys_obj::println((HX_("Error: A valid 'loop' expression was not found at line ",76,ba,74,5a) + i));
HXLINE( 106)											return true;
            										}
            									}
            								}
            							}
            						}
HXLINE( 110)						{
HXLINE( 110)							int _g2 = 0;
HXDLIN( 110)							int _g3 = chars.split(HX_("",00,00,00,00))->length;
HXDLIN( 110)							while((_g2 < _g3)){
HXLINE( 110)								_g2 = (_g2 + 1);
HXDLIN( 110)								int n = (_g2 - 1);
HXLINE( 111)								bool _hx_tmp;
HXDLIN( 111)								if ((line.indexOf(chars.split(HX_("",00,00,00,00))->__get(n),null()) != -1)) {
HXLINE( 111)									::String s = ::blue::Blue_obj::completeSyntax->__get(i);
HXDLIN( 111)									_hx_tmp = (s.indexOf(chars.split(HX_("",00,00,00,00))->__get(n),null()) == -1);
            								}
            								else {
HXLINE( 111)									_hx_tmp = false;
            								}
HXDLIN( 111)								if (_hx_tmp) {
HXLINE( 112)									::Sys_obj::println((((HX_("Error: Unknown character: ",4b,01,29,5a) + chars.split(HX_("",00,00,00,00))->__get(n)) + HX_(" at line ",df,96,71,22)) + i));
HXLINE( 113)									return true;
            								}
            							}
            						}
            					}
HXLINE( 118)					bool _hx_tmp1;
HXDLIN( 118)					if ((line.indexOf(HX_("method",e1,f6,5a,09),null()) != -1)) {
HXLINE( 118)						_hx_tmp1 = (line.indexOf(HX_(":",3a,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 118)						_hx_tmp1 = false;
            					}
HXDLIN( 118)					if (_hx_tmp1) {
HXLINE( 119)						::Sys_obj::println(((HX_("Error: Unknown character: ':'",29,6a,5e,80) + HX_(" at line ",df,96,71,22)) + i));
HXLINE( 120)						return true;
            					}
HXLINE( 122)					bool _hx_tmp2;
HXDLIN( 122)					if ((line.indexOf(HX_("(",28,00,00,00),null()) != -1)) {
HXLINE( 122)						_hx_tmp2 = (line.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).indexOf(HX_(",",2c,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 122)						_hx_tmp2 = false;
            					}
HXDLIN( 122)					if (_hx_tmp2) {
HXLINE( 123)						bool _hx_tmp;
HXDLIN( 123)						if ((input.indexOf(::StringTools_obj::replace(line.split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)),null()) != -1)) {
HXLINE( 123)							_hx_tmp = (input.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).indexOf(HX_(",",2c,00,00,00),null()) != -1);
            						}
            						else {
HXLINE( 123)							_hx_tmp = false;
            						}
HXDLIN( 123)						if (_hx_tmp) {
HXLINE( 124)							int _hx_tmp = line.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).split(HX_(",",2c,00,00,00))->length;
HXDLIN( 124)							if ((_hx_tmp > input.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).split(HX_(",",2c,00,00,00))->length)) {
HXLINE( 125)								::Sys_obj::println((((HX_("Error: Too many parameters for method: ",ed,d9,1b,50) + ::StringTools_obj::replace(line.split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_(" at line ",df,96,71,22)) + i));
HXLINE( 126)								return true;
            							}
            							else {
HXLINE( 127)								int _hx_tmp = line.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).split(HX_(",",2c,00,00,00))->length;
HXDLIN( 127)								if ((_hx_tmp < input.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).split(HX_(",",2c,00,00,00))->length)) {
HXLINE( 128)									::Sys_obj::println((((HX_("Error: Not enough parameters for method: ",df,32,a5,55) + ::StringTools_obj::replace(line.split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_(" at line ",df,96,71,22)) + i));
HXLINE( 129)									return true;
            								}
            							}
            						}
            					}
HXLINE( 133)					bool _hx_tmp3;
HXDLIN( 133)					if ((line.indexOf(HX_("new ",c0,83,02,49),null()) != -1)) {
HXLINE( 133)						_hx_tmp3 = ::sys::FileSystem_obj::exists((line.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0) + HX_(".bl",78,3d,23,00)));
            					}
            					else {
HXLINE( 133)						_hx_tmp3 = false;
            					}
HXDLIN( 133)					if (_hx_tmp3) {
HXLINE( 134)						if ((::sys::io::File_obj::getContent((line.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0) + HX_(".bl",78,3d,23,00))).indexOf(HX_("constructor method()",08,d8,4a,0a),null()) == -1)) {
HXLINE( 135)							::Sys_obj::println((((HX_("Error: Source File: ",b9,e3,33,52) + line.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0)) + HX_(" has no constructor method at line ",7f,66,51,a3)) + i));
HXLINE( 136)							return true;
            						}
            					}
HXLINE( 140)					bool _hx_tmp4;
HXDLIN( 140)					if ((line.indexOf(HX_("constructor method()",08,d8,4a,0a),null()) != -1)) {
HXLINE( 140)						_hx_tmp4 = (input.split(HX_("constructor method()",08,d8,4a,0a))->__get(1).split(HX_("end",db,03,4d,00))->__get(0).indexOf(HX_("return ",70,75,c2,fe),null()) != -1);
            					}
            					else {
HXLINE( 140)						_hx_tmp4 = false;
            					}
HXDLIN( 140)					if (_hx_tmp4) {
HXLINE( 141)						::Sys_obj::println((HX_("Error: Constructor methods cannot have a return value at line ",c2,7f,49,19) + i));
HXLINE( 142)						return true;
            					}
HXLINE( 145)					bool _hx_tmp5;
HXDLIN( 145)					if ((line.indexOf(HX_("main method()",e9,ec,13,c5),null()) != -1)) {
HXLINE( 145)						_hx_tmp5 = (input.split(HX_("main method()",e9,ec,13,c5))->__get(1).split(HX_("end",db,03,4d,00))->__get(0).indexOf(HX_("return ",70,75,c2,fe),null()) != -1);
            					}
            					else {
HXLINE( 145)						_hx_tmp5 = false;
            					}
HXDLIN( 145)					if (_hx_tmp5) {
HXLINE( 146)						::Sys_obj::println((HX_("Error: The main method cannot have a return value at line ",af,6d,78,26) + i));
HXLINE( 147)						return true;
            					}
HXLINE( 150)					if ((line.indexOf(HX_("@BuildCommand(",6b,4d,6b,ac),null()) != -1)) {
HXLINE( 151)						::blue::Blue_obj::buildCommand = line.split(HX_("@BuildCommand('",5c,70,78,31))->__get(1).split(HX_("')",22,22,00,00))->__get(0);
HXLINE( 152)						::Sys_obj::println(HX_("Warning: You are using a custom build command! The program is not guaranteed to successfully compile!",c1,eb,da,c1));
HXLINE( 153)						return false;
            					}
HXLINE( 155)					if ((line.indexOf(HX_("@IncludeLib(",2b,6b,ef,da),null()) != -1)) {
HXLINE( 156)						::Array< ::String > _hx_tmp = ::blue::Blue_obj::libs;
HXDLIN( 156)						_hx_tmp->push(line.split(HX_("@IncludeLib('",9c,5a,8e,b6))->__get(1).split(HX_("')",22,22,00,00))->__get(0));
            					}
HXLINE( 167)					if ((line.indexOf(HX_("[0]",48,37,45,00),null()) != -1)) {
HXLINE( 168)						::Sys_obj::println((HX_("Error: Array index's start at '1' at line ",fa,81,14,16) + i));
HXLINE( 169)						return true;
            					}
HXLINE( 172)					bool _hx_tmp6;
HXDLIN( 172)					bool _hx_tmp7;
HXDLIN( 172)					if ((line.indexOf(HX_("method ",1f,0e,3d,26),null()) != -1)) {
HXLINE( 172)						_hx_tmp7 = (line.indexOf(HX_("(",28,00,00,00),null()) == -1);
            					}
            					else {
HXLINE( 172)						_hx_tmp7 = false;
            					}
HXDLIN( 172)					if (_hx_tmp7) {
HXLINE( 172)						_hx_tmp6 = (line.indexOf(HX_(")",29,00,00,00),null()) == -1);
            					}
            					else {
HXLINE( 172)						_hx_tmp6 = false;
            					}
HXDLIN( 172)					if (_hx_tmp6) {
HXLINE( 173)						::Sys_obj::println((((HX_("Error: Method: ",35,c6,b2,e5) + ::StringTools_obj::replace(line.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_("is missing it's parameter brackets at line ",64,00,45,69)) + i));
HXLINE( 175)						return true;
            					}
HXLINE( 178)					bool _hx_tmp8;
HXDLIN( 178)					if ((line.indexOf(HX_("method ",1f,0e,3d,26),null()) != -1)) {
HXLINE( 178)						_hx_tmp8 = (input.split(HX_("method ",1f,0e,3d,26))->__get(1).indexOf(HX_("end",db,03,4d,00),null()) == -1);
            					}
            					else {
HXLINE( 178)						_hx_tmp8 = false;
            					}
HXDLIN( 178)					if (_hx_tmp8) {
HXLINE( 179)						::Sys_obj::println((((HX_("Error: Method: ",35,c6,b2,e5) + ::StringTools_obj::replace(line.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_("is missing it's enclosing 'end' block at line ",cc,be,43,ad)) + i));
HXLINE( 181)						return true;
            					}
HXLINE( 184)					bool _hx_tmp9;
HXDLIN( 184)					if ((line.indexOf(HX_("loop ",3c,f1,f9,78),null()) != -1)) {
HXLINE( 184)						_hx_tmp9 = (input.split(HX_("loop ",3c,f1,f9,78))->__get(1).indexOf(HX_("end",db,03,4d,00),null()) == -1);
            					}
            					else {
HXLINE( 184)						_hx_tmp9 = false;
            					}
HXDLIN( 184)					if (_hx_tmp9) {
HXLINE( 185)						::Sys_obj::println((((HX_("Error: Loop: ",f8,84,61,85) + ::StringTools_obj::replace(line.split(HX_("loop ",3c,f1,f9,78))->__get(1).split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_("is missing it's enclosing 'end' block at line ",cc,be,43,ad)) + i));
HXLINE( 187)						return true;
            					}
HXLINE( 190)					bool _hx_tmp10;
HXDLIN( 190)					if ((line.indexOf(HX_("if ",a3,05,50,00),null()) != -1)) {
HXLINE( 190)						_hx_tmp10 = (input.split(HX_("if ",a3,05,50,00))->__get(1).indexOf(HX_("end",db,03,4d,00),null()) == -1);
            					}
            					else {
HXLINE( 190)						_hx_tmp10 = false;
            					}
HXDLIN( 190)					if (_hx_tmp10) {
HXLINE( 191)						::Sys_obj::println((HX_("Error: An if statement is missing it's enclosing 'end' block at line ",7b,e5,06,60) + i));
HXLINE( 192)						return true;
            					}
HXLINE( 195)					bool _hx_tmp11;
HXDLIN( 195)					if ((line.indexOf(HX_("otherwise",f4,83,f2,9a),null()) != -1)) {
HXLINE( 195)						_hx_tmp11 = (input.split(HX_("otherwise",f4,83,f2,9a))->__get(1).indexOf(HX_("end",db,03,4d,00),null()) == -1);
            					}
            					else {
HXLINE( 195)						_hx_tmp11 = false;
            					}
HXDLIN( 195)					if (_hx_tmp11) {
HXLINE( 196)						::Sys_obj::println((HX_("Error: An else statement is missing it's enclosing 'end' block at line ",df,7d,41,d8) + i));
HXLINE( 197)						return true;
            					}
            				}
            			}
HXLINE( 201)			return false;
            		}
HXLINE( 203)		return false;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Blue_obj,checkForErrors,return )


Blue_obj::Blue_obj()
{
}

bool Blue_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"libs") ) { outValue = ( libs ); return true; }
		if (HX_FIELD_EQ(inName,"main") ) { outValue = main_dyn(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mapFile") ) { outValue = mapFile_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mainFile") ) { outValue = ( mainFile ); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"directory") ) { outValue = ( directory ); return true; }
		if (HX_FIELD_EQ(inName,"mapSource") ) { outValue = mapSource_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"buildCommand") ) { outValue = ( buildCommand ); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"lexSourceFile") ) { outValue = lexSourceFile_dyn(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"completeSyntax") ) { outValue = ( completeSyntax ); return true; }
		if (HX_FIELD_EQ(inName,"checkForErrors") ) { outValue = checkForErrors_dyn(); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"currentMappedFiles") ) { outValue = ( currentMappedFiles ); return true; }
		if (HX_FIELD_EQ(inName,"currentMappedLines") ) { outValue = ( currentMappedLines ); return true; }
	}
	return false;
}

bool Blue_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"libs") ) { libs=ioValue.Cast< ::Array< ::String > >(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mainFile") ) { mainFile=ioValue.Cast< ::String >(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"directory") ) { directory=ioValue.Cast< ::String >(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"buildCommand") ) { buildCommand=ioValue.Cast< ::String >(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"completeSyntax") ) { completeSyntax=ioValue.Cast< ::Array< ::String > >(); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"currentMappedFiles") ) { currentMappedFiles=ioValue.Cast< ::Array< ::String > >(); return true; }
		if (HX_FIELD_EQ(inName,"currentMappedLines") ) { currentMappedLines=ioValue.Cast< ::Array< ::Dynamic> >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Blue_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo Blue_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &Blue_obj::currentMappedFiles,HX_("currentMappedFiles",0b,16,a5,79)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(void *) &Blue_obj::currentMappedLines,HX_("currentMappedLines",93,15,0e,ee)},
	{::hx::fsString,(void *) &Blue_obj::directory,HX_("directory",6d,f2,44,10)},
	{::hx::fsString,(void *) &Blue_obj::mainFile,HX_("mainFile",55,43,3e,9c)},
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &Blue_obj::libs,HX_("libs",8e,0d,b3,47)},
	{::hx::fsString,(void *) &Blue_obj::buildCommand,HX_("buildCommand",bd,9f,c5,93)},
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &Blue_obj::completeSyntax,HX_("completeSyntax",fc,c7,f3,b6)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void Blue_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Blue_obj::currentMappedFiles,"currentMappedFiles");
	HX_MARK_MEMBER_NAME(Blue_obj::currentMappedLines,"currentMappedLines");
	HX_MARK_MEMBER_NAME(Blue_obj::directory,"directory");
	HX_MARK_MEMBER_NAME(Blue_obj::mainFile,"mainFile");
	HX_MARK_MEMBER_NAME(Blue_obj::libs,"libs");
	HX_MARK_MEMBER_NAME(Blue_obj::buildCommand,"buildCommand");
	HX_MARK_MEMBER_NAME(Blue_obj::completeSyntax,"completeSyntax");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Blue_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Blue_obj::currentMappedFiles,"currentMappedFiles");
	HX_VISIT_MEMBER_NAME(Blue_obj::currentMappedLines,"currentMappedLines");
	HX_VISIT_MEMBER_NAME(Blue_obj::directory,"directory");
	HX_VISIT_MEMBER_NAME(Blue_obj::mainFile,"mainFile");
	HX_VISIT_MEMBER_NAME(Blue_obj::libs,"libs");
	HX_VISIT_MEMBER_NAME(Blue_obj::buildCommand,"buildCommand");
	HX_VISIT_MEMBER_NAME(Blue_obj::completeSyntax,"completeSyntax");
};

#endif

::hx::Class Blue_obj::__mClass;

static ::String Blue_obj_sStaticFields[] = {
	HX_("currentMappedFiles",0b,16,a5,79),
	HX_("currentMappedLines",93,15,0e,ee),
	HX_("directory",6d,f2,44,10),
	HX_("mainFile",55,43,3e,9c),
	HX_("libs",8e,0d,b3,47),
	HX_("buildCommand",bd,9f,c5,93),
	HX_("completeSyntax",fc,c7,f3,b6),
	HX_("main",39,38,56,48),
	HX_("mapSource",97,0c,11,15),
	HX_("mapFile",38,83,b7,28),
	HX_("lexSourceFile",b6,31,ce,28),
	HX_("checkForErrors",ac,19,52,4a),
	::String(null())
};

void Blue_obj::__register()
{
	Blue_obj _hx_dummy;
	Blue_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("blue.Blue",0e,2d,6e,ed);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Blue_obj::__GetStatic;
	__mClass->mSetStaticField = &Blue_obj::__SetStatic;
	__mClass->mMarkFunc = Blue_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Blue_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Blue_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Blue_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Blue_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Blue_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Blue_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_12_boot)
HXDLIN(  12)		currentMappedFiles = ::Array_obj< ::String >::__new(0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_13_boot)
HXDLIN(  13)		currentMappedLines = ::Array_obj< ::Dynamic>::__new(0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_14_boot)
HXDLIN(  14)		directory = HX_("",00,00,00,00);
            	}
{
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_16_boot)
HXDLIN(  16)		mainFile = HX_("",00,00,00,00);
            	}
{
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_17_boot)
HXDLIN(  17)		libs = ::Array_obj< ::String >::__new(0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_19_boot)
HXDLIN(  19)		buildCommand = HX_("haxe -cp src --main export.hxsrc.Main --cpp export/bin",27,fb,f9,49);
            	}
{
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_21_boot)
HXDLIN(  21)		completeSyntax = ::Array_obj< ::String >::fromData( _hx_array_data_ed6e2d0e_17,25);
            	}
}

} // end namespace blue
