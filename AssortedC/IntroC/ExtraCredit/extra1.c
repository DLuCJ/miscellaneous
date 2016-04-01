#include <stdio.h>
#include <stdlib.h>

int main (int argc, const char *argv[]) {
	 
  char cmd[100]; //buffer to hold cp command 
  
  char path[] = "/home/faculty/skoss/fall2013/d.lu";
  
  sprintf(cmd, "cp %s %s", argv[1], path); // params (program name, path) as Strings 
  system(cmd); // gives the cmd command to the OS for execution 
  return 0;
    
}
