USING_PART_OF_NAMESPACE_EIGEN
class ZMatrix : public ZTBaseObject<ZMatrix> 
{
public:
    ZTList myList;
    
    static void Init()
    {
        StProps.InitScope();

        AddFunction(_ZC("toString"),1,&ZMatrix::toString);
		AddFunction(_ZC("add"),2,&ZMatrix::Zadd);

        ZTObject::Inheriet(StProps);
    }

    ZMatrix(ZTvarS inp)
    {
		if (inp.size() == 0)
			ZError::Throw<ZWrongNumberOfArguments>();

		myList = LIST_ZCONV(*inp[ 0 ] );
		ZTList subList = LIST_ZCONV(*(myList.Get(0)));

		int size = subList.size();

	
		for (int i = 1; i < myList.size(); i++)
		{
			subList = LIST_ZCONV(*(myList.Get(i)));

			if (subList.size() != size)
				ZError::Throw<ZWrongNumberInList>();
		}
        
        ZMatrix();
    }

    ZMatrix()
    {
    }

    ZTvarp Zadd(ZTvarS inp)
    {
		MatrixXi m(3,3);
		return NULL;
    }
	
	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << "";

		for (int i = 0; i < myList.size(); i++)
		{
			ZTList subList = LIST_ZCONV(*(myList.Get(i)));
			s1 << " [ " << FLOAT_ZCONV(*(subList.Get(0)));

			for (int j = 1; j < subList.size(); j++)
			{
				s1 << " " << FLOAT_ZCONV(*(subList.Get(j)));
			}

			s1 << " ]";

			if (i != myList.size() - 1)
				s1 << endl;
		}

		s1 << "" << endl;
		
		INST_TO_STR( s1.str() );
	}
    
};