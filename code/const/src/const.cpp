# include <iostream>
# include <SQuIDS/SQuIDS.h>

int main(){
	// task 1: Default constr. const object
	squids::Const units;

	// task 2: Translate between unit systems
	/// 300 km to eV^{-1}
	std::cout << "300 km = " << 300 * units.km << " 1 / eV" << "\n";

	/// 25° to rad
	std::cout << "25° = " << 25 * units.degree << " rad" << "\n";

	/// 24 yr to eV^{-1}
	std::cout << "24 yr = " << 24 * units.year << " 1 / eV" << "\n";

	// task 3: Set mixing params of const object
	/// \theta_{12} = 33.48°
	units.SetMixingAngle(0, 1, 33.48 * units.degree);

	/// \theta_{13} = 8.55°
	units.SetMixingAngle(0, 2, 8.55 * units.degree);

	/// \theta_{23} = 42.30°
	units.SetMixingAngle(1, 2, 42.3 * units.degree);

	// task 4: Set energy differences for H0
	/// \Delta m_{21}^2 = 7.5 x 10−5 eV^2
	units.SetEnergyDifference(1, 7.5e-5 * units.eV * units.eV);

	/// \Delta m_{31}^2 = 2.45 x 10−3 eV^2
	units.SetEnergyDifference(2, 2.45e-3 * units.eV * units.eV);
	
	return 0;
}
