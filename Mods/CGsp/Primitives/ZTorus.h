class ZTorus    : public PrimitiveAPI<ZTorus>
{
public:

	Torus_3* primt;

	ZTorus()
	{}

	static void Init()
	{
		PrimitiveAPI<ZTorus>::Init();

		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	//FIXME : int conversions
	ZTorus(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Torus_3();
			break;
		case 2:
			primt = new Torus_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Torus_3( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) );
			break;
		case 7:
		default:
			primt = new Torus_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , FLOAT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) );
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZTorus();
	}
};