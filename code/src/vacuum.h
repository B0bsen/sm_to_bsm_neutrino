#ifndef VACUUM_H
#define VACUUM_H

#include <iostream>
#include <float.h>
#include <cmath>
#include <complex>
#include <vector>

#include <SQuIDS/SQuIDS.h>

class vacuum: public squids::SQuIDS {
 private:
  squids::SU_vector DM2;
 public:
  std::unique_ptr<squids::SU_vector[]> b0_proj;
  std::unique_ptr<squids::SU_vector[]> b1_proj;

  vacuum(){};
  //constructor and initialization
  //nbins -> number of energy bins
  //nflavor -> number of flavors
  //Ein -> initial energy
  //Efin -> final energy
  vacuum(unsigned int nbins, unsigned int nflavor, double Eini, double Efin){init(nbins,nflavor,Eini,Efin);};
  void init(unsigned int nbins, unsigned int nflavor, double Eini, double Efin);

  //Function to set the parameters.
  void SetVacuum(squids::Const par);
  //H0 operator
  squids::SU_vector H0(double E, unsigned int irho) const;
  
  //get the final flux, the initial one is flat in energy
  double Get_flux(int,double);
};

#endif