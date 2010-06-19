class ZTwist    : public ModifierAPI<ZTwist>
{
public:

	Twist* primt;

	ZTwist()
	{}

	static void Init()
	{
		ModifierAPI<ZTwist>::Init();

		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	//FIXME : int conversions
	ZTwist(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Twist();
			break;
		case 1:
		default:
			primt = new Twist( FLOAT_ZCONV(*(inp[0])) );
			break;
		}
		ZTwist();
	}
};