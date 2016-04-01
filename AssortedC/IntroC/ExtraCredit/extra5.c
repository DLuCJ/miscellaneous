/* This program performs a bit-level 
 * XOR encryption of a text-file and overwrites
 * the original.  
 *
 * Author: Daniel Lu
 * Date: 12/4/2013
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt_data(FILE *filename);


//If you want to double check functionality, comment out the code that creates the 
//original "encrypt_file" file, and uncomment the spare File *f 
int main(void) {

  FILE *f = fopen ("encrypt_file", "w");
  if(f == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  const char * str1 = "This is my text This is a text \nThis is some text This is the text";
  fprintf(f, "%s\n",str1);
  fclose(f);
  

  //FILE *f;
  int return_code = encrypt_data(f);
  if(return_code != 0) exit(1);
  return 0;
}

//Parameters: pointer to file
//encrypts data in given file and writes encryption to file
int encrypt_data(FILE * filename) {
  int i;
  const char *key = "itsAKey";
  size_t key_len = strlen(key);
  size_t file_size;
  char *data = NULL;
  
  
  filename = fopen("encrypt_file", "r");

  fseek(filename,0, SEEK_END);
  file_size = ftell(filename);
  fseek(filename,0, SEEK_SET);
  
  data = malloc(file_size);

  if( fread(data, file_size, 1, filename) != 1) {
    printf("Error in reading file\n");
    exit(1);
  }
  
  //XOR encryption
  for (i = 0; i < file_size; i++) {
    data[i] = data[i]^key[i%key_len];
  }
 
  fclose(filename); 
  fseek(filename,0, SEEK_SET);
  filename = fopen("encrypt_file", "wb");

  //write encryption to file
  for(i = 0; i < file_size; i++) {
    fputc(data[i], filename);
  }
  
  free(data);
  fclose(filename);
  return 0;
}














