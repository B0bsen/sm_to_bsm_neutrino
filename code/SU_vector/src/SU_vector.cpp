# include <iostream>
# include <SQuIDS/SQuIDS.h>

int main(){
	const unsigned int dim = 3;
	
	// task 1: Declare empty SU vector for dim(H) = 3
	squids::SU_vector rho(dim);

	// task 2: Initialize array of projectors (B0; mass basis)
	squids::SU_vector *proj0 = new squids::SU_vector[dim];
	for (int i = 0; i < dim; i++)
		proj0[i] = squids::SU_vector::Projector(dim, i);

	// task 3: Rotate them to (B1; flavor basis)
	squids::Const params;
	params.SetMixingAngle(0, 1, 33.48 * params.degree);
	params.SetMixingAngle(0, 2, 8.55 * params.degree);
	params.SetMixingAngle(1, 2, 42.3 * params.degree);
	
	squids::SU_vector *proj1 = new squids::SU_vector[dim];
	for (int i = 0; i < dim; i++)
	{
		proj1[i] = squids::SU_vector::Projector(dim, i);
		proj1[i].RotateToB1(params);
	}

	// task 4: Declare SU vector corresponding to diag(0, \Delta m_{21}^2, \Delta m_{31}^2)
	squids::SU_vector DM2(dim);
	std::vector<double> dm2 = {0, 7.5e-5 * params.eV * params.eV, 2.45e-3 * params.eV * params.eV};

	for (int i = 0; i < dim; i++)
		DM2 +=dm2[i] * proj0[i];
	

	return 0;
}
