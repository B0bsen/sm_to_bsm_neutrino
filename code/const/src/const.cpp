# include <iostream>
# include <SQuIDS/SQuIDS.h>

int main(){
	// initialize SQuIDS object
	squids::Const units;
	
	// how many inverse electron volts are 300 km?
	std::cout << "300 km = " << 300 * units.km << " 1 / eV" << "\n";
	
	// set mixing angles in rad
	units.SetMixingAngle(0, 1, 33.48 * units.degree);
	units.SetMixingAngle(0, 2, 8.55 * units.degree);
	units.SetMixingAngle(1, 2, 42.3 * units.degree);
	
	// set energy differences wrt. ground state
	units.SetEnergyDifference(1, 7.5e-5 * units.eV * units.eV);
	units.SetEnergyDifference(2, 2.45e-3 * units.eV * units.eV);
	
	return 0;
}
