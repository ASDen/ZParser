/*
a way for identifying statically linked built-in modules
the technique is genreal , but this specific is taken directly
from Python sources
*/

#include "stdafx.h"

//--- Begin Externs ---//
extern void ZModInit_Test();
//---  End Externs  ---//

//--- Begin Module Inserions ---//
ZBuiltinModule ZBMods[]={

	{_ZC("Test"),ZModInit_Test},
	{0,0}
};
//---  End Module Inserions  ---//
