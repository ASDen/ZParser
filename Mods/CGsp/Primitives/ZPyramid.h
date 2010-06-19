class ZPyramid    : public PrimitiveAPI<ZPyramid>
{
public:

	Pyramid_3* primt;

	ZPyramid()
	{}

	static void Init()
	{
		PrimitiveAPI<ZPyramid>::Init();

		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	//FIXME : int conversions
	ZPyramid(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Pyramid_3();
			break;
		case 2:
			primt = new Pyramid_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Pyramid_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new Pyramid_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) );
			break;
		case 5:
			primt = new Pyramid_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		case 6:
			primt = new Pyramid_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) );
			break;
		case 7:
		default:
			primt = new Pyramid_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) );
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZPyramid();
	}
};