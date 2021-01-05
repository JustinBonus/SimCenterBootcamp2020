#include <stdio.h>

int sumArray(int *arrayData, int size);
int main(int argc, char **argv){
  int intArray[6] = {19,12,13,14,50,0};
  int sum1 = sumArray(intArray, 6);
  printf("sum: %d\n", sum1);
  return(0);
}

// function to evaluate vector sum
int sumArray(int *dataPtr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++){
    sum += *dataPtr;
    dataPtr++;
  }
  return sum;
}
