class ZPlane    : public PrimitiveAPI<ZPlane>
{
public:

	Plane_3* primt;

	ZPlane()
	{}

	static void Init()
	{
		PrimitiveAPI<ZPlane>::Init();

		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	//FIXME : int conversions
	ZPlane(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Plane_3();
			break;
		case 2:
			primt = new Plane_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Plane_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 5:
		default:
			primt = new Plane_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZPlane();
	}
};