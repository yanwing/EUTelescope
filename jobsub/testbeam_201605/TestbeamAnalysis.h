// ROOT includes
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "TObjArray.h"
#include "TEnv.h"
#include "TMath.h"

// C++ includes
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

vector<double>* ID_loc;
vector<double>* x_loc;
vector<double>* y_loc;
int event_nr_loc;

vector<double>* ID_gbl;
vector<double>* x_gbl;
vector<double>* y_gbl;
vector<double>* chi2_gbl;
vector<double>* ndf_gbl;
int event_nr_gbl;

vector<double>* ID_cl;
vector<double>* x_cl;
vector<double>* y_cl;
int event_nr_cl;

int timing;

void fatal(string msg){
  cout << "ERROR: " << msg << endl;
  abort();
}

double x_trk_FEI4, y_trk_FEI4;
double x_hit_FEI4, y_hit_FEI4;
double x_resid_FEI4, y_resid_FEI4;
double dist_FEI4;
double x_trk_DUT, y_trk_DUT;
double x_hit_DUT, y_hit_DUT;
int    pix_hit_DUT;
double pix_trk_DUT;
int    ASIC_trk_DUT, ASIC_hit_DUT;
double x_resid_DUT, y_resid_DUT,resid_DUT;
double dist_DUT,dist_DUT2, dist_DUT3;
double dist_trk_ctr;
int    cl_size, delay;
int    pixel_centre;
  
std::vector<TString> vectorise(TString str, TString sep=" ") {
  std::vector<TString> result; TObjArray *strings = str.Tokenize(sep.Data());
  if (strings->GetEntries()==0) { delete strings; return result; }
  TIter istr(strings);
  while (TObjString* os=(TObjString*)istr()) result.push_back(os->GetString());
  delete strings; return result;
}

std::vector<int> vectoriseI(TString str, TString sep=" ") {
  std::vector<int> result; std::vector<TString> vecS = vectorise(str);
  for (uint i=0;i<vecS.size();++i)
  result.push_back(atof(vecS[i]));
  return result;
}
