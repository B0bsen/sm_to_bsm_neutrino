#include "vacuum.h"

using squids::SU_vector;

void vacuum::init(unsigned int nbins, unsigned int nflavor, double Eini, double Efin){
    // initialize SQUID with one density matrix and zero scalar functions
    // nbins -> is the number of energy modes
    // nflavor -> is the number of flavors
    // 1 -> is the number of density matrices, rho, in every energy bin
    // 0 -> number of scalar functions
    // 0 -> initial time
    ini(nbins, nflavor, 1, 0, 0);
    
    // initialize the SU_vector that contains the delta_m
    DM2 = SU_vector(nsun);
    
    // set the energy range (Ein, Efin) in log scale
    Set_xrange(Eini, Efin, "log");
    
    // set the oscillation parameters
    const double ev2 = params.eV * params.eV;
    params.SetEnergyDifference(1,7.5e-5 * ev2); //delta m^2 2,1
    params.SetEnergyDifference(2,2.45e-3 * ev2); //delta m^2 3,1
    params.SetMixingAngle(0, 1, 33.48 * params.degree); //theta 1,2
    params.SetMixingAngle(0, 2, 8.55 * params.degree);  //theta 1,3
    params.SetMixingAngle(1, 2, 42.3 * params.degree);  //theta 2,3

    // Construction of the projectors for the mass and flavor bases
    b0_proj = new SU_vector[nsun];
    b1_proj = new SU_vector[nsun];

    for(int i = 0; i < nsun; i++){
      b0_proj[i] = SU_vector::Projector(nsun,i);
      b1_proj[i] = SU_vector::Projector(nsun,i);
      b1_proj[i].RotateToB1(params);
    }

    for(int i = 1; i < nsun; i++)
      DM2 += (b0_proj[i]) * params.GetEnergyDifference(i);

    // set initial conditions for the density matrix.
    // Here b1 is the flavor basis, and we set a flat spectrum with value 1 to the flavor number 0  
    for(int ei = 0; ei < nx; ei++)
    state[ei].rho[0]=b1_proj[0];
}   

//Function that returns the H0 operator
SU_vector vacuum::H0(double x, unsigned int irho) const{
  return DM2 * (0.5 / x);
}

//function that returns the flux for the neutrino with flavor "i" and energy "e"
double vacuum::Get_flux(int i, double e){
  return GetExpectationValueD(b1_proj[i], 0, e);
}

// destructor
~vacuum(){
  delete[] b1_proj;
  delete[] b0_proj;
}