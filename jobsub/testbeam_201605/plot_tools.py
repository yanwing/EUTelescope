#!/bin/python

from ROOT import *
from input_files import *

# ASIC numbers
asics = [1,2,3,4,5,6,7,8,9,10]

# dictionary to convert DAC -> mV
pp=[1189.70,3.03,-575.12] #SS ASIC 20 300V

convtable = {}
file = open("ABC130_thrCal.txt")
for l in file.readlines():
	l = l.strip()
	convtable[float(l.split()[0])] = float(l.split()[2])
	
thresholds_mV  = []
for threshold in thresholds:
	thresholds_mV.append(convtable[int(threshold)])	

thresholds_fC = []
for threshold in thresholds_mV:
	thresholds_fC.append(-1.0 * pp[1] * TMath.Log( (pp[0]/(threshold-pp[2])) - 1.0 ))

def error_function(func_name,min,max):
    func = TF1(func_name,"[0]*0.5*TMath::Erfc((x-[1])/(TMath::Sqrt(2)*[2])*(1+0.6*(TMath::Exp(-[3]*(x-[1])/(TMath::Sqrt(2)*[2]))-TMath::Exp([3]*(x-[1])/(TMath::Sqrt(2)*[2]))) / (TMath::Exp(-[3]*(x-[1])/(TMath::Sqrt(2)*[2]))+TMath::Exp([3]*(x-[1])/(TMath::Sqrt(2)*[2])))))",min,max)
    func.SetParameter(0,1)       # efficiency
    func.SetParLimits(0,0,1.0)
    func.SetParameter(1,max*0.4) # median charge
    func.SetParameter(2,1.5)     # width (sigma)
    func.SetParameter(3,0.5)     # skew
    return func

def set_atlas_style():

    gStyle.SetOptStat(0)
    gStyle.SetPadTopMargin(0.05)
    gStyle.SetPadRightMargin(0.05)
    gStyle.SetPadBottomMargin(0.14)
    gStyle.SetPadLeftMargin(0.14)
    gStyle.SetTitleYOffset(0.9)
    gStyle.SetTitleXOffset(0.9)

    gStyle.SetMarkerStyle(20)
    gStyle.SetLineColor(kBlack)

    font = 42
    tsize = 0.05
    gStyle.SetTextFont(font)

    gStyle.SetTextSize(tsize)
    gStyle.SetLabelFont(font,"x")
    gStyle.SetTitleFont(font,"x")
    gStyle.SetLabelFont(font,"y")
    gStyle.SetTitleFont(font,"y")
    gStyle.SetLabelFont(font,"z")
    gStyle.SetTitleFont(font,"z")

    gStyle.SetLabelSize(tsize,"x")
    gStyle.SetTitleSize(tsize,"x")
    gStyle.SetLabelSize(tsize,"y")
    gStyle.SetTitleSize(tsize,"y")
    gStyle.SetLabelSize(tsize,"z")
    gStyle.SetTitleSize(tsize,"z")

    gStyle.SetPalette(1)
    gStyle.SetNumberContours(100)

    TH1.SetDefaultSumw2(kTRUE)
