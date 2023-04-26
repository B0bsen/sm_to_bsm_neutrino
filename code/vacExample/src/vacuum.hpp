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
        // SU vector storing the mass squared differences: dm_{21}^2 and dm_{31}^2
        squids::SU_vector DM2; 
    public:
        squids::SU_vector *b0_proj; // mass basis projectors
        squids::SU_vector *b1_proj; // flavor basis projectors

    vacuum(){};
    // constructor and initialization
    // nbins -> number of energy bins
    // nflavor -> number of flavors
    // Ein -> initial energy
    // Efin -> final energy
    vacuum(unsigned int nbins, unsigned int nflavor, double Eini, double Efin){init(nbins, nflavor, Eini, Efin);};
    void init(unsigned int nbins, unsigned int nflavor, double Eini, double Efin);

    // Function to set the parameters.
    void SetVacuum(squids::Const par);
    
    // H0 operator
    squids::SU_vector H0(double E, unsigned int irho) const;
  
    // get the final flux, the initial one is flat in energy
    double Get_flux(int, double);

    // destructor
    ~vacuum();
};

#endif