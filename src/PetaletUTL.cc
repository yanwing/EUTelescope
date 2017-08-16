#include "PetaletUTL.h"

namespace eutelescope {
namespace geo {
  
PetaletUTL::PetaletUTL(): EUTelGenericPixGeoDescr(40.0, 40.0, 1.0,	//size X, Y, Z (21.2, 10.6, 0.02)
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
	Double_t YAdd=-19.4,XAdd=0.0/*18.4055*/;
	Double_t y1=37.752,y2=19.443,y3=19.357,y4=1.048;
	Double_t LTLx1=17.575,LTLx2=-17.707,LTLx3=19.683,LTLx4=-17.260;//y1 and y2
	Double_t UTLx1=19.179,UTLx2=-17.901,UTLx3=21.287,UTLx4=-17.460;//y3 and y4
	Double_t TLFocusX=-27.708,TLFocusY=426.474;

	Double_t Y[]={y1,y2,y3,y4};
	Double_t X[]={LTLx1,LTLx2,LTLx3,LTLx4,UTLx1,UTLx2,UTLx3,UTLx4};
	//Apply rotations and translations
	for (int i=0;i<4;i++){ Y[i]=-(Y[i]+YAdd);}
	for (int i=0;i<8;i++){ X[i]=-X[i]+XAdd;}
	TLFocusX=-TLFocusX+XAdd;
	TLFocusY=-(TLFocusY+YAdd);
/*
	//=======================================================================================================
	//LTL
	//=======================================================================================================
	//cout<<"------- LTL -------"<<endl;
	//Get focus and angles
	Int_t SIndex=388,EIndex=764;
	Double_t m1=(Y[0]-Y[1])/(X[1]-X[3]);//channel 388 (right)
	Double_t m2=(Y[0]-Y[1])/(X[0]-X[2]);//channel 764 (left)
	Double_t angle1,angle2,n=EIndex-SIndex;
	if(m1<0){angle1=atan(m1)+Pi;}
	else{angle1=atan(m1);}
	if(m2<0){angle2=atan(m2)+Pi;}
	else{angle2=atan(m2);}
	Double_t c1=Y[0]-m1*X[1],c2=Y[0]-m2*X[0];
	Double_t fx=(c2-c1)/(m1-m2),fy=(c1*m2-c2*m1)/(m2-m1);//focus point
	//cout<<angle1<<" "<<(y2-y1)/(xa2-xa1)<<endl;
	//cout<<"Given focus fx: "<<TLFocusX <<" fy: "<<TLFocusY <<endl;
	//cout<<"Calculated focus fx: "<<fx<<" fy: "<<fy<<endl;
	//fx=0,fy=0;

	Double_t start_theta=angle1,d_theta=abs(angle2-angle1)/n,stM_theta=angle1;
	Double_t stR_theta=stM_theta-d_theta/2,stL_theta=stM_theta+d_theta/2,ymid=(Y[0]+Y[1])/2;
	Double_t xM1, xM2, xR1, xR2, xL1, xL2, xC, M_theta, R_theta, L_theta;

	for (int i=SIndex;i<=EIndex;i++){
	  int j=i-SIndex;
	  //get left edge, right edge and centre angles of each strip
	  M_theta=(stM_theta+j*d_theta), R_theta=(stR_theta+j*d_theta), L_theta=(stL_theta+j*d_theta);
	  //get x values of the corners of each strip and the x values of the centre at the ends in y
	  xM1=(Y[0]-fy)/tan(M_theta)+fx, xR1=(Y[0]-fy)/tan(R_theta)+fx, xL1=(Y[0]-fy)/tan(L_theta)+fx;
	  xM2=(Y[1]-fy)/tan(M_theta)+fx, xR2=(Y[1]-fy)/tan(R_theta)+fx, xL2=(Y[1]-fy)/tan(L_theta)+fx;
	  //get centre of strip x
	  xC=(ymid-fy)/tan(M_theta)+fx;

	  Double_t vert[16]={xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0],
                             xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0]};
          TGeoVolume* strip=_tGeoManager->MakeArb8("sensarea_row1", Si, 0.155, vert);
	  //TGeoVolume* strip=(TGeoVolume*)geom->MakeArb8(sensarea_row1, Si, 0.155);
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
	  plane->AddNode(strip,i+1,new TGeoTranslation(0,0,0));
	}
*/
	//=======================================================================================================
	//UTL
	//=======================================================================================================
	//cout<<"------- UTL -------"<<endl;
	//Get focus and angles
	Int_t SIndex1=1664,EIndex1=1787, n1=EIndex1-SIndex1;
	Int_t SIndex2=1792,EIndex2=1919, n2=EIndex2-SIndex2;
	Int_t SIndex3=1923,EIndex3=2047, n3=EIndex3-SIndex3;
	Double_t angle1,angle2;
	Double_t m1=(Y[2]-Y[3])/(X[5]-X[7]),m2=(Y[2]-Y[3])/(X[4]-X[6]);
	Double_t n=n1+n2+n3+2;
	if(m1<0){angle1=atan(m1)+Pi;}
	else{angle1=atan(m1);}
	if(m2<0){angle2=atan(m2)+Pi;}
	else{angle2=atan(m2);}
	Double_t c1=Y[2]-m1*X[5],c2=Y[2]-m2*X[4];
	Double_t fx=(c2-c1)/(m1-m2),fy=(c1*m2-c2*m1)/(m2-m1);
	//cout<<"Given focus fx: "<<TLFocusX <<" fy: "<<TLFocusY <<endl;
	//cout<<"Calculated focus fx: "<<fx<<" fy: "<<fy<<endl;
	//fx=0,fy=0;

	Double_t start_theta=angle2,d_theta=abs(angle2-angle1)/n,stM_theta=angle2;
	Double_t stR_theta=stM_theta-d_theta/2,stL_theta=stM_theta+d_theta/2;
	Double_t xM1, xM2, xR1, xR2, xL1, xL2, xC, M_theta, R_theta, L_theta;
	Double_t ymid=(Y[2]+Y[3])/2;
	//Double_t xmid[EIndex3+2];

	for (int i=SIndex3;i<=EIndex3;i++){
          int j=i-SIndex3;
          M_theta=(stM_theta-j*d_theta), R_theta=(stR_theta-j*d_theta), L_theta=(stL_theta-j*d_theta);
          xM1=(Y[2]-fy)/tan(M_theta)+fx, xR1=(Y[2]-fy)/tan(R_theta)+fx, xL1=(Y[2]-fy)/tan(L_theta)+fx;
          xM2=(Y[3]-fy)/tan(M_theta)+fx, xR2=(Y[3]-fy)/tan(R_theta)+fx, xL2=(Y[3]-fy)/tan(L_theta)+fx;
          xC=(ymid-fy)/tan(M_theta)+fx;
	//	  xmid[i+1]=xC;

	  Double_t vert[16]={xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0],
                             xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0]};
							 
          TGeoVolume* strip=_tGeoManager->MakeArb8("sensarea_row2", Si, 0.155, vert);

          /*TGeoVolume strip=(TGeoVolume*)geom->MakeArb8(sensarea_row2, Si, 0.155);
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
		  //xmid[i+1]=xC;

	  Double_t vert[16]={xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0],
                             xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0]};
						 
          TGeoVolume* strip=_tGeoManager->MakeArb8("sensarea_row2", Si, 0.155, vert);
	  /*TGeoVolume strip=(TGeoVolume*)geom->MakeArb8(sensarea_row2, Si, 0.155);
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
		  //xmid[i+1]=xC;

	  Double_t vert[16]={xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0],
                             xL2, Y[1], xR2, Y[1], xR1, Y[0], xL1, Y[0]};
				 
          TGeoVolume* strip=_tGeoManager->MakeArb8("sensarea_row2", Si, 0.155, vert);
          /*TGeoVolume strip=(TGeoVolume*)geom->MakeArb8(sensarea_row2, Si, 0.155);

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

PetaletUTL::~ PetaletUTL()
{
	//It appears that ROOT will take ownership and delete that stuff! 
	//delete matSi,
	//delete Si;
}

void  PetaletUTL::createRootDescr(char const * planeVolume)
{
	//Get the plane as provided by the EUTelGeometryTelescopeGeoDescription
	TGeoVolume* topplane =_tGeoManager->GetVolume(planeVolume);
	//Add the sensitive area to the plane
	topplane->AddNode(plane, 1);
    
}

std::string PetaletUTL::getPixName(int x , int y)
{
	char buffer [100];
	//return path to the pixel, don't forget to shift indices by +1+
	snprintf( buffer, 100, "/sensarea_box_1/sensarea_row%d_%d", y+1, x+1);
	return std::string( buffer ); 
}
	/*TODO*/ std::pair<int, int>  PetaletUTL::getPixIndex(char const*){return std::make_pair(0,0); }

EUTelGenericPixGeoDescr* maker()
{
	PetaletUTL* mPixGeoDescr = new PetaletUTL();
	return dynamic_cast<EUTelGenericPixGeoDescr*>(mPixGeoDescr);
}

} //namespace geo
} //namespace eutelescope

