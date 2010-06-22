#include "XCGsp.h"
#include "../../stdafx.h"
#include "../../ZInterp.h"
#include "ClassDefs.h"

#define ADD_CLASS(X,Y) X::Init();\
						*zv=ZObjP();\
						boost::get<gZObject>(*zv).cont=new X();\
						ZInterp::ZSym.InsertSymbol(_ZC(Y),zv);\
						zv++;


void ZModInit_CGsp()
{
	ZTvarp zv = ZAlloc(ZTvar,35);

	ADD_CLASS(ZBox,"Box");
	ADD_CLASS(ZCapsule,"Capsule");
	ADD_CLASS(ZChamferCyl,"ChamferCyl");
	ADD_CLASS(ZCone,"Cone");
	ADD_CLASS(ZCylinder,"Cylinder");
	//ADD_CLASS(ZLathe,"Lathe");
	ADD_CLASS(ZPlane,"Plane");
	ADD_CLASS(ZPyramid,"Pyramid");
	ADD_CLASS(ZSphere,"Sphere");
	ADD_CLASS(ZSpindle,"Spindle");
	ADD_CLASS(ZSpring,"Spring");
	ADD_CLASS(ZTorus,"Torus");
	ADD_CLASS(ZTube,"Tube");

	ADD_CLASS(ZBevel,"Bevel");
	ADD_CLASS(ZExtrude,"Extrude");
	ADD_CLASS(ZOutline,"Outline");

	ADD_CLASS(ZBend,"Bend");
	ADD_CLASS(ZBulge,"Bulge");
	ADD_CLASS(ZCylindrical_Wave,"Cylindrical_Wave");
	ADD_CLASS(ZLinear_Wave,"Linear_Wave");
	//ADD_CLASS(ZMorph,"Morph");
	//ADD_CLASS(ZNoise,"Noise");
	ADD_CLASS(ZSkew,"Skew");
	ADD_CLASS(ZSmooth,"Smooth");
	ADD_CLASS(ZSpherify,"Spherify");
	ADD_CLASS(ZSqueeze,"Squeeze");
	ADD_CLASS(ZStretch,"Stretch");
	ADD_CLASS(ZTaper,"Taper");
	//ADD_CLASS(ZTriangulate,"Triangulate");
	ADD_CLASS(ZTwist,"Twist");

	ADD_CLASS(ZRigidBodySimulation,"PhysicsSimulation");
	ADD_CLASS(ZKeyFrame,"KeyFrameAnimation");
	ADD_CLASS(ZAxis,"ZAxis");
	ADD_CLASS(ZPoint,"ZPoint");
	ADD_CLASS(ZBulgeType,"ZBulgeType");
	

	/*ZBox::Init();
	*zv=ZObjP();
	boost::get<gZObject>(*zv).cont=new ZBox();
	ZInterp::ZSym.InsertSymbol(_ZC("Box"),zv);

	zv++;
	ZPlane::Init();
	*zv=ZObjP();
	boost::get<gZObject>(*zv).cont=new ZPlane();
	ZInterp::ZSym.InsertSymbol(_ZC("Plane"),zv);

	zv++;
	ZRigidBodySimulation::Init();
	*zv=ZObjP();
	boost::get<gZObject>(*zv).cont=new ZRigidBodySimulation();
	ZInterp::ZSym.InsertSymbol(_ZC("ZRigidBodySimulation"),zv);*/
}