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

HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_24_main,"blue.Blue","main",0x10d2a799,"blue.Blue.main","blue/Blue.hx",24,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_27_mapSource,"blue.Blue","mapSource",0x0a64e137,"blue.Blue.mapSource","blue/Blue.hx",27,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_56_mapFile,"blue.Blue","mapFile",0x73deefd8,"blue.Blue.mapFile","blue/Blue.hx",56,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_60_lexSourceFile,"blue.Blue","lexSourceFile",0xd6b8d656,"blue.Blue.lexSourceFile","blue/Blue.hx",60,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_63_checkForErrors,"blue.Blue","checkForErrors",0xc9b7810c,"blue.Blue.checkForErrors","blue/Blue.hx",63,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_12_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",12,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_13_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",13,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_14_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",14,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_16_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",16,0xac82a48f)
HX_LOCAL_STACK_FRAME(_hx_pos_67c8f7f6948cffcd_18_boot,"blue.Blue","boot",0x0997f392,"blue.Blue.boot","blue/Blue.hx",18,0xac82a48f)
static const ::String _hx_array_data_ed6e2d0e_15[] = {
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

::Array< ::String > Blue_obj::completeSyntax;

void Blue_obj::main(){
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_24_main)
HXDLIN(  24)		::blue::Blue_obj::mapSource(::Sys_obj::getCwd());
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Blue_obj,main,(void))

void Blue_obj::mapSource(::String directory){
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_27_mapSource)
HXLINE(  28)		::blue::Blue_obj::directory = directory;
HXLINE(  29)		int i = 0;
HXLINE(  30)		::Array< ::String > files = ::Array_obj< ::String >::__new(0);
HXLINE(  31)		bool _hx_tmp;
HXDLIN(  31)		if (::sys::FileSystem_obj::exists(directory)) {
HXLINE(  31)			_hx_tmp = ::sys::FileSystem_obj::isDirectory(directory);
            		}
            		else {
HXLINE(  31)			_hx_tmp = false;
            		}
HXDLIN(  31)		if (_hx_tmp) {
HXLINE(  32)			::Sys_obj::println((HX_("Compiling source folder: ",e9,e1,f0,0b) + directory));
HXLINE(  33)			{
HXLINE(  33)				int _g = 0;
HXDLIN(  33)				::Array< ::String > _g1 = ::sys::FileSystem_obj::readDirectory(directory);
HXDLIN(  33)				while((_g < _g1->length)){
HXLINE(  33)					::String file = _g1->__get(_g);
HXDLIN(  33)					_g = (_g + 1);
HXLINE(  34)					bool _hx_tmp;
HXDLIN(  34)					if (!(::sys::FileSystem_obj::isDirectory(file))) {
HXLINE(  34)						_hx_tmp = ::StringTools_obj::endsWith(file,HX_(".bl",78,3d,23,00));
            					}
            					else {
HXLINE(  34)						_hx_tmp = false;
            					}
HXDLIN(  34)					if (_hx_tmp) {
HXLINE(  35)						i = (i + 1);
HXLINE(  36)						files->push(file);
HXLINE(  37)						::Sys_obj::println(file);
HXLINE(  38)						if (!(::blue::Blue_obj::checkForErrors(::sys::io::File_obj::getContent(((directory + HX_("/",2f,00,00,00)) + file))))) {
HXLINE(  39)							::String rawContent = ::sys::io::File_obj::getContent(((directory + HX_("/",2f,00,00,00)) + file));
HXLINE(  40)							::blue::Blue_obj::mapFile(((directory + HX_("/",2f,00,00,00)) + file));
HXLINE(  41)							::blue::BHaxeUtil_obj::fileName = file;
HXLINE(  42)							::blue::Blue_obj::lexSourceFile(rawContent);
HXLINE(  43)							if ((i == files->length)) {
HXLINE(  44)								::Sys_obj::command(HX_("haxe -cp src --main export.hxsrc.Main --cpp export/bin",27,fb,f9,49),null());
HXLINE(  45)								::Sys_obj::exit(0);
            							}
            						}
            					}
            				}
            			}
            		}
            		else {
HXLINE(  51)			::Sys_obj::println(((HX_("Error: Source folder '",6c,fd,d1,da) + directory) + HX_("' does not exist or is not a directory",84,e6,8a,70)));
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Blue_obj,mapSource,(void))

void Blue_obj::mapFile(::String input){
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_56_mapFile)
HXDLIN(  56)		::blue::Blue_obj::currentMappedFiles->push(input);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Blue_obj,mapFile,(void))

void Blue_obj::lexSourceFile(::String content){
            	HX_GC_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_60_lexSourceFile)
HXDLIN(  60)		 ::blue::BLexer_obj::__alloc( HX_CTX ,content);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Blue_obj,lexSourceFile,(void))

bool Blue_obj::checkForErrors(::String input){
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_63_checkForErrors)
HXLINE(  64)		if ((input.indexOf(HX_("\n",0a,00,00,00),null()) != -1)) {
HXLINE(  65)			{
HXLINE(  65)				int _g = 0;
HXDLIN(  65)				int _g1 = input.split(HX_("\n",0a,00,00,00))->length;
HXDLIN(  65)				while((_g < _g1)){
HXLINE(  65)					_g = (_g + 1);
HXDLIN(  65)					int i = (_g - 1);
HXLINE(  66)					::String line = input.split(HX_("\n",0a,00,00,00))->__get(i);
HXLINE(  67)					::String letters = HX_("abcdefghijklmnopqrstuvwusyz",2b,b6,72,75);
HXLINE(  68)					::String chars = HX_("@#$%^&_{}:><?|;",1b,b6,41,25);
HXLINE(  69)					bool _hx_tmp;
HXDLIN(  69)					if ((line.indexOf(HX_("if",dd,5b,00,00),null()) != -1)) {
HXLINE(  69)						_hx_tmp = (line.indexOf(HX_("then",dd,02,fc,4c),null()) == -1);
            					}
            					else {
HXLINE(  69)						_hx_tmp = false;
            					}
HXDLIN(  69)					if (_hx_tmp) {
HXLINE(  70)						::Sys_obj::println((HX_("Error: Expected 'then' at the end of line ",21,d7,11,f7) + i));
HXLINE(  71)						return true;
            					}
            					else {
HXLINE(  73)						{
HXLINE(  73)							int _g = 0;
HXDLIN(  73)							int _g1 = letters.split(HX_("",00,00,00,00))->length;
HXDLIN(  73)							while((_g < _g1)){
HXLINE(  73)								_g = (_g + 1);
HXDLIN(  73)								int k = (_g - 1);
HXLINE(  74)								{
HXLINE(  74)									int _g1 = 0;
HXDLIN(  74)									int _g2 = ::blue::Blue_obj::completeSyntax->length;
HXDLIN(  74)									while((_g1 < _g2)){
HXLINE(  74)										_g1 = (_g1 + 1);
HXDLIN(  74)										int l = (_g1 - 1);
HXLINE(  75)										bool _hx_tmp;
HXDLIN(  75)										bool _hx_tmp1;
HXDLIN(  75)										bool _hx_tmp2;
HXDLIN(  75)										bool _hx_tmp3;
HXDLIN(  75)										bool _hx_tmp4;
HXDLIN(  75)										bool _hx_tmp5;
HXDLIN(  75)										bool _hx_tmp6;
HXDLIN(  75)										bool _hx_tmp7;
HXDLIN(  75)										bool _hx_tmp8;
HXDLIN(  75)										bool _hx_tmp9;
HXDLIN(  75)										bool _hx_tmp10;
HXDLIN(  75)										bool _hx_tmp11;
HXDLIN(  75)										bool _hx_tmp12;
HXDLIN(  75)										bool _hx_tmp13;
HXDLIN(  75)										bool _hx_tmp14;
HXDLIN(  75)										bool _hx_tmp15;
HXDLIN(  75)										bool _hx_tmp16;
HXDLIN(  75)										if ((line.indexOf(letters.split(HX_("",00,00,00,00))->__get(k),null()) != -1)) {
HXLINE(  75)											_hx_tmp16 = (line.indexOf(HX_("=",3d,00,00,00),null()) != -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp16 = false;
            										}
HXDLIN(  75)										if (_hx_tmp16) {
HXLINE(  75)											_hx_tmp15 = (line.indexOf(HX_("if",dd,5b,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp15 = false;
            										}
HXDLIN(  75)										if (_hx_tmp15) {
HXLINE(  75)											_hx_tmp14 = (line.indexOf(HX_("1",31,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp14 = false;
            										}
HXDLIN(  75)										if (_hx_tmp14) {
HXLINE(  75)											_hx_tmp13 = (line.indexOf(HX_("2",32,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp13 = false;
            										}
HXDLIN(  75)										if (_hx_tmp13) {
HXLINE(  75)											_hx_tmp12 = (line.indexOf(HX_("3",33,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp12 = false;
            										}
HXDLIN(  75)										if (_hx_tmp12) {
HXLINE(  75)											_hx_tmp11 = (line.indexOf(HX_("4",34,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp11 = false;
            										}
HXDLIN(  75)										if (_hx_tmp11) {
HXLINE(  75)											_hx_tmp10 = (line.indexOf(HX_("5",35,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp10 = false;
            										}
HXDLIN(  75)										if (_hx_tmp10) {
HXLINE(  75)											_hx_tmp9 = (line.indexOf(HX_("6",36,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp9 = false;
            										}
HXDLIN(  75)										if (_hx_tmp9) {
HXLINE(  75)											_hx_tmp8 = (line.indexOf(HX_("7",37,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp8 = false;
            										}
HXDLIN(  75)										if (_hx_tmp8) {
HXLINE(  75)											_hx_tmp7 = (line.indexOf(HX_("8",38,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp7 = false;
            										}
HXDLIN(  75)										if (_hx_tmp7) {
HXLINE(  75)											_hx_tmp6 = (line.indexOf(HX_("9",39,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp6 = false;
            										}
HXDLIN(  75)										if (_hx_tmp6) {
HXLINE(  75)											_hx_tmp5 = (line.indexOf(HX_("true",4e,a7,03,4d),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp5 = false;
            										}
HXDLIN(  75)										if (_hx_tmp5) {
HXLINE(  75)											_hx_tmp4 = (line.indexOf(HX_("false",a3,35,4f,fb),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp4 = false;
            										}
HXDLIN(  75)										if (_hx_tmp4) {
HXLINE(  75)											_hx_tmp3 = (line.indexOf(HX_("'",27,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp3 = false;
            										}
HXDLIN(  75)										if (_hx_tmp3) {
HXLINE(  75)											_hx_tmp2 = (line.indexOf(HX_("\"",22,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp2 = false;
            										}
HXDLIN(  75)										if (_hx_tmp2) {
HXLINE(  75)											_hx_tmp1 = (line.indexOf(HX_("[",5b,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp1 = false;
            										}
HXDLIN(  75)										if (_hx_tmp1) {
HXLINE(  75)											_hx_tmp = (line.indexOf(HX_("]",5d,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  75)											_hx_tmp = false;
            										}
HXDLIN(  75)										if (_hx_tmp) {
HXLINE(  79)											::Sys_obj::println((HX_("Error: Values assigned to variables can only be 'Bool', 'Int', 'Float', 'String', or 'Array', Which was not found at line ",95,91,54,be) + i));
HXLINE(  81)											return true;
            										}
HXLINE(  84)										bool _hx_tmp17;
HXDLIN(  84)										bool _hx_tmp18;
HXDLIN(  84)										bool _hx_tmp19;
HXDLIN(  84)										bool _hx_tmp20;
HXDLIN(  84)										bool _hx_tmp21;
HXDLIN(  84)										bool _hx_tmp22;
HXDLIN(  84)										bool _hx_tmp23;
HXDLIN(  84)										bool _hx_tmp24;
HXDLIN(  84)										bool _hx_tmp25;
HXDLIN(  84)										bool _hx_tmp26;
HXDLIN(  84)										bool _hx_tmp27;
HXDLIN(  84)										bool _hx_tmp28;
HXDLIN(  84)										bool _hx_tmp29;
HXDLIN(  84)										bool _hx_tmp30;
HXDLIN(  84)										bool _hx_tmp31;
HXDLIN(  84)										bool _hx_tmp32;
HXDLIN(  84)										bool _hx_tmp33;
HXDLIN(  84)										bool _hx_tmp34;
HXDLIN(  84)										bool _hx_tmp35;
HXDLIN(  84)										if ((line.indexOf(letters.split(HX_("",00,00,00,00))->__get(k),null()) != -1)) {
HXLINE(  84)											_hx_tmp35 = (line.indexOf(HX_("if",dd,5b,00,00),null()) != -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp35 = false;
            										}
HXDLIN(  84)										if (_hx_tmp35) {
HXLINE(  84)											_hx_tmp34 = (line.indexOf(HX_("1",31,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp34 = false;
            										}
HXDLIN(  84)										if (_hx_tmp34) {
HXLINE(  84)											_hx_tmp33 = (line.indexOf(HX_("2",32,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp33 = false;
            										}
HXDLIN(  84)										if (_hx_tmp33) {
HXLINE(  84)											_hx_tmp32 = (line.indexOf(HX_("3",33,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp32 = false;
            										}
HXDLIN(  84)										if (_hx_tmp32) {
HXLINE(  84)											_hx_tmp31 = (line.indexOf(HX_("4",34,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp31 = false;
            										}
HXDLIN(  84)										if (_hx_tmp31) {
HXLINE(  84)											_hx_tmp30 = (line.indexOf(HX_("5",35,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp30 = false;
            										}
HXDLIN(  84)										if (_hx_tmp30) {
HXLINE(  84)											_hx_tmp29 = (line.indexOf(HX_("6",36,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp29 = false;
            										}
HXDLIN(  84)										if (_hx_tmp29) {
HXLINE(  84)											_hx_tmp28 = (line.indexOf(HX_("7",37,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp28 = false;
            										}
HXDLIN(  84)										if (_hx_tmp28) {
HXLINE(  84)											_hx_tmp27 = (line.indexOf(HX_("8",38,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp27 = false;
            										}
HXDLIN(  84)										if (_hx_tmp27) {
HXLINE(  84)											_hx_tmp26 = (line.indexOf(HX_("9",39,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp26 = false;
            										}
HXDLIN(  84)										if (_hx_tmp26) {
HXLINE(  84)											_hx_tmp25 = (line.indexOf(HX_("true",4e,a7,03,4d),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp25 = false;
            										}
HXDLIN(  84)										if (_hx_tmp25) {
HXLINE(  84)											_hx_tmp24 = (line.indexOf(HX_("false",a3,35,4f,fb),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp24 = false;
            										}
HXDLIN(  84)										if (_hx_tmp24) {
HXLINE(  84)											_hx_tmp23 = (line.indexOf(HX_("'",27,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp23 = false;
            										}
HXDLIN(  84)										if (_hx_tmp23) {
HXLINE(  84)											_hx_tmp22 = (line.indexOf(HX_("\"",22,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp22 = false;
            										}
HXDLIN(  84)										if (_hx_tmp22) {
HXLINE(  84)											_hx_tmp21 = (line.indexOf(HX_("=",3d,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp21 = false;
            										}
HXDLIN(  84)										if (_hx_tmp21) {
HXLINE(  84)											_hx_tmp20 = (line.indexOf(HX_("greater than",47,34,3c,43),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp20 = false;
            										}
HXDLIN(  84)										if (_hx_tmp20) {
HXLINE(  84)											_hx_tmp19 = (line.indexOf(HX_("less than",88,b9,bc,f1),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp19 = false;
            										}
HXDLIN(  84)										if (_hx_tmp19) {
HXLINE(  84)											_hx_tmp18 = (line.indexOf(HX_("div",51,3d,4c,00),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp18 = false;
            										}
HXDLIN(  84)										if (_hx_tmp18) {
HXLINE(  84)											_hx_tmp17 = (line.indexOf(HX_("mult",f0,67,65,48),null()) == -1);
            										}
            										else {
HXLINE(  84)											_hx_tmp17 = false;
            										}
HXDLIN(  84)										if (_hx_tmp17) {
HXLINE(  89)											::Sys_obj::println((HX_("Error: A valid 'if' condition was not found at line ",92,e4,43,51) + i));
HXLINE(  90)											return true;
            										}
HXLINE(  93)										bool _hx_tmp36;
HXDLIN(  93)										bool _hx_tmp37;
HXDLIN(  93)										bool _hx_tmp38;
HXDLIN(  93)										bool _hx_tmp39;
HXDLIN(  93)										bool _hx_tmp40;
HXDLIN(  93)										bool _hx_tmp41;
HXDLIN(  93)										bool _hx_tmp42;
HXDLIN(  93)										bool _hx_tmp43;
HXDLIN(  93)										bool _hx_tmp44;
HXDLIN(  93)										bool _hx_tmp45;
HXDLIN(  93)										bool _hx_tmp46;
HXDLIN(  93)										bool _hx_tmp47;
HXDLIN(  93)										bool _hx_tmp48;
HXDLIN(  93)										bool _hx_tmp49;
HXDLIN(  93)										bool _hx_tmp50;
HXDLIN(  93)										bool _hx_tmp51;
HXDLIN(  93)										bool _hx_tmp52;
HXDLIN(  93)										bool _hx_tmp53;
HXDLIN(  93)										bool _hx_tmp54;
HXDLIN(  93)										bool _hx_tmp55;
HXDLIN(  93)										bool _hx_tmp56;
HXDLIN(  93)										if ((line.indexOf(letters.split(HX_("",00,00,00,00))->__get(k),null()) != -1)) {
HXLINE(  93)											_hx_tmp56 = (line.indexOf(HX_("loop",64,a6,b7,47),null()) != -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp56 = false;
            										}
HXDLIN(  93)										if (_hx_tmp56) {
HXLINE(  93)											_hx_tmp55 = (line.indexOf(HX_("1",31,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp55 = false;
            										}
HXDLIN(  93)										if (_hx_tmp55) {
HXLINE(  93)											_hx_tmp54 = (line.indexOf(HX_("2",32,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp54 = false;
            										}
HXDLIN(  93)										if (_hx_tmp54) {
HXLINE(  93)											_hx_tmp53 = (line.indexOf(HX_("3",33,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp53 = false;
            										}
HXDLIN(  93)										if (_hx_tmp53) {
HXLINE(  93)											_hx_tmp52 = (line.indexOf(HX_("4",34,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp52 = false;
            										}
HXDLIN(  93)										if (_hx_tmp52) {
HXLINE(  93)											_hx_tmp51 = (line.indexOf(HX_("5",35,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp51 = false;
            										}
HXDLIN(  93)										if (_hx_tmp51) {
HXLINE(  93)											_hx_tmp50 = (line.indexOf(HX_("6",36,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp50 = false;
            										}
HXDLIN(  93)										if (_hx_tmp50) {
HXLINE(  93)											_hx_tmp49 = (line.indexOf(HX_("7",37,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp49 = false;
            										}
HXDLIN(  93)										if (_hx_tmp49) {
HXLINE(  93)											_hx_tmp48 = (line.indexOf(HX_("8",38,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp48 = false;
            										}
HXDLIN(  93)										if (_hx_tmp48) {
HXLINE(  93)											_hx_tmp47 = (line.indexOf(HX_("9",39,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp47 = false;
            										}
HXDLIN(  93)										if (_hx_tmp47) {
HXLINE(  93)											_hx_tmp46 = (line.indexOf(HX_("true",4e,a7,03,4d),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp46 = false;
            										}
HXDLIN(  93)										if (_hx_tmp46) {
HXLINE(  93)											_hx_tmp45 = (line.indexOf(HX_("false",a3,35,4f,fb),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp45 = false;
            										}
HXDLIN(  93)										if (_hx_tmp45) {
HXLINE(  93)											_hx_tmp44 = (line.indexOf(HX_("'",27,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp44 = false;
            										}
HXDLIN(  93)										if (_hx_tmp44) {
HXLINE(  93)											_hx_tmp43 = (line.indexOf(HX_("\"",22,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp43 = false;
            										}
HXDLIN(  93)										if (_hx_tmp43) {
HXLINE(  93)											_hx_tmp42 = (line.indexOf(HX_("=",3d,00,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp42 = false;
            										}
HXDLIN(  93)										if (_hx_tmp42) {
HXLINE(  93)											_hx_tmp41 = (line.indexOf(HX_("greater than",47,34,3c,43),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp41 = false;
            										}
HXDLIN(  93)										if (_hx_tmp41) {
HXLINE(  93)											_hx_tmp40 = (line.indexOf(HX_("less than",88,b9,bc,f1),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp40 = false;
            										}
HXDLIN(  93)										if (_hx_tmp40) {
HXLINE(  93)											_hx_tmp39 = (line.indexOf(HX_("div",51,3d,4c,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp39 = false;
            										}
HXDLIN(  93)										if (_hx_tmp39) {
HXLINE(  93)											_hx_tmp38 = (line.indexOf(HX_("mult",f0,67,65,48),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp38 = false;
            										}
HXDLIN(  93)										if (_hx_tmp38) {
HXLINE(  93)											_hx_tmp37 = (line.indexOf(HX_("until",9e,b8,ef,a6),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp37 = false;
            										}
HXDLIN(  93)										if (_hx_tmp37) {
HXLINE(  93)											_hx_tmp36 = (line.indexOf(HX_("in",e5,5b,00,00),null()) == -1);
            										}
            										else {
HXLINE(  93)											_hx_tmp36 = false;
            										}
HXDLIN(  93)										if (_hx_tmp36) {
HXLINE(  98)											::Sys_obj::println((HX_("Error: A valid 'loop' expression was not found at line ",76,ba,74,5a) + i));
HXLINE(  99)											return true;
            										}
            									}
            								}
            							}
            						}
HXLINE( 103)						{
HXLINE( 103)							int _g2 = 0;
HXDLIN( 103)							int _g3 = chars.split(HX_("",00,00,00,00))->length;
HXDLIN( 103)							while((_g2 < _g3)){
HXLINE( 103)								_g2 = (_g2 + 1);
HXDLIN( 103)								int n = (_g2 - 1);
HXLINE( 104)								bool _hx_tmp;
HXDLIN( 104)								if ((line.indexOf(chars.split(HX_("",00,00,00,00))->__get(n),null()) != -1)) {
HXLINE( 104)									::String s = ::blue::Blue_obj::completeSyntax->__get(i);
HXDLIN( 104)									_hx_tmp = (s.indexOf(chars.split(HX_("",00,00,00,00))->__get(n),null()) == -1);
            								}
            								else {
HXLINE( 104)									_hx_tmp = false;
            								}
HXDLIN( 104)								if (_hx_tmp) {
HXLINE( 105)									::Sys_obj::println((((HX_("Error: Unknown character: ",4b,01,29,5a) + chars.split(HX_("",00,00,00,00))->__get(n)) + HX_(" at line ",df,96,71,22)) + i));
HXLINE( 106)									return true;
            								}
            							}
            						}
            					}
HXLINE( 111)					bool _hx_tmp1;
HXDLIN( 111)					if ((line.indexOf(HX_("method",e1,f6,5a,09),null()) != -1)) {
HXLINE( 111)						_hx_tmp1 = (line.indexOf(HX_(":",3a,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 111)						_hx_tmp1 = false;
            					}
HXDLIN( 111)					if (_hx_tmp1) {
HXLINE( 112)						::Sys_obj::println(((HX_("Error: Unknown character: ':'",29,6a,5e,80) + HX_(" at line ",df,96,71,22)) + i));
HXLINE( 113)						return true;
            					}
HXLINE( 115)					bool _hx_tmp2;
HXDLIN( 115)					if ((line.indexOf(HX_("(",28,00,00,00),null()) != -1)) {
HXLINE( 115)						_hx_tmp2 = (line.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).indexOf(HX_(",",2c,00,00,00),null()) != -1);
            					}
            					else {
HXLINE( 115)						_hx_tmp2 = false;
            					}
HXDLIN( 115)					if (_hx_tmp2) {
HXLINE( 116)						bool _hx_tmp;
HXDLIN( 116)						if ((input.indexOf(::StringTools_obj::replace(line.split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00)),null()) != -1)) {
HXLINE( 116)							_hx_tmp = (input.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).indexOf(HX_(",",2c,00,00,00),null()) != -1);
            						}
            						else {
HXLINE( 116)							_hx_tmp = false;
            						}
HXDLIN( 116)						if (_hx_tmp) {
HXLINE( 117)							int _hx_tmp = line.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).split(HX_(",",2c,00,00,00))->length;
HXDLIN( 117)							if ((_hx_tmp > input.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).split(HX_(",",2c,00,00,00))->length)) {
HXLINE( 118)								::Sys_obj::println((((HX_("Error: Too many parameters for method: ",ed,d9,1b,50) + ::StringTools_obj::replace(line.split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_(" at line ",df,96,71,22)) + i));
HXLINE( 119)								return true;
            							}
            							else {
HXLINE( 120)								int _hx_tmp = line.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).split(HX_(",",2c,00,00,00))->length;
HXDLIN( 120)								if ((_hx_tmp < input.split(HX_("(",28,00,00,00))->__get(1).split(HX_(")",29,00,00,00))->__get(0).split(HX_(",",2c,00,00,00))->length)) {
HXLINE( 121)									::Sys_obj::println((((HX_("Error: Not enough parameters for method: ",df,32,a5,55) + ::StringTools_obj::replace(line.split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_(" at line ",df,96,71,22)) + i));
HXLINE( 122)									return true;
            								}
            							}
            						}
            					}
HXLINE( 126)					bool _hx_tmp3;
HXDLIN( 126)					if ((line.indexOf(HX_("new ",c0,83,02,49),null()) != -1)) {
HXLINE( 126)						_hx_tmp3 = ::sys::FileSystem_obj::exists((line.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0) + HX_(".bl",78,3d,23,00)));
            					}
            					else {
HXLINE( 126)						_hx_tmp3 = false;
            					}
HXDLIN( 126)					if (_hx_tmp3) {
HXLINE( 127)						if ((::sys::io::File_obj::getContent((line.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0) + HX_(".bl",78,3d,23,00))).indexOf(HX_("constructor method()",08,d8,4a,0a),null()) == -1)) {
HXLINE( 128)							::Sys_obj::println((((HX_("Error: Source File: ",b9,e3,33,52) + line.split(HX_("new ",c0,83,02,49))->__get(1).split(HX_("(",28,00,00,00))->__get(0)) + HX_(" has no constructor method at line ",7f,66,51,a3)) + i));
HXLINE( 129)							return true;
            						}
            					}
HXLINE( 133)					bool _hx_tmp4;
HXDLIN( 133)					if ((line.indexOf(HX_("constructor method()",08,d8,4a,0a),null()) != -1)) {
HXLINE( 133)						_hx_tmp4 = (input.split(HX_("constructor method()",08,d8,4a,0a))->__get(1).split(HX_("end",db,03,4d,00))->__get(0).indexOf(HX_("return ",70,75,c2,fe),null()) != -1);
            					}
            					else {
HXLINE( 133)						_hx_tmp4 = false;
            					}
HXDLIN( 133)					if (_hx_tmp4) {
HXLINE( 134)						::Sys_obj::println((HX_("Error: Constructor methods cannot have a return value at line ",c2,7f,49,19) + i));
HXLINE( 135)						return true;
            					}
HXLINE( 138)					bool _hx_tmp5;
HXDLIN( 138)					if ((line.indexOf(HX_("main method()",e9,ec,13,c5),null()) != -1)) {
HXLINE( 138)						_hx_tmp5 = (input.split(HX_("main method()",e9,ec,13,c5))->__get(1).split(HX_("end",db,03,4d,00))->__get(0).indexOf(HX_("return ",70,75,c2,fe),null()) != -1);
            					}
            					else {
HXLINE( 138)						_hx_tmp5 = false;
            					}
HXDLIN( 138)					if (_hx_tmp5) {
HXLINE( 139)						::Sys_obj::println((HX_("Error: The main method cannot have a return value at line ",af,6d,78,26) + i));
HXLINE( 140)						return true;
            					}
HXLINE( 151)					if ((line.indexOf(HX_("[0]",48,37,45,00),null()) != -1)) {
HXLINE( 152)						::Sys_obj::println((HX_("Error: Array index's start at '1' at line ",fa,81,14,16) + i));
HXLINE( 153)						return true;
            					}
HXLINE( 156)					bool _hx_tmp6;
HXDLIN( 156)					bool _hx_tmp7;
HXDLIN( 156)					if ((line.indexOf(HX_("method ",1f,0e,3d,26),null()) != -1)) {
HXLINE( 156)						_hx_tmp7 = (line.indexOf(HX_("(",28,00,00,00),null()) == -1);
            					}
            					else {
HXLINE( 156)						_hx_tmp7 = false;
            					}
HXDLIN( 156)					if (_hx_tmp7) {
HXLINE( 156)						_hx_tmp6 = (line.indexOf(HX_(")",29,00,00,00),null()) == -1);
            					}
            					else {
HXLINE( 156)						_hx_tmp6 = false;
            					}
HXDLIN( 156)					if (_hx_tmp6) {
HXLINE( 157)						::Sys_obj::println((((HX_("Error: Method: ",35,c6,b2,e5) + ::StringTools_obj::replace(line.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_("is missing it's parameter brackets at line ",64,00,45,69)) + i));
HXLINE( 159)						return true;
            					}
HXLINE( 162)					bool _hx_tmp8;
HXDLIN( 162)					if ((line.indexOf(HX_("method ",1f,0e,3d,26),null()) != -1)) {
HXLINE( 162)						_hx_tmp8 = (input.split(HX_("method ",1f,0e,3d,26))->__get(1).indexOf(HX_("end",db,03,4d,00),null()) == -1);
            					}
            					else {
HXLINE( 162)						_hx_tmp8 = false;
            					}
HXDLIN( 162)					if (_hx_tmp8) {
HXLINE( 163)						::Sys_obj::println((((HX_("Error: Method: ",35,c6,b2,e5) + ::StringTools_obj::replace(line.split(HX_("method ",1f,0e,3d,26))->__get(1).split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_("is missing it's enclosing 'end' block at line ",cc,be,43,ad)) + i));
HXLINE( 165)						return true;
            					}
HXLINE( 168)					bool _hx_tmp9;
HXDLIN( 168)					if ((line.indexOf(HX_("loop ",3c,f1,f9,78),null()) != -1)) {
HXLINE( 168)						_hx_tmp9 = (input.split(HX_("loop ",3c,f1,f9,78))->__get(1).indexOf(HX_("end",db,03,4d,00),null()) == -1);
            					}
            					else {
HXLINE( 168)						_hx_tmp9 = false;
            					}
HXDLIN( 168)					if (_hx_tmp9) {
HXLINE( 169)						::Sys_obj::println((((HX_("Error: Loop: ",f8,84,61,85) + ::StringTools_obj::replace(line.split(HX_("loop ",3c,f1,f9,78))->__get(1).split(HX_("(",28,00,00,00))->__get(0),HX_(" ",20,00,00,00),HX_("",00,00,00,00))) + HX_("is missing it's enclosing 'end' block at line ",cc,be,43,ad)) + i));
HXLINE( 171)						return true;
            					}
HXLINE( 174)					bool _hx_tmp10;
HXDLIN( 174)					if ((line.indexOf(HX_("if ",a3,05,50,00),null()) != -1)) {
HXLINE( 174)						_hx_tmp10 = (input.split(HX_("if ",a3,05,50,00))->__get(1).indexOf(HX_("end",db,03,4d,00),null()) == -1);
            					}
            					else {
HXLINE( 174)						_hx_tmp10 = false;
            					}
HXDLIN( 174)					if (_hx_tmp10) {
HXLINE( 175)						::Sys_obj::println((HX_("Error: An if statement is missing it's enclosing 'end' block at line ",7b,e5,06,60) + i));
HXLINE( 176)						return true;
            					}
HXLINE( 179)					bool _hx_tmp11;
HXDLIN( 179)					if ((line.indexOf(HX_("otherwise",f4,83,f2,9a),null()) != -1)) {
HXLINE( 179)						_hx_tmp11 = (input.split(HX_("otherwise",f4,83,f2,9a))->__get(1).indexOf(HX_("end",db,03,4d,00),null()) == -1);
            					}
            					else {
HXLINE( 179)						_hx_tmp11 = false;
            					}
HXDLIN( 179)					if (_hx_tmp11) {
HXLINE( 180)						::Sys_obj::println((HX_("Error: An else statement is missing it's enclosing 'end' block at line ",df,7d,41,d8) + i));
HXLINE( 181)						return true;
            					}
            				}
            			}
HXLINE( 185)			return false;
            		}
HXLINE( 187)		return false;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Blue_obj,checkForErrors,return )


Blue_obj::Blue_obj()
{
}

bool Blue_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
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
	case 8:
		if (HX_FIELD_EQ(inName,"mainFile") ) { mainFile=ioValue.Cast< ::String >(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"directory") ) { directory=ioValue.Cast< ::String >(); return true; }
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
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &Blue_obj::completeSyntax,HX_("completeSyntax",fc,c7,f3,b6)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void Blue_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Blue_obj::currentMappedFiles,"currentMappedFiles");
	HX_MARK_MEMBER_NAME(Blue_obj::currentMappedLines,"currentMappedLines");
	HX_MARK_MEMBER_NAME(Blue_obj::directory,"directory");
	HX_MARK_MEMBER_NAME(Blue_obj::mainFile,"mainFile");
	HX_MARK_MEMBER_NAME(Blue_obj::completeSyntax,"completeSyntax");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Blue_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Blue_obj::currentMappedFiles,"currentMappedFiles");
	HX_VISIT_MEMBER_NAME(Blue_obj::currentMappedLines,"currentMappedLines");
	HX_VISIT_MEMBER_NAME(Blue_obj::directory,"directory");
	HX_VISIT_MEMBER_NAME(Blue_obj::mainFile,"mainFile");
	HX_VISIT_MEMBER_NAME(Blue_obj::completeSyntax,"completeSyntax");
};

#endif

::hx::Class Blue_obj::__mClass;

static ::String Blue_obj_sStaticFields[] = {
	HX_("currentMappedFiles",0b,16,a5,79),
	HX_("currentMappedLines",93,15,0e,ee),
	HX_("directory",6d,f2,44,10),
	HX_("mainFile",55,43,3e,9c),
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
            	HX_STACKFRAME(&_hx_pos_67c8f7f6948cffcd_18_boot)
HXDLIN(  18)		completeSyntax = ::Array_obj< ::String >::fromData( _hx_array_data_ed6e2d0e_15,25);
            	}
}

} // end namespace blue
