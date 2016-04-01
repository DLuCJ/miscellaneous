/* Hash table functions, including functions to make and delete hash
 * table, and the hashing algorithm
 *
 * Author: Daniel Lu
 * Date:   2/17/2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dlist.h"
#include "hash.h"
#include <limits.h>

Hashtable * makeTable(int size) {
  Hashtable * newTable = (Hashtable *) malloc(sizeof(Hashtable));
  newTable->table = (Dlist **) malloc(sizeof(Dlist *) * size);
  
  int i;
  for(i = 0; i < size; i++) {
    newTable->table[i] = NULL;
  }
  newTable->size = size;
  return newTable;
}

void hashListFull(Hashtable * thisTable) {
  int i;
  for(i = 0; i < thisTable->size; i++) {
    if(isNull(i,thisTable)) {
      printf("List #%i : empty\n",i);
    }else{
      printf("List #%i :", i);
      hashList(i, thisTable);
      printf("\n");
    }
  }
}

void term(Hashtable * thisTable) {
  int i;
  for(i = 0; i < thisTable->size; i++) {
    if(thisTable->table[i] != NULL) {
      del(thisTable->table[i]);
    }
  }
  free(thisTable->table);
  free(thisTable);
}

unsigned int hash(int k) {
  return k % 10;
}

bool hashDelete(int k, Hashtable * thisTable) {
  int index = hash(k);
  if(thisTable->table[index] == NULL) {
    return false;
  }
  
  if(delNum(thisTable->table[index],k) == 0) {
    return false;
  }
  if(thisTable->table[index]->head == NULL) {
    free(thisTable->table[index]);
    thisTable->table[index] = NULL;
  }	
  return true; 
}

bool hashInsert(int k, Hashtable * thisTable) {
  int index = hash(k);
  if(search(k, thisTable)) {
    return false;
  }
  if(thisTable->table[index] == NULL) {
    thisTable->table[index] = make(index);
  } 
  insert(thisTable->table[index], k);
  return true;
}

bool isNull(int index, Hashtable* thisTable) {
  return thisTable->table[index] == NULL;
}
void hashList(int index, Hashtable * thisTable) {
   list(thisTable->table[index]);
}

bool search(int k, Hashtable * thisTable) {
  int index = hash(k);
  if(thisTable->table[index] != NULL) {
    int position = find(thisTable->table[index], k);
    if(position == 0) {
      return false;
    } else {
      return true;
    }
  } else {
    return false;
  }
}


