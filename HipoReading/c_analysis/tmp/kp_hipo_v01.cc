
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

const double PI=  3.14159, M_e=0.000511, M_p= 0.93827, M_n= 0.93957;  
const double Eb= 10.3853;  // from https://logbooks.jlab.org/entry/3810178
const double M_d= 1.8756, TODEG = 180.0/PI, TORAD = PI/180.0;

void SetStyles()
{
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
}
int dc_cut(float X, float Y, int S);

TH1F *h1rtpcSector, *h1rtpcLayer, *h1rtpcComponent, *h1rtpcOrder,
  *h1rtpcAdc, *h1rtpcAdcT, *h1rtpcPed;
void defineHistos()
{
  h1rtpcSector = new TH1F("rtpcSector","rtpcSector",200, -10.0,10.0);
  h1rtpcLayer = new TH1F("rtpcLayer","rtpcLayer",200, 40.0,60.0);
  h1rtpcComponent = new TH1F("rtpcComponent","rtpcComponent",110, -20.0,200.0);
  h1rtpcOrder = new TH1F("rtpcOrder","rtpcOrder",200, -10.0,10.0);
  h1rtpcAdc = new TH1F("rtpcAdc","rtpcAdc",200, -10.0,10.0);
  h1rtpcAdcT = new TH1F("rtpcAdcT","rtpcAdcTime",200, -9000.0,13000.0);
  h1rtpcPed = new TH1F("rtpcPed","rtpcPed",200, -10.0,10.0);
}
 
void SavePlots();

int main(int argc, char** argv)
{
  char inputFile[256];
        
  gROOT->Reset();
  SetStyles();


  defineHistos();

 
  int nb = 150;
  float vz_min    = -15,  vz_max= 5;
  float theta_min = 0,    theta_max = 30;
  float phi_min   = -200, phi_max = 200;
  float mom_min   = 0.0,  mom_max = 11.0;

  //F1D fn_sig_up = new F1D("fn_sig_up","[p0]*(x*x) + [p1]*x + [p2]", xmin, xmax);
  //** photoelectrons histograms **//


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

      hipo::bank  rtpcadc(factory.getSchema("RTPC::adc"));
      hipo::bank  rtpchits(factory.getSchema("RTPC::hits")); //Empty in GEMC o/p
      hipo::bank  rtpcpos(factory.getSchema("RTPC::pos"));   //Empty  in GEMC o/p
      hipo::bank  rtpctracks(factory.getSchema("RTPC::tracks"));//Empty in GEMC o/p

      //First I looked at the banks using 'hipo-utils -dump out.hipo' and hitting 'n' for next evs
      hipo::bank  dcdoca(factory.getSchema("DC::doca"));
      hipo::bank  dctdc(factory.getSchema("DC::tdc"));
      hipo::bank  ecaladc(factory.getSchema("ECAL::adc"));
      hipo::bank  ecaltdc(factory.getSchema("ECAL::tdc"));
      hipo::bank  fmtadc(factory.getSchema("FMT::adc"));
      hipo::bank  ftofadc(factory.getSchema("FTOF::adc"));
      hipo::bank  ftoftdc(factory.getSchema("FTOF::tdc"));
      hipo::bank  htccadc(factory.getSchema("HTCC::adc"));
      hipo::bank  mcevent(factory.getSchema("MC::Event"));
      hipo::bank  mclund(factory.getSchema("MC::Lund"));
      hipo::bank  mctrue(factory.getSchema("MC::True"));
      hipo::bank  mcparticle(factory.getSchema("MC::Particle"));
      hipo::bank  runconfig(factory.getSchema("RUN::config"));
      hipo::bank  runrf(factory.getSchema("RUN::rf"));
    
 

      hipo::event      event;
      int kp = 0; 

      while(reader.next()==true) {
	//if(kp > 20) break;

        reader.read(event);
        event.getStructure(parts);
        event.getStructure(chers);
        event.getStructure(calos);

	event.getStructure(rtpcadc);
	event.getStructure(rtpchits);
	event.getStructure(rtpcpos);
	event.getStructure(rtpctracks);

	event.getStructure(dcdoca);
	event.getStructure(ecaladc);
	event.getStructure(ecaltdc);
	event.getStructure(fmtadc);
	event.getStructure(ftofadc);
	event.getStructure(ftoftdc);
	event.getStructure(htccadc);
	event.getStructure(mcevent);
	event.getStructure(mclund);
	event.getStructure(mctrue);
	event.getStructure(mcparticle);
	event.getStructure(runconfig);
	event.getStructure(runrf);

	if(kp == 3) {
	  /*
	    calos.show();
	    chers.show();
	    parts.show();
	    rec_trk.show();
	  */
	  rtpcadc.show();
	  
	    rtpctracks.show();
	    rtpchits.show();
	    rtpcpos.show();

	    
	  
	  
	  /*
	  dcdoca.show();
	  dctdc.show();
	  ecaladc.show();
	  ecaltdc.show();
	  fmtadc.show();
	  ftofadc.show();
	  ftoftdc.show();
	  htccadc.show();
	  */
	  mcevent.show();
	  mclund.show();
	  mctrue.show();
	  mcparticle.show();
	  /*
	  runconfig.show();
	  runrf.show();
	  */
	}
	kp++;
	//if(kp < 5) rtpcadc.show();
	/*
	  if( kp == 0)
	  rtpc_bank.show(); //enabled by kp
	  kp++;
	*/

        int n_el = 0;
 	int rtpcADC = 0;
	float rtpcTime = 999.9;

        for(int ii=0; ii< rtpcadc.getRows(); ii++) {
	  
	  rtpcADC = rtpcadc.getInt("ADC",ii);
	  rtpcTime = rtpcadc.getFloat("time",ii);

	  //cout<<"trkID: "<<vtrkID<<", nhits: "<<vnhits<<endl;
	  h1rtpcSector->Fill(1.0*rtpcadc.getByte("sector",ii));
	  h1rtpcLayer->Fill(1.0*rtpcadc.getByte("layer",ii));
	  h1rtpcComponent->Fill(1.0*rtpcadc.getShort("component",ii));
	  h1rtpcOrder->Fill(1.0*rtpcadc.getByte("order",ii));
	  h1rtpcPed->Fill(1.0*rtpcadc.getShort("ped",ii));
	  h1rtpcAdc->Fill(rtpcADC);
	  h1rtpcAdcT->Fill(rtpcTime);
	} 

      }// end of while reader.next=true loop
    } // end of long int i =1 to argc loop


  SavePlots();
}
//### END OF GENERATED CODE


void SavePlots() {
  TCanvas *c1 = new TCanvas("c1","c1",1600,800); c1->Divide(4,2,0.00001,0.00001);
  c1->cd(1); h1rtpcAdc->Draw();
  c1->cd(2); h1rtpcAdcT->Draw();
  c1->cd(3); h1rtpcSector->Draw();
  c1->cd(4); h1rtpcLayer->Draw();
  c1->cd(5); h1rtpcComponent->Draw();
  c1->cd(6); h1rtpcOrder->Draw();
  c1->cd(7); h1rtpcPed->Draw();
 
  cout<<"Couldn't write from ifarm1901 to hall-b secure disk. So use ifarm1801/02"<<endl;
  c1->SaveAs("FigsKp/rtpc_mc_adc_time.png");
  //c1->SaveAs("rtpc_mc_adc_time.png");
}
