class ZSphere    : public PrimitiveAPI<ZSphere>
{
public:

	Sphere_3* primt;

	ZSphere()
	{}

	static void Init()
	{
		PrimitiveAPI<ZSphere>::Init();

		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	//FIXME : int conversions
	ZSphere(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Sphere_3();
			break;
		case 2:
			primt = new Sphere_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 7:
		default:
			primt = new Sphere_3( FLOAT_ZCONV(*inp[0]) , INT_ZCONV(*inp[1]) );
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZSphere();
	}
};