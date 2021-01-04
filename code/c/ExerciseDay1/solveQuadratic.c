// program to solve quadratic equation
//        ax^2 + bx + c = 0
//
// soln: x = -b/2a +/- sqrt(b^2-4ac)/2a
//
// write a program to take 3 inputs and output the soln
// deal with possible errors in input, i.e. b^2-4ac negative

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if (argc != 4) {
    printf("Usage: appName a b c\n");
    exit(-1);
  }

  float a = atof(argv[1]);
  float b = atof(argv[2]);
  float c = atof(argv[3]);
  float d;
  d = (b*b) - 4*a*c;
  
  float x1, x2;
  if ( d >= 0 && a != 0) {
    x1 = ( (-b) + sqrt(d) ) / (2*a);
    x2 = ( (-b) - sqrt(d) ) / (2*a);
    printf("Root value(s) of x = (%f, %f) \n", x1, x2);
  } else if (a == 0.) {
    printf("Error, a = 0\n");
  } else {
    printf("Root value(s) x have an imaginary component. \n");
    printf("x = (%.3f%+.3fi, %.3f%+.3fi) \n", -b/(2*a), sqrt(-d)/(2*a), -b/(2*a), -sqrt(-d)/(2*a));
  }

  printf("Have a Nice Day! (Justin Bonus)\n");
  printf("\n");
  return 0;
}

