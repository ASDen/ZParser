#include "stdafx.h"
namespace Helper
{
	class Function
	{
	public:
		static bool ZTestArg(ZFunction* fun,ZTvarS Fargs)
		{
			return (fun->NumArgs<=Fargs.size())?true:false;
		}
	};
}