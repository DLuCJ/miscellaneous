/* Hash table function definitions, and definition for the table struct
 *
 * Author: Daniel Lu
 * Date:   2/17/2014
 */


typedef struct _HashTable {
  int size;
  Dlist ** table;
} Hashtable;

bool hashInsert(int k, Hashtable * thisTable);
bool hashDelete(int k, Hashtable * thisTable);
bool search(int k, Hashtable * thisTable);
bool isNull(int k, Hashtable * thisTable);
void hashList(int index, Hashtable * thisTable);
void hashListFull(Hashtable * thisTable);
void term(Hashtable * thisTable);
Hashtable* makeTable(int size);
unsigned int hash(int k);
