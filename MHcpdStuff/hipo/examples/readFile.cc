//******************************************************************
//*  ██╗  ██╗██╗██████╗  ██████╗     ██╗  ██╗    ██████╗
//*  ██║  ██║██║██╔══██╗██╔═══██╗    ██║  ██║   ██╔═████╗
//*  ███████║██║██████╔╝██║   ██║    ███████║   ██║██╔██║
//*  ██╔══██║██║██╔═══╝ ██║   ██║    ╚════██║   ████╔╝██║
//*  ██║  ██║██║██║     ╚██████╔╝         ██║██╗╚██████╔╝
//*  ╚═╝  ╚═╝╚═╝╚═╝      ╚═════╝          ╚═╝╚═╝ ╚═════╝
//************************ Jefferson National Lab (2017) ***********
//******************************************************************
//* Example program for reading HIPO-4 Files..
//* Reads the file created by writeFile program
//*--
//* Author: G.Gavalian
//*

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "reader.h"
//include <node.h>
#include <TCanvas.h>
#include <TH1D.h>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <math.h>
#include <TH1D.h>
#include <TH1F.h>
#include <TH2D.h>
#include <TF1.h>
#include <TH2F.h>
#include <TFile.h>
#include <iomanip>
#include <time.h>
#include <TVector3.h>
#include <TMath.h>
#include "TCutG.h"
#include <TLine.h>
#include <TLorentzVector.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <TGraphErrors.h>
#include "TLegend.h"
//#include <map>
#include <unordered_map>
#include <float.h>
#include <TROOT.h>
#include <TLatex.h>
#include <TPaveText.h>
#include <THStack.h>
#include <TLegend.h>

//#include "fastmc.C"
//#include "SpecsGEO.hh"
//#include "moh_functions.C"
//#include "clas12_fastmc/n_CLAS12_fastmc.C"

//	TF1 fn_sig_up = new F1D("fn_sig_up","[p0]*(x*x) + [p1]*x + [p2]", 0.9, 10);
//       TF1 fn_sig_dn = new F1D("fn_sig_dn","[p0]*(x*x) + [p1]*x + [p2]", 0.9, 10);


#define PI  3.14159
const double M_e=0.000511;   
const double E_b= 2.14;
const double M_p= 0.93827;
const double M_n= 0.93957;
const double M_d= 1.8756;

	int main(int argc, char** argv) 
{
 TF1 *fn_sig_up = new TF1("fn_sig_up","[p0]*(x*x) + [p1]*x + [p2]", 0.9, 10);
       TF1 *fn_sig_dn = new TF1("fn_sig_dn","[p0]*(x*x) + [p1]*x + [p2]", 0.9, 10);


	gROOT->Reset();
 	gStyle->SetPalette(kBird);
  	gStyle->SetOptStat(1111);
  	gStyle->SetLineWidth(1);
  	gStyle->SetTextSize(0.9);
  	gStyle->SetPalette(55);
  	gStyle->SetLabelSize(0.03,"xyz"); // size of axis value font 
  	gStyle->SetTitleSize(0.035,"xyz"); // size of axis title font 
  	gStyle->SetTitleFont(22,"xyz"); // font option 
  	gStyle->SetLabelFont(22,"xyz");
  	gStyle->SetTitleOffset(1.2,"y");
  	gStyle->SetCanvasBorderMode(0);
  	gStyle->SetCanvasBorderSize(0);
  	gStyle->SetPadBottomMargin(0.17); //margins... 
  	gStyle->SetPadTopMargin(0.17);
  	gStyle->SetPadLeftMargin(0.17);
  	gStyle->SetPadRightMargin(0.17);
  	gStyle->SetFrameBorderMode(0);
  	gStyle->SetPaperSize(20,24);
  	gStyle->SetLabelSize(0.05,"xy");
  	gStyle->SetTitleSize(0.06,"xy");
   	int counter = 0;
	
	fn_sig_up->SetParameter(0,0.0006);
        fn_sig_up->SetParameter(1,-0.0058);
        fn_sig_up->SetParameter(2,0.3014);
        
        fn_sig_dn->SetParameter(0,-0.0018);
        fn_sig_dn->SetParameter(1,0.0176);
        fn_sig_dn->SetParameter(2,0.1417);
        

TH1F *h_xB = new TH1F ("","x-Bjorken distribution",150,0.,1.);
      	TCanvas *cxB = new TCanvas("cxB","cxB",500,500);
   	h_xB->SetXTitle("X-Bjorken");

TH1F *h_nu = new TH1F ("","nu-distribution",150,0.,10.4);
        TCanvas *cnu = new TCanvas("cnu","cnu",500,500);
        h_nu->SetXTitle("nu-distrinution");

TH1F *h_yy = new TH1F ("","y-distribution",150,0.,1.);
        TCanvas *cyy = new TCanvas("cyy","cyy",500,500);
        h_yy->SetXTitle("y-distribution");



TH1F *h_evz = new TH1F ("","evz",150,-50,50);
        TCanvas *cevz = new TCanvas("cevz","cevz",500,500);
        h_evz->SetXTitle("Z-vertex didtributions of electrons");


TH1F *h_eprime= new TH1F("","eprime",150,0.,10.4);
   	TCanvas *ceprime = new TCanvas("ceprime","ceprime",500,500);
   	h_eprime->SetXTitle("eprime");

TH1F *h_Q2= new TH1F("","Q2",150,0.,14);
   	TCanvas *cQ2 = new TCanvas("cQ2","cQ2",500,500);
   	h_Q2->SetXTitle("Q2(GeV^2)");


TH1F *h_etheta= new TH1F("","etheta",150,0,45);
   	TCanvas *cetheta = new TCanvas("cetheta","cetheta",500,500);
   	h_etheta->SetXTitle("etheta");

//
TH1F *h_etheta_predicted_measured= new TH1F("","etheta_predicted_measured",150,-40,40);
 	TCanvas *cetheta_predicted_measured = new TCanvas("cetheta_predicted_measured","cetheta_predicted_measured",500,500);
        h_etheta_predicted_measured->SetXTitle("etheta_predicted_measured");

//

TH1F *h_ephi= new TH1F("","ephi",150,-180,180);
        TCanvas *cephi = new TCanvas("cephi","cephi",500,500);
        h_ephi->SetXTitle("ephi");

TH1F *h_W = new TH1F("","W",150,0,5);
	TCanvas *cW = new TCanvas("cW","cW",600,600);
	h_W-> SetXTitle("W distributions");

TH2F *h_Q2_vs_xB = new TH2F("","Q^2 vs xB",150,0.,1.,150,0.,15);
	TCanvas *cQ2_vs_xB = new TCanvas("cQ2_vs_xB","cQ2_vs_xB",600,600);
	h_Q2_vs_xB ->SetXTitle("x-Bjorken");
	h_Q2_vs_xB ->SetYTitle("Q^2(GeV^2)");
	h_Q2_vs_xB->SetTitle(" Q^2 vs xB ");

TH2F *h_W_vs_xB = new TH2F("","W vs xB",150,0.,1.,150,0.8,5);
        TCanvas *cW_vs_xB = new TCanvas("cW_vs_xB","cQ2_vs_xB",600,600);
        h_W_vs_xB ->SetXTitle("x-Bjorken");
        h_W_vs_xB ->SetYTitle("W");
        h_W_vs_xB->SetTitle(" W vs xB ");

TH2F *h_Q2_vs_W = new TH2F("","Q^2 vs W",150,0.,5,150,0.,15);
        TCanvas *cQ2_vs_W = new TCanvas("cQ2_vs_W","cQ2_vs_W",600,600);
        h_Q2_vs_W ->SetXTitle("W");
        h_Q2_vs_W ->SetYTitle("Q^2(GeV^2)");
        h_Q2_vs_W->SetTitle(" Q^2 vs W ");

TH2F *h2_sampFrac = new TH2F("","h2_sampFrac",150,0,10.4,150,0.1,0.3);
	TCanvas *csampFrac = new TCanvas("csampFrac","csampFrac",600,600);
	h2_sampFrac->SetTitle("Sampling Fraction vs p");
	h2_sampFrac->SetXTitle("Momentum  [GeV]");
	h2_sampFrac->SetYTitle("Etot/p");

TH2F *h2_eprime_vs_theta = new TH2F("","h2_eprime_vs_theta",150,0,10.4,150,0.0,40);
        TCanvas *ceprimevstheta = new TCanvas("ceprimevstheta","ceprimevstheta",600,600);
        h2_eprime_vs_theta->SetTitle("Eprime vs theta");
        h2_eprime_vs_theta->SetXTitle("Eprime");
        h2_eprime_vs_theta->SetYTitle("Theta");


TH2F *h_e_theta_vs_phi = new TH2F("","e_theta_vs_phi",150,-180,180,150,0.,40.);
	TCanvas *cethetavsphi = new TCanvas("cethetavsphi","cethetavsphi",600,600);
	h_e_theta_vs_phi->SetXTitle("e_phi");
	h_e_theta_vs_phi->SetYTitle("e_theta");
	h_e_theta_vs_phi->SetTitle("e_theta_vs_phi");

TH2F *h_e_theta_vs_mom = new TH2F("","e_theta_vs_mom",150,0.,10.4,150,0.,40.);
	TCanvas *cethetavsmom = new TCanvas("cethetavsmom","cethetavsmom",600,600);
	h_e_theta_vs_mom->SetXTitle("mom(GeV/c)");
	h_e_theta_vs_mom->SetYTitle("e_theta");
	h_e_theta_vs_mom->SetTitle("e_theta_vs_mom");

TH2F *h_e_phi_vs_mom = new TH2F("","e_phi_vs_mom",150,0.,10.4,150,-180,180);
	TCanvas *cephivsmom = new TCanvas("cephivsmom","cephivsmom",600,600);
	h_e_phi_vs_mom->SetXTitle("mom(GeV/c)");
	h_e_phi_vs_mom->SetYTitle("e_mom");
	h_e_phi_vs_mom->SetTitle("e_phi_vs_mom");

TH2F *h_e_vz_vs_mom = new TH2F("","e_vz_vs_mom",150,0.,10.4,150,-50,50.);
	TCanvas *cevzvsmom = new TCanvas("cevzvsmom","cevzvsmom",600,600);
	h_e_vz_vs_mom->SetXTitle("mom(GeV/c)");
	h_e_vz_vs_mom->SetYTitle("e_vz");
	h_e_vz_vs_mom->SetTitle("e_vz_vs_mom");

TH2F *h_e_vz_vs_theta = new TH2F("","e_vz_vs_theta",150,0.,40,150,-50,50.);
        TCanvas *cevzvstheta = new TCanvas("cevzvstheta","cevzvsmom",600,600);
        h_e_vz_vs_theta->SetXTitle("theta(in degrees)");
        h_e_vz_vs_theta->SetYTitle("e_vz");
        h_e_vz_vs_theta->SetTitle("e_vz_vs_theta");

TH2F *h_e_vz_vs_phi = new TH2F("","e_vz_vs_phi",150,-180,180,150,-50,50.);
        TCanvas *cevzvsphi = new TCanvas("cevzvsphi","cevzvsphi",600,600);
        h_e_vz_vs_phi->SetXTitle("phi(in degrees)");
        h_e_vz_vs_phi->SetYTitle("e_vz");
        h_e_vz_vs_phi->SetTitle("e_vz_vs_phi");

TH2F *h_cal_y_vs_x_precut = new TH2F("","cal_y_vs_x_precut",150,-400.,400.,150,-400.,400);
	TCanvas *ccal_y_vs_x_precut = new TCanvas("ccal_y_vs_x_precut","ccal_y_vs_x_precut",600,600);
	h_cal_y_vs_x_precut ->SetXTitle("X-position");
	h_cal_y_vs_x_precut ->SetYTitle("Y-position");
	h_cal_y_vs_x_precut ->SetTitle("Cal-x-vs-y position");

TH2F *h_cal_y_vs_x = new TH2F("","cal_y_vs_x",150,-400.,400.,150,-400.,400);
        TCanvas *ccal_y_vs_x = new TCanvas("ccal_y_vs_x","ccal_y_vs_x",600,600);
        h_cal_y_vs_x ->SetXTitle("X-position");
        h_cal_y_vs_x ->SetYTitle("Y-position");
        h_cal_y_vs_x ->SetTitle("Cal-x-vs-y-position");




/*
TH1F *h_calluprecut = new TH1F("","cal_lu_precut",100,0,450);
	TCanvas *clu_precut = new TCanvas("","lu_precut",600,600);
	h_calluprecut->SetXTitle("lu");
	h_calluprecut->SetTitle("cal-lu-precut");

TH1F *h_callvprecut = new TH1F("","cal_lv_precut",100,0,450);
        TCanvas *clv_precut = new TCanvas("","lv_precut",600,600);
	h_callvprecut->SetXTitle("lv");
        h_callvprecut->SetTitle("cal-lv-precut");

TH1F *h_callwprecut = new TH1F("","cal_lw_precut",100,0,450);
        TCanvas *clw_precut = new TCanvas("","lw_precut",600,600);
	h_callwprecut->SetXTitle("lw");
        h_callwprecut->SetTitle("cal-lw-precut");
	

TH1F *h_cal_lu = new TH1F("","cal_lu",100,0,450);
        TCanvas *clu = new TCanvas("","lu",600,600);
        h_cal_lu->SetXTitle("lu");
        h_cal_lu->SetTitle("cal-lu");

TH1F *h_cal_lv = new TH1F("","cal_lv",100,0,450);
        TCanvas *clv = new TCanvas("","lv",600,600);
        h_cal_lv->SetXTitle("lv");
        h_cal_lv->SetTitle("cal-lv");

TH1F *h_cal_lw = new TH1F("","cal_lw",100,0,450);
        TCanvas *clw = new TCanvas("","lw",600,600);
        h_cal_lw->SetXTitle("lw");
        h_cal_lw->SetTitle("cal-lw");

*/	char inputFile[256];
//int main(int argc, char** argv) {

	for(long int i=1;i<argc;i++)
	{
     		 sprintf(inputFile,"%s",argv[i]);

	
   hipo::reader  reader;
   reader.open(inputFile);
   hipo::dictionary  factory;
   reader.readDictionary(factory);

 //  factory.show();

   
    hipo::bank  rtpc_bank(factory.getSchema("RTPC::tracks"));
    hipo::bank  rtpc_hits(factory.getSchema("RTPC::hits"));
    hipo::bank  calos(factory.getSchema("REC::Calorimeter"));
    hipo::bank  chers(factory.getSchema("REC::Cherenkov"));
    hipo::bank  parts(factory.getSchema("REC::Particle"));

   hipo::event      event;
    
   int counter = 0;
 
   while(reader.next()==true){
      reader.read(event);
       event.getStructure(rtpc_bank);
       event.getStructure(rtpc_hits);
       event.getStructure(calos);
       event.getStructure(chers);
       event.getStructure(parts);

     //rtpc_bank.show();
     //rtpc_hits.show();
     //calos.show();
     //chers.show();
     //parts.show();
TLorentzVector beam4Vector; beam4Vector.SetPxPyPzE(0.,0.,E_b,E_b);
TLorentzVector target4Vector; target4Vector.SetPxPyPzE(0.,0.,0.,M_p);
TLorentzVector out_Electron4Vector;// out_Electron4vector.SetPxPyPzE(0.,0.,0.,0.);
TLorentzVector q4Vector;
TLorentzVector proton4Vector;

      int max_calos = calos.getRows();
       int max_chers = chers.getRows();
	int nrows = rtpc_bank.getRows();
	int max_parts = parts.getRows();

     // printf("---------- PARTICLE BANK CONTENT -------\n");
     for( int ipart=0;ipart< max_parts;ipart++)
	{
	//require negative charge
	if (parts.getInt("pid",ipart) ==11)
	{
	//get E Caloriemeter data
	        double energy=0;
                double ecin=0;
                double epcal=0;
                double ecout=0;
                double ectotal=0;
                double nphe=0;
                float x_cal = 0;
                float y_cal = 0;
                                    
                float lu = 0;
                float lv = 0;
                float lw = 0;
	//get number of photoelectrons from cherenkov
           for (int cher = 0; cher < max_chers; cher++)
                  {
                     if (calos.getShort("pindex",cher) == ipart)
                     {
                         if (chers.getByte("detector",cher) == 15)
                         {
                             nphe = chers.getFloat("nphe",cher);
                             break;
                         }
                      }
                  } 
	
	//get some caloriemetric data
	for(int icalo = 0; icalo < max_calos; icalo++)
      {
           // get particle number
           if (calos.getShort("pindex",icalo) == ipart)
                 {
                   if (calos.getByte("detector",icalo) == 7) 
                   {
                     if (calos.getByte("layer",icalo) == 1)
			{
                          epcal += calos.getFloat("energy",icalo);
			}
		     if (calos.getByte("layer",icalo) == 4)
			{
                           ecin += calos.getFloat("energy",icalo);
			}
		     if (calos.getByte("layer",icalo) == 7)
 			{
                            ecout += calos.getFloat("energy",icalo);
                         }
		      x_cal = calos.getFloat("x",icalo);
                      y_cal = calos.getFloat("y",icalo);
                                    
                      lu = calos.getFloat("lu",icalo);
                      lv = calos.getFloat("lv",icalo);
                      lw = calos.getFloat("lw",icalo);


		   }
		}
		}
	//end of icalo = 0 to max_calos loop
	energy = epcal + ecin + ecout;// used for calorimetric cut
	h_cal_y_vs_x_precut->Fill(x_cal,y_cal);
/*	h_calluprecut->Fill(lu);
	h_callvprecut->Fill(lv);
	h_callwprecut->Fill(lw);
*/


       //caloriemetric cut begin from here//
       if(energy > 0.065)
	{
	             	float px   = parts.getFloat("px",ipart);
                     	float py   = parts.getFloat("py",ipart);
                     	float pz   = parts.getFloat("pz",ipart);
		    	float evz = parts.getFloat("vz",ipart);
                     	float p = sqrt(px*px+py*py+pz*pz);

       	//* Remember to put other things here*//
	out_Electron4Vector.SetPxPyPzE(px,py,pz,p);
	 ectotal= ecin +ecout;
	double	 e_prime = p;
       	double 	 etheta = out_Electron4Vector.Theta();
      	float	 thetae = etheta*180/PI;
	float 	 etheta_predicted = acos((1-((E_b-e_prime)*(M_p/(E_b*e_prime)))));
	double   thetae_predicted = etheta_predicted*180/PI;
	double	 ephi= out_Electron4Vector.Phi();
	float	 phie = ephi*180/PI;
        float	 Q2 = 4*e_prime*E_b*pow(sin(etheta/2),2);
	double	 nu = E_b -e_prime;
	double	 yy = nu/E_b;
	double	 W = sqrt(M_n*M_n +2*M_n*nu - Q2);
	double	 xB = Q2/(2*M_n*nu);
	double	 sf= energy/p;
// new added
	proton4Vector = out_Electron4Vector - beam4Vector+ target4Vector;
	float protonmom = proton4Vector.P(); 
        if(thetae>5&& thetae <40 && lv<370&& lw<390&& lu < 350 && lu >60  &&sf > fn_sig_dn->Eval(p) && 
                    sf <  fn_sig_up->Eval(p) &&e_prime>0.1*E_b && ectotal>0 && evz>-20 && evz< 15)
	 { 

		h_nu->Fill(nu);
		h_yy->Fill(yy);
		h_evz->Fill(evz);
		h_ephi->Fill(phie);
		h_eprime->Fill(p);
		h2_eprime_vs_theta->Fill(p,thetae);
	//	h_cal_lu->Fill(lu);
        //	h_cal_lv->Fill(lv);
       	//	h_cal_lw->Fill(lw);
		h2_sampFrac->Fill(p,sf);
       		h_Q2->Fill(Q2);
		h_Q2_vs_xB->Fill(xB,Q2);
		h_Q2_vs_W->Fill(W,Q2);

		h_etheta->Fill(thetae);
		h_etheta_predicted_measured->Fill(thetae_predicted-thetae);
		h_e_theta_vs_phi->Fill(phie,thetae);
		h_e_theta_vs_mom->Fill(p,thetae);

		h_ephi->Fill(phie);
		h_e_phi_vs_mom->Fill(p,phie);

		h_xB->Fill(xB);
        	h_W->Fill(W);
		h_W_vs_xB->Fill(xB,W);
		
		h_e_vz_vs_mom->Fill(p,evz);
		h_e_vz_vs_theta->Fill(thetae,evz);
		h_e_vz_vs_phi->Fill(phie,evz);
		h_cal_y_vs_x->Fill(x_cal,y_cal);		 
		
	
	 }
        
       }
}
}
}
counter++;
}


cxB ->cd();
h_xB->Draw();
cxB->Draw("h_xB");
cxB->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cxB.png");

cnu ->cd();
h_nu->Draw();
cnu->Draw("h_nu");
cnu->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cnu.png");

cyy ->cd();
h_yy->Draw();
cyy->Draw("h_yy");
cyy->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cyy.png");

ceprime->cd();
h_eprime->Draw();
ceprime->Draw("h_eprime");
ceprime->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/ceprime.png");
 

cQ2->cd();
h_Q2->Draw();
cQ2->Draw("h_Q2");
cQ2->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cQ2.png");


cetheta->cd();
h_etheta->Draw();
cetheta->Draw("h_etheta");
cetheta->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cetheta.png");

cetheta_predicted_measured->cd();
h_etheta_predicted_measured->Draw();
cetheta_predicted_measured->Draw("h_etheta_predicted_measured");
cetheta_predicted_measured->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cetheta_predicted_measured.png");


cephi->cd();
h_ephi->Draw();
cephi->Draw("h_ephi");
cephi->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cephi.png");
cevz->cd();
h_evz->Draw();
cevz->Draw("h_evz");
cevz->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cevz.png");


ceprimevstheta->cd();
h2_eprime_vs_theta->Draw("COLZ");
ceprimevstheta->Draw("h2_eprime_vs_theta");
ceprimevstheta->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/ceprimevstheta.png");


cW->cd();
h_W->Draw();
cW->Draw("h_W");
cW->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cW.png");


cQ2_vs_xB->cd();
h_Q2_vs_xB->Draw("COLZ");
cQ2_vs_xB->Draw("h_Q2_vs_xB");
cQ2_vs_xB->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cQ2_vs_xB.png");

cW_vs_xB->cd();
h_W_vs_xB->Draw("COLZ");
cW_vs_xB->Draw("h_W_vs_xB");
cW_vs_xB->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cW_vs_xB.png");


cQ2_vs_W->cd();
h_Q2_vs_W->Draw("COLZ");
cQ2_vs_W->Draw("h_Q2_vs_W");
cQ2_vs_W->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cQ2_vs_W.png");



csampFrac->cd();
h2_sampFrac->Draw("COLZ");
csampFrac->Draw("h2_sampFrac");
csampFrac->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/csampFrac.png");


cethetavsphi->cd();
h_e_theta_vs_phi->Draw("COLZ");
cethetavsphi->Draw("h_e_theta_vs_phi");
cethetavsphi->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cethetavsphi.png");

cethetavsmom->cd();
h_e_theta_vs_mom->Draw("COLZ");
cethetavsmom->Draw("h_e_theta_vs_mom");
cethetavsmom->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cethetavsmom.png");


cephivsmom->cd();
h_e_phi_vs_mom->Draw("COLZ");
cephivsmom->Draw("h_e_phi_vs_mom");
cephivsmom->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cephivsmom.png");


cevzvsmom->cd();
h_e_vz_vs_mom->Draw("COLZ");
cevzvsmom->Draw("h_e_vz_vs_mom");
cevzvsmom->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cevzvsmom.png");


cevzvstheta->cd();
h_e_vz_vs_theta->Draw("COLZ");
cevzvstheta->Draw("h_e_vz_vs_theta");
cevzvstheta->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cevzvstheta.png");

cevzvsphi->cd();
h_e_vz_vs_phi->Draw("COLZ");
cevzvsphi->Draw("h_e_vz_vs_phi");
cevzvsphi->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/cevzvsphi.png");



ccal_y_vs_x_precut->cd();
h_cal_y_vs_x_precut->Draw("COLZ");
ccal_y_vs_x_precut->Draw("h_cal_y_vs_x_precut");
ccal_y_vs_x_precut->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/ccal_y_vs_x_precut.png");

ccal_y_vs_x->cd();
h_cal_y_vs_x->Draw("COLZ");
ccal_y_vs_x->Draw("h_cal_y_vs_x");
ccal_y_vs_x->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11867/ccal_y_vs_x.png");




/*
clu_precut->cd();
h_calluprecut->Draw();
clu_precut->Draw("h_calluprecut");
clu_precut->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11637/clu_precut.png");


clv_precut->cd();
h_callvprecut->Draw();
clv_precut->Draw("h_callvprecut");
clv_precut->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11637/clv_precut.png");


clw_precut->cd();
h_callwprecut->Draw();
clw_precut->Draw("h_callwprecut");
clw_precut->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11637/clw_precut.png");



clu->cd();
h_cal_lu->Draw();
clu->Draw("h_cal_lu");
clu->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11637/clu.png");


clv->cd();
h_cal_lv->Draw();
clv->Draw("h_cal_lv");
clv->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11637/clv.png");


clw->cd();
h_cal_lw->Draw();
clw->Draw("h_cal_lw");
clw->SaveAs("/w/hallb-scifs17exp/clas12/mpokhrel/hipo/examples/11637/clw.png");



*/


}
//### END OF GENERATED CODE
