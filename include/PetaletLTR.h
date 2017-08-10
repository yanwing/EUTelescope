#ifndef PETALETLTR_H
#define	PETALETLTR_H

  /** @class Mimosa26
	* This class is the implementation of  @class EUTelGenericPixGeoDescr
	* for the Mimosa26 which is the standard telescope reference plane of
	* the DESY pixel telescope.
	* The geoemtry is as following: the 21.2 x 10.6 mm**2 are is divided
	* into a 1151 x 575 pixel matrix. All pixels are of the same dimension. 
    */

//STL
#include <string> //std::string
#include <utility> //std::pair


//EUTELESCOPE
#include "EUTelGenericPixGeoDescr.h"

//ROOT
#include "TGeoMaterial.h"
#include "TGeoMedium.h"
#include "TGeoVolume.h"


using namespace std;

//	extern	Double_t xmid[400];
 //	extern	Double_t ymid;


namespace eutelescope {
namespace geo {



class PetaletLTR : public EUTelGenericPixGeoDescr {
	
	public:
		PetaletLTR();
		~PetaletLTR();

		void createRootDescr(char const *);
		std::string getPixName(int, int);
		std::pair<int, int> getPixIndex(char const *);
		 
		 //void getcenter(double& xmid);


	protected:
		TGeoMaterial* matSi;
		TGeoMedium* Si;
		TGeoVolume* plane;
		
		
};

extern "C"
{
	 inline EUTelGenericPixGeoDescr* maker();
}

} //namespace geo
} //namespace eutelescope

#endif	//MIMOSAR02_H
