#include "vacuum.hpp"

// task 2: Define the member functions of your class
vacuum::vacuum()
{

}

vacuum::vacuum(unsigned int nbins, unsigned int nflavor, double E0, double E1, std::string scale)
{
    init(nbins, nflavor, E0, E1, scale);
}

void vacuum::init(unsigned int nbins, unsigned int nflavor, double E0, double E1, std::string scale)
{
    // initialize base class members
    // defines nsun = nflavors, params, ...
    unsigned int nrho = 1; // num density matrices per node
    unsigned int nscalar = 0; // num scalars per node
    double t0 = 0.0; // initial time
    ini(nbins, nflavor, nrho, nscalar, t0);

    // Set_xrange as energies
    if (scale != "log" && scale != "linear") Set_xrange(E0, E1, "log");
    else Set_xrange(E0, E1, scale);

    // initialize params object
    double eV2 = params.eV * params.eV;
    params.SetEnergyDifference(1, 7.5e-5 * eV2); // \Delta m_{21}^2
    params.SetEnergyDifference(2, 2.45e-3 * eV2); // \Delta m_{31}^2
    params.SetMixingAngle(0, 1, 33.48 * params.degree); // \theta_{12}
    params.SetMixingAngle(0, 2, 8.55 * params.degree);  // \theta_{13}
    params.SetMixingAngle(1, 2, 42.3 * params.degree);  // \theta_{14}

    // init projectors
    proj0 = new squids::SU_vector[nsun];
    proj1 = new squids::SU_vector[nsun];

    for (unsigned int i = 0; i < nsun; i++)
    {
        proj0[i] = squids::SU_vector::Projector(nsun, i);
        proj1[i] = squids::SU_vector::Projector(nsun, i);
        proj1[i].RotateToB1(params);
    }

    // initialize DM2
    DM2 = squids::SU_vector(nsun);

    for (unsigned int i = 1; i < nsun; i++)
    {
        DM2 += proj0[i] * params.GetEnergyDifference(i);
    }
    
    // initial conditions (all electron neutrinos)
    for (unsigned int node = 0; node < nbins; node++)
    {
        state[node].rho[0] = proj1[0];
    }
    
}

squids::SU_vector vacuum::H0(double E, unsigned int irho) const
{
    return DM2 * (0.5 / E);
}

double vacuum::GetProb(unsigned int flav, unsigned int n)
{
    return GetExpectationValue(proj1[flav], 0, n);
}

double vacuum::GetProbD(unsigned int flav, double E)
{
    return GetExpectationValueD(proj1[flav], 0, E);
}

vacuum::~vacuum()
{
    delete[] proj1;
    delete[] proj0;
}
