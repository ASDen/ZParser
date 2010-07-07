class ZRigidBodySimulation : public ZTBaseObject<ZRigidBodySimulation>
{
public:
	osgPolyManager* opm;
	PhysicsManager* pm;

	ZTvar ZPhysBOX,
		  ZPhysLATHE,
		  ZPhysCONVEX,
		  ZPhysPLANE,
		  ZPhysSPHERE,
		  ZPhysCLOTH,
		  ZPhysSPRING,
		  ZPhysTORUS,
		  ZPhysTUBE;


	ZRigidBodySimulation()
	{
		AddDataMember(_ZC("ZPhysBOX")    , &ZRigidBodySimulation::ZPhysBOX);
		AddDataMember(_ZC("ZPhysCLOTH")  , &ZRigidBodySimulation::ZPhysCLOTH);
		AddDataMember(_ZC("ZPhysLATHE")  , &ZRigidBodySimulation::ZPhysLATHE);
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
		ZPhysLATHE  = ZTFloat(2);
		ZPhysCONVEX  = ZTFloat(3);
		ZPhysPLANE  = ZTFloat(4);
		ZPhysSPHERE  = ZTFloat(5);
		ZPhysSPRING  = ZTFloat(6);
		ZPhysTORUS  = ZTFloat(7);
		ZPhysTUBE  = ZTFloat(8);
		ZPhysCLOTH  = ZTFloat(9);

		pm  = new PhysicsManager();
		opm = new osgPolyManager;
		pm->InitOsg();
		pm->setPolyManager(opm);

		ZRigidBodySimulation();
	}

	static void Init()
	{
		StProps.InitScope();

		AddFunction(_ZC("AddRigid") ,1,&ZRigidBodySimulation::AddRigidBody);
		AddFunction(_ZC("AddCloth") ,1,&ZRigidBodySimulation::AddCloth);
		AddFunction(_ZC("setGravity") ,1,&ZRigidBodySimulation::setGravity);
		AddFunction(_ZC("View"),0,&ZRigidBodySimulation::ViewScene);

		ZTObject::Inheriet(StProps);
	}

	ZTvarp AddRigidBody (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZError::Throw<ZWrongNumberOfArguments>();
			return NULL;
		}

		pZObjP zins=INSTANCE_ZCONV(*(inp[0]));
		//because we need to get all pnode from different primitives - Box,sphere,...etc 
		opm->AddPolyhedron<RigidBodyManager>( reinterpret_cast<PrimitiveAPI<ZBox>* >(zins)->pnode );
		return NULL;
	}

	ZTvarp AddCloth (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZError::Throw<ZWrongNumberOfArguments>();
			return NULL;
		}

		pZObjP zins = INSTANCE_ZCONV(*(inp[0]));
		//because we need to get all pnode from different primitives - Box,sphere,...etc 
		opm->AddPolyhedron<ClothManager>( reinterpret_cast<PrimitiveAPI<ZBox>* >(zins)->pnode );
		return NULL;
	}

	ZTvarp setGravity (ZTvarS inp)
	{
		pZObjP zins=INSTANCE_ZCONV(*(inp[0]));
		Point_3* p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
		pm->gScene->setGravity(NxVec3(-p3->x(),p3->z(),p3->y()));
		return NULL;
	}
	

	ZTvarp ViewScene (ZTvarS inp)
	{
		pm->DisplayLoop();
		return NULL;
	}
};