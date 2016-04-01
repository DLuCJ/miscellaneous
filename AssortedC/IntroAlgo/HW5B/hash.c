
/* Hash table functions, including functions to make and delete hash
 * table, and the hashing algorithm
 *
 * Author: Daniel Lu
 * Date:   2/17/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash.h"
#include <limits.h>
#include <string.h>

Hashtable * makeTable(int size) {
  Hashtable * newTable = (Hashtable *) malloc(sizeof(Hashtable));
  newTable->table = (char **) malloc(sizeof(char *) * size);
  
  int i;
  for(i = 0; i < size; i++) {
    newTable->table[i] = NULL;
  }
  newTable->size = size;
  return newTable;
}

bool overflow(char * val) {
  bool overflow = false;
  if(val != NULL) {
    int i;
    for(i = 0; i < strlen(val);i++) {
      if(*(val + i) < 'a' || *(val+i) > 'z') {
	overflow = true;
	break;
      }
    }
    if(!overflow){
      overflow = strlen(val) > 10 || strlen(val) < 1; 
    }
  }
  return overflow;
}

void hashListFull(Hashtable * thisTable) {
  int i;
  for(i = 0; i < thisTable->size; i++) {
    if(isNull(i,thisTable)) {
      printf("List #%i : empty\n",i);
    }else{
      printf("List #%i :", i);
      printf("%s",thisTable->table[i]);
      printf("\n");
    }
  }
}

void term(Hashtable * thisTable) {
  int i;
  for(i = 0; i < thisTable->size; i++) {
    if(thisTable->table[i] != NULL) {
      free(thisTable->table[i]);
    }
  }
  free(thisTable->table);
  free(thisTable);
}

unsigned int hash(char * k) {
  return (int)*(k) - (int)('a');
}

bool hashDelete(char * k, Hashtable * thisTable) {
  int index = hash(k);
  int pos = index;
  do {
    if(isNull(pos,thisTable)) {
      return false;
    } else if(strcasecmp(thisTable->table[pos],k) == 0) {
      free(thisTable->table[pos]);
      thisTable->table[pos] = NULL;
      return true;
    } else {
      if(pos == thisTable->size - 1) {
        pos = 0;
      } else {
        pos++;
      }
    }
  } while(pos != index);
  return false;
}

bool hashInsert(char * k, Hashtable * thisTable) {
  if(search(k,thisTable)) {
    return false;
  }
  int index = hash(k);
  int pos = index;
  

  do {
    if(isNull(pos,thisTable)) {
      thisTable->table[pos] = (char *) malloc(sizeof(char) * 12);
      strcpy(thisTable->table[pos],k); 
      return true;
    } else {
      if(pos == thisTable->size - 1) {
	pos = 0;
      } else {
	pos++;
      }
    }
  }while(pos != index);	  
  return false;
}  

bool isNull(int index, Hashtable* thisTable) {
  return thisTable->table[index] == NULL;
}

/*bool search(char * k, Hashtable * thisTable) {
  return indexSearch(k,thisTable) != -1;
  } */

bool search(char * k, Hashtable * thisTable) {
  int i;
  for(i = 0; i < thisTable->size;i++) {
    if(thisTable->table[i] && strcasecmp(thisTable->table[i], k) == 0) {
      return true;
    } 
  }
  return false;
}

  

