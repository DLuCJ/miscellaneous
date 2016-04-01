/* BST function definitions, including definitions for node and tree 
 * structs.
 *
 * Author: Daniel Lu
 * Date:   2/20/2014
 */


#include <stdbool.h>

typedef struct _Node {
  int data;
  struct _Node * right;
  struct _Node * left;
  struct _Node * parent;
}Node;

typedef struct _Tree {
  Node * root;
}Tree;

Node *getNode(Tree * d, int item);
Node * min(Node * root);
Node * findSuccessor(Node * root);
Tree * make();
void term(Tree* d,Node * node);
bool find(Tree *d, int item);
bool delNum(Tree *d, int item);
bool insert(Tree *d, Node* head, int item);
void list(Tree *d, Node * node);
bool isEmpty(Tree *d);
bool overflow(long long val);
