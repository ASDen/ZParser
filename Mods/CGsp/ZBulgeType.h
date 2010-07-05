class ZBulgeType : public ZTBaseObject<ZBulgeType> 
{
public:

	BulgeType buType;

	ZBulgeType()
	{}

	ZBulgeType(BulgeType b):buType(b)
	{}

	ZBulgeType(ZTvarS inp)
	{
		ZBulgeType(BLinear);
	}

	static BulgeType getType(ZTvarp inp)
	{
		pZObjP zins = INSTANCE_ZCONV(*(inp));
		return BulgeType(reinterpret_cast<ZBulgeType*>(zins)->buType);
	}

	static void Init()
	{
		StProps.InitScope();
        AddFunction(_ZC("toString"),1,&ZBulgeType::toString);
	
		ZTObject::Inheriet(StProps);
	}

	static ZIString toString(BulgeType butype)
	{
		switch (butype)
		{
		case BRadial:
			return ZIString("Radial");
			break;
		case BLinear:
			return ZIString("Linear");
			break;
		default:
			return ZIString("Type Error");
		}
	}
	
	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		switch (buType)
		{
		case BRadial:	
			s1 << " Bulge Type : " << "Radial" << endl;
			break;
		case BLinear:
			s1 << " Bulge Type : " << "Linear" << endl;
			break;
		default:
			s1 << " Bulge Type : " << "Type Error" << endl;
		};
		
		INST_TO_STR( s1.str() );
	}
};