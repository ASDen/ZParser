class ZPolyhedron : public ZTBaseObject<ZPolyhedron> 
{
public:

	Polyhedron* P;

	ZPolyhedron()
	{}

	ZPolyhedron(Polyhedron* x):P(x)
	{}

	ZPolyhedron(ZTvarS inp)
	{
		ZPolyhedron();
	}

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