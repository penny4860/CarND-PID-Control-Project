#include "twiddle.h"
#include <iostream>

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

	params[param_index] += d_params[param_index];
	state = STATE_AFTER_INCREASE;
}

void Twiddle::run(double error)
{
	double dp_sum = d_params[0] + d_params[1] + d_params[2];
	// End Tuning
	if (dp_sum < 0.2)
		return;

	// Compare best error & current error
	if (error < best_error)
	{
		best_error = error;
		d_params[param_index] *= 1.1;
		param_index++;

		// end of iter
		if (param_index == N_PARAMS)
		{
			param_index = 0;
			n_iter++;
		}
		params[param_index] += d_params[param_index];
		state = STATE_AFTER_INCREASE;
	}
	else
	{
		if (state == STATE_AFTER_INCREASE)
		{
			params[param_index] -= 2*d_params[param_index];
			state = STATE_AFTER_DECREASE;
		}
		else if (state == STATE_AFTER_DECREASE)
		{
			params[param_index] += d_params[param_index];
			d_params[param_index] *= 0.9;
			param_index++;

			// end of iter
			if (param_index == N_PARAMS)
			{
				param_index = 0;
				n_iter++;
			}
			params[param_index] += d_params[param_index];
			state = STATE_AFTER_INCREASE;
		}
	}
	std::cout << "\n	parameter index: " << param_index;
	std::cout << "\n	params: " << d_params[0] << ", " << d_params[1] << ", " << d_params[2];


}









