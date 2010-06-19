class ZSpring    : public PrimitiveAPI<ZSpring>
{
public:

	Spring_3* primt;

	ZSpring()
	{}

	static void Init()
	{
		PrimitiveAPI<ZSpring>::Init();

		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	//FIXME : int conversions
	ZSpring(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Spring_3();
			break;
		case 2:
			primt = new Spring_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Spring_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new Spring_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) );
			break;
		case 5:
			primt = new Spring_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		case 7:
		default:
			primt = new Spring_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) );
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZSpring();
	}
};