/*
a way for identifying statically linked built-in modules
the technique is genreal , but this specific is taken directly
from Python sources
*/

#include "stdafx.h"

//--- Begin Externs ---//
extern void ZModInit_Test();
extern void ZModInit_Test2();
//---  End Externs  ---//

//--- Begin Module Inserions ---//
ZBuiltinModule ZBMods[]={

	{_ZC("Test"),ZModInit_Test},
	{_ZC("Test2"),ZModInit_Test2},
	{0,0}
};
//---  End Module Inserions  ---//
