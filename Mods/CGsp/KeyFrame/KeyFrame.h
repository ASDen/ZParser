class ZKeyFrame : public ZTBaseObject<ZKeyFrame>
{
public:
	osgPolyManager* opm;
	KeyFrameManager* pm;

	ZKeyFrame()
	{}

	ZKeyFrame(ZTvarS inp)
	{
		pm  = new KeyFrameManager();
		opm = new osgPolyManager;
		pm->InitOsg();
		pm->setPolyManager(opm);

		ZKeyFrame();
	}

	static void Init()
	{
		StProps.InitScope();

		AddFunction(_ZC("Add") ,1,&ZKeyFrame::AddPrimitive);
		AddFunction(_ZC("View"),0,&ZKeyFrame::ViewScene);

		ZTObject::Inheriet(StProps);
	}

	ZTvarp AddPrimitive (ZTvarS inp)
	{
		pZObjP zins=INSTANCE_ZCONV(*(inp[0]));
		//because we need to get all pnode from different primitives - Box,sphere,...etc 
		opm->AddPolyhedron<KeyFrameManager>( reinterpret_cast<PrimitiveAPI<ZBox>* >(zins)->pnode );
		return NULL;
	}

	ZTvarp ViewScene (ZTvarS inp)
	{
		pm->DisplayLoop();
		return NULL;
	}
};