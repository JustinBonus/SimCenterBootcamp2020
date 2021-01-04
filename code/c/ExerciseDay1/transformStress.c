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

void transform(float X, float Y, float XY, float t);

int main(int argc, char **argv){

  if (argc != 5) {
    printf("Usage: appName sigmaX sigmaY tauXY theta \n");
    exit(-1);
  }

  float sigmaX = atof(argv[1]);   // in kPa
  float sigmaY = atof(argv[2]);   // in kPa
  float tauXY  = atof(argv[3]);   // in kPa
  float theta  = atof(argv[4]);   // in degrees
  theta = theta * (M_PI / 180.0); // in radians

  transform(sigmaX, sigmaY, tauXY, theta);
  return(0);
}


void transform(float sigmaX, float sigmaY, float tauXY, float theta){
  float sX, sY, tXY;
  sX = (sigmaX * (cos(theta)*cos(theta))) + (sigmaY * (sin(theta)*sin(theta))) + (2 * tauXY * sin(theta)*cos(theta));
  sY = (sigmaX * (sin(theta)*sin(theta))) + (sigmaY * (cos(theta)*cos(theta))) - (2 * tauXY * sin(theta)*cos(theta));
  tXY = (sigmaX-sigmaY) * sin(theta) * cos(theta) + tauXY*(cos(theta)*cos(theta) - sin(theta)*sin(theta));
  printf("Transformed Stress (sigmaX', sigmaY', tauXY') [kPa]: (%f, %f, %f) \n", sX, sY, tXY);
  return;
}
