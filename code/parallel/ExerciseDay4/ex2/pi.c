#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

static long int numSteps = 100000000;

int main(int argc, char **argv) {
  int nThreads = 0;
  double pi = 0;
  double sum[64]; // Can reach 125336 threads Ubuntu 18.04, i7 12-core, 12 GB RAM
  
#pragma omp parallel
  {
    // Process info
    int id = omp_get_thread_num();
    int numP = omp_get_num_threads();

    // Set thread number on processor 0
    if (id == 0) nThreads = numP;
    
    // Calculation Variables
    double myPart = 0;
    double dx = 1./numSteps;
    double x = dx*0.50;


    // Calculate pi-partial
    for (int i=0; i<numSteps; i+=numP){
      x = (i+0.5)*dx;
      myPart += 4./(1.+x*x);
    }

    // Place part into array element
    myPart *= dx;
    sum[id] = myPart;
  }

  // Sum (reduce) array elements into pi
  for (int i=0; i<nThreads; i++)
    pi+= sum[i];

  // Print to screen
  printf("Total Number of Threads: %d\n", nThreads);
  printf("PI = %16.14f Difference from math.h definition %16.14f \n",pi, pi-M_PI);
  return 0;
}
