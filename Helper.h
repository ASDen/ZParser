#include "stdafx.h"
namespace Helper
{
	class Function
	{
	public:
		static bool ZTestArg(ZIFunction* fun,ZTvarS Fargs)
		{
			return (fun->NumArgs<=Fargs.size())?true:false;
		}
	};
}