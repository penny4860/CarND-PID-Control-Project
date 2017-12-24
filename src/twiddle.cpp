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
	param_index = 0;
	is_init = true;
	state = STATE_INIT;

	//
	params[param_index] += d_params[param_index];
}


void Twiddle::run(double *params, double error)
{
	double dp_sum = d_params[0] + d_params[1] + d_params[2];
	// End Tuning
	if (dp_sum < 0.2)
		return;

	switch (state)
	{
	case STATE_INIT:
		//update parameter & run
		break;

	case STATE_AFTER_INCREASE:
		break;

	case STATE_AFTER_DECREASE:
		break;
	}
}









