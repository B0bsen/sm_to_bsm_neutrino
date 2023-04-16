#include "vacuum.h"
#include <fstream>

int main(){
  squids::Const units;
  
  //Number of energy bins
  unsigned int Nenergy=1000;
  //Number of flavors
  unsigned int Nflavor=3;
  //Energy Range
  double Emin=10*units.MeV, Emax=10*units.GeV;
  //declaration of the object
  vacuum V0(Nenergy,Nflavor,Emin,Emax);

  V0.Evolve(1000*units.km);

  std::ofstream file("oscillations.dat");

  const int nu_e=0, nu_mu=1, nu_tau=2;
  for(double lE=log(Emin); lE<log(Emax); lE+=0.0001){
    double E=exp(lE);
    file << E/units.GeV << "  " << V0.Get_flux(nu_e,E) << "  " <<
      V0.Get_flux(nu_mu,E) << "  " << V0.Get_flux(nu_tau,E) << std::endl;
  }

  std::cout << std::endl <<  "Done! " << std::endl <<  "Do you want to run the gnuplot script? yes/no" << std::endl;
  std::string plt;
  std::cin >> plt;

  if(plt=="yes" || plt=="y"){
    return system("./plot.plt");
  }
  
  return 0;
}