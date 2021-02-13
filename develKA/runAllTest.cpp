#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream> //this and the following line required for cout, cin etc. (otherwise, it's basically C)
//#include "/u/home/adhikari/LinkedFiles/myOwnHeaderFiles.h"
//https://www.jlab.org/Hall-B//secure/eg4/adhikari/myHomeLinked/MyHm/RadCorr/RCSLACPOL_STEG/SingleProg2Stage/TestExe/createNsubJobs4rcslacpolStegPassVarsFrmMain.C

#define MAKE_MULT_PLOTS

#include <dirent.h> //Needed for the following function which is fully defined at the bottom

using namespace std;


int main(int argc, char **argv)
{
  int forWhat, testOrAna;
  int whExe=1;
  /*
  char *ext, *jobNmStr;
  if(argc<2) //If 1, no extra argument, just the executable name i.e., run as ./exe
    {
    cout<<endl<<"\t This program is used to submit basically three types of jobs (to the Jlab batch farm) "<<endl

      return -1;
    }
  forWhat=atoi(argv[1]);

  char cstr[200]; ext = argv[argc-1];
  sprintf(cstr,"\t Just for test.%s.%c.%c.%c ",ext,ext[0],ext[1],ext[2]);
  cout<<"\t argc="<<argc<<" "<<cstr<<ext<<endl<<endl;

  if(forWhat==0 && argc<11) //8/19/13 (adding jobNmStr)
    {
      system("tput bold"); system("tput setaf 4"); //Bold & Red //http://linuxtidbits.wordpress.com/2008/08/11/output-color-on-bash-scripts/ //Bold
      cout<<"Usage: exe <int forWhat> <int testOrAnalysis> <int HowManyJobs> <int: jobHours> <int WbinsFactor>  <int Q2binCase>"<<endl
      system("tput sgr0"); // Reset
      return -1;
    }

  int GppHow=0, EventNum=70000; //12/8/12, 1/16/13

  ext = argv[argc-3]; jobNmStr = argv[argc-2]; SubJobNowOrNot=atoi(argv[argc-1]);   //8/19/13 (adding jobNmStr)
  */



  /*
    https://stackoverflow.com/questions/26401051/run-2-or-more-cmd-command-using-system-in-c
    The cd command used in the system() call will change the directory only for the sub shell opened, not for
    your actual process. – πάντα ῥεῖ Oct 16 '14 at 9:41

    You need to put both steps in one system() command and how that is done will be platform depe
    ndant. – Galik Oct 16 '14 at 9:42

  */

  //system("pwd");  system("cd .."); //didn't change dir (read above comment by πάντα ῥεῖ), we have to use all commands together.
  //system("cd ..; pwd; ls");
  //system("cd /Users/kpadhikari/GitProj/KPAdhikari/TidBits/; pwd; ls"); //works
  


  //Code that modifies GCARDS file (with diff. op name, ev#, B-field sign etc)
  //     Sometimes this file may have to be modified manually too.


  system("pwd");  //system("ls");
  char fGcards[100] = "rgf_spring2020_lund_15kEvs_Bneg.gcard"; //Make it as a par (coming as arg or from a config file)
  char com1[50] = "source gemcKA.env";
  char com2[150]; sprintf(com2,"./gemc %s", fGcards);
  char com3[200]; sprintf(com3, "e2h %s", opGemc); //I am using my alias e2h to convert evio to hipo
  

  //Next run CLARA to do reconstruction.
  //First place the hipo converted GEMC output in the input file location
  //Modify the inputFileList.txt adding those files that need to be cooked/reconstructed.
  //Next modify the clara configuration file (with .template for example) if necessary.
  //Modify it as a parameter
  char claraConfigFile[75]; sprintf(claraConfigFile,"kpLocalClaraCfgKpDebug.template");
  char comRec[150] = sprintf(comRec,"$CLARA_HOME/bin/clara-shell   %s", claraConfigFile);
}
