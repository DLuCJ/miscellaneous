#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dlist.h"
#include <string.h>
#include "hash.h"

int main() {

  Hashtable * newTable = makeTable(10);

  hashInsert(5,newTable);
  hashInsert(3,newTable);
  hashInsert(5,newTable);
  hashListFull(newTable);
  term(newTable);
     
  return 0;
}
