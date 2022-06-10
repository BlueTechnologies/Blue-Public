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
static const ::String _hx_array_data_ed6e2d0e_7[] = {
	HX_("package export.hxsrc;",87,95,b1,6f),HX_("using StringTools;",ed,61,db,f1),HX_("class",38,78,58,48),HX_("{",7b,00,00,00),
};
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_89_mapFile,"blue.Blue","mapFile",0x73deefd8,"blue.Blue.mapFile","blue/Blue.hx",89,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_93_lexSourceFile,"blue.Blue","lexSourceFile",0xd6b8d656,"blue.Blue.lexSourceFile","blue/Blue.hx",93,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_96_checkForErrors,"blue.Blue","checkForErrors",0xc9b7810c,"blue.Blue.checkForErrors","blue/Blue.hx",96,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_12_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",12,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_13_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",13,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_14_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",14,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_16_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",16,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_17_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",17,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_19_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",19,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_21_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",21,0xac82a48f)
static const ::String _hx_array_data_ed6e2d0e_22[] = {
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
HXLINE(  32)		int i = -1;
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
HXDLIN(  37)					if (!(::sys::FileSystem_obj::isDirectory(file))) {
HXLINE(  37)						_hx_tmp = ::StringTools_obj::endsWith(file,HX_(".bl",78,3d,23,00));
            					}
            					else {
HXLINE(  37)						_hx_tmp = false;
            					}
HXDLIN(  37)					if (_hx_tmp) {
HXLINE(  38)						::Sys_obj::println(file);
HXLINE(  39)						if (!(::blue::Blue_obj::checkForErrors(::sys::io::File_obj::getContent(((directory + HX_("/",2f,00,00,00)) + file))))) {
HXLINE(  40)							i = (i + 1);
HXLINE(  41)							files->push(file);
HXLINE(  42)							::String rawContent = ::sys::io::File_obj::getContent(((directory + HX_("/",2f,00,00,00)) + file));
HXLINE(  43)							::blue::Blue_obj::mapFile(((directory + HX_("/",2f,00,00,00)) + file));
HXLINE(  44)							::blue::BHaxeUtil_obj::fileName = file;
HXLINE(  45)							::blue::BHaxeUtil_obj::haxeData = ::Array_obj< ::String >::fromData( _hx_array_data_ed6e2d0e_7,4);
HXLINE(  46)							{
HXLINE(  46)								int _g = 0;
HXDLIN(  46)								int _g1 = rawContent.split(HX_("\n",0a,00,00,00))->length;
HXDLIN(  46)								while((_g < _g1)){
HXLINE(  46)									_g = (_g + 1);
HXDLIN(  46)									int i = (_g - 1);
HXLINE(  47)									::String line = rawContent.split(HX_("\n",0a,00,00,00))->__get(i);
HXLINE(  48)									if ((line.indexOf(HX_("@BuildCommand(",6b,4d,6b,ac),null()) != -1)) {
HXLINE(  49)										::blue::Blue_obj::buildCommand = line.split(HX_("@BuildCommand('",5c,70,78,31))->__get(1).split(HX_("')",22,22,00,00))->__get(0);
HXLINE(  50)										::Sys_obj::println(HX_("Warning: You are using a custom build command! The program is not guaranteed to successfully compile!",c1,eb,da,c1));
            									}
            								}
            							}
HXLINE(  53)							{
HXLINE(  53)								int _g2 = 0;
HXDLIN(  53)								int _g3 = rawContent.split(HX_("\n",0a,00,00,00))->length;
HXDLIN(  53)								while((_g2 < _g3)){
HXLINE(  53)									_g2 = (_g2 + 1);
HXDLIN(  53)									int i = (_g2 - 1);
HXLINE(  54)									::String line = rawContent.split(HX_("\n",0a,00,00,00))->__get(i);
HXLINE(  55)									if ((line.indexOf(HX_("@IncludeLib(",2b,6b,ef,da),null()) != -1)) {
HXLINE(  56)										::Array< ::String > _hx_tmp = ::blue::Blue_obj::libs;
HXDLIN(  56)										_hx_tmp->push(line.split(HX_("@IncludeLib('",9c,5a,8e,b6))->__get(1).split(HX_("')",22,22,00,00))->__get(0));
            									}
            								}
            							}
HXLINE(  59)							{
HXLINE(  59)								int _g4 = 0;
HXDLIN(  59)								int _g5 = rawContent.split(HX_("\n",0a,00,00,00))->length;
HXDLIN(  59)								while((_g4 < _g5)){
HXLINE(  59)									_g4 = (_g4 + 1);
HXDLIN(  59)									int i = (_g4 - 1);
HXLINE(  60)									::String line = rawContent.split(HX_("\n",0a,00,00,00))->__get(i);
HXLINE(  61)									if ((line.indexOf(HX_("@Extends(",0f,dd,e2,76),null()) != -1)) {
HXLINE(  62)										::blue::BHaxeUtil_obj::extension = line.split(HX_("@Extends(",0f,dd,e2,76))->__get(1).split(HX_(")",29,00,00,00))->__get(0);
            									}
            								}
            							}
HXLINE(  65)							{
HXLINE(  65)								int _g6 = 0;
HXDLIN(  65)								int _g7 = rawContent.split(HX_("\n",0a,00,00,00))->length;
HXDLIN(  65)								while((_g6 < _g7)){
HXLINE(  65)									_g6 = (_g6 + 1);
HXDLIN(  65)									int i = (_g6 - 1);
HXLINE(  66)									::String line = rawContent.split(HX_("\n",0a,00,00,00))->__get(i);
HXLINE(  67)									if ((line.indexOf(HX_("@Package(",42,e6,60,cf),null()) != -1)) {
HXLINE(  68)										::blue::BHaxeUtil_obj::haxeData[0] = ((HX_("package ",da,e9,54,39) + line.split(HX_("@Package(",42,e6,60,cf))->__get(1).split(HX_(")",29,00,00,00))->__get(0)) + HX_(";",3b,00,00,00));
            									}
            								}
            							}
HXLINE(  72)							::blue::Blue_obj::lexSourceFile(rawContent);
HXLINE(  73)							bool _hx_tmp;
HXDLIN(  73)							if (::sys::FileSystem_obj::exists(HX_("export/hxsrc",b9,ab,55,3c))) {
HXLINE(  73)								int files1 = files->length;
HXDLIN(  73)								_hx_tmp = (files1 == ::sys::FileSystem_obj::readDirectory(HX_("export/hxsrc",b9,ab,55,3c))->length);
            							}
            							else {
HXLINE(  73)								_hx_tmp = false;
            							}
HXDLIN(  73)							if (_hx_tmp) {
HXLINE(  74)								bool _hx_tmp;
HXDLIN(  74)								if (::hx::IsNotNull( ::blue::Blue_obj::libs )) {
HXLINE(  74)									_hx_tmp = (::blue::Blue_obj::buildCommand == HX_("haxe -cp src --main export.hxsrc.Main --cpp export/bin",27,fb,f9,49));
            								}
            								else {
HXLINE(  74)									_hx_tmp = false;
            								}
HXDLIN(  74)								if (_hx_tmp) {
HXLINE(  75)									::blue::Blue_obj::buildCommand = ((HX_("haxe -cp src --main export.hxsrc --library ",60,2c,8a,c8) + ::blue::Blue_obj::libs->join(HX_(" --library",7b,a7,0c,6b))) + HX_(" --cpp export/bin",c9,2e,e9,89));
            								}
HXLINE(  77)								::Sys_obj::command(::blue::Blue_obj::buildCommand,null());
HXLINE(  78)								::Sys_obj::exit(0);
            							}
            						}
            					}
            				}
            			}
            		}
            		else {
HXLINE(  84)			::Sys_obj::println(((HX_("Error: Source folder '",6c,fd,d1,da) + directory) + HX_("' does not exist or is not a directory",84,e6,8a,70)));
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Blue_obj,mapSource,(void))

void Blue_obj::mapFile(::String input){
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_89_mapFile)
HXDLIN(  89)		::blue::Blue_obj::currentMappedFiles->push(input);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Blue_obj,mapFile,(void))

void Blue_obj::lexSourceFile(::String content){
            	HX_GC_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_93_lexSourceFile)
HXDLIN(  93)		 ::blue::BLexer_obj::__alloc( HX_CTX ,content);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Blue_obj,lexSourceFile,(void))

bool Blue_obj::checkForErrors(::String input){
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_96_checkForErrors)
HXLINE(  97)		if ((input.indexOf(HX_("\n",0a,00,00,00),null()) != -1)) {
HXLINE(  98)			{
HXLINE(  98)				int _g = 0;
HXDLIN(  98)				int _g1 = input.split(HX_("\n",0a,00,00,00))->length;
HXDLIN(  98)				while((_g < _g1)){
HXLINE(  98)					_g = (_g + 1);
HXDLIN(  98)					int i = (_g - 1);
HXLINE(  99)					::String line = input.split(HX_("\n",0a,00,00,00))->__get(i);
HXLINE( 100)					::String letters = HX_("abcdefghijklmnopqrstuvwusyz",2b,b6,72,75);
HXLINE( 101)					::String chars = HX_("#$%^&_{}:><?|;",db,c5,59,e6);
HXLINE( 102)					bool _hx_tmp;
HXDLIN( 102)					if ((line.indexOf(HX_("if",dd,5b,00,00),null()) != -1)) {
HXLINE( 102)						_hx_tmp = (line.indexOf(HX_("then",dd,02,fc,4c),null()) == -1);
            					}
            					else {
HXLINE( 102)						_hx_tmp = false;
            					}
HXDLIN( 102)					if (_hx_tmp) {
HXLINE( 103)						::Sys_obj::println((HX_("Error: Expected 'then' at the end of line ",21,d7,11,f7) + i));
HXLINE( 104)						return true;
            					}
            					else {
HXLINE( 106)						{
HXLINE( 106)							int _g = 0;
HXDLIN( 106)							int _g1 = letters.split(HX_("",00,00,00,00))->length;
HXDLIN( 106)							while((_g < _g1)){
HXLINE( 106)								_g = (_g + 1);
HXDLIN( 106)								int k = (_g - 1);
HXLINE( 107)								{
HXLINE( 107)									int _g1 = 0;
HXDLIN( 107)									int _g2 = ::blue::Blue_obj::completeSyntax->length;
HXDLIN( 107)									while((_g1 < _g2)){
HXLINE( 107)										_g1 = (_g1 + 1);
HXDLIN( 107)										int l = (_g1 - 1);
HXLINE( 108)										bool _hx_tmp;
HXDLIN( 108)										bool _hx_tmp1;
HXDLIN( 108)										bool _hx_tmp2;
HXDLIN( 108)										bool _hx_tmp3;
HXDLIN( 108)										bool _hx_tmp4;
HXDLIN( 108)										bool _hx_tmp5;
HXDLIN( 108)										bool _hx_tmp6;
HXDLIN( 108)										bool _hx_tmp7;
HXDLIN( 108)										bool _hx_tmp8;
HXDLIN( 108)										bool _hx_tmp9;
HXDLIN( 108)										bool _hx_tmp10;
HXDLIN( 108)										bool _hx_tmp11;
HXDLIN( 108)										bool _hx_tmp12;
HXDLIN( 108)										bool _hx_tmp13;
HXDLIN( 108)										bool _hx_tmp14;
HXDLIN( 108)										bool _hx_tmp15;
HXDLIN( 108)										bool _hx_tmp16;
HXDLIN( 108)										bool _hx_tmp17;
HXDLIN( 108)										bool _hx_tmp18;
HXDLIN( 108)										bool _hx_tmp19;
HXDLIN( 108)										if ((line.indexOf(letters.split(HX_("",00,00,00,00))->__get(k),null()) != -1)) {
HXLINE( 108)											_hx_tmp19 = (line.indexOf(HX_("=",3d,00,00,00),null()) != -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp19 = false;
            										}
HXDLIN( 108)										if (_hx_tmp19) {
HXLINE( 108)											_hx_tmp18 = (line.indexOf(HX_("if",dd,5b,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp18 = false;
            										}
HXDLIN( 108)										if (_hx_tmp18) {
HXLINE( 108)											_hx_tmp17 = (line.indexOf(HX_("1",31,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp17 = false;
            										}
HXDLIN( 108)										if (_hx_tmp17) {
HXLINE( 108)											_hx_tmp16 = (line.indexOf(HX_("2",32,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp16 = false;
            										}
HXDLIN( 108)										if (_hx_tmp16) {
HXLINE( 108)											_hx_tmp15 = (line.indexOf(HX_("3",33,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp15 = false;
            										}
HXDLIN( 108)										if (_hx_tmp15) {
HXLINE( 108)											_hx_tmp14 = (line.indexOf(HX_("4",34,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp14 = false;
            										}
HXDLIN( 108)										if (_hx_tmp14) {
HXLINE( 108)											_hx_tmp13 = (line.indexOf(HX_("5",35,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp13 = false;
            										}
HXDLIN( 108)										if (_hx_tmp13) {
HXLINE( 108)											_hx_tmp12 = (line.indexOf(HX_("6",36,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp12 = false;
            										}
HXDLIN( 108)										if (_hx_tmp12) {
HXLINE( 108)											_hx_tmp11 = (line.indexOf(HX_("7",37,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp11 = false;
            										}
HXDLIN( 108)										if (_hx_tmp11) {
HXLINE( 108)											_hx_tmp10 = (line.indexOf(HX_("8",38,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp10 = false;
            										}
HXDLIN( 108)										if (_hx_tmp10) {
HXLINE( 108)											_hx_tmp9 = (line.indexOf(HX_("9",39,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp9 = false;
            										}
HXDLIN( 108)										if (_hx_tmp9) {
HXLINE( 108)											_hx_tmp8 = (line.indexOf(HX_("true",4e,a7,03,4d),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp8 = false;
            										}
HXDLIN( 108)										if (_hx_tmp8) {
HXLINE( 108)											_hx_tmp7 = (line.indexOf(HX_("false",a3,35,4f,fb),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp7 = false;
            										}
HXDLIN( 108)										if (_hx_tmp7) {
HXLINE( 108)											_hx_tmp6 = (line.indexOf(HX_("'",27,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp6 = false;
            										}
HXDLIN( 108)										if (_hx_tmp6) {
HXLINE( 108)											_hx_tmp5 = (line.indexOf(HX_("\"",22,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp5 = false;
            										}
HXDLIN( 108)										if (_hx_tmp5) {
HXLINE( 108)											_hx_tmp4 = (line.indexOf(HX_("[",5b,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp4 = false;
            										}
HXDLIN( 108)										if (_hx_tmp4) {
HXLINE( 108)											_hx_tmp3 = (line.indexOf(HX_("]",5d,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp3 = false;
            										}
HXDLIN( 108)										if (_hx_tmp3) {
HXLINE( 108)											_hx_tmp2 = (line.indexOf(HX_("null",87,9e,0e,49),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp2 = false;
            										}
HXDLIN( 108)										if (_hx_tmp2) {
HXLINE( 108)											_hx_tmp1 = (line.indexOf(HX_("new",60,d0,53,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp1 = false;
            										}
HXDLIN( 108)										if (_hx_tmp1) {
HXLINE( 108)											_hx_tmp = (line.indexOf(HX_(".",2e,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 108)											_hx_tmp = false;
            										}
HXDLIN( 108)										if (_hx_tmp) {
HXLINE( 113)											::Sys_obj::println((HX_("Error: Values assigned to variables can only be 'Bool', 'Int', 'Float', 'String', or 'Array', Which was not found at line ",95,91,54,be) + i));
HXLINE( 115)											return true;
            										}
HXLINE( 118)										bool _hx_tmp20;
HXDLIN( 118)										bool _hx_tmp21;
HXDLIN( 118)										bool _hx_tmp22;
HXDLIN( 118)										bool _hx_tmp23;
HXDLIN( 118)										bool _hx_tmp24;
HXDLIN( 118)										bool _hx_tmp25;
HXDLIN( 118)										bool _hx_tmp26;
HXDLIN( 118)										bool _hx_tmp27;
HXDLIN( 118)										bool _hx_tmp28;
HXDLIN( 118)										bool _hx_tmp29;
HXDLIN( 118)										bool _hx_tmp30;
HXDLIN( 118)										bool _hx_tmp31;
HXDLIN( 118)										bool _hx_tmp32;
HXDLIN( 118)										bool _hx_tmp33;
HXDLIN( 118)										bool _hx_tmp34;
HXDLIN( 118)										bool _hx_tmp35;
HXDLIN( 118)										bool _hx_tmp36;
HXDLIN( 118)										bool _hx_tmp37;
HXDLIN( 118)										bool _hx_tmp38;
HXDLIN( 118)										bool _hx_tmp39;
HXDLIN( 118)										bool _hx_tmp40;
HXDLIN( 118)										if ((line.indexOf(letters.split(HX_("",00,00,00,00))->__get(k),null()) != -1)) {
HXLINE( 118)											_hx_tmp40 = (line.indexOf(HX_("if",dd,5b,00,00),null()) != -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp40 = false;
            										}
HXDLIN( 118)										if (_hx_tmp40) {
HXLINE( 118)											_hx_tmp39 = (line.indexOf(HX_("1",31,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp39 = false;
            										}
HXDLIN( 118)										if (_hx_tmp39) {
HXLINE( 118)											_hx_tmp38 = (line.indexOf(HX_("2",32,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp38 = false;
            										}
HXDLIN( 118)										if (_hx_tmp38) {
HXLINE( 118)											_hx_tmp37 = (line.indexOf(HX_("3",33,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp37 = false;
            										}
HXDLIN( 118)										if (_hx_tmp37) {
HXLINE( 118)											_hx_tmp36 = (line.indexOf(HX_("4",34,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp36 = false;
            										}
HXDLIN( 118)										if (_hx_tmp36) {
HXLINE( 118)											_hx_tmp35 = (line.indexOf(HX_("5",35,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp35 = false;
            										}
HXDLIN( 118)										if (_hx_tmp35) {
HXLINE( 118)											_hx_tmp34 = (line.indexOf(HX_("6",36,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp34 = false;
            										}
HXDLIN( 118)										if (_hx_tmp34) {
HXLINE( 118)											_hx_tmp33 = (line.indexOf(HX_("7",37,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp33 = false;
            										}
HXDLIN( 118)										if (_hx_tmp33) {
HXLINE( 118)											_hx_tmp32 = (line.indexOf(HX_("8",38,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp32 = false;
            										}
HXDLIN( 118)										if (_hx_tmp32) {
HXLINE( 118)											_hx_tmp31 = (line.indexOf(HX_("9",39,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp31 = false;
            										}
HXDLIN( 118)										if (_hx_tmp31) {
HXLINE( 118)											_hx_tmp30 = (line.indexOf(HX_("true",4e,a7,03,4d),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp30 = false;
            										}
HXDLIN( 118)										if (_hx_tmp30) {
HXLINE( 118)											_hx_tmp29 = (line.indexOf(HX_("false",a3,35,4f,fb),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp29 = false;
            										}
HXDLIN( 118)										if (_hx_tmp29) {
HXLINE( 118)											_hx_tmp28 = (line.indexOf(HX_("'",27,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp28 = false;
            										}
HXDLIN( 118)										if (_hx_tmp28) {
HXLINE( 118)											_hx_tmp27 = (line.indexOf(HX_("\"",22,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp27 = false;
            										}
HXDLIN( 118)										if (_hx_tmp27) {
HXLINE( 118)											_hx_tmp26 = (line.indexOf(HX_("=",3d,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp26 = false;
            										}
HXDLIN( 118)										if (_hx_tmp26) {
HXLINE( 118)											_hx_tmp25 = (line.indexOf(HX_("greater than",47,34,3c,43),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp25 = false;
            										}
HXDLIN( 118)										if (_hx_tmp25) {
HXLINE( 118)											_hx_tmp24 = (line.indexOf(HX_("less than",88,b9,bc,f1),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp24 = false;
            										}
HXDLIN( 118)										if (_hx_tmp24) {
HXLINE( 118)											_hx_tmp23 = (line.indexOf(HX_("div",51,3d,4c,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp23 = false;
            										}
HXDLIN( 118)										if (_hx_tmp23) {
HXLINE( 118)											_hx_tmp22 = (line.indexOf(HX_("mult",f0,67,65,48),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp22 = false;
            										}
HXDLIN( 118)										if (_hx_tmp22) {
HXLINE( 118)											_hx_tmp21 = (line.indexOf(HX_("null",87,9e,0e,49),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp21 = false;
            										}
HXDLIN( 118)										if (_hx_tmp21) {
HXLINE( 118)											_hx_tmp20 = (line.indexOf(HX_(".",2e,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 118)											_hx_tmp20 = false;
            										}
HXDLIN( 118)										if (_hx_tmp20) {
HXLINE( 123)											::Sys_obj::println((HX_("Error: A valid 'if' condition was not found at line ",92,e4,43,51) + i));
HXLINE( 124)											return true;
            										}
HXLINE( 127)										bool _hx_tmp41;
HXDLIN( 127)										bool _hx_tmp42;
HXDLIN( 127)										bool _hx_tmp43;
HXDLIN( 127)										bool _hx_tmp44;
HXDLIN( 127)										bool _hx_tmp45;
HXDLIN( 127)										bool _hx_tmp46;
HXDLIN( 127)										bool _hx_tmp47;
HXDLIN( 127)										bool _hx_tmp48;
HXDLIN( 127)										bool _hx_tmp49;
HXDLIN( 127)										bool _hx_tmp50;
HXDLIN( 127)										bool _hx_tmp51;
HXDLIN( 127)										bool _hx_tmp52;
HXDLIN( 127)										bool _hx_tmp53;
HXDLIN( 127)										bool _hx_tmp54;
HXDLIN( 127)										bool _hx_tmp55;
HXDLIN( 127)										bool _hx_tmp56;
HXDLIN( 127)										bool _hx_tmp57;
HXDLIN( 127)										bool _hx_tmp58;
HXDLIN( 127)										bool _hx_tmp59;
HXDLIN( 127)										bool _hx_tmp60;
HXDLIN( 127)										bool _hx_tmp61;
HXDLIN( 127)										bool _hx_tmp62;
HXDLIN( 127)										bool _hx_tmp63;
HXDLIN( 127)										if ((line.indexOf(letters.split(HX_("",00,00,00,00))->__get(k),null()) != -1)) {
HXLINE( 127)											_hx_tmp63 = (line.indexOf(HX_("loop",64,a6,b7,47),null()) != -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp63 = false;
            										}
HXDLIN( 127)										if (_hx_tmp63) {
HXLINE( 127)											_hx_tmp62 = (line.indexOf(HX_("1",31,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp62 = false;
            										}
HXDLIN( 127)										if (_hx_tmp62) {
HXLINE( 127)											_hx_tmp61 = (line.indexOf(HX_("2",32,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp61 = false;
            										}
HXDLIN( 127)										if (_hx_tmp61) {
HXLINE( 127)											_hx_tmp60 = (line.indexOf(HX_("3",33,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp60 = false;
            										}
HXDLIN( 127)										if (_hx_tmp60) {
HXLINE( 127)											_hx_tmp59 = (line.indexOf(HX_("4",34,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp59 = false;
            										}
HXDLIN( 127)										if (_hx_tmp59) {
HXLINE( 127)											_hx_tmp58 = (line.indexOf(HX_("5",35,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp58 = false;
            										}
HXDLIN( 127)										if (_hx_tmp58) {
HXLINE( 127)											_hx_tmp57 = (line.indexOf(HX_("6",36,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp57 = false;
            										}
HXDLIN( 127)										if (_hx_tmp57) {
HXLINE( 127)											_hx_tmp56 = (line.indexOf(HX_("7",37,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp56 = false;
            										}
HXDLIN( 127)										if (_hx_tmp56) {
HXLINE( 127)											_hx_tmp55 = (line.indexOf(HX_("8",38,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp55 = false;
            										}
HXDLIN( 127)										if (_hx_tmp55) {
HXLINE( 127)											_hx_tmp54 = (line.indexOf(HX_("9",39,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp54 = false;
            										}
HXDLIN( 127)										if (_hx_tmp54) {
HXLINE( 127)											_hx_tmp53 = (line.indexOf(HX_("true",4e,a7,03,4d),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp53 = false;
            										}
HXDLIN( 127)										if (_hx_tmp53) {
HXLINE( 127)											_hx_tmp52 = (line.indexOf(HX_("false",a3,35,4f,fb),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp52 = false;
            										}
HXDLIN( 127)										if (_hx_tmp52) {
HXLINE( 127)											_hx_tmp51 = (line.indexOf(HX_("'",27,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp51 = false;
            										}
HXDLIN( 127)										if (_hx_tmp51) {
HXLINE( 127)											_hx_tmp50 = (line.indexOf(HX_("\"",22,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp50 = false;
            										}
HXDLIN( 127)										if (_hx_tmp50) {
HXLINE( 127)											_hx_tmp49 = (line.indexOf(HX_("=",3d,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp49 = false;
            										}
HXDLIN( 127)										if (_hx_tmp49) {
HXLINE( 127)											_hx_tmp48 = (line.indexOf(HX_("greater than",47,34,3c,43),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp48 = false;
            										}
HXDLIN( 127)										if (_hx_tmp48) {
HXLINE( 127)											_hx_tmp47 = (line.indexOf(HX_("less than",88,b9,bc,f1),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp47 = false;
            										}
HXDLIN( 127)										if (_hx_tmp47) {
HXLINE( 127)											_hx_tmp46 = (line.indexOf(HX_("div",51,3d,4c,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp46 = false;
            										}
HXDLIN( 127)										if (_hx_tmp46) {
HXLINE( 127)											_hx_tmp45 = (line.indexOf(HX_("mult",f0,67,65,48),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp45 = false;
            										}
HXDLIN( 127)										if (_hx_tmp45) {
HXLINE( 127)											_hx_tmp44 = (line.indexOf(HX_("until",9e,b8,ef,a6),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp44 = false;
            										}
HXDLIN( 127)										if (_hx_tmp44) {
HXLINE( 127)											_hx_tmp43 = (line.indexOf(HX_("in",e5,5b,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp43 = false;
            										}
HXDLIN( 127)										if (_hx_tmp43) {
HXLINE( 127)											_hx_tmp42 = (line.indexOf(HX_("null",87,9e,0e,49),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp42 = false;
            										}
HXDLIN( 127)										if (_hx_tmp42) {
HXLINE( 127)											_hx_tmp41 = (line.indexOf(HX_(".",2e,00,00,00),null()) == -1);
            										}
            										else {
HXLINE( 127)											_hx_tmp41 = false;
            										}
HXDLIN( 127)										if (_hx_tmp41) {
HXLINE( 132)											::Sys_obj::println((HX_("Error: A valid 'loop' expression was not found at line ",76,ba,74,5a) + i));
HXLINE( 133)											return true;
            										}
            									}
            								}
            							}
            						}
HXLINE( 137)						{
HXLINE( 137)							int _g2 = 0;
HXDLIN( 137)							int _g3 = chars.split(HX_("",00,00,00,00))->length;
HXDLIN( 137)							while((_g2 < _g3)){
HXLINE( 137)								_g2 = (_g2 + 1);
HXDLIN( 137)								int n = (_g2 - 1);
HXLINE( 138)								bool _hx_tmp;
HXDLIN( 138)								if ((line.indexOf(chars.split(HX_("",00,00,00,00))->__get(n),null()) != -1)) {
HXLINE( 138)									::String s = ::blue::Blue_obj::completeSyntax->__get(i);
HXDLIN( 138)									_hx_tmp = (s.indexOf(chars.split(HX_("",00,00,00,00))->__get(n),null()) == -1);
            								}
            								else {
HXLINE( 138)									_hx_tmp = false;
            								}
HXDLIN( 138)								if (_hx_tmp) {
HXLINE( 139)									::Sys_obj::println((((HX_("Error: Unknown character: ",4b,01,29,5a) + chars.split(HX_("",00,00,00,00))->__get(n)) + HX_(" at line ",df,96,71,22)) + i));
HXLINE( 140)									return true;
            								}
            							}
            						}
            					}
HXLINE( 145)					bool _hx_tmp1;
HXDLIN( 145)					if ((line.indexOf(HX_("method",e1,f6,5a,09),null()) != -1)) {
HXLINE( 145)						_hx_tmp1 = (line.indexOf(HX_(":",3a,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 145)						_hx_tmp1 = false;
            					}
HXDLIN( 145)					if (_hx_tmp1) {
HXLINE( 146)						::Sys_obj::println(((HX_("Error: Unknown character: ':'",29,6a,5e,80) + HX_(" at line ",df,96,71,22)) + i));
HXLINE( 147)						return true;
            					}
HXLINE( 149)					bool _hx_tmp2;
HXDLIN( 149)					if ((line.indexOf(HX_("(",28,00,00,00),null()) != -1)) {
HXLINE( 149)						_hx_tmp2 = (line.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).indexOf(HX_(",",2c,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 149)						_hx_tmp2 = false;
            					}
HXDLIN( 149)					if (_hx_tmp2) {
HXLINE( 150)						bool _hx_tmp;
HXDLIN( 150)						if ((input.indexOf(::StringTools_obj::replace(line.split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)),null()) != -1)) {
HXLINE( 150)							_hx_tmp = (input.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).indexOf(HX_(",",2c,00,00,00),null()) != -1);
            						}
            						else {
HXLINE( 150)							_hx_tmp = false;
            						}
HXDLIN( 150)						if (_hx_tmp) {
HXLINE( 151)							int _hx_tmp = line.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).split(HX_(",",2c,00,00,00))->length;
HXDLIN( 151)							if ((_hx_tmp > input.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).split(HX_(",",2c,00,00,00))->length)) {
HXLINE( 152)								::Sys_obj::println((((HX_("Error: Too many parameters for method: ",ed,d9,1b,50) + ::StringTools_obj::replace(line.split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_(" at line ",df,96,71,22)) + i));
HXLINE( 153)								return true;
            							}
            							else {
HXLINE( 154)								int _hx_tmp = line.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).split(HX_(",",2c,00,00,00))->length;
HXDLIN( 154)								if ((_hx_tmp < input.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).split(HX_(",",2c,00,00,00))->length)) {
HXLINE( 155)									::Sys_obj::println((((HX_("Error: Not enough parameters for method: ",df,32,a5,55) + ::StringTools_obj::replace(line.split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_(" at line ",df,96,71,22)) + i));
HXLINE( 156)									return true;
            								}
            							}
            						}
            					}
HXLINE( 160)					bool _hx_tmp3;
HXDLIN( 160)					if ((line.indexOf(HX_("new ",c0,83,02,49),null()) != -1)) {
HXLINE( 160)						_hx_tmp3 = ::sys::FileSystem_obj::exists((line.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0) + HX_(".bl",78,3d,23,00)));
            					}
            					else {
HXLINE( 160)						_hx_tmp3 = false;
            					}
HXDLIN( 160)					if (_hx_tmp3) {
HXLINE( 161)						if ((::sys::io::File_obj::getContent((line.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0) + HX_(".bl",78,3d,23,00))).indexOf(HX_("constructor method()",08,d8,4a,0a),null()) == -1)) {
HXLINE( 162)							::Sys_obj::println((((HX_("Error: Source File: ",b9,e3,33,52) + line.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0)) + HX_(" has no constructor method at line ",7f,66,51,a3)) + i));
HXLINE( 163)							return true;
            						}
            					}
HXLINE( 167)					bool _hx_tmp4;
HXDLIN( 167)					if ((line.indexOf(HX_("constructor method()",08,d8,4a,0a),null()) != -1)) {
HXLINE( 167)						_hx_tmp4 = (input.split(HX_("constructor method()",08,d8,4a,0a))->__get(1).split(HX_("end",db,03,4d,00))->__get(0).indexOf(HX_("return ",70,75,c2,fe),null()) != -1);
            					}
            					else {
HXLINE( 167)						_hx_tmp4 = false;
            					}
HXDLIN( 167)					if (_hx_tmp4) {
HXLINE( 168)						::Sys_obj::println((HX_("Error: Constructor methods cannot have a return value at line ",c2,7f,49,19) + i));
HXLINE( 169)						return true;
            					}
HXLINE( 172)					bool _hx_tmp5;
HXDLIN( 172)					if ((line.indexOf(HX_("main method()",e9,ec,13,c5),null()) != -1)) {
HXLINE( 172)						_hx_tmp5 = (input.split(HX_("main method()",e9,ec,13,c5))->__get(1).split(HX_("end",db,03,4d,00))->__get(0).indexOf(HX_("return ",70,75,c2,fe),null()) != -1);
            					}
            					else {
HXLINE( 172)						_hx_tmp5 = false;
            					}
HXDLIN( 172)					if (_hx_tmp5) {
HXLINE( 173)						::Sys_obj::println((HX_("Error: The main method cannot have a return value at line ",af,6d,78,26) + i));
HXLINE( 174)						return true;
            					}
HXLINE( 184)					if ((line.indexOf(HX_("[0]",48,37,45,00),null()) != -1)) {
HXLINE( 185)						::Sys_obj::println((HX_("Error: Array index's start at '1' at line ",fa,81,14,16) + i));
HXLINE( 186)						return true;
            					}
HXLINE( 189)					bool _hx_tmp6;
HXDLIN( 189)					bool _hx_tmp7;
HXDLIN( 189)					if ((line.indexOf(HX_("method ",1f,0e,3d,26),null()) != -1)) {
HXLINE( 189)						_hx_tmp7 = (line.indexOf(HX_("(",28,00,00,00),null()) == -1);
            					}
            					else {
HXLINE( 189)						_hx_tmp7 = false;
            					}
HXDLIN( 189)					if (_hx_tmp7) {
HXLINE( 189)						_hx_tmp6 = (line.indexOf(HX_(")",29,00,00,00),null()) == -1);
            					}
            					else {
HXLINE( 189)						_hx_tmp6 = false;
            					}
HXDLIN( 189)					if (_hx_tmp6) {
HXLINE( 190)						::Sys_obj::println((((HX_("Error: Method: ",35,c6,b2,e5) + ::StringTools_obj::replace(line.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_("is missing it's parameter brackets at line ",64,00,45,69)) + i));
HXLINE( 192)						return true;
            					}
HXLINE( 195)					bool _hx_tmp8;
HXDLIN( 195)					if ((line.indexOf(HX_("method ",1f,0e,3d,26),null()) != -1)) {
HXLINE( 195)						_hx_tmp8 = (input.split(HX_("method ",1f,0e,3d,26))->__get(1).indexOf(HX_("end",db,03,4d,00),null()) == -1);
            					}
            					else {
HXLINE( 195)						_hx_tmp8 = false;
            					}
HXDLIN( 195)					if (_hx_tmp8) {
HXLINE( 196)						::Sys_obj::println((((HX_("Error: Method: ",35,c6,b2,e5) + ::StringTools_obj::replace(line.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_("is missing it's enclosing 'end' block at line ",cc,be,43,ad)) + i));
HXLINE( 198)						return true;
            					}
HXLINE( 201)					bool _hx_tmp9;
HXDLIN( 201)					if ((line.indexOf(HX_("loop ",3c,f1,f9,78),null()) != -1)) {
HXLINE( 201)						_hx_tmp9 = (input.split(HX_("loop ",3c,f1,f9,78))->__get(1).indexOf(HX_("end",db,03,4d,00),null()) == -1);
            					}
            					else {
HXLINE( 201)						_hx_tmp9 = false;
            					}
HXDLIN( 201)					if (_hx_tmp9) {
HXLINE( 202)						::Sys_obj::println((((HX_("Error: Loop: ",f8,84,61,85) + ::StringTools_obj::replace(line.split(HX_("loop ",3c,f1,f9,78))->__get(1).split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_("is missing it's enclosing 'end' block at line ",cc,be,43,ad)) + i));
HXLINE( 204)						return true;
            					}
HXLINE( 207)					bool _hx_tmp10;
HXDLIN( 207)					if ((line.indexOf(HX_("if ",a3,05,50,00),null()) != -1)) {
HXLINE( 207)						_hx_tmp10 = (input.split(HX_("if ",a3,05,50,00))->__get(1).indexOf(HX_("end",db,03,4d,00),null()) == -1);
            					}
            					else {
HXLINE( 207)						_hx_tmp10 = false;
            					}
HXDLIN( 207)					if (_hx_tmp10) {
HXLINE( 208)						::Sys_obj::println((HX_("Error: An if statement is missing it's enclosing 'end' block at line ",7b,e5,06,60) + i));
HXLINE( 209)						return true;
            					}
HXLINE( 212)					bool _hx_tmp11;
HXDLIN( 212)					if ((line.indexOf(HX_("otherwise",f4,83,f2,9a),null()) != -1)) {
HXLINE( 212)						_hx_tmp11 = (input.split(HX_("otherwise",f4,83,f2,9a))->__get(1).indexOf(HX_("end",db,03,4d,00),null()) == -1);
            					}
            					else {
HXLINE( 212)						_hx_tmp11 = false;
            					}
HXDLIN( 212)					if (_hx_tmp11) {
HXLINE( 213)						::Sys_obj::println((HX_("Error: An else statement is missing it's enclosing 'end' block at line ",df,7d,41,d8) + i));
HXLINE( 214)						return true;
            					}
HXLINE( 217)					bool _hx_tmp12;
HXDLIN( 217)					bool _hx_tmp13;
HXDLIN( 217)					bool _hx_tmp14;
HXDLIN( 217)					bool _hx_tmp15;
HXDLIN( 217)					bool _hx_tmp16;
HXDLIN( 217)					bool _hx_tmp17;
HXDLIN( 217)					bool _hx_tmp18;
HXDLIN( 217)					bool _hx_tmp19;
HXDLIN( 217)					bool _hx_tmp20;
HXDLIN( 217)					if ((line.indexOf(HX_(".",2e,00,00,00),null()) != -1)) {
HXLINE( 217)						_hx_tmp20 = (line.indexOf(HX_("1",31,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 217)						_hx_tmp20 = false;
            					}
HXDLIN( 217)					if (!(_hx_tmp20)) {
HXLINE( 217)						_hx_tmp19 = (line.indexOf(HX_("2",32,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 217)						_hx_tmp19 = true;
            					}
HXDLIN( 217)					if (!(_hx_tmp19)) {
HXLINE( 217)						_hx_tmp18 = (line.indexOf(HX_("3",33,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 217)						_hx_tmp18 = true;
            					}
HXDLIN( 217)					if (!(_hx_tmp18)) {
HXLINE( 217)						_hx_tmp17 = (line.indexOf(HX_("4",34,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 217)						_hx_tmp17 = true;
            					}
HXDLIN( 217)					if (!(_hx_tmp17)) {
HXLINE( 217)						_hx_tmp16 = (line.indexOf(HX_("5",35,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 217)						_hx_tmp16 = true;
            					}
HXDLIN( 217)					if (!(_hx_tmp16)) {
HXLINE( 217)						_hx_tmp15 = (line.indexOf(HX_("6",36,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 217)						_hx_tmp15 = true;
            					}
HXDLIN( 217)					if (!(_hx_tmp15)) {
HXLINE( 217)						_hx_tmp14 = (line.indexOf(HX_("7",37,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 217)						_hx_tmp14 = true;
            					}
HXDLIN( 217)					if (!(_hx_tmp14)) {
HXLINE( 217)						_hx_tmp13 = (line.indexOf(HX_("8",38,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 217)						_hx_tmp13 = true;
            					}
HXDLIN( 217)					if (!(_hx_tmp13)) {
HXLINE( 217)						_hx_tmp12 = (line.indexOf(HX_("9",39,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 217)						_hx_tmp12 = true;
            					}
HXDLIN( 217)					if (_hx_tmp12) {
HXLINE( 218)						::Sys_obj::println((HX_("Error: Unknown character: . at line ",fc,cd,d0,56) + i));
HXLINE( 219)						return true;
            					}
            				}
            			}
HXLINE( 223)			return false;
            		}
HXLINE( 225)		return false;
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
HXDLIN(  21)		completeSyntax = ::Array_obj< ::String >::fromData( _hx_array_data_ed6e2d0e_22,25);
            	}
}

} // end namespace blue
