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
#include <TH3F.h>
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
#include <TString.h>

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
