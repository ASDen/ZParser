#include "../stdafx.h"
#include "../ZInterp.h"

#define _USE_MATH_DEFINES
#include "math.h"

class Zsqrt : public boost::static_visitor<ZTvar>
{
public:

	BASE_CASE_1

	template<class S,template <typename,typename> class T>
	ZTvar operator()(T<S,NumOps> &a1) const
	{
		return ZTFloat(sqrtf(a1.cont->val));;
	}

	static ZTvarp Zsqrt_(ZTvarS var)
	{
		if (var.size() != 1)
		{
			ZError::Throw<ZWrongNumberOfArguments>();
			return NULL;
		}

		ZTvarp res = ZAlloc(ZTvar,1);
		*res=boost::apply_visitor(Zsqrt(),*(var[0]));
		return res;
	}
};

class Zsin : public boost::static_visitor<ZTvar>
{
public:

	BASE_CASE_1

	template<class S,template <typename,typename> class T>
	ZTvar operator()(T<S,NumOps> &a1) const
	{
		return ZTFloat(sin(a1.cont->val * M_PI / 180.0));;
	}

	static ZTvarp Zsin_(ZTvarS var)
	{
		if (var.size() != 1)
		{
			ZError::Throw<ZWrongNumberOfArguments>();
			return NULL;
		}

		ZTvarp res=ZAlloc(ZTvar,1);
		*res=boost::apply_visitor(Zsin(),*(var[0]));
		return res;
	}
};

class Zcos : public boost::static_visitor<ZTvar>
{
public:

	BASE_CASE_1

	template<class S,template <typename,typename> class T>
	ZTvar operator()(T<S,NumOps> &a1) const
	{
		return ZTFloat(cos(a1.cont->val * M_PI / 180.0));;
	}

	static ZTvarp Zcos_(ZTvarS var)
	{
		if (var.size() != 1)
		{
			ZError::Throw<ZWrongNumberOfArguments>();
			return NULL;
		}

		ZTvarp res=ZAlloc(ZTvar,1);
		*res=boost::apply_visitor(Zcos(),*(var[0]));
		return res;
	}
};

class Ztan : public boost::static_visitor<ZTvar>
{
public:

	BASE_CASE_1

	template<class S,template <typename,typename> class T>
	ZTvar operator()(T<S,NumOps> &a1) const
	{
		return ZTFloat(tan(a1.cont->val * M_PI / 180.0));;
	}

	static ZTvarp Ztan_(ZTvarS var)
	{
		if (var.size() != 1)
		{
			ZError::Throw<ZWrongNumberOfArguments>();
			return NULL;
		}

		ZTvarp res=ZAlloc(ZTvar,1);
		*res=boost::apply_visitor(Ztan(),*(var[0]));
		return res;
	}
};
class Zpower : public boost::static_visitor<ZTvar>
{
public:

	BASE_CASE

	template<class S,class W,template <typename,typename> class T>
	ZTvar operator()(T<S,NumOps> &a1,T<W,NumOps> &a2) const
	{
		return ZTFloat(pow((ZIFloat)a1.cont->val,(ZIFloat)a2.cont->val));;
	}

	static ZTvarp Zpower_(ZTvarS var)
	{
		if (var.size() != 2)
		{
			ZError::Throw<ZWrongNumberOfArguments>();
			return NULL;
		}

		ZTvarp res = ZAlloc(ZTvar,1);
		*res=boost::apply_visitor( Zpower() , *(var[0]) ,*(var[1]) );
		return res;
	}
};


ZTvarp Zprint(ZTvarS var)
{
	
	for(int i=0;i<var.size();i++)
	{
		string data=boost::apply_visitor(ToString(),*(var[i]));
		while (data!="")
		{
			int i=data.find("\\");
			if(i>=0)
			{
				switch(data[i+1])
				{
				case 'n':
					std::cout<< data.substr(0,data.find("\\"))<<"\n" ;
					break;
				case 't':
					std::cout<< data.substr(0,data.find("\\"))<<"\t" ;
					break;
				case '\\':
					std::cout<<data.substr(0,data.find("\\"))<<"\\";
					break;
				case '\r':
					std::cout<<data.substr(0,data.find("\\"))<<"\r";
					break;
				case '\"':
					std::cout<<data.substr(0,data.find("\\"))<<"\"";
					break;
				case 'b':
					std::cout<< data.substr(0,data.find("\\"))<<"\b" ;
					break;
				}
				data=data.replace(0,data.find("\\")+2,"");
			}
			else
			{
				std::cout<<data;
				break;
			}
		}
	}
	ZTvarp res = ZAlloc(ZTvar,1);
	*res=ZTBool(true);
	return res;
}

ZTvarp ZprintL(ZTvarS var)
{
	for(int i=0;i<var.size();i++)
		std::cout<< boost::apply_visitor(ToString(),*(var[i])) ;
	std::cout<<std::endl;
	ZTvarp res=ZAlloc(ZTvar,1);
	*res=ZTBool(true);
	return res;
}

ZTvarp ZRead(ZTvarS var)
{
	string s;
	std::cin>> s;
	ZTString str=ZTString(s);
	ZTvarp inp=ZAlloc(ZTvar,1);
	*inp=str;
	return inp;
}

ZTvarp ZParseInt(ZTvarS inp)
{
	try
	{
		ZIInteger i = boost::lexical_cast<int>(STRING_ZCONV( *inp[0]));

		ZTvarp res=ZAlloc(ZTvar,1);
		*res=ZTInt(i);
		return res;
	}

	catch(boost::bad_lexical_cast& e)
	{
		ZError::Throw<ZBadConversionError>();
		return NULL;
	}
}

void ZModInit_Test()
{
	ZIFunction* zf=ZAlloc(ZIFunction,50);
	ZTvarp zv=ZAlloc(ZTvar,50);

	zf->pFunInit(1,Zprint);
	*zv=ZTFunction(zf);
	ZInterp::ZSym.InsertSymbol(_ZC("print"),zv);

	zf++;zv++;
	zf->pFunInit(1,ZprintL);
	*zv=ZTFunction(zf);
	ZInterp::ZSym.InsertSymbol(_ZC("printL"),zv);

	zf++;zv++;
	zf->pFunInit(1,Zsqrt::Zsqrt_);
	*zv=ZTFunction(zf);
	ZInterp::ZSym.InsertSymbol(_ZC("sqrt"),zv);

	zf++;zv++;
	zf->pFunInit(2,Zpower::Zpower_);
	*zv=ZTFunction(zf);
	ZInterp::ZSym.InsertSymbol(_ZC("pow"),zv);

	zf++;zv++;
	zf->pFunInit(0,ZRead);
	*zv=ZTFunction(zf);
	ZInterp::ZSym.InsertSymbol(_ZC("Read"),zv);

	zf++;zv++;
	zf->pFunInit(1,ZParseInt);
	*zv=ZTFunction(zf);
	ZInterp::ZSym.InsertSymbol(_ZC("ParseInt"),zv);

	zf++;zv++;
	zf->pFunInit(1,Zsin::Zsin_);
	*zv=ZTFunction(zf);
	ZInterp::ZSym.InsertSymbol(_ZC("sin"),zv);

	zf++;zv++;
	zf->pFunInit(1,Zcos::Zcos_);
	*zv=ZTFunction(zf);
	ZInterp::ZSym.InsertSymbol(_ZC("cos"),zv);

	zf++;zv++;
	zf->pFunInit(1,Ztan::Ztan_);
	*zv=ZTFunction(zf);
	ZInterp::ZSym.InsertSymbol(_ZC("tan"),zv);

}