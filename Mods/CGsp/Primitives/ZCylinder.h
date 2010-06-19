class ZCylinder    : public PrimitiveAPI<ZCylinder>
{
public:

	Cylinder_3* primt;

	ZCylinder()
	{}

	static void Init()
	{
		PrimitiveAPI<ZCylinder>::Init();

		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	//FIXME : int conversions
	ZCylinder(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Cylinder_3();
			break;
		case 2:
			primt = new Cylinder_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Cylinder_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new Cylinder_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) );
			break;
		case 6:
		default:
			primt = new Cylinder_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) );
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZCylinder();
	}
};