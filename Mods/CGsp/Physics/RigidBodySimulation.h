class ZRigidBodySimulation : public ZTBaseObject<ZRigidBodySimulation>
{
public:
	osgPolyManager* opm;
	PhysicsManager* pm;

	ZTvar ZPhysBOX,
		  ZPhysCAPSULE,
		  ZPhysCONVEX,
		  ZPhysPLANE,
		  ZPhysSPHERE,
		  ZPhysSPRING,
		  ZPhysTORUS,
		  ZPhysTUBE;


	ZRigidBodySimulation()
	{
		AddDataMember(_ZC("ZPhysBOX")    , &ZRigidBodySimulation::ZPhysBOX);
		AddDataMember(_ZC("ZPhysCAPSULE")  , &ZRigidBodySimulation::ZPhysCAPSULE);
		AddDataMember(_ZC("ZPhysCONVEX")  , &ZRigidBodySimulation::ZPhysCONVEX);
		AddDataMember(_ZC("ZPhysPLANE")  , &ZRigidBodySimulation::ZPhysPLANE);
		AddDataMember(_ZC("ZPhysSPHERE")  , &ZRigidBodySimulation::ZPhysSPHERE);
		AddDataMember(_ZC("ZPhysSPRING")  , &ZRigidBodySimulation::ZPhysSPRING);
		AddDataMember(_ZC("ZPhysTORUS")  , &ZRigidBodySimulation::ZPhysTORUS);
		AddDataMember(_ZC("ZPhysTUBE")  , &ZRigidBodySimulation::ZPhysTUBE);
	}

	ZRigidBodySimulation(ZTvarS inp)
	{
		ZPhysBOX    = ZTFloat(1);
		ZPhysCAPSULE  = ZTFloat(2);
		ZPhysCONVEX  = ZTFloat(3);
		ZPhysPLANE  = ZTFloat(4);
		ZPhysSPHERE  = ZTFloat(5);
		ZPhysSPRING  = ZTFloat(6);
		ZPhysTORUS  = ZTFloat(7);
		ZPhysTUBE  = ZTFloat(8);

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