// program to transform stress:
//
// sigmaX' = sigmaX * cos^2(theta) + sigmaY * sin^2(theta) + 2 * tauXY Sin(theta)Cos(theta)
// sigmaY' = sigmaX * sin^2(theta) + sigmaY * cos^2(theta) - 2 * tauXY Sin(theta)Cos(theta)
// tauXY' = (sigmaX-sigmaY) * sin(theta)cos(theta) + tauXY(cos^2(theta) - sin^2(theta))
//
// write a program to take 4 inputs: sigmaX, sigmaY, tauXY, theta
// output transformed stresses: sigmaX', sigmaY', tauXY'
//
// NOTE: perform the transformation inside a function that cannot be named main


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float transform(float sigmaX, float sigmaY, float tauXY, float theta);

int main(int arc, char **argv){

  if (argc != 5) {
    printf("Usage: appName sigmaX sigmaY tauXY theta \n");
    exit(-1);
  }

  float sigmaX = atof(argv[1]);
  float sigmaY = atof(argv[2]);
  float tauXY = atof(argv[3]);
  float theta  = atof(argv[4]);


  sigmaX, sigmaY, tauXY = transform(sigmaX, sigmaY, tauXY, theta);
  printf("Transformed Stress: (%f, %f, %f) \n", sigmaX, sigmaY, tauXY, theta);
  return(0);
}


float transform(float sigmaX, float sigmaY, float tauXY, float theta){

  float sX, sY, tXY;
  sX = (sigmaX * (cos(theta)*cos(theta))) + (sigmaY * (sin(theta)*sin(theta))) + (2 * tauXY * sin(theta)*cos(theta));
  sY = (sigmaX * (sin(theta)*sin(theta))) + (sigmaY * (cos(theta)*cos(theta))) - (2 * tauXY * sin(theta)*cos(theta));
  tXY = (sigmaX-sigmaY) * sin(theta) * cos(theta) + tauXY*(cos(theta)*cos(theta) - sin(theta)*sin(theta);
  
  return sX, sY, tXY;
}
