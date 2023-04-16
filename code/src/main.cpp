#include "vacuum.h"
#include <fstream>

int main()
{
    squids::Const units;
  
    // Number of energy bins
    unsigned int Nenergy = 1000;
    
    // Number of flavors
    unsigned int Nflavor = 3;
    
    // Energy Range
    double Emin = 10 * units.MeV, Emax = 10 * units.GeV;
    
    // Declaration of the object
    vacuum V0(Nenergy, Nflavor, Emin, Emax);

    V0.Evolve(1000 * units.km);

    std::ofstream file("data/oscillations.dat");

    const int nu_e = 0, nu_mu = 1, nu_tau = 2;
    for(double logE = log(Emin); logE < log(Emax); logE += 0.0001)
    {
        double E = exp(logE);
        file << E / units.GeV << "  " << V0.Get_flux(nu_e, E) << "  " <<
            V0.Get_flux(nu_mu, E) << "  " << V0.Get_flux(nu_tau, E) << std::endl;
    }
    
    file.close();
  
    return 0;
}