#!/bin/python

from ROOT import *
from input_files import *
from plot_tools import *
import array
import copy
import math

set_atlas_style()

can = TCanvas("can","")
gPad.SetTicks(1,1)

npoints = 0

g = TGraphErrors(len(thresholds))
g.SetName("cluster_size_vs_threshold")
g_eff = TGraphErrors(len(thresholds))
g_eff.SetName("efficiency_vs_threshold_not_time_corrected")

g_eff_timing = TGraphErrors(len(thresholds))
g_eff_timing.SetName("efficiency_vs_threshold_time_corrected")

g_eff_strip_ctr = TGraphErrors(len(thresholds))
g_eff_strip_ctr.SetName("efficiency_vs_threshold_strip_ctr")

g_eff_strip_edge = TGraphErrors(len(thresholds))
g_eff_strip_edge.SetName("efficiency_vs_threshold_strip_edge")

g_eff_asics = []
ntotal_asic = []
npass_asic = []

h_eff_interstrip = []

for fn in files:
    f = TFile.Open(input_path+fn,"read")
    t = f.Get("testbeam")

    thresh = thresholds[npoints]

    # cluster size
    h_cl_size_x = TH1D("cl_size_x",";x;Average cluster size",6666,-80,20)
    h_nevents_x = TH1D("nevents_x",";x;",6666,-80,20)

    # efficiency
    eff_x = TEfficiency("eff_x","my efficiency;x;#epsilon",6666,-80,20)
    eff_y = TEfficiency("eff_y","my efficiency;y;#epsilon",6666,-80,20)
    eff_interstrip = TEfficiency("eff_interstrip","my efficiency;x;#epsilon",50,-0.5,0.5)

    # efficiency per strip
    eff_strip = TEfficiency("eff_strip",";x;#epsilon",1343,-79,21)

    hit = 0
    cluster_size = -1.0
    npass = -1.0
    npass_ctr = -1.0
    npass_edge = -1.0
    nevents_tot = -1.0
    nevents_ctr = -1.0
    nevents_edge = -1.0
    nevents = -1.0
    npass_notiming=-1.0
    nevents_notiming=-1.0

    for event in t:     
        #non time corrected plot
        if event.dist_FEI4 < 0.2:
             nevents_notiming+=1
        if event.dist_DUT < 0.2:
             npass_notiming+=1
        #time corrected plots
        if event.delay >= 20 and event.delay <=25: #change the time window!
            if event.dist_FEI4 < 0.2:
                nevents_tot+=1
                if event.dist_DUT > 0.2:
                     hit = 0
                if math.fabs(event.dist_trk_ctr) < 0.2:
                    nevents_ctr+=1
                if math.fabs(event.dist_trk_ctr) > 0.4:
                    nevents_edge+=1
                if event.dist_DUT < 0.2:
                    npass+=1
                    hit = 1                
                    if math.fabs(event.dist_trk_ctr) < 0.2:
                        npass_ctr+=1
                    if math.fabs(event.dist_trk_ctr) > 0.4:
                        npass_edge+=1
                    if event.cl_size<1:
                        continue
                    cluster_size += event.cl_size
                    nevents += 1.0
                    h_cl_size_x.Fill(event.x_trk_DUT,float(event.cl_size))
                    h_nevents_x.Fill(event.x_trk_DUT,1.0)
                eff_strip.Fill(hit,event.x_trk_DUT)
                eff_interstrip.Fill(hit,event.dist_trk_ctr)
                eff_x.Fill(hit,event.x_trk_DUT)
                eff_y.Fill(hit,event.y_trk_DUT)
                    
    # print nevents
    if nevents==0:
         nevents=1
    cluster_size = cluster_size/nevents
    err = TMath.Sqrt(((cluster_size-1)*(2-cluster_size)/nevents))
    # err = TMath.Sqrt((cluster_size*(cluster_size-1)/nevents))

    g.SetPoint(npoints,thresholds_fC[npoints],cluster_size)
    g.SetPointError(npoints,0,err)

    eff = npass_notiming/nevents_notiming
    err_eff = TMath.Sqrt((eff*(1-eff)/nevents_notiming))
    g_eff.SetPoint(npoints,thresholds_fC[npoints],eff)
    g_eff.SetPointError(npoints,0,err_eff)

    eff = npass/nevents_tot
    err_eff = TMath.Sqrt((eff*(1-eff)/nevents_tot))
    g_eff_timing.SetPoint(npoints,thresholds_fC[npoints],eff)
    g_eff_timing.SetPointError(npoints,0,err_eff)

    eff = npass_ctr/nevents_ctr
    err_eff = TMath.Sqrt((eff*(1-eff)/nevents_ctr))
    g_eff_strip_ctr.SetPoint(npoints,thresholds_fC[npoints],eff)
    g_eff_strip_ctr.SetPointError(npoints,0,err_eff)

    eff = npass_edge/nevents_edge
    err_eff = TMath.Sqrt((eff*(1-eff)/nevents_edge))
    g_eff_strip_edge.SetPoint(npoints,thresholds_fC[npoints],eff)
    g_eff_strip_edge.SetPointError(npoints,0,err_eff)

    for ibin in range(0,h_nevents_x.GetNbinsX()) :
        if h_nevents_x.GetBinContent(ibin+1)==0:
            h_cl_size_x.SetBinContent(ibin+1,0)
            h_cl_size_x.SetBinError(ibin+1,0)
            continue

        CS = h_cl_size_x.GetBinContent(ibin+1)/h_nevents_x.GetBinContent(ibin+1)
        h_cl_size_x.SetBinContent(ibin+1,CS)
        err = TMath.Sqrt(((CS-1)*(2-CS)/h_nevents_x.GetBinContent(ibin+1)))

        h_cl_size_x.SetBinError(ibin+1,err)

    h_cl_size_x.UseCurrentStyle()
    h_cl_size_x.SetLineColor(kBlack)
    h_cl_size_x.SetLineWidth(2)
    h_cl_size_x.GetXaxis().SetRangeUser(-3,13)
    h_cl_size_x.GetYaxis().SetRangeUser(0,3)
    h_cl_size_x.Draw()
    can.SaveAs(output_path+"cl_size_x_th"+str(thresh)+".pdf")

    h_cl_size_x.GetXaxis().SetRangeUser(-0.6,0)
    h_cl_size_x.GetYaxis().SetRangeUser(0,2)
    h_cl_size_x.Draw()
    can.SaveAs(output_path+"cl_size_x_zoom_th"+str(thresh)+".pdf")

    h_eff = eff_x.CreateGraph()
    h_eff.SetName("graph_eff_x");
    h_eff.SetTitle(";x;Efficiency");
    h_eff.UseCurrentStyle()
    h_eff.SetLineColor(kBlack)
    h_eff.SetLineWidth(2)
    h_eff.GetXaxis().SetRangeUser(-3,13)
    h_eff.GetYaxis().SetRangeUser(0,1.05)
    h_eff.Draw("APZ")
    can.SaveAs(output_path+"eff_x_th"+str(thresh)+".pdf")

    h_eff.GetXaxis().SetRangeUser(-0.6,0)
    h_eff.GetYaxis().SetRangeUser(0,1.05)
    h_eff.Draw("APZ")
    can.SaveAs(output_path+"eff_x_zoom_th"+str(thresh)+".pdf")

    h_eff_strip = eff_strip.CreateGraph()
    h_eff_strip.SetName("graph_eff_strip");
    h_eff_strip.SetTitle(";x;Efficiency");
    h_eff_strip.UseCurrentStyle()
    h_eff_strip.SetLineColor(kBlack)
    h_eff_strip.SetLineWidth(2)
    h_eff_strip.GetYaxis().SetRangeUser(0,1.05)
    h_eff_strip.Draw("APZ")
    can.SaveAs(output_path+"eff_per_strip_th"+str(thresh)+".pdf")

    h_eff_strip.GetXaxis().SetRangeUser(-1,5)
    h_eff_strip.GetYaxis().SetRangeUser(0,1.05)
    h_eff_strip.Draw("APZ")
    can.SaveAs(output_path+"eff_per_strip_zoom_th"+str(thresh)+".pdf")


    h_eff_interstrip.append( eff_interstrip.CreateGraph() )
    h_eff_interstrip[-1].SetName("graph_eff_interstrip_th"+str(thresh));
    h_eff_interstrip[-1].SetTitle(";#Deltax from strip centre;Efficiency");
    h_eff_interstrip[-1].UseCurrentStyle()
    h_eff_interstrip[-1].SetLineColor(kBlack)
    h_eff_interstrip[-1].SetLineWidth(2)
    h_eff_interstrip[-1].GetYaxis().SetRangeUser(0,1.05)
    h_eff_interstrip[-1].Draw("APZ")
    can.SaveAs(output_path+"eff_inter_strip_th"+str(thresh)+".pdf")

    npoints+=1

npoints=0

g.Draw("AP")
g.SetTitle(";Threshold;Average cluster size")
g.GetYaxis().SetRangeUser(0.9,1.4)

can.SaveAs(output_path+"cl_size_vs_threshold.pdf")

g_eff.Draw("AP")
g_eff.SetTitle(";Threshold [fC];Efficiency")
g_eff.GetYaxis().SetRangeUser(0.0,1.05)
can.SaveAs(output_path+"efficiency_vs_threshold.pdf")

g_eff_strip_ctr.Draw("AP")
g_eff_strip_ctr.SetTitle(";Threshold [fC];Efficiency (strip centre)")
g_eff_strip_ctr.GetYaxis().SetRangeUser(0.0,1.05)
can.SaveAs(output_path+"efficiency_vs_threshold_strip_ctr.pdf")

g_eff_strip_edge.Draw("AP")
g_eff_strip_edge.SetTitle(";Threshold [fC];Efficiency (strip edge)")
g_eff_strip_edge.GetYaxis().SetRangeUser(0.0,1.05)
can.SaveAs(output_path+"efficiency_vs_threshold_strip_edge.pdf")

fit_ctr = error_function("erfcFit_ctr",0,10)
fit_ctr.SetParameter(1,4) # median charge
fit_ctr.SetParameter(2,1.7)  # width (sigma)
fit_ctr.SetParameter(3,0.3)   # skew
fit_ctr.SetLineColor(kAzure-2)
g_eff_strip_ctr.Fit("erfcFit_ctr","RSB")

g_eff_strip_ctr.SetLineColor(kAzure-2)
g_eff_strip_ctr.SetMarkerColor(kAzure-2)
g_eff_strip_ctr.SetTitle(";Threshold [fC];Efficiency")
g_eff_strip_ctr.Draw("AP")

fit_all = error_function("erfcFit_all",0,10)
fit_all.SetParameter(1,3) # median charge
fit_all.SetParameter(2,1.4)  # width (sigma)
fit_all.SetParameter(3,0.5)   # skew
fit_all.SetLineColor(kBlack)
g_eff.Fit("erfcFit_all","RS")

g_eff.Draw("P same")

fit_timing = error_function("erfcFit_timing",0,10)
fit_timing.SetParameter(1,4) # median charge
fit_timing.SetParameter(2,1.7)  # width (sigma)
fit_timing.SetParameter(3,0.5)   # skew
fit_timing.SetLineColor(kBlack)
g_eff_timing.Fit("erfcFit_timing","RS")

g_eff_timing.Draw("A P")
g_eff_timing.SetTitle(";Threshold [fC];Efficiency")
g_eff_timing.GetYaxis().SetRangeUser(0.0,1.05)

can.SaveAs(output_path+"efficiency_vs_threshold_timing.pdf")

fit_edge = error_function("erfcFit_edge",0,10)
fit_edge.SetParameter(1,1.5) # median charge
fit_edge.SetParameter(2,0.7)  # width (sigma)
fit_edge.SetParameter(3,0.3)   # skew
fit_edge.SetLineColor(kBlue+1)
g_eff_strip_edge.Fit("erfcFit_edge","RS")

g_eff_strip_edge.SetLineColor(kBlue+1)
g_eff_strip_edge.SetMarkerColor(kBlue+1)
g_eff_strip_edge.Draw("P same")

can.SaveAs(output_path+"efficiency_vs_threshold_strip_ctr_vs_edge.pdf")

h_eff_interstrip[0].Draw("PA")
icol = 0
for h in h_eff_interstrip:
    h.SetLineColor(kAzure+icol)
    h.SetMarkerColor(kAzure+icol)
    h.Draw("P same")
    icol+=1

can.SaveAs(output_path+"efficiency_vs_threshold_interstrip.pdf")

can.cd()

fout = TFile.Open(output_path+"testbeam_plots_efficiency_pos1.root","recreate")

g.Write()
g_eff.Write()
g_eff_timing.Write()
g_eff_strip_ctr.Write()
g_eff_strip_edge.Write()
