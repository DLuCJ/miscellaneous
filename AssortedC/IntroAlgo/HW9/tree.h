/*Trie function definitions, including definitions for node and trie 
 * structs.
 *
 * Author: Daniel Lu
 * Date:   3/14/2014
 */


#include <stdbool.h>

typedef struct _Node {
  bool flag;
  struct _Node ** chars;
}Node;

typedef struct _Tree {
  Node * root;
}Tree;


void preList(Tree * d, char * prefix);
bool preFind(Tree * d, char * prefix);
bool find(Tree *d, char* item);
Tree * make();
void term(Tree* d,Node * node);
void delNum(Tree *d, char* item);
void insert(Tree *d, Node* head, char* item);
void list(Tree *d);
void listNode(Node * node, char * buffer, int index);
bool isEmpty(Tree *d);
Node * newNode(Node * head);
bool overflow(char * item);



