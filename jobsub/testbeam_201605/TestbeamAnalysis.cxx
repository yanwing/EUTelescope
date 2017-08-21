//-------------------------------------------------------------------------------------------
// TestbeamAnalyses: analyses reconstructed testbeam TTrees
// Author: Michaela Queitsch-Maitland <michaela.queitsch-maitland@cern.ch>
//-------------------------------------------------------------------------------------------

#include "TestbeamAnalysis.h"

// main function
int main(int argc, char** argv) {

  if ( argc<2 ) {
    fatal("No arguments given! Can't continue.");
  }

  TH1::SetDefaultSumw2(kTRUE);

  // read input file
  TString input_file="";
  TString output_file="";

  bool debug = false;
  TString settings_file;

  // loop over arguments
  for(int i=1; i<argc; ++i){
    TString arg = TString(argv[i]);
    if(arg.BeginsWith("-")){
      arg.ReplaceAll("-","");
      if(arg=="config"){ settings_file = TString(argv[i+1]); ++i; continue; }
      else if(arg=="input"){ input_file = argv[i+1]; ++i; continue; }
      else if(arg=="debug"){ debug = true; break; }
      else {
        fatal(Form("Don't understand input argument %s",arg.Data()));
      }
    }
  }

  // read run settings from config file
  TEnv* settings = new TEnv();
  settings->ReadFile(settings_file.Data(),EEnvLevel(0));

  // DUT and FEI4 IDs and relative position
  int DUT_ID = settings->GetValue("DUT_ID",10);
  int FEI4_ID = settings->GetValue("FEI4_ID",20);
  int DUT_FEI4_pos = settings->GetValue("DUT_FEI4_pos",2);

  // GBL track chi2/ndf cut
  double max_chi2 = settings->GetValue("GBL_chi2",3.0);

  // parameters to convert from local coordinate system to pixel
  double strip_pitch = settings->GetValue("strip_pitch",0.0745);
  double offset = settings->GetValue("beam_offset",50.0);

  // maximum distance to associate hit to track for both FEI4 and DUT
  double max_dist = settings->GetValue("max_dist",0.2);

  // timing selection
  int min_time = settings->GetValue("min_time",0);
  int max_time = settings->GetValue("max_time",50);

  // fiducial area cuts
  double pix_cut_min = settings->GetValue("pix_cut_min",-5.0);
  double pix_cut_max = settings->GetValue("pix_cut_max",2000.0);
  double y_cut_min = settings->GetValue("y_cut_min",-1000.0);
  double y_cut_max = settings->GetValue("y_cut_max",1000.0);

  // orientation of DUT with respect to FEI4
  bool rotated = settings->GetValue("rotated",0);

  // Noisy/inefficient pixels and/or bad events to be vetoed
  vector<int> bad_pixels = vectoriseI(settings->GetValue("bad_pixels",""));

  cout << "bad pixels:" << endl;
  for ( auto pixel : bad_pixels )
  {
    cout << pixel << endl;
  }

  // set planes to analyse residuals
  vector<int> planes = vector<int>{0,1,2,4,5,DUT_ID,FEI4_ID};

  TFile* f_in = TFile::Open(input_file,"read");

  // get file name for output
  TObjArray *strings = input_file.Tokenize("/");
  output_file = ((TObjString*)strings->Last())->GetString();
  output_file.ReplaceAll("NTuple","TestbeamAnalysis");
  delete strings;
  cout << "Output file name: " << output_file << endl;

  // get ttrees from input file
  TTree* t_loc = (TTree*)f_in->Get("local_hit");
  TTree* t_gbl = (TTree*)f_in->Get("GBL_tracks");
  TTree* t_cl = (TTree*)f_in->Get("zsdata_strip");

  // set branch addresses
  t_loc->SetBranchAddress("ID",&ID_loc);
  if (rotated) {
    t_loc->SetBranchAddress("y",&x_loc);
    t_loc->SetBranchAddress("x",&y_loc);
  } else {
    t_loc->SetBranchAddress("x",&x_loc);
    t_loc->SetBranchAddress("y",&y_loc);
  }
  t_loc->SetBranchAddress("event_nr",&event_nr_loc);

  t_gbl->SetBranchAddress("ID",&ID_gbl);
  if (rotated) {
    t_gbl->SetBranchAddress("y",&x_gbl);
    t_gbl->SetBranchAddress("x",&y_gbl);
  }
  else {
    t_gbl->SetBranchAddress("x",&x_gbl);
    t_gbl->SetBranchAddress("y",&y_gbl);
  }
  t_gbl->SetBranchAddress("chi2",&chi2_gbl);
  t_gbl->SetBranchAddress("ndf",&ndf_gbl);
  t_gbl->SetBranchAddress("event_nr",&event_nr_gbl);

  t_cl->SetBranchAddress("ID",&ID_cl);
  if (rotated) {
    t_cl->SetBranchAddress("y",&x_cl);
    t_cl->SetBranchAddress("x",&y_cl);
  }
  else {
    t_cl->SetBranchAddress("x",&x_cl);
    t_cl->SetBranchAddress("y",&y_cl);
  }
  t_cl->SetBranchAddress("event_nr",&event_nr_cl);

  t_gbl->SetBranchAddress("TDC",&timing);

  // read number of entries and check they are the same for local hits/GBL tracks
  Long64_t nentries_loc = t_loc->GetEntries();
  Long64_t nentries_gbl = t_gbl->GetEntries();
  Long64_t nentries_cl = t_cl->GetEntries();

  if ( nentries_loc!=nentries_gbl ) fatal("Number of local hits and GBL track entries do not match!");
  else if ( nentries_loc!=nentries_cl ) fatal("Number of local hits and cluster entries do not match!");

  // create output root file and write trees/histograms/graphs
  TFile* f_out = TFile::Open(output_file,"recreate");

  // create output ntuple (for final plots/histograms)
  TTree* t_out = new TTree("testbeam","testbeam");
  t_out->Branch("x_trk_FEI4",&x_trk_FEI4);
  t_out->Branch("y_trk_FEI4",&y_trk_FEI4);
  t_out->Branch("x_hit_FEI4",&x_hit_FEI4);
  t_out->Branch("y_hit_FEI4",&y_hit_FEI4);
  t_out->Branch("dist_FEI4",&dist_FEI4);
  t_out->Branch("x_trk_DUT",&x_trk_DUT);
  t_out->Branch("y_trk_DUT",&y_trk_DUT);
  t_out->Branch("x_hit_DUT",&x_hit_DUT);
  t_out->Branch("y_hit_DUT",&y_hit_DUT);
  t_out->Branch("pix_hit_DUT",&pix_hit_DUT);
  t_out->Branch("pix_trk_DUT",&pix_trk_DUT);
  t_out->Branch("pixel_centre",&pixel_centre);
  t_out->Branch("dist_trk_ctr",&dist_trk_ctr);
  t_out->Branch("ASIC_hit_DUT",&ASIC_hit_DUT);
  t_out->Branch("ASIC_trk_DUT",&ASIC_trk_DUT);
  t_out->Branch("dist_DUT",&dist_DUT);
  t_out->Branch("dist_DUT2",&dist_DUT2);
  t_out->Branch("dist_DUT3",&dist_DUT3);
  t_out->Branch("resid_DUT",&resid_DUT);
  t_out->Branch("cl_size",&cl_size);
  t_out->Branch("delay",&delay);

  // create output histograms
  map <string, TH1D*> hists;
  for ( const auto& pid : planes) {
    hists[Form("resid_dist_%d",pid)] = new TH1D(Form("resid_dist_%d",pid),";#sqrt{(x_{track}-x_{hit})^{2}+(y_{track}-y_{hit})^{2}};",200,0,5);
    hists[Form("resid_x_%d",pid)] = new TH1D(Form("resid_x_%d",pid),";x_{track}-x_{hit};",200,-0.2,0.2);
    hists[Form("resid_y_%d",pid)] = new TH1D(Form("resid_y_%d",pid),";y_{track}-y_{hit};",200,-0.2,0.2);
  }
  hists["dist_DUT_FEI4"] = new TH1D("dist_DUT_FEI4",";;",200,0,5);
  hists["cl_size_x"] = new TH1D("cl_size_x",";x_{track};",6666,-80,20);
  // Efficiency objects to create
  TEfficiency* eff_x = new TEfficiency("eff_x","my efficiency;x;#epsilon",1280*10,0.5,1280.5);
  TEfficiency* eff_y = new TEfficiency("eff_y","my efficiency;y [mm];#epsilon",1000,-100,100);
  TEfficiency* eff_timing = new TEfficiency("eff_timing","my efficiency;delay [time bin];#epsilon",65,-15.5,49.5);
  TEfficiency* eff_event = new TEfficiency("eff_event","my efficiency;event number;#epsilon",120,0,240000);
  TEfficiency* cl_x = new TEfficiency("cl_x","cluster size;x;P(cluster>1)",1280*6,0.5,1280.5);
  TEfficiency* cl_y = new TEfficiency("cl_y","cluster size;y [mm];P(cluster>1)",1000,-100,100);
  TEfficiency* cs_timing = new TEfficiency("cs_timing","my efficiency;delay [time bin];P(cluster>1)",65,-15.5,49.5);

  // loop over entries
  for ( Long64_t ientry=0; ientry<nentries_loc; ientry++) {

    if ( ientry % 5000 == 0 ) cout << Form("%5d / %6d events ( %7.1f%% )",int(ientry),int(nentries_loc),100.0*ientry/nentries_loc) << endl;

    // get the entry from each ttree
    t_loc->GetEntry(ientry);
    t_gbl->GetEntry(ientry);
    t_cl->GetEntry(ientry);

    if ( event_nr_loc != event_nr_cl ) {
      cout << event_nr_loc << "\t" << event_nr_cl << endl;
      fatal("Event number mismatch between local hit and cluster ntuples.");
    }

    // print information
    if (debug && ientry<100) {
      cout << "Event " << ientry << "  " << event_nr_loc << endl;
      cout << endl;
      cout << "GBL tracks" << endl;
      for ( int j=0; j<ID_gbl->size(); ++j){
        cout << Form("ID: %1.0f \t x: %1.3f \t y: %1.3f \t chi2/ndf: %1.3f ",ID_gbl->at(j),x_gbl->at(j),y_gbl->at(j),chi2_gbl->at(j)/ndf_gbl->at(j)) << endl;
      }
      cout << endl;
      cout << "local hits" << endl;
      for ( int j=0; j<ID_loc->size(); ++j){
        cout << Form("ID: %1.0f \t x: %1.3f \t y: %1.3f",ID_loc->at(j),x_loc->at(j),y_loc->at(j)) << endl;
      }
      cout << endl;
      cout << "cluster" << endl;
      for ( int j=0; j<ID_cl->size(); ++j){
        cout << Form("ID: %1.0f \t x: %1.3f \t y: %1.3f",ID_cl->at(j),x_cl->at(j),y_cl->at(j)) << endl;
      }
    }

    // calculate residuals
    for ( int j=0; j<ID_gbl->size(); ++j){
      for ( const auto& pid : planes) {
        if ( ID_gbl->at(j)==pid ) {
          for ( int k=0; k<ID_loc->size(); ++k){
            if ( ID_loc->at(k)==pid ) {
              double dist = sqrt(pow(x_gbl->at(j)-x_loc->at(k),2)+pow(y_gbl->at(j)-y_loc->at(k),2));

              // only check x-distance if looking at DUT
              if ( pid==DUT_ID ) {
                dist = sqrt(pow(x_gbl->at(j)-x_loc->at(k),2));
              }

              hists[Form("resid_dist_%d",pid)]->Fill(dist);

              if ( dist>max_dist ) continue;

              hists[Form("resid_x_%d",pid)]->Fill(x_gbl->at(j)-x_loc->at(k));
              hists[Form("resid_y_%d",pid)]->Fill(y_gbl->at(j)-y_loc->at(k));
            }
          }
        }
      }
    }

    dist_FEI4=999.9;
    int FEI4_trk_id=-1;
    pixel_centre= -1;
    double chi2_ndf=999.9;
    bool FEI41 = false;
    bool FEI42=false;
    for ( int j=0; j<ID_gbl->size(); ++j){
      // check for matched track in FEI4
      if ( ID_gbl->at(j)==FEI4_ID ) {

        chi2_ndf = chi2_gbl->at(j)/ndf_gbl->at(j);
        if ( max_chi2>0 && chi2_ndf > max_chi2 ) continue;

        for ( int k=0; k<ID_loc->size(); ++k){
          if ( ID_loc->at(k)==FEI4_ID ) {
            double dist = sqrt(pow(x_gbl->at(j)-x_loc->at(k),2)+pow(y_gbl->at(j)-y_loc->at(k),2));
            
            if ( dist<dist_FEI4 ) {
              dist_FEI4 = dist;

              x_trk_FEI4 = x_gbl->at(j);
              y_trk_FEI4 = y_gbl->at(j);

              x_hit_FEI4 = x_loc->at(k);
              y_hit_FEI4 = y_loc->at(k);

              x_resid_FEI4 = x_gbl->at(j)-x_loc->at(k);
              y_resid_FEI4 = y_gbl->at(j)-y_loc->at(k);

              FEI4_trk_id=j;
              
              // FEI41 and FEI42 serve to cut events with more than a track on the SAME FEI4 pixel.
              // Unfortunately the only way I could think was to cut the events with more than a track with a hit on ANY FEI4 pixel
              if (dist_FEI4<max_dist&&FEI41==true) FEI42=true;
              if (dist_FEI4<max_dist) FEI41=true;
            }
          }
        }
      }
    }

    // no matched FEI4 track...
    if ( dist_FEI4 > max_dist ) continue;
    if ( FEI42 ==true ) continue;

    TString n;
    n = n.Itoa(timing,2);
    delay=n.Sizeof();
    if (n.CountChar(49)==1) delay = delay-1; //this is due to some overflow that should be check for new data

    if ( ID_gbl->at(FEI4_trk_id-DUT_FEI4_pos) != DUT_ID ) {
      fatal("ID of the DUT incorrect or position of DUT with respect to FEI4 is wrong. Check DUT_FEI4_pos!");
    }

    x_trk_DUT = x_gbl->at(FEI4_trk_id-DUT_FEI4_pos);
    y_trk_DUT = y_gbl->at(FEI4_trk_id-DUT_FEI4_pos);

    dist_DUT=999.9;
    dist_DUT2=999.9;
    dist_DUT3=999.9;
    resid_DUT=999.9;
    // check for matched track in DUT (using same track as in FEI4)
    for ( int k=0; k<ID_loc->size(); ++k){
      if ( ID_loc->at(k)==DUT_ID ) {
        double dist = sqrt(pow(x_gbl->at(FEI4_trk_id-DUT_FEI4_pos)-x_loc->at(k),2));
        hists["dist_DUT_FEI4"]->Fill(dist);
        if ( dist<dist_DUT ) {
          dist_DUT = dist;
          resid_DUT = x_gbl->at(FEI4_trk_id-DUT_FEI4_pos)-x_loc->at(k);

          x_hit_DUT = x_loc->at(k);
          y_hit_DUT = y_loc->at(k);

          x_resid_DUT = x_gbl->at(FEI4_trk_id-DUT_FEI4_pos)-x_loc->at(k);
          y_resid_DUT = y_gbl->at(FEI4_trk_id-DUT_FEI4_pos)-y_loc->at(k);

        }
      }
      if ( ID_loc->at(k)==DUT_ID +2) {
        double dist = sqrt(pow(x_gbl->at(FEI4_trk_id-DUT_FEI4_pos)-x_loc->at(k),2));
        if ( dist<dist_DUT2) dist_DUT2 = dist;
      }
      if ( ID_loc->at(k)==DUT_ID +4) {
        double dist = sqrt(pow(x_gbl->at(FEI4_trk_id-DUT_FEI4_pos)-x_loc->at(k),2));
        if ( dist<dist_DUT3) dist_DUT3 = dist;
      }
    }

    // position of hit and track in pixel coordinates
    pix_hit_DUT = int((x_hit_DUT+offset)/strip_pitch-0.5);
    pix_trk_DUT = (x_trk_DUT+offset)/strip_pitch-0.5;

    // Track and hit position cut
    if ( pix_trk_DUT < pix_cut_min || pix_trk_DUT>pix_cut_max || y_trk_DUT<y_cut_min || y_trk_DUT>y_cut_max )continue;

    // ASIC associated with the hit and track (10 ASICs with 128 strips each)
    ASIC_hit_DUT = int(ceil((float(pix_hit_DUT)/128)));
    ASIC_trk_DUT = int(ceil((pix_trk_DUT)/128));

    int trk_pixel = ceil(pix_trk_DUT);
    pixel_centre = trk_pixel;
    if (fabs(pix_trk_DUT-trk_pixel)>0.5) pixel_centre = pixel_centre-1;
    dist_trk_ctr = pix_trk_DUT - pixel_centre;
    
    // Noisy/inefficient pixel remover
    bool bad_pixel=false;
    for ( const auto& pixel : bad_pixels ) {
      if ( fabs(pixel-pixel_centre)<2 ) {
        bad_pixel=true;
        break;
      }
    }
    if (bad_pixel) continue;

    //Efficiency plots
    if(dist_DUT<max_dist && delay>=min_time && delay <=max_time) {eff_x->Fill(true,pix_trk_DUT); eff_y->Fill(true,y_gbl->at(FEI4_trk_id-DUT_FEI4_pos)); eff_event->Fill(true,event_nr_loc);}
    if(dist_DUT>max_dist && delay>=min_time && delay <=max_time) {eff_x->Fill(false,pix_trk_DUT);eff_y->Fill(false,y_gbl->at(FEI4_trk_id-DUT_FEI4_pos));eff_event->Fill(false,event_nr_loc);}
    if(dist_DUT<max_dist) eff_timing->Fill(true,delay);
    if(dist_DUT2<max_dist) eff_timing->Fill(true,delay-16);
    if(dist_DUT3<max_dist) eff_timing->Fill(true,delay+16);
    if(dist_DUT>max_dist) eff_timing->Fill(false,delay);
    if(dist_DUT2>max_dist) eff_timing->Fill(false,delay-16);
    if(dist_DUT3>max_dist) eff_timing->Fill(false,delay+16); 
    
    // cluster size
    cl_size = -1;
    for ( int k=0; k<ID_cl->size(); ++k){
      if ( ID_cl->at(k)==DUT_ID ) {
        // found pixel associated with hit
        if ( fabs(pix_hit_DUT - x_cl->at(k)) <1.5 ) {
          cl_size=1;

          //Look for hits on the neighbour strips on the right
          for (int mR=1; mR<30; mR++){
            if ( (k+mR)<ID_cl->size() && abs(x_cl->at(k+mR)-x_cl->at(k+mR-1))==1 && ID_cl->at(k+mR)==DUT_ID && ID_cl->at(k+mR-1)==DUT_ID){
              cl_size += 1;
            } else break;
          }

          //Look for hits in the neighbour strips on the left
          for (int mL=1; mL<30; mL++){
            if ( (k-mL)>-1 && abs(x_cl->at(k-mL)-x_cl->at(k-mL+1))==1 && ID_cl->at(k-mL)==DUT_ID && ID_cl->at(k-mL+1)==DUT_ID) {
              cl_size+=1;
            } else break;
          }
        }
      }
    }

    if (delay>=min_time && delay <=max_time){
      if (cl_size==1) {cl_x->Fill(false,pix_trk_DUT); cl_y->Fill(false,y_trk_DUT);}
      if (cl_size>1) {cl_x->Fill(true,pix_trk_DUT); cl_y->Fill(true,y_trk_DUT);}
    }

    if (cl_size==1) cs_timing->Fill(false,delay);
    if (cl_size>1) cs_timing->Fill(true,delay);

    t_out->Fill();

  }

  // create efficiency graphs ("g_" files are needed by root 5)
  TGraphAsymmErrors* g_eff_x = eff_x->CreateGraph();
  g_eff_x->SetName("graph_eff_x");
  TGraphAsymmErrors* g_eff_y = eff_y->CreateGraph();
  g_eff_y->SetName("graph_eff_y");
  TGraphAsymmErrors* g_eff_timing = eff_timing->CreateGraph();
  g_eff_timing->SetName("graph_eff_timing");
  g_eff_timing->GetXaxis()->SetTitle("Delay [ns]");
  TGraphAsymmErrors* g_cl_x = cl_x->CreateGraph();
  g_cl_x->SetName("graph_cl_x");
  TGraphAsymmErrors* g_cl_y = cl_y->CreateGraph();
  g_cl_y->SetName("graph_cl_y");
  TGraphAsymmErrors* g_cs_timing = cs_timing->CreateGraph();
  g_cs_timing->SetName("graph_cs_timing");

  // fit gaussian to residuals
  for ( const auto& pid : planes) {
    hists[Form("resid_x_%d",pid)]->Fit("gaus");
    hists[Form("resid_y_%d",pid)]->Fit("gaus");
  }

  f_out->cd();
  t_out->Write();

  hists["dist_DUT_FEI4"]->Write();
  eff_x->Write();
  g_eff_x->Write();
  eff_y->Write();
  g_eff_y->Write();
  eff_timing->Write();
  g_eff_timing->Write();
  cl_x->Write();
  g_cl_x->Write();
  cl_y->Write();
  g_cl_y->Write();
  cs_timing->Write();
  g_cs_timing->Write();
  eff_event->Write();
  for ( const auto& pid : planes) {
    hists[Form("resid_dist_%d",pid)]->Write();
    hists[Form("resid_x_%d",pid)]->Write();
    hists[Form("resid_y_%d",pid)]->Write();
  }

  hists.clear();
  f_out->Close();
  delete f_out;

  return 1;
}
