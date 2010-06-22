class ZAxis : public ZTBaseObject<ZAxis> 
{
public:

	Axis ax;

	ZAxis(){}

	ZAxis(Axis a):ax(a)
	{}

	ZAxis(ZTvarS inp)
	{ZAxis(X_ax);}

	static Axis getAxis(ZTvarp inp)
	{
		pZObjP zins=INSTANCE_ZCONV(*(inp));
		return Axis(reinterpret_cast<ZAxis*>(zins)->ax);
	}

	static void Init()
	{
		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}
};