/* BST functions, including functions to insert and delete nodes
 *
 * Author: Daniel Lu
 * Date:   2/26/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"
#include <limits.h>
#include <string.h>


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

Node * max(Node * root) {
  Node * maxnode = NULL;
  while(root!= NULL) {
    maxnode = root;
    root = root->right;
  }
  return maxnode;
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

Node * findPredecessor(Node * root) {
  if(root == NULL) {
    return NULL;
  }

  if(root->left != NULL) {
    return max(root->left);
  }
  
  Node * ancestor = root->parent;
  while(ancestor != NULL && ancestor->left == root) {
    root = ancestor;
    ancestor = ancestor->parent;
  }
  return ancestor;
}

Node * getPred(Tree *d, char* item) {
  Node * node = getNode(d,item);
  if(!find(d,item)) {
    return NULL;
  }
  return findPredecessor(node);
}

Node * getSucc(Tree *d, char * item) {
  Node * node = getNode(d,item);
  if(!find(d,item)) {
    return NULL;
  }
  return findSuccessor(node);
}

bool delNum(Tree *d, char * item) {
  
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
 
Node * getNode(Tree *d, char * item) {
  Node * node = d->root;
  while(node != NULL) {
    if(strcasecmp(node->data, item) == 0) {
      return node;
    } else if(strcasecmp(item, node->data) < 0) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
}
  
bool find(Tree *d, char* item) {
  Node * node = d->root;
  while(node != NULL) {
    if(strcasecmp(node->data, item) == 0) {
      return true;
    } else if(strcasecmp(item,node->data) < 0) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return false;
}


bool insert(Tree *d, Node * head, char* item) {
  if(isEmpty(d)) {
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = (char *) malloc(sizeof(char) * 12);
    strcpy(node->data,item);
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

  if(strcasecmp(item, parent->data) < 0) {
    if(parent->left == NULL) {
      Node * node = (Node *)malloc(sizeof(Node));
      node->data = (char *) malloc(sizeof(char) * 12);
      strcpy(node->data,item);
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
      node->data = (char *) malloc(sizeof(char) * 12);
      strcpy(node->data,item);
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
      printf("%s ", node->data);
      list(d,node->right);
    }
  }
}


