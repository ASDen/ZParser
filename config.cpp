/*
a way for identifying statically linked built-in modules
the technique is genreal , but this specific is taken directly
from Python sources
*/

#include "stdafx.h"

//--- Begin Externs ---//
extern void ZModInit_Test();
extern void ZModInit_Test2();
extern void ZModInit_ZMath();
extern void ZModInit_ZArray();
extern void ZModInit_CGsp();
//---  End Externs  ---//

//--- Begin Module Inserions ---//
ZBuiltinModule ZBMods[]={

	//{_ZC("Test"),ZModInit_Test},
	//{_ZC("Test2"),ZModInit_Test2},
	//{_ZC("ZMath"),ZModInit_ZMath},
	//{_ZC("ZArray"),ZModInit_ZArray},
	{_ZC("CGsp"),ZModInit_CGsp},
	{0,0}
};
//---  End Module Inserions  ---//
