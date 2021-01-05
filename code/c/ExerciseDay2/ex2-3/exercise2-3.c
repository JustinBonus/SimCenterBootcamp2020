#include <stdio.h>
#include <stdlib.h>
#include <math.h>    // need this for the constant pi = M_PI

#include "stresstransform.h"


int main(int argc, char **argv) {

  // get dth from the first argument.  This is given in degrees!
  // might be smart to set a default value, just in case the user
  // forgets when calling this  program;)
  float dth = atof(argv[1]); //in degrees

  // set the initial stress state

  STRESS S0;
  STRESS Sp;

  S0.sigx = 12.0;
  S0.sigy = -5.5;
  S0.tau  =  3.5;

  printf("theta, sigma_x, sigma_y, tau_xy\n");
  
  // loop to compute transformed states
  for (float d = dth; d < 180.0 + dth; d = d + dth) {
    StressTransform(S0, &Sp, d);
    printf("%12.5f, %12.6f, %12.6f, %12.6f\n", d, Sp.sigx, Sp.sigy, Sp.tau);
  }
}

