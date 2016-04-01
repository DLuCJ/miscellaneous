#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>

/* This program checks user input and confirms or denies palindromeness
 *
 * Author: Daniel Lu
 * Date: 11/8/13
 */

const static int MAX_STRING_SIZE = 101;
char * getPhrase(char * phrase);
void keep_chars(char * phrase);
void toLowerCase(char * phrase);
bool isPalindrome(char * phrase);

int main(void) {
  char * phrase = getPhrase(phrase);
  char phrase_copy[MAX_STRING_SIZE];
  strcpy(phrase_copy, phrase);
  keep_chars(phrase_copy);
  toLowerCase(phrase_copy);
  if(isPalindrome(phrase_copy)) {
    printf("\nThe phrase: %s\nIs a palindrome!\n",phrase);
  } else {
    printf("The phrase: %s\nIs not a palindrome!\n",phrase);
  }
  
  free(phrase); //frees malloc   
  return 0;
}

//parameter: copy of phrase
//returns true if phrase is a palindrome, else returns false
bool isPalindrome(char * phrase) {
  char * phrase2 = phrase + strlen(phrase) - 1;
  while(phrase < phrase2) {
    if(*phrase2-- != *phrase++){
      return false;
    }
    return true;
  }
}

//parameters: char array to hold user input
//returns user input phrase to main 
char * getPhrase(char * phrase) {
  phrase = malloc(MAX_STRING_SIZE);
  printf("Enter a phrase: ");
  fgets(phrase, MAX_STRING_SIZE, stdin);
  return phrase;
}

//parameters: copy of phrase
//removes everything except for letters 
void keep_chars(char * phrase) {
  int i = 0, j = 0;
  while( phrase[i] != '\0') {
    if( ('A' <= phrase[i] && phrase[i] <= 'Z') || ('a' <= phrase[i] && phrase[i] <= 'z')) {
      phrase[j] = phrase[i];
      i++;
      j++;
    } else {
      i++;
    }
  }
  phrase[j] = '\0';
}

//parameters : copy of phrase
//converts all upper case characters to lower case 
void toLowerCase (char * phrase) {
  for( ; *phrase; ++phrase) *phrase = tolower(*phrase); 
}
