class ZPoint : public ZTBaseObject<ZPoint> 
{
public:
    ZTList myList;
    
    static void Init()
    {
        StProps.InitScope();
        AddFunction(_ZC("X"),1,&ZPoint::X);
        AddFunction(_ZC("Y"),1,&ZPoint::Y);
        AddFunction(_ZC("Z"),1,&ZPoint::Z);
        ZTObject::Inheriet(StProps);
    }

    ZPoint(ZTvarS inp)
    {
        switch(inp.size())
        {
        case 1:
            myList = LIST_ZCONV(*inp[ 0 ] );
            break;
        case 3:
            myList.Append(inp[0]);
            myList.Append(inp[1]);
            myList.Append(inp[2]);
            break;
        }
        
        ZPoint();
    }

    ZPoint()
    {
        //AddDataMember(_ZC("PI") , &ZArray::ZPI);
        //AddDataMember(_ZC("ZEXP") , &ZArray::ZEXP);
    }

    ZTvarp Zadd(ZTvarS inp)
    {
        //ZIFloat in = boost::get<gZInt>(*inp[0]).cont->val;
        //ZIInteger ai = boost::get<gZFloat>(a).cont->val;
        //myList.Concat(inp);
        //ZIFloat fr = (float)sqrtf(in);
        /*ZTvarp res=ZAlloc(ZTvar,1);
        *res = myList;
        return res;*/
    }
	
	Point_3* getPnt()
	{
		return new Point_3(		FLOAT_ZCONV(*(myList.Get(0))) ,
								FLOAT_ZCONV(*(myList.Get(1))) ,
								FLOAT_ZCONV(*(myList.Get(2)))
							);
	}

    ZTvarp X(ZTvarS inp)
    {
        switch(inp.size())
        {
        case 0:
            return myList.Get(0);
            break;
        default:
            myList.val[0]=inp[0];
            return NULL;
        }

    }
    ZTvarp Y(ZTvarS inp)
    {
        switch(inp.size())
        {
        case 0:
            return myList.Get(1);
            break;
        default:
            myList.val[1]=inp[1];
            return NULL;
        }
    }
    ZTvarp Z(ZTvarS inp)
    {
        switch(inp.size())
        {
        case 0:
            return myList.Get(2);
            break;
        default:
            myList.val[2]=inp[2];
            return NULL;
        }
    }
    
};

void ZModInit_ZPoint()
{
    ZPoint::Init();

    ZTvarp zv = ZAlloc(ZTvar,1);
    //ZTOInstance zin;
    //zin.val = new ZArray();
    *zv=ZObjP();
    boost::get<gZObject>(*zv).cont=new ZPoint();
    ZInterp::ZSym.InsertSymbol(_ZC("ZPoint3"),zv);

}