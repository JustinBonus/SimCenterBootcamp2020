#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <mpi.h>
#define LUMP 1

static long int numSteps = 100000000;

int main(int argc, char **argv) {

  // Basic MPI initialization
  int numP, procID;
  printf("procID %d\n", procID);
  
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numP);
  MPI_Comm_rank(MPI_COMM_WORLD, &procID);
  printf("procID %d\n", procID);
  
  double *globalData=NULL;
  double localData[LUMP];

  // Set globalData to procID 0 heap array, initialize to zero
  if (procID == 0){
    globalData = (double *)malloc(LUMP * numP * sizeof(double));
    for (int i=0; i<LUMP*numP; i++)
      globalData[i]=0;
  }


  // perform calculation
  double myPart = 0;
  //double numSteps = LUMP*numP;
  double dx   = 1./(numSteps);
  double x = 0.50*dx;

  for (int i=0; i<numSteps; i+=numP){
    x = (i+0.5)*dx;
    myPart += 4./(1.+x*x);
  }
  
  myPart *= dx;
  
  for (int i=0; i<LUMP; i++) {
    localData[i] = myPart;
  }
  
  MPI_Gather(localData, LUMP, MPI_DOUBLE, globalData, LUMP, MPI_DOUBLE, 0, MPI_COMM_WORLD);


  if (procID == 0) {
    double pi = 0;
    for (int i=0; i<numP*LUMP; i++){
      pi += globalData[i];
    }
    printf("\n");
    printf("PI = %16.14f Difference from math.h definition %16.14f \n",pi, pi-M_PI);
  }
  
  if (procID == 0) {
    free(globalData);
  }

  MPI_Finalize();

  return 0;
}
