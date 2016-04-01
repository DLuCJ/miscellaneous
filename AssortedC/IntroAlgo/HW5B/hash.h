

/* Hash table function definitions, and definition for the table struct
 *
 * Author: Daniel Lu
 * Date:   2/17/2014
 */


typedef struct _HashTable {
  int size;
  char ** table;
} Hashtable;

int indexSearch(char * k, Hashtable * thisTable);
bool hashInsert(char * k, Hashtable * thisTable);
bool hashDelete(char * k, Hashtable * thisTable);
bool search(char * k, Hashtable * thisTable);
bool isNull(int index , Hashtable * thisTable);
void hashListFull(Hashtable * thisTable);
void term(Hashtable * thisTable);
Hashtable* makeTable(int size);
unsigned int hash(char * k);
