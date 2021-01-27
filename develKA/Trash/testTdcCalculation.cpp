// Example program
#include <iostream>
#include <string>
#include <random>

using namespace std;

int main()
{
  //std::string name;
  int aNum = 0;
  std::cout << "Enter an integer? ";
  //getline (std::cin, aNum);
  cin>>aNum;
  std::cout << "5 times the number you entered is " << 5*aNum << "!\n";
  
  //kp: from http://www.cplusplus.com/reference/random/normal_distribution/
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(5.0,2.0); //mean=5.0, sigma = 2.0?
  //kp: Just printing four random numbers from the normal/gaussian distribution
  for (int i=0; i<4; i++) cout<<i<<"th #: "<<distribution(generator)<<endl;
  
  
  //Testing tdc calculation used in: 
  // https://raw.githubusercontent.com/KPAdhikari/Gemc/main/develKA/source/hitprocess/clas12/rtpc_hitprocess.cc
  
  // Drift time from first GEM to readout pad
  double t_2GEM2 = 0.0; // 169.183;
  double sigma_t_2GEM2 = 8.72728;
  double t_2GEM3 = 0.0; //222.415;
  double sigma_t_2GEM3 = 5.62223;
  double t_2PAD = 0.0; //414.459;
  double sigma_t_2PAD = 7.58056;
  
  double t_2END = t_2GEM2 + t_2GEM3 + t_2PAD;
  double sigma_t_gap = sqrt(pow(sigma_t_2GEM2,2)+pow(sigma_t_2GEM3,2)+pow(sigma_t_2PAD,2));


  // Diffusion parameters
  double diff_at=388.7449859;
  double diff_bt=-4.33E+01;
  
  /*
  // local variable for each step
  vector<G4ThreeVector> Lpos = aHit->GetLPos();
  //Here, We'll have to try some reasonably random value for r0 by hand.
  LposX = Lpos[s].x(); LposY = Lpos[s].y(); LposZ = Lpos[s].z();
  double r0=(sqrt(LposX*LposX+LposY*LposY))/10.0;  //in cm
  */
  double r0 = aNum;
   
  // -------------------------------- Addition of Diffusion -----------------------------
          
  // calculate drift time [ns] to first GEM
  /*  The following is the complicated form that we abandon
            double t_drift = a_t+b_t*(0.5+(-40.0+sqrt(4.0*(0.1+c_t*c_t)*(49-r0*r0)+pow((40.0-(0.1+c_t*c_t)),2)))/(2*(0.1+c_t*c_t)));
  */
  double t_drift = a_t + b_t*(7.0*7.0-r0*r0)/40.0;
            
  // determine sigma of drift time [ns]
  double t_diff = sqrt(diff_at*(7.0-r0)+diff_bt*(7.0-r0)*(7.0-r0));
  
  
  //std::normal_distribution<double> distribution1(t_drift, t_diff); //mean=5.0, sigma = 2.0?
  std::normal_distribution<double> distribution2(t_2END, sigma_t_gap); //mean=5.0, sigma = 2.0?
  //for (int i=0; i<4; i++) cout<<i<<"th #: "<<distribution(generator)<<endl;

  // find t_s2pad etc by gaussians //kp: G4RandGauss::shoot(mean, sigma)
  double t_s2pad = 0.0; //distribution1(generator); //G4RandGauss::shoot(t_drift, t_diff);
  double t_gap = distribution2(generator); //G4RandGauss::shoot(t_2END, sigma_t_gap);
  //https://www.ge.infn.it/geant4/training/ptb_2009/day2/code/PrimaryGenerator.2.6.cc
  // The G4RandGauss::shoot(mean, sigma) function is used for sampling randomly
  // the kinetic energy if the user has specified a sigma > 0.0:
  
  
  // time shift
  double shift_t = 0.0; //timeShift_map.find(aHit->GetTId())->second;
    
  double tdc = t_s2pad + t_gap + shift_t; //kp:
  
  cout<<"\n tdc = "<<tdc<<endl;
  return tdc; //return 0;
}

