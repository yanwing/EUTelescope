#include "PetaletUTR.h"

namespace eutelescope {
namespace geo {
  
PetaletUTR::PetaletUTR(): EUTelGenericPixGeoDescr(45.0, 45.0, 1.0,	//size X, Y, Z (21.2, 10.6, 0.02)
						0,385 , 0, 1,	//min max X,Y
						9.3660734 )		//rad length
{
	//Create the material for the sensor
    matSi = new TGeoMaterial( "Si", 28.0855 , 14.0, 2.33, -_radLength, 45.753206 );//(name,Atomic mass,no. protons,rho(g.cm^-3),radLength,interactionLength)
	Si = new TGeoMedium("PetaletSilicon",1, matSi);
	TGeoMaterial* matVacuum = new TGeoMaterial("Vacuum", 0,0,0);
	TGeoMedium* Vacuum = new TGeoMedium("Vacuum",1, matVacuum);
	//Create a plane for the sensitive area
	plane = _tGeoManager->MakeBox( "sensarea_box", Vacuum, 0.5*_sizeSensitiveAreaX, 0.5*_sizeSensitiveAreaY, 0.5*_sizeSensitiveAreaZ );//(name,medium,dx,dy,dz) (was just the actual values not using the variable names)
	
	Double_t Pi=3.14159265358979;
	Double_t YAdd=19.4,XAdd=0.0/*18.4055*/;
	Double_t y1=-37.752,y2=-19.443,y3=-19.357,y4=-1.048;
	Double_t LTRx1=-17.487,LTRx2=17.680,LTRx3=-17.774,LTRx4=19.041;//y1 and y2
	Double_t UTRx1=-17.302,UTRx2=19.792,UTRx3=-17.595,UTRx4=21.163;//y3 and y4
	Double_t TRFocusX=-10.766,TRFocusY=-427.317;

	Double_t Y[]={y1,y2,y3,y4};
	Double_t X[]={LTRx1,LTRx2,LTRx3,LTRx4,UTRx1,UTRx2,UTRx3,UTRx4};
	//Apply rotations and translations
	for (int i=0;i<4;i++){ Y[i]+=YAdd;}
	for (int i=0;i<8;i++){ X[i]+=XAdd;}
	TRFocusX+=XAdd;
	TRFocusY+=YAdd;
/*
	//=======================================================================================================
	//LTR
	//=======================================================================================================
	//std::cout<<"------- LTR -------"<<std::endl;
	//Get focus and angles
	Int_t SIndex =5, EIndex =380;
	Double_t m1=(Y[0]-Y[1])/(X[1]-X[3]);//channel 5 (right)
	Double_t m2=(Y[0]-Y[1])/(X[0]-X[2]);//channel 380 (left)
	Double_t angle1,angle2,n=EIndex-SIndex;
	if(m1<0){angle1=atan(m1)+Pi;}
	else{angle1=atan(m1);}
	if(m2<0){angle2=atan(m2)+Pi;}
	else{angle2=atan(m2);}
	Double_t c1=Y[0]-m1*X[1],c2=Y[0]-m2*X[0];
	Double_t fx=(c2-c1)/(m1-m2),fy=(c1*m2-c2*m1)/(m2-m1);//focus point
	//cout<<angle1<<" "<<(y2-y1)/(xa2-xa1)<<endl;
	//std::cout<<"Given focus fx: "<<TRFocusX <<" fy: "<<TRFocusY <<std::endl;
	//std::cout<<"Calculated focus fx: "<<fx<<" fy: "<<fy<<std::endl;
	//fx=0,fy=0;

	Double_t start_theta=angle1,d_theta=abs(angle2-angle1)/n,stM_theta=angle1;
	Double_t stR_theta=stM_theta-d_theta/2,stL_theta=stM_theta+d_theta/2,ymid=(Y[0]+Y[1])/2;
	Double_t xM1, xM2, xR1, xR2, xL1, xL2, xC, M_theta, R_theta, L_theta;

	for (int i=0;i<=n;i++){
	  //get left edge, right edge and centre angles of each strip
	  M_theta=(stM_theta+i*d_theta), R_theta=(stR_theta+i*d_theta), L_theta=(stL_theta+i*d_theta);
	  //get x values of the corners of each strip and the x values of the centre at the ends in y
	  xM1=(Y[0]-fy)/tan(M_theta)+fx, xR1=(Y[0]-fy)/tan(R_theta)+fx, xL1=(Y[0]-fy)/tan(L_theta)+fx;
	  xM2=(Y[1]-fy)/tan(M_theta)+fx, xR2=(Y[1]-fy)/tan(R_theta)+fx, xL2=(Y[1]-fy)/tan(L_theta)+fx;
	  //get centre of strip x
	  xC=(ymid-fy)/tan(M_theta)+fx;

	  //Define the strips. Name, material, half the thickness
	  Double_t vert[16]={xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0],
			     xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0]};
	  TGeoVolume* strip=_tGeoManager->MakeArb8("sensarea_row1", Si, 0.155, vert);
	  //TGeoVolume* strip=_tGeoManager->MakeArb8("sensarea_row1", Si, 0.155);
	  //Strips[i]->SetLineColor(kRed);
	  //TGeoArb8* arbL = (TGeoArb8*)strip->GetShape();
	  //arbL->SetVertex(0, xL1, Y[0]);// front 0-3
	  //arbL->SetVertex(1, xR1, Y[0]);
	  //arbL->SetVertex(2, xR2, Y[1]);
	  //arbL->SetVertex(3, xL2, Y[1]);
	  //arbL->SetVertex(4, xL1, Y[0]);// back 0-3
	  //arbL->SetVertex(5, xR1, Y[0]);
	  //arbL->SetVertex(6, xR2, Y[1]);
	  //arbL->SetVertex(7, xL2, Y[1]);
	  plane->AddNode(strip,i+1+ SIndex ,new TGeoTranslation(0,0,0)); //i+3 ->> i+5, short /ganged strip correction
	}
*/
	//=======================================================================================================
	//UTR
	//=======================================================================================================
	//cout<<"------- UTR -------"<<endl;
	std::array<std::vector<int>,16> corner;
	//Get focus and angles
	Int_t SIndex1=1280,EIndex1=1403, n1=EIndex1-SIndex1;
	Int_t SIndex2=1408,EIndex2=1535, n2=EIndex2-SIndex2;
	Int_t SIndex3=1539,EIndex3=1663, n3=EIndex3-SIndex3;
	Double_t angle1,angle2;
	Double_t m1=(Y[2]-Y[3])/(X[5]-X[7]),m2=(Y[2]-Y[3])/(X[4]-X[6]);
	Double_t n=n1+n2+n3+2;

	if(m1<0){angle1=atan(m1)+Pi;}
	else{angle1=atan(m1);}
	if(m2<0){angle2=atan(m2)+Pi;}
	else{angle2=atan(m2);}
	Double_t c1=Y[2]-m1*X[5],c2=Y[2]-m2*X[4];
	Double_t fx=(c2-c1)/(m1-m2),fy=(c1*m2-c2*m1)/(m2-m1);
	//cout<<"Given focus fx: "<<TRFocusX <<" fy: "<<TRFocusY <<endl;
	//cout<<"Calculated focus fx: "<<fx<<" fy: "<<fy<<endl;
	//fx=0,fy=0;


	Double_t start_theta=angle2,d_theta=abs(angle2-angle1)/n,stM_theta=angle2;
	Double_t stR_theta=stM_theta-d_theta/2,stL_theta=stM_theta+d_theta/2;
	Double_t xM1, xM2, xR1, xR2, xL1, xL2, xC, M_theta, R_theta, L_theta;
	Double_t ymid=(Y[2]+Y[3])/2;
	Double_t xmid[EIndex3+2];

	for (int i=SIndex3;i<=EIndex3;i++){
	  int j=i-SIndex3;
	  M_theta=(stM_theta-j*d_theta), R_theta=(stR_theta-j*d_theta), L_theta=(stL_theta-j*d_theta);
	  xM1=(Y[2]-fy)/tan(M_theta)+fx, xR1=(Y[2]-fy)/tan(R_theta)+fx, xL1=(Y[2]-fy)/tan(L_theta)+fx;
	  xM2=(Y[3]-fy)/tan(M_theta)+fx, xR2=(Y[3]-fy)/tan(R_theta)+fx, xL2=(Y[3]-fy)/tan(L_theta)+fx;
	  xC=(ymid-fy)/tan(M_theta)+fx;
	  xmid[i+1]=xC;
	  Double_t vert[16]={xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0],
                             xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0]};

          TGeoVolume* strip=_tGeoManager->MakeArb8("sensarea_row2", Si, 0.155, vert);

	  /*TGeoVolume* strip=_tGeoManager->MakeArb8("sensarea_row2", Si, 0.155);
	  TGeoArb8* arbL = (TGeoArb8*)strip->GetShape();
	  arbL->SetVertex(0, xL1, Y[2]);// front 0-3
	  arbL->SetVertex(1, xR1, Y[2]);
	  arbL->SetVertex(2, xR2, Y[3]);
	  arbL->SetVertex(3, xL2, Y[3]);
	  arbL->SetVertex(4, xL1, Y[2]);// back 0-3
	  arbL->SetVertex(5, xR1, Y[2]);
	  arbL->SetVertex(6, xR2, Y[3]);
	  arbL->SetVertex(7, xL2, Y[3]);*/
	  plane->AddNode(strip,i+1,new TGeoTranslation(0,0,0));
	}

	stR_theta=R_theta-d_theta,stL_theta=L_theta-d_theta,stM_theta=M_theta-d_theta;
	for (int i=SIndex2;i<=EIndex2;i++){
	  int j=i-SIndex2;
	  M_theta=(stM_theta-j*d_theta), R_theta=(stR_theta-j*d_theta), L_theta=(stL_theta-j*d_theta);
	  xM1=(Y[2]-fy)/tan(M_theta)+fx, xR1=(Y[2]-fy)/tan(R_theta)+fx, xL1=(Y[2]-fy)/tan(L_theta)+fx;
	  xM2=(Y[3]-fy)/tan(M_theta)+fx, xR2=(Y[3]-fy)/tan(R_theta)+fx, xL2=(Y[3]-fy)/tan(L_theta)+fx;
	  xC=(ymid-fy)/tan(M_theta)+fx;
	  xmid[i+1]=xC;

	  Double_t vert[16]={xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0],
                             xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0]};

          TGeoVolume* strip=_tGeoManager->MakeArb8("sensarea_row2", Si, 0.155, vert);

	  /*TGeoVolume* strip=_tGeoManager->MakeArb8("sensarea_row2", Si, 0.155);
	  TGeoArb8* arbL = (TGeoArb8*)strip->GetShape();
	  arbL->SetVertex(0, xL1, Y[2]);// front 0-3
	  arbL->SetVertex(1, xR1, Y[2]);
	  arbL->SetVertex(2, xR2, Y[3]);
	  arbL->SetVertex(3, xL2, Y[3]);
	  arbL->SetVertex(4, xL1, Y[2]);// back 0-3
	  arbL->SetVertex(5, xR1, Y[2]);
	  arbL->SetVertex(6, xR2, Y[3]);
	  arbL->SetVertex(7, xL2, Y[3]);*/
	  plane->AddNode(strip,i+1,new TGeoTranslation(0,0,0));
	}

	stR_theta=R_theta-d_theta,stL_theta=L_theta-d_theta,stM_theta=M_theta-d_theta;
	for (int i=SIndex1;i<=EIndex1;i++){
	  int j=i-SIndex1;
	  M_theta=(stM_theta-j*d_theta), R_theta=(stR_theta-j*d_theta), L_theta=(stL_theta-j*d_theta);
	  xM1=(Y[2]-fy)/tan(M_theta)+fx, xR1=(Y[2]-fy)/tan(R_theta)+fx, xL1=(Y[2]-fy)/tan(L_theta)+fx;
	  xM2=(Y[3]-fy)/tan(M_theta)+fx, xR2=(Y[3]-fy)/tan(R_theta)+fx, xL2=(Y[3]-fy)/tan(L_theta)+fx;
	  xC=(ymid-fy)/tan(M_theta)+fx;
	  xmid[i+1]=xC;

	  Double_t vert[16]={xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0],
                             xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0]};
						 
          TGeoVolume* strip=_tGeoManager->MakeArb8("sensarea_row2", Si, 0.155, vert);

	  /*TGeoVolume* strip=_tGeoManager->MakeArb8("sensarea_row2", Si, 0.155);

	  TGeoArb8* arbL = (TGeoArb8*)strip->GetShape();
	  arbL->SetVertex(0, xL1, Y[2]);// front 0-3
	  arbL->SetVertex(1, xR1, Y[2]);
	  arbL->SetVertex(2, xR2, Y[3]);
	  arbL->SetVertex(3, xL2, Y[3]);
	  arbL->SetVertex(4, xL1, Y[2]);// back 0-3
	  arbL->SetVertex(5, xR1, Y[2]);
	  arbL->SetVertex(6, xR2, Y[3]);
	  arbL->SetVertex(7, xL2, Y[3]);*/
	  plane->AddNode(strip,i+1,new TGeoTranslation(0,0,0));
	}







}

PetaletUTR::~ PetaletUTR()
{
	//It appears that ROOT will take ownership and delete that stuff! 
	//delete matSi,
	//delete Si;
}

void  PetaletUTR::createRootDescr(char const * planeVolume)
{
	//Get the plane as provided by the EUTelGeometryTelescopeGeoDescription
	TGeoVolume* topplane =_tGeoManager->GetVolume(planeVolume);
	//Add the sensitive area to the plane
	topplane->AddNode(plane, 1);
    
}

std::string PetaletUTR::getPixName(int x , int y)
{
	char buffer [100];
	//return path to the pixel, don't forget to shift indices by +1+
	snprintf( buffer, 100, "/sensarea_box_1/sensarea_row%d_%d", y+1, x+1);
	return std::string( buffer ); 
}
	/*TODO*/ std::pair<int, int>  PetaletUTR::getPixIndex(char const*){return std::make_pair(0,0); }

EUTelGenericPixGeoDescr* maker()
{
	PetaletUTR* mPixGeoDescr = new PetaletUTR();
	return dynamic_cast<EUTelGenericPixGeoDescr*>(mPixGeoDescr);
}

} //namespace geo
} //namespace eutelescope

