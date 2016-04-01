#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(void){
  /*  if(argc != 2){
    if(argc > 2) {
      printf("Error: too many name parameters\n");
    }
    else {
    printf("Error: missing name parameter\n");
    }
    printf("Usage: ./a.out <name>\n");
    exit(1);
    }*/
  
  char* name;
  name = (char*) malloc (100 * sizeof(char)); 
  memset(name,0,100);
  printf("Please type in the name of the person you want to greet\n");
  scanf("%s", name);
  printf("Hello, %s and world\n",name);
  
  free(name);
  return 0;
}

