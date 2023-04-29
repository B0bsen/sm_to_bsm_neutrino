# include <iostream>
# include <SQuIDS/SQuIDS.h>

int main(){
	// task 1: Default constr. const object

	// task 2: Translate between unit systems
	/// 300 km to eV^{-1}

	/// 25° to rad

	/// 24 yr to eV^{-1}

	// task 3: Set mixing params of const object
	/// \theta_{12} = 33.48°

	/// \theta_{13} = 8.55°

	/// \theta_{23} = 42.30°

	// task 4: Set energy differences for H0
	/// \Delta m_{21}^2 = 7.5 x 10−5 eV^2

	/// \Delta m_{31}^2 = 2.45 x 10−3 eV^2
	
	squids::Const units;
	double L = 10 * units.cm;
	double T = 1 * units.year;
	double GF = units.GF * (units.GeV * units.GeV);
	std::cout << L << std::endl;
	std::cout << T << std::endl;
	std::cout << GF << std::endl;
	return 0;
}
