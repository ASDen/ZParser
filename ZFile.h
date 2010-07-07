#include "stdafx.h"
#include "ZInterp.h"
#include <fstream>
using namespace std;
class ZFile : public ZTBaseObject<ZFile> 
{
public:
	fstream file;
	
	static void Init()
	{
		StProps.InitScope();

		AddFunction(_ZC("ToString"),0,&ZFile::toString);
		AddFunction(_ZC("Read"),0,&ZFile::ZRead);

		ZTObject::Inheriet(StProps);
	}

	ZFile(ZTvarS inp)
	{
		file.open(STRING_ZCONV(*(inp[0])).c_str());
		ZFile();
	}

	ZFile()
	{
	}

	ZTvarp toString(ZTvarS inp)
	{
		ZTvarp res=ZAlloc(ZTvar,1);
		ZIString str=_ZC("File Object");
		*res=ZTString(str);
		return res;
	}

	ZTvarp ZRead(ZTvarS inp)
	{
		int size = INT_ZCONV(*(inp[0]));
		ZTvarp res=ZAlloc(ZTvar,1);
		string data="";char ch;
		for ( int i=0;i < size; i++)
		{
			file>>ch;
			data +=ch;
		}
		*res=ZTString(data);
		return res;
	}

};
