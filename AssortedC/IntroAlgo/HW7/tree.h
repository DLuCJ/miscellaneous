/* BST function definitions, including definitions for node and tree 
 * structs.
 *
 * Author: Daniel Lu
 * Date:   2/26/2014
 */


#include <stdbool.h>

typedef struct _Node {
  char * data;
  struct _Node * right;
  struct _Node * left;
  struct _Node * parent;
}Node;

typedef struct _Tree {
  Node * root;
}Tree;

Node *getNode(Tree * d, char* item);
Node * min(Node * root);
Node * findSuccessor(Node * root);
Node * findPredecessor(Node * root);
Tree * make();
void term(Tree* d,Node * node);
bool find(Tree *d, char* item);
bool delNum(Tree *d, char* item);
bool insert(Tree *d, Node* head, char* item);
void list(Tree *d, Node * node);
bool isEmpty(Tree *d);
Node * max(Node * root);
bool overflow(char * item);
Node * getPred(Tree * d, char* item);
Node * getSucc(Tree * d, char * item);


