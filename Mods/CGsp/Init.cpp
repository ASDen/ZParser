#include "XCGsp.h"
#include "../../stdafx.h"
#include "../../ZInterp.h"
#include "ClassDefs.h"

#define ADD_CLASS(X,Y) X::Init();\
						*zv=ZObjP();\
						boost::get<gZObject>(*zv).cont=new X();\
						ZInterp::ZSym.InsertSymbol(_ZC(Y),zv);\
						zv++;

#define ADD_VAR(X,Y)	zin.val = new X; \
						*zv=zin;\
						ZInterp::ZSym.InsertSymbol(_ZC(Y),zv);\
						zv++;

void ZModInit_CGsp()
{
	ZTvarp zv = ZAlloc(ZTvar,450);

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

	ZTvarS zvs;
	ZTOInstance zin;
	ADD_VAR( ZAxis (X_ax) , _ZC("XAxis") );
	ADD_VAR( ZAxis (Y_ax) , _ZC("YAxis") );
	ADD_VAR( ZAxis (Z_ax) , _ZC("ZAxis") );

	ADD_VAR( ZBulgeType (BRadial) , _ZC("BRadial") );
	ADD_VAR( ZBulgeType (BLinear) , _ZC("BLinear") );

	ADD_CLASS(ZBulgeType,"ZBulgeType");
	ADD_CLASS(ZAxis  ,"__ZAxis");
	ADD_CLASS(ZPoint ,"ZPoint");
	
	

}