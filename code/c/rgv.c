#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

  for (int i=0; i<argc; i++){

    int length = strlen(argv[i]);
    char *newString = (char *)malloc((length+1)*sizeof(char));
    strcpy(newString, argv[i]);
    printf("%d %d %s  %s\n",i,length,argv[i], newString);
    free(newString);

  }
  
  return 0;
}
