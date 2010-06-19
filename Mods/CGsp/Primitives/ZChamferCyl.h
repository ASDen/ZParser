class ZChamferCyl    : public PrimitiveAPI<ZChamferCyl>
{
public:

	ChamferCyl_3* primt;

	ZChamferCyl()
	{}

	static void Init()
	{
		PrimitiveAPI<ZChamferCyl>::Init();

		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	//FIXME : int conversions
	ZChamferCyl(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new ChamferCyl_3();
			break;
		case 2:
			primt = new ChamferCyl_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new ChamferCyl_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new ChamferCyl_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) );
			break;
		case 5:
			primt = new ChamferCyl_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		case 8:
		default:
			primt = new ChamferCyl_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) , INT_ZCONV(*inp[6]) );
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZChamferCyl();
	}
};