/* BST functions, including functions to insert and delete nodes
 *
 * Author: Daniel Lu
 * Date:   2/20/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"
#include <limits.h>


Tree * make() {
  Tree* t = (Tree *) malloc(sizeof(Tree));
  t->root = NULL;
  return t;
}

void term(Tree * d, Node * node) {
  if(d != NULL) {
    if(node != NULL) {
      term(d,node->left);
      term(d,node->right);
      free(node);
    }
  }
}

bool overflow(long long val) {
  bool overflow = val > 999 || val < 0;
  if(overflow) {
    printf("Error: integer overflow\n");
  }
  return overflow;
}

bool isEmpty(Tree *d) {
  return (d->root == NULL);
}

Node * min(Node * root) {
  Node * minnode = NULL;
  while(root != NULL) {
    minnode = root;
    root = root->left;
  }
  
  return minnode;
}

Node * findSuccessor(Node * root) {
  if(root == NULL) {
    return NULL;
  }

  if(root->right != NULL) {
    return min(root->right);
  }

  Node * ancestor = root->parent;
  while(ancestor != NULL && ancestor->right == root) {
    root = ancestor;
    ancestor = ancestor->parent;
  }
  return ancestor;
}

bool delNum(Tree *d, int item) {
  
  if(isEmpty(d)) {
    return false;
  }
  Node * node = getNode(d,item);
  if(!find(d, item)) {
    return false;
  }

  Node * successor = NULL;
  Node * x = NULL;
  
  if(node->left != NULL && node->right != NULL) {
    successor = findSuccessor(node);
  } else {
    successor = node;
  }

  if(successor->left != NULL) {
    x = successor->left;
  }else {
    x = successor->right;
  }

  if(x!= NULL) {
    x->parent = successor->parent;
  }
  
  if(successor->parent == NULL) {
    d->root = x;
  } else {
    if(successor == successor->parent->left) {
      successor->parent->left = x;
    } else {
      successor->parent->right = x;
    }
  }
  
  if(successor != node) {
    node->data = successor->data;
  }
  free(successor);
  return true;
}
 
Node * getNode(Tree *d, int item) {
  Node * node = d->root;
  while(node != NULL) {
    if((node->data == item)) {
      return node;
    } else if(item < node->data) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
}
  
bool find(Tree *d, int item) {
  Node * node = d->root;
  while(node != NULL) {
    if((node->data == item)) {
      return true;
    } else if(item < node->data) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return false;
}


bool insert(Tree *d, Node * head, int item) {
  if(isEmpty(d)) {
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = item;
    node->right = NULL;
    node->left = NULL;
    node->parent = NULL;
    d->root = node;
    return true;
  }

  if(find(d,item)) {
    return false;
  }

  Node * parent = head;

  if(item < parent->data) {
    if(parent->left == NULL) {
      Node * node = (Node *)malloc(sizeof(Node));
      node->data = item;
      node->right = NULL;
      node->left = NULL;
      parent->left = node;
      node->parent = parent;
    } else {
      insert(d,parent->left,item);
    }
  } else {
    if(parent->right == NULL) {
      Node * node = (Node *)malloc(sizeof(Node));
      node->right = NULL;
      node->left = NULL;
      node->data = item;
      parent->right = node;
      node->parent = parent;
    } else {
      insert(d,parent->right,item);
    }
  }
  return true;
}

void list(Tree *d, Node * node) {
  if(d != NULL) { 
    if(node != NULL) {
      list(d,node->left);
      printf("%i ", node->data);
      list(d,node->right);
    }
  }
}


