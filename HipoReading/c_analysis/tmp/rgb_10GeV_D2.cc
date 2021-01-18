
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "reader.h"
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

using namespace std; //kp: 11/19/20

const double PI=  3.14159;
const double M_e=0.000511;   
const double Eb= 10.3853;  // from https://logbooks.jlab.org/entry/3810178
const double M_p= 0.93827;
const double M_n= 0.93957;
const double M_d= 1.8756;
const double TODEG = 180.0/PI;
const double TORAD = PI/180.0;

int dc_cut(float X, float Y, int S);

int main(int argc, char** argv)

{
  char inputFile[256];
        
  gROOT->Reset();
  gStyle->SetOptStat(kFALSE);
  gStyle->SetOptFit(10010);
  gStyle->SetStatFontSize(0.065);
  gStyle->SetStatW(0.25);


  gStyle->SetLabelSize(0.04,"xyz"); // size of axis value font 
  gStyle->SetTitleSize(0.06,"xyz"); // size of axis title font 
  gStyle->SetTitleFont(22,"xyz"); // font option 
  gStyle->SetLabelFont(22,"xyz"); 
  gStyle->SetTitleOffset(1.2,"y");
  gStyle->SetCanvasBorderMode(0); 
  gStyle->SetCanvasBorderSize(0); 
  gStyle->SetPadBottomMargin(0.15); //margins... 
  gStyle->SetPadTopMargin(0.1); 
  gStyle->SetPadLeftMargin(0.15); 
  gStyle->SetPadRightMargin(0.17); 
  gStyle->SetFrameBorderMode(0); 
  gStyle->SetPaperSize(20,24); 
  gStyle->SetLineWidth(2.0);

  TLine *l = new TLine();
  l->SetLineStyle(7);
  l->SetLineWidth(4);
  l->SetLineColor(2);  

  int nb = 150;
  float vz_min= -15;    float vz_max= 5;
  float theta_min = 0;  float theta_max = 30;
  float phi_min = -200; float phi_max = 200;
  float mom_min = 0.0;    float mom_max = 11.0;

  //F1D fn_sig_up = new F1D("fn_sig_up","[p0]*(x*x) + [p1]*x + [p2]", xmin, xmax);


  // The reconstructed el 1D histos
  TH1F *h1_el_chi2pid    = new TH1F("h1_el_chi2pid","",    nb, 0,    7);
  TH1F *h1_el_status     = new TH1F("h1_el_status","",    nb, 2000,    2400);
        h1_el_chi2pid ->SetXTitle("#Chi^{2} of PID=11"); 
        h1_el_status  ->SetXTitle("Electron status"); 
  
  TH1F *h1_el_vz    = new TH1F("h1_el_vz","",    nb, vz_min,    vz_max);
  TH1F *h1_el_theta = new TH1F("h1_el_theta","", nb, theta_min, theta_max);
  TH1F *h1_el_phi   = new TH1F("h1_el_phi","",   nb, phi_min,   phi_max);
  TH1F *h1_el_mom   = new TH1F("h1_el_mom","",   nb, mom_min,   mom_max);
        h1_el_vz   ->SetXTitle("vz_{e-} [cm]");   
        h1_el_theta->SetXTitle("#theta_{e-} [deg]");   
        h1_el_phi  ->SetXTitle("#phi_{e-} [deg]");
        h1_el_mom  ->SetXTitle("p_{e-} [GeV/c]");
        h1_el_vz   ->SetMinimum(0.0);
        h1_el_theta->SetMinimum(0.0);
        h1_el_phi  ->SetMinimum(0.0);
        h1_el_mom  ->SetMinimum(0.0);


  TH1F *h1_el_mom_0   = new TH1F("h1_el_mom_0","",  nb, mom_min,   mom_max);
        h1_el_mom_0  ->SetXTitle("p_{e-} [GeV/c]");
        h1_el_mom_0  ->SetLineColor(kBlack);
  TH1F *h1_el_mom_1   = new TH1F("h1_el_mom_1","",  nb, mom_min,   mom_max);
        h1_el_mom_1  ->SetLineColor(kBlue);
  TH1F *h1_el_mom_2   = new TH1F("h1_el_mom_2","",  nb, mom_min,   mom_max);
        h1_el_mom_2  ->SetLineColor(kRed);
  TH1F *h1_el_mom_3   = new TH1F("h1_el_mom_3","",  nb, mom_min,   mom_max);
        h1_el_mom_3  ->SetLineColor(28);
 



  TH1F *h1_el_lu   = new TH1F("h1_el_lu","",  nb, 0, 450);
  TH1F *h1_el_lv   = new TH1F("h1_el_lv","",  nb, 0, 450);
  TH1F *h1_el_lw   = new TH1F("h1_el_lw","",  nb, 0, 450);
        h1_el_lu   ->SetXTitle("U_{e-} [cm]");   
        h1_el_lv   ->SetXTitle("V_{e-} [cm]");   
        h1_el_lw   ->SetXTitle("W_{e-} [cm]");
        h1_el_lu   ->SetMinimum(0.0);
        h1_el_lv   ->SetMinimum(0.0);
        h1_el_lw   ->SetMinimum(0.0);

  TH1D *h_el_ecin = new TH1D("h_el_ecin","", nb, 0, 1.0);
  TH1D *h_el_ecout = new TH1D("h_el_ecout","", nb, 0, 1.0);
  TH1D *h_el_epcal = new TH1D("h_el_epcal","", nb, 0, 1.5);
        h_el_ecin->SetXTitle("EC_{in} [GeV]"); 
        h_el_ecout->SetXTitle("EC_{out} [GeV]"); 
        h_el_epcal->SetXTitle("PCAL [GeV]");


  TH2F *h2_el_EC_YX_b = new TH2F("h2_el_EC_YX_b","", nb,-450,450, nb, -450, 450);      
        h2_el_EC_YX_b->SetTitle("Electron EC: Y vs. X :: Before UVW cuts");
        h2_el_EC_YX_b->SetYTitle("Y [cm]");
        h2_el_EC_YX_b->SetXTitle("X [cm]");
  TH2F *h2_el_EC_YX_a = new TH2F("h2_el_EC_YX_a","", nb,-450,450, nb, -450, 450);      
        h2_el_EC_YX_a->SetTitle("Electron EC: Y vs. X :: After UVW cuts");
        h2_el_EC_YX_a->SetYTitle("Y [cm]");
        h2_el_EC_YX_a->SetXTitle("X [cm]");

  //** photoelectrons histograms **//
  TH1D *h1_el_1_nphe = new TH1D("h1_el_1_nphe","Nphe", 70, 0, 70); 
        h1_el_1_nphe->SetLineColor(kBlack);
        h1_el_1_nphe->SetLineWidth(2);
        h1_el_1_nphe->SetXTitle("nphe");
  TH1D *h1_el_2_nphe = new TH1D("h1_el_2_nphe","Nphe", 70, 0, 70); 
        h1_el_2_nphe->SetLineWidth(2);
        h1_el_2_nphe->SetLineColor(kBlue);
  TH1D *h1_el_3_nphe = new TH1D("h1_el_3_nphe","Nphe", 70, 0, 70); 
        h1_el_3_nphe->SetLineWidth(2);
        h1_el_3_nphe->SetLineColor(kRed);

  TH2D *h_el_theta_phi = new TH2D("h_el_theta_phi","", nb, theta_min, theta_max, nb,phi_min, phi_max);
        h_el_theta_phi->SetXTitle("#theta_{e-} [deg]"); 
        h_el_theta_phi->SetYTitle("phi_{e-} [deg]");

  TH2D *h_el_theta_p = new TH2D("h_el_theta_p","", nb, mom_min, mom_max, nb, theta_min, theta_max);
        h_el_theta_p->SetXTitle("#theta_{e-} [deg]"); 
        h_el_theta_p->SetYTitle("p_{e-} [GeV/c]");

  TH2D *h_el_p_etot = new TH2D("h_e_p_etot","", nb, mom_min, mom_max, nb, 0.1, 0.45);
        h_el_p_etot->SetXTitle("p_{e-} [GeV/c]"); 
        h_el_p_etot->SetYTitle("e_{tot}/p ");


  TH1D *h_W_p = new TH1D("h_W_p","", nb, 0.5, 6);
        h_W_p->SetXTitle("W_{p} [GeV]");
        h_W_p->SetLineWidth(2);

  TH1D *h_Q2= new TH1D("h_Q2", "", nb, 0, 10);
        h_Q2->SetXTitle("Q^{2} [GeV^{2}]");
        h_Q2->SetLineWidth(2);
        
  TH1D *h_yy = new TH1D("h_yy","y Distribution",nb,0,1);
  TH1D *h_nu = new TH1D("h_nu","nu Distribution",nb, 0, 1.5);




for(long int i=1;i<argc;i++)
{
    
   std::cout << " Reading run : " << argv[i] << std::endl;
   sprintf(inputFile,"%s",argv[i]);
    
    hipo::reader  reader;
    reader.open(inputFile);
    hipo::dictionary  factory;
    reader.readDictionary(factory);
    //cout<<"kp: factory: "<<factory<<endl;
    cout<<"kp: Hi ..."<<endl;

    factory.show(); //Initially disabled, but enabled by kp
    cout<<"kp: Hi .."<<endl;
   
    hipo::bank  calos(factory.getSchema("REC::Calorimeter"));
    hipo::bank  chers(factory.getSchema("REC::Cherenkov"));
    hipo::bank  parts(factory.getSchema("REC::Particle"));
    hipo::bank  rec_trk(factory.getSchema("REC::Track"));

    hipo::event      event;
    //int kp = 0; 

    while(reader.next()==true) {

        reader.read(event);
        event.getStructure(parts);
        event.getStructure(chers);
        event.getStructure(calos);

	/*
        if( kp == 0)
	  rtpc_bank.show(); //enabled by kp
	kp++;
	*/

        int n_el = 0;
        TLorentzVector  Elec_4V;
        float Elec_vz    = 999.9;
        float Elec_p     = 999.9;
        float Elec_theta = 999.9;
        float Elec_phi   = 999.9;
        float Elec_energy= 999.9;
        int Elec_sec     = 0;
        int nphe         = 0;

        TLorentzVector  Prot_4V;
        float Prot_vz    = 999.9;
        float Prot_p     = 999.9;
        float Prot_theta = 999.9;
        float Prot_phi   = 999.9;

        TLorentzVector  InEl_4V;       InEl_4V.SetPxPyPzE(0., 0., Eb, Eb);
        TLorentzVector  TargetP_4V;    TargetP_4V.SetPxPyPzE(0., 0., 0., M_d);
        TLorentzVector  cal_Prot_4V;   cal_Prot_4V.SetPxPyPzE(0., 0., 0., 0.0);

        // loop over REC::Particle
        for(int ii=0; ii< parts.getRows(); ii++) {
           //require negative charge
           if (parts.getInt("pid",ii) ==11) {
            // loop over cherenkov 
            for(int jj = 0; jj < chers.getRows(); jj++){
               if(calos.getShort("pindex",jj) == ii) {
                 if (chers.getByte("detector",jj) == 15) {
                     nphe = chers.getFloat("nphe",jj);
                     break;
                     } 
               } 
            }  // end loop over the cherenkov 
 

            //get E Caloriemeter data
            float ec_in=0, ec_out=0, e_pcal=0, ec_total=0;
            float x_cal= 0, y_cal = 0;
            float lu= 0, lv= 0, lw= 0;
	
            //get some caloriemetric data
            for(int jj = 0; jj < calos.getRows(); jj++){
               // get particle number
               if (calos.getShort("pindex",jj) == ii){
                  if (calos.getByte("detector",jj) == 7){
                     if (calos.getByte("layer",jj) == 1){ e_pcal += calos.getFloat("energy",jj); }
                     if (calos.getByte("layer",jj) == 4){ ec_in += calos.getFloat("energy",jj); }
                     if (calos.getByte("layer",jj) == 7){ ec_out += calos.getFloat("energy",jj); }
                                    
                     x_cal = calos.getFloat("x",jj);
                     y_cal = calos.getFloat("y",jj);
                     lu = calos.getFloat("lu",jj);
                     lv = calos.getFloat("lv",jj);
                     lw = calos.getFloat("lw",jj);
                     Elec_sec = calos.getByte("sector",jj);
                  }
               }
            }//end of calorimeter bank
                            
            ec_total= ec_in +ec_out;
            Elec_energy = e_pcal + ec_in + ec_out;// used for calorimetric cut
            Elec_vz   = parts.getFloat("vz",ii);
            float Elec_px   = parts.getFloat("px",ii);
            float Elec_py   = parts.getFloat("py",ii);
            float Elec_pz   = parts.getFloat("pz",ii);
            float Elec_chi2pid   = parts.getFloat("chi2pid",ii);
            int   Elec_status    = parts.getShort("status",ii);
            if (Elec_status<0 ) Elec_status = -1 *Elec_status;
            Elec_p = sqrt(Elec_px*Elec_px + Elec_py*Elec_py + Elec_pz*Elec_pz) + 0.0065;  //6.5 MeV mom correction



            if( Elec_vz < 0.0 ){
               h1_el_vz      ->Fill(Elec_vz);
               h1_el_1_nphe  ->Fill(nphe);
               h1_el_lu      ->Fill(lu);                             
               h1_el_lv      ->Fill(lv);
               h1_el_lw      ->Fill(lw);
               h2_el_EC_YX_b ->Fill(x_cal, y_cal);
               h_el_epcal    ->Fill(e_pcal);
               h_el_ecin     ->Fill(ec_in);
               h_el_ecout    ->Fill(ec_out);
            }
 
            if( Elec_vz < 0.0 ) h1_el_mom_0 ->Fill(Elec_p);  
            if(50<lu && lu<410 && lv<410 && lw<370 && Elec_vz<0.0 ) h1_el_mom_1 ->Fill(Elec_p);  
            if(50<lu && lu<410 && lv<410 && lw<370 && e_pcal>0.1 &&  Elec_vz< 0.0 ) h1_el_mom_2 ->Fill(Elec_p);  
            if(50<lu && lu<410 && lv<410 && lw<370 && e_pcal>0.1 && ec_total> 0.06 && Elec_vz<0.0 ) h1_el_mom_3 ->Fill(Elec_p);  
            
            if(50<lu && lu<410 && lv<410 && lw<370 && e_pcal>0.1 && ec_total> 0.06 && Elec_vz < 0.0 ){ 
               n_el++; 
                       
               Elec_4V.SetPxPyPzE(Elec_px, Elec_py, Elec_pz, Elec_p);
               Elec_theta = (Elec_4V.Theta()) *TODEG;
               Elec_phi   = (Elec_4V.Phi()) *TODEG; 

               float Q2 = 4*Elec_p*Eb*pow(sin(Elec_theta*TORAD/2), 2);
               float nu = (Eb - Elec_p);
               float yy = nu/Eb;
               float W_p= sqrt(M_p*M_p + 2*M_p*nu - Q2);
               float xB = Q2/(2*M_p*nu);
               
               h1_el_mom     ->Fill(Elec_p);
               h_W_p   ->Fill(W_p);
               h_Q2    ->Fill(Q2);
               h_nu    ->Fill(nu);
               h_yy    ->Fill(yy);
                   
               h1_el_3_nphe  ->Fill(nphe);
               h_el_theta_phi->Fill(Elec_theta, Elec_phi);            
               h_el_theta_p  ->Fill(Elec_p, Elec_theta);            
               h_el_p_etot  ->Fill(Elec_p, Elec_energy/Elec_p);            

               h2_el_EC_YX_a ->Fill(x_cal, y_cal); 
               h1_el_2_nphe  ->Fill(nphe);
               h1_el_chi2pid ->Fill(Elec_chi2pid );
               h1_el_status  ->Fill(Elec_status );

            } //end of UVW cuts 
           }//end of PID ==11 ,ipart loop
        }//end of ipart =0 to ipart max loop


    }// end of while reader.next=true loop
} // end of long int i =1 to argc loop

TCanvas *c1 = new TCanvas("c1","",1400,900);
         c1->Divide(2,2);

TCanvas *c2 = new TCanvas("c2","",600,500);
         
TCanvas *c3 = new TCanvas("c3","",1000,500);
         c3->Divide(2,1);


TCanvas *c4 = new TCanvas("c4","",1200,500);
         c4->Divide(3,1);
 

         c4->cd(1); h1_el_vz   ->Draw(); 
                    l->DrawLine(-23,0,-23,h1_el_vz->GetMaximum());
                    l->DrawLine( 17,0, 17,h1_el_vz->GetMaximum());
         c4->cd(2); h1_el_mom ->Draw();
                    l->DrawLine(1.0,0,1.0,h1_el_mom->GetMaximum());
         c4->cd(3); h1_el_chi2pid ->Draw();
                    l->DrawLine(3.0,0,3.0,h1_el_chi2pid->GetMaximum());
         c4->SaveAs("figs/el_kinematics.pdf");
         c4->SaveAs("cfigs/el_kinematics.C");


         c3->cd(1); h_W_p->Draw("colz");  
         c3->cd(2); h_Q2->Draw("colz");  
                    //l->DrawLine(0.065,0.1,0.065,0.7); 
                    //l->DrawLine(0.065,0.1,0.7,0.1); 
         c3->Print("figs/W_Q2.pdf");
         c3->Print("cfigs/W_Q2.C");

         c2->cd(); h1_el_mom_0 ->Draw();
                   h1_el_mom_1 ->Draw("same");
                   h1_el_mom_2 ->Draw("same");
                   h1_el_mom_3 ->Draw("same");
         c2->Print("figs/el_mom_cuts.pdf");


         c3->cd(1);  h_el_theta_phi->Draw("colz");
         c3->cd(2);  h_el_theta_p  ->Draw("colz");
         c3->SaveAs("figs/el_phi_theta_p.pdf");
         c3->SaveAs("cfigs/el_phi_theta_p.C");


         c4->cd(1); h1_el_lu->Draw();
                    l->DrawLine(50,0,50,h1_el_lu->GetMaximum()); 
                    l->DrawLine(410,0,410,h1_el_lu->GetMaximum()); 
         c4->cd(2); h1_el_lv->Draw();
                    l->DrawLine(410,0,410,h1_el_lv->GetMaximum()); 
         c4->cd(3); h1_el_lw->Draw();
                    l->DrawLine(370,0,370,h1_el_lw->GetMaximum()); 
         c4->SaveAs("figs/el_rec_uvw.pdf");
         c4->SaveAs("cfigs/el_rec_uvw.C");

         c4->cd(1); h_el_epcal->Draw();
         c4->cd(2); h_el_ecin ->Draw();
         c4->cd(3); h_el_ecout->Draw();
         c4->SaveAs("figs/el_ecin_out_pcal.pdf");
         c4->SaveAs("cfigs/el_ecin_out_pcal.C");

         c3->cd(1);  h2_el_EC_YX_b->Draw("colz");
         c3->cd(2);  h2_el_EC_YX_a->Draw("colz");
         c3->SaveAs("figs/el_EC_EC_Y_X.pdf");
         c3->SaveAs("cfigs/el_EC_EC_Y_X.C");

         
TCanvas *c5 = new TCanvas("c5","",600,500);
         h1_el_1_nphe->Draw();
         h1_el_2_nphe->Draw("same");  
         h1_el_3_nphe->Draw("same");
         //l->DrawLine(5,0,5,h_e_1_nphe->GetMaximum());
         c5->Print("figs/el_nphe.pdf");
         c5->Print("cfigs/el_nphe.C");


         c5->cd();
         h_el_p_etot->Draw("colz");
         c5->Print("figs/el_p_etot.pdf");
         c5->Print("cfigs/el_p_etot.C");

         c5->cd(1); h_W_p   ->Draw();
                    h_W_p   ->SetMaximum(h_W_p->GetMaximum()*1.2); 
                    l->DrawLine(2.0,0,2.0,h_W_p->GetMaximum()); 
         c5->SaveAs("figs/el_Q2_xB_W.pdf");
         c5->SaveAs("cfigs/el_Q2_xB_W.C");



}
//### END OF GENERATED CODE
//
int dc_cut(float X, float Y, int S){  // X, Y are the positions on DC1, S stands for sector number
   int result= 0;     
   if( (S==3 || S==4 || S==5 || (Y>X*tan(PI*((S-1)/3.0-1.0/9)) && Y<X*tan(PI*((S-1)/3.0+1.0/9))))
       && (S==1 || S==2 || S==6 || (Y<X*tan(PI*((S-1)/3.0-1.0/9)) && Y>X*tan(PI*((S-1)/3.0+1.0/9)))) )
       result= 1;
   
   return result;
}
