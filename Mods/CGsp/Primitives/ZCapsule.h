class ZCapsule    : public PrimitiveAPI<ZCapsule>
{
public:

	Capsule_3* primt;

	ZCapsule()
	{}

	static void Init()
	{
		PrimitiveAPI<ZCapsule>::Init();

		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	//FIXME : int conversions
	ZCapsule(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Capsule_3();
			break;
		case 2:
			primt = new Capsule_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Capsule_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new Capsule_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) );
			break;
		case 5:
		default:
			primt = new Capsule_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZCapsule();
	}
};