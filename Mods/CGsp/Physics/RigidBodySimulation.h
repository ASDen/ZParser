class ZRigidBodySimulation : public ZTBaseObject<ZRigidBodySimulation>
{
public:
	osgPolyManager* opm;
	PhysicsManager* pm;

	ZTvar ZPhysBOX,
		  ZPhysPlane,
		  ZPhysSPHERE,
		  ZPhysTORUS;


	ZRigidBodySimulation()
	{
		AddDataMember(_ZC("ZPhysBOX")    , &ZRigidBodySimulation::ZPhysBOX);
		AddDataMember(_ZC("ZPhysPlane")  , &ZRigidBodySimulation::ZPhysPlane);
		AddDataMember(_ZC("ZPhysSPHERE") , &ZRigidBodySimulation::ZPhysSPHERE);
		AddDataMember(_ZC("ZPhysTORUS")  , &ZRigidBodySimulation::ZPhysTORUS);
	}

	ZRigidBodySimulation(ZTvarS inp)
	{
		ZPhysBOX    = ZTFloat(1);
		ZPhysPlane  = ZTFloat(2);
		ZPhysSPHERE = ZTFloat(3);
		ZPhysTORUS  = ZTFloat(4);

		pm  = new PhysicsManager();
		opm = new osgPolyManager;
		pm->InitOsg();
		pm->setPolyManager(opm);

		ZRigidBodySimulation();
	}

	static void Init()
	{
		StProps.InitScope();

		AddFunction(_ZC("Add") ,1,&ZRigidBodySimulation::AddPrimitive);
		AddFunction(_ZC("View"),0,&ZRigidBodySimulation::ViewScene);

		ZTObject::Inheriet(StProps);
	}

	ZTvarp AddPrimitive (ZTvarS inp)
	{
		pZObjP zins=INSTANCE_ZCONV(*(inp[0]));
		//because we need to get all pnode from different primitives - Box,sphere,...etc 
		opm->AddPolyhedron<RigidBodyManager>( reinterpret_cast<PrimitiveAPI<ZBox>* >(zins)->pnode );
		return NULL;
	}

	ZTvarp ViewScene (ZTvarS inp)
	{
		pm->DisplayLoop();
		return NULL;
	}
};