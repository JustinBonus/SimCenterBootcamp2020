// calculate pi numerically
//
// pi = integral 0->1 (4/(1+x^2))dX
//
// compute an approx using sum from i = 1 to N
// of F(xi)delta X, where F(xi) computed at middle of iterval i
//
// take as input the number of intervals N

#include <stdio.h>
#include <time.h>

static int long numSteps = 1000;
int main(int argc, char **argv){
  double pi  = 0, time = 0;
  clock_t tic, toc;
  double dx, x;
  dx = (double) 1/numSteps;

  toc = clock();
  for (int i=0; i<numSteps; i++){
    x  = (double) i * dx;
    pi += ( (4/(1+(x*x))) * dx);
  }
  tic = clock();
  
  time = ((double) (tic - toc)) / CLOCKS_PER_SEC;
  printf("PI = %f, duration: %f ms\n", pi, time*1000);
  return(0);
}
