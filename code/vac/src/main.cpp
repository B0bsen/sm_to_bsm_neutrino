#include <iostream>
#include <fstream>
#include <cmath>
#include "vacuum.hpp"


int main()
{
	squids::Const units;
	const unsigned int nbins = 1000, nflavor = 3;
	const double E0 = 10.0 * units.MeV, E1 = 10.0 * units.GeV;
	double E;
	std::string scale = "log";
	
	// task 3: Initialize an object from your class
	vacuum state_nu_e(nbins, nflavor, E0, E1, scale);

	// task 4: Evolve it for L = 300 km
	double L = 300 * units.km;
	state_nu_e.Evolve(L);

	// task 5: Save the three probability arrays
	// P_{\nu_e \to \nu_{e} / \nu_{\mu} / \nu_{\tau}}(L, E_j)
	// to files in data (directory will be automatically generated)
	std::ofstream f_E("data/E.txt");
	std::ofstream f_nu_e("data/p_nu_e.txt");
	std::ofstream f_nu_mu("data/p_nu_mu.txt");
	std::ofstream f_nu_tau("data/p_nu_tau.txt");

	for (unsigned int n = 0; n < nbins; n++)
	{
		f_E << state_nu_e.Get_x(n) << "\n";
		f_nu_e << state_nu_e.GetProb(0, n) << "\n";
		f_nu_mu << state_nu_e.GetProb(1, n) << "\n";
		f_nu_tau << state_nu_e.GetProb(2, n) << "\n";
	}

	f_nu_tau.close();
	f_nu_mu.close();
	f_nu_e.close();

	return 0;
}
