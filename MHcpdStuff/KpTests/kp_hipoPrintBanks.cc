#include "myHeaders.h"
#include "/u/home/adhikari/LinkedFiles/someFns4_Q2_W_etc.h"


/*
 searched for 'getSchema(' in /w/hallb-scifs17exp/clas12/mhattawy/hipo/hipo4
which is also /work/clas12/mhattawy/hipo/hipo4 as found in the Makefile
Also found the getRows() method to return bankRows, which I used to select
events that have rtpc::hits bank not-empty.

 */


using namespace std; //kp: 11/19/20

const double PI=  3.14159, M_e=0.000511, M_p= 0.93827, M_n= 0.93957;  
const double Eb= 10.3853;  // from https://logbooks.jlab.org/entry/3810178
const double M_d= 1.8756, TODEG = 180.0/PI, TORAD = PI/180.0;


int dc_cut(float X, float Y, int S);


void defineHistos()
{
  
}
 
//void SavePlots(int mcOrRc, int whData, int plotVersion, char opTag[]);

int main(int argc, char** argv)
{
  cout<<"argc = "<<argc <<endl;
  char inputFile[256];
        
  gROOT->Reset();
  SetStyles();
  defineHistos();
  
  int mcOrRc=0,  plotVersion=0;
  char opTag[20] = "";
  if(argc < 4)
    {
      cout<<"Usage: \n";
      cout<<"\t ./exe <filename> <whData> <whEvent/howMany>" <<endl;
      cout<<"\t\t filename: hipo file to be read."<<endl;
      cout<<"\t\t whData: 0 for GEMC output and 1 for Reconstruction output.\n";
      cout<<"\t\t\t  for whData:0, we print a single event bank, so enter whEvent rather than howMany.\n";
      cout<<"\t\t howMany: how many rtpcHits banks to print.\n";
      cout<<"\t\t          n > -1 : # of rtpcHits banks to print.\n";
      cout<<"\t\t          n = -1 : # of rtpcHits banks to print.\n";
     
      exit(1);
    }

  int whData = atoi(argv[2]);
  int howMany = atoi(argv[3]), whEvent = atoi(argv[3]);
  int nRows =2, nEvsWdRtpcHits = 0;
 
  //for(long int i=1;i<argc;i++)  { 
  
  cout << " Reading run : " << argv[1] <<endl; // argv[i] << endl;
  sprintf(inputFile,"%s",argv[1]); //argv[i]);
    
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

    //bool brr = event.getStructure(runrf);
    //cout << typeof(event.getStructure(runrf)) <<endl;//Error
    //cout << typeid(event.getStructure(runrf)).name() <<endl; //Error
    //cout <<" brr = "<<brr<<endl;

    //cout<<"rtpchits.getEntries(): "<<rtpchits.getEntries()<<endl;

    if (whData == 0) { //Monte Carlo or GEMC data before cooking
      //if (kp == 100) {
      if (kp == whEvent) {
	cout<<"The rtpc::adc bank of the "<<whEvent<<"th event: "<<endl;
	rtpcadc.show();
	break; //exit(1);
      }
    }
    else if (whData == 1) {  //Cooked or Reconstructed GEMC data
      //https://eicweb.phy.anl.gov/clas12/software/hipo/-/blob/master/hipo4/bank.h
      nRows = rtpchits.getRows();
      if(nRows > 0) nEvsWdRtpcHits++;
      if(nRows > 0 || kp == 3 || kp == 3000) //kp < 20)
	{
	  cout<<"ev#: "<<kp<<", rtpchits.getRows() = "<<rtpchits.getRows()<<endl;
	    

	  //if(kp == 3 || kp == 3000) {  //Printing only for this particular event for debugging purpose ...
	  /*
	    calos.show();
	    chers.show();
	  */
	  parts.show();
	  //rec_trk.show();

	  ////rtpcadc.show();
	  
	  rtpctracks.show();
	  rtpchits.show();
	  //rtpcpos.show();

	  if(howMany > -1 && nEvsWdRtpcHits == howMany) break;
	  
	  
	  /*
	    dcdoca.show();
	    dctdc.show();
	    ecaladc.show();
	    ecaltdc.show();
	    fmtadc.show();
	    ftofadc.show();
	    ftoftdc.show();
	    htccadc.show();
	  
	    mcevent.show();
	    mclund.show();
	  */

	  ///mctrue.show();

	  /*
	    mcparticle.show();
	  
	    runconfig.show();
	    runrf.show();
	  */
	}
    }
    kp++;
	
  }// end of while reader.next=true loop
  //} // end of long int i =1 to argc loop

  cout<<"# of Evs with non-empty rtpc:hits bank = "<<nEvsWdRtpcHits<<endl;
}
//### END OF GENERATED CODE

//https://home.fnal.gov/~mrenna/lutp0613man2/node44.html
//Various particle IDs: 11 electron, 22 - gamma/photon, 2112 = neutron, 2212 = proton etc.
void SavePlots(int mcOrRc, int whData, int plotVersion, char opTag[]) {

}
