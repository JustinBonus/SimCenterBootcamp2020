
// program to read values from a file, each file a csv list of int and two double
// written: fmk
// completed: Justin Bonus, Jan 5th 2020

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  // Check for correct usage of executable
  if (argc != 2) {
    fprintf(stdout, "ERROR correct usage appName inputFile\n");
    return -1;
  }

  // Pointer to input file, e.g. './file3 small.txt'
  FILE *filePtr = fopen(argv[1],"r"); 

  // Variables to populate with info from binary file
  int i = 0;
  float float1, float2;

  // Max vector size, initially
  int maxVectorSize = 100;

  // Initialize vectors
  double *vector1 = (double *)malloc(maxVectorSize*sizeof(double));
  double *vector2 = (double *)malloc(maxVectorSize*sizeof(double));  
  int vectorSize = 0;

  // Loop through entire binary file
  while (fscanf(filePtr,"%d, %f, %f\n", &i, &float1, &float2) != EOF) {

    // Populate vector elements from binary file
    vector1[vectorSize] = float1;
    vector2[vectorSize] = float2;

    // Print to screen
    printf("%d, %f, %f\n",i, vector2[i], vector1[i]);

    // Iterate
    vectorSize++;

    // Check if current index is greater than max assigned to vectors
    if (vectorSize == maxVectorSize) {
      // Create new vectors of larger size
      maxVectorSize += vectorSize;
      double *newVector1 = (double *)malloc((maxVectorSize)*sizeof(double));
      double *newVector2 = (double *)malloc((maxVectorSize)*sizeof(double));

      for (int j=0; j<vectorSize; j++){
	// Copy over the data we have so far
	newVector1[j] = vector1[j];
	newVector2[j] = vector2[j];
      }
      // Free original vectors from memory
      free(vector1);
      free(vector2);
      // Reassign as the new, expanded vectors
      vector1 = newVector1;
      vector2 = newVector2;
    }
  }
  // Close out binary file pointer
  fclose(filePtr);  
}
