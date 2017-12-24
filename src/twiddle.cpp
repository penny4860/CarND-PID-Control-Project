#include "twiddle.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

Twiddle::Twiddle() {}

Twiddle::~Twiddle() {}

void Twiddle::init(double *params_, double *d_params_, double error)
{
	// set initial params & d_params
	for (int i = 0; i < N_PARAMS; i++)
	{
		params[i] = params_[i];
		d_params[i] = d_params_[i];
	}
	// set best error to initial error
	best_error = error;
	n_iter = 0;
	is_init = true;
}
