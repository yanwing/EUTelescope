#include "EUTelTrackCreate.h"	

namespace eutelescope 
{
EUTelTrack EUTelTrackCreate::getTrackFourHits(std::vector<EUTelHit> hits ){
	streamlog_out(DEBUG1) << "HITS TO FORM TRACK FROM: " << std::endl;
    std::vector<EUTelHit>::iterator itHit;
    for(itHit = hits.begin(); itHit != hits.end(); itHit++){
        itHit->print(); 
        streamlog_out(DEBUG1) << "gettrackfourhits ithit " << std::endl;
    }
    streamlog_out(DEBUG1) << "gettrackfourhits check 1 " << std::endl;
    //Always use mimosa planes to create initial track parameterisation.
    EUTelHit hitArmOne1;
    EUTelHit hitArmOne2;
    EUTelHit hitArmTwo1;
    EUTelHit hitArmTwo2;
    streamlog_out(DEBUG1) << "gettrackfourhits check 2 " << std::endl;
    for(itHit = hits.begin(); itHit != hits.end(); itHit++){
        if(itHit->getLocation() == 0){
            hitArmOne1 = *itHit;
        }
        if(itHit->getLocation() == 2){
            hitArmOne2 = *itHit;
        }
        if(itHit->getLocation() == 3){
            hitArmTwo1 = *itHit;
        }
        if(itHit->getLocation() == 5){
            hitArmTwo2 = *itHit;
        }

    }
    double qOverPCorr;
    //Find correction of curvature through slope change.
    const gear::BField& B = geo::gGeometry().getMagneticField();
    const double Bmag = B.at( TVector3(0.,0.,0.) ).r2();
    if ( Bmag < 1.E-6 ){
        qOverPCorr = 0;
    }else{
        qOverPCorr =  EUTelNav::getCorr(hitArmOne1,hitArmOne2,hitArmTwo1,hitArmTwo2);
    }
    double qOverP = -1.0/EUTelNav::_intBeamE+ qOverPCorr;
    streamlog_out(DEBUG1) << "gettrackfourhits check 3, qOverP = "<<qOverPCorr << std::endl;
    //NOW CREATE TRACK CANDIDATE
    std::vector<double> offset;
    std::vector<double> trackSlope; 
    EUTelNav::getTrackAvePara(hitArmOne1, hitArmTwo2, offset, trackSlope);
    streamlog_out(DEBUG1) << "gettrackfourhits check 4 " << std::endl;
    EUTelTrack track = getTrack(hits,offset,trackSlope,qOverP);
    streamlog_out(DEBUG1) << "gettrackfourhits check 5, print track"<< std::endl;
    track.print();
    return track;

}
EUTelTrack EUTelTrackCreate::getTrack(std::vector<EUTelHit> hits, std::vector<double> offset, std::vector<double> trackSlope,double qOverP){
    EUTelTrack track;
    track.setQOverP(qOverP);
    std::vector<double> curvCorr; curvCorr.push_back(track.getQOverP()*EUTelNav::_bFac[0]);curvCorr.push_back(track.getQOverP()*EUTelNav::_bFac[1]);
    // loop around planes
    // loop around hits -> if hit matched to plane record hit, if not record my intersection
  // streamlog_out(DEBUG1) << "EUTelExcludedPlanes::_senInc.size() = " <<EUTelExcludedPlanes::_senInc.size()<<std::endl;
   /* for(unsigned int  j = 0; j < (EUTelExcludedPlanes::_senInc.size()); ++j){
        unsigned int sensorIDtest = EUTelExcludedPlanes::_senInc.at(j);
        streamlog_out(DEBUG1) << "The Z position " << j << " sensor ID: " << sensorIDtest  <<std::endl;
    }*/
    for(unsigned int  j = 0; j < (EUTelExcludedPlanes::_senInc.size()); ++j){
        unsigned int sensorID = EUTelExcludedPlanes::_senInc.at(j);
        streamlog_out(DEBUG1) << "The Z position " << j << " sensor ID: " << sensorID  <<std::endl;
        bool hitOnPlane=false;
        EUTelState state; //Create a state for each plane included in the fit.
       // streamlog_out(DEBUG1) << "hits.size() = " << hits.size() << std::endl;
         for(unsigned int i = 0; i < hits.size(); ++i){//Check the list of hits to see if we have one on this plane.
          //  streamlog_out(DEBUG1) << "loop over hit" <<std::endl;
            if(hits.at(i).getLocation()==sensorID){
                hitOnPlane=true;
                Eigen::Vector3d posPred;
                std::vector<double> slopePred;
                EUTelNav::getTrackPredictionFromParam(offset,trackSlope,qOverP, hits.at(i).getPositionGlobal()[2],posPred,slopePred);
                //streamlog_out(DEBUG1) << "get track check1" << std::endl;
                state.setLocation(hits.at(i).getLocation());
               // streamlog_out(DEBUG1) << "get track check2" << std::endl;
                state.setHit(hits.at(i));
               // streamlog_out(DEBUG1) << "get track check3" << std::endl;
                float intersectionPoint[3];
                intersectionPoint[0] = posPred[0];  intersectionPoint[1] = posPred[1]; intersectionPoint[2] = hits.at(i).getPositionGlobal()[2];
                //streamlog_out(DEBUG1) << "intersectionPoint[0]= " << intersectionPoint[0]<<", [1] = " << intersectionPoint[1]<<", [2] = "  << intersectionPoint[2]<<std::endl;
                streamlog_out(DEBUG1) << "get track check4" << std::endl;
                //intersection might not be inside a volume. 
                state.setPositionGlobal(intersectionPoint);
                streamlog_out(DEBUG1) << "get track check5" << std::endl;
                state.setDirFromGloSlope(slopePred);
                streamlog_out(DEBUG1) << "get track check6" << std::endl;
                track.setState(state);
               //std::cout<<"Added hit! " << " z pos: " << i  <<std::endl;
            }
        }
        streamlog_out(DEBUG1) << "looped over hit" << std::endl;
        if(hitOnPlane){streamlog_out(DEBUG1) <<"this should already be recorded as there is a hit on sensor "<<sensorID<<std::endl;}
        else {
        //    std::cout<<"No hit ID " <<sensorID <<std::endl;
            double z_dut=geo::gGeometry().getOffsetVector(sensorID)[2];
            Eigen::Vector3d posPred;
            std::vector<double> slopePred;
            EUTelNav::getTrackPredictionFromParam(offset,trackSlope,qOverP, z_dut,posPred,slopePred);
            state.setDirFromGloSlope(slopePred);
            //   TVector3 hitPosGlo = hit.getPositionGlobal();
            float intersectionPoint[3];
            intersectionPoint[0] = posPred[0];  intersectionPoint[1] = posPred[1]; intersectionPoint[2] = z_dut;
            //   //intersection might not be inside a volume. 
            streamlog_out(DEBUG1)<<"intersection point on sensorID "<<sensorID<<" = "<<	intersectionPoint[0]<<", "<<intersectionPoint[1]<<", "<<intersectionPoint[2]<<std::endl;
            //add explicit check that it intersects with sensor?   but i want edge effects?   
            //add arc length thingy
            state.setLocation(sensorID);
            state.setPositionGlobal(intersectionPoint);
            track.setState(state);

        }//else
        streamlog_out(DEBUG1) << "loop at The Z position " << j << " sensor ID: " << sensorID  << " ends " <<std::endl;
    }//loop about planes, j iterator
    streamlog_out(DEBUG1) << "loop over all planes"  <<std::endl;
    track.print();
    return track;
}


} //napace eutelescope
