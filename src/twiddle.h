#ifndef TWIDDLE_H
#define TWIDDLE_H

#define N_PARAMS	3

class Twiddle {

public:
  double best_error;
  int n_iter;
  double params[N_PARAMS];
  double d_params[N_PARAMS];
  bool is_init = false;

  Twiddle();
  virtual ~Twiddle();

  /*
  * Initialize PID.
  */
  void init(double *params_, double *d_params_, double error);

};

#endif /* TWIDDLE_H */
