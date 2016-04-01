/* Trie functions
 *
 * Author: Daniel Lu
 * Date:   3/14/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include "tree.h"

Tree * make() {
  Tree* t = (Tree *) malloc(sizeof(Tree));
  t->root = newNode(t->root);
  return t;
}

void term(Tree * d, Node * node) {
  int i;
  if(d != NULL) {
    if(node != NULL) {
      for(i = 0; i < 26; i++) {
	term(d, node->chars[i]);
      }
      free(node->chars);
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
      overflow = (strlen(val) < 1);
    }
  }
  return overflow;
}

bool isEmpty(Tree *d) {
  return (d->root == NULL);
}


void delNum(Tree *d, char * item) {

  if(!find(d,item)) {
    return;
  }

  int i;
  Node *p;
  p = d->root;
  for(i = 0; i < strlen(item); i++) {
    p = p->chars[item[i]-'a'];
  }
  p->flag = false;
}

Node * newNode(Node * head) {
  int i;
  head = malloc(sizeof (Node));
  head->chars = (Node **) malloc(26 * sizeof(Node*));
  for (i = 0; i < 26; i++) {
    head->chars[i] = NULL;
  }
  return head;
}

bool find(Tree *d, char* item) {
  if(isEmpty(d)) {
    return false;
  }

  int i;
  Node *p;
  p = d->root;
  for(i = 0; i < strlen(item); i++) {

    if(p->chars[item[i]-'a'] == NULL) {
      return false;
    }

    p = p->chars[item[i]-'a'];
  }
  if(!p->flag) {
    return false;
  } else {
    return true;
  }
}

void insert(Tree *d, Node * head, char* item) {
  if(find(d,item)) {
    return;
  }
  
  int i;
  for(i = 0; i < strlen(item); i++) {
    
    if(head->chars[item[i]-'a'] == NULL) {
      head->chars[item[i]-'a'] = newNode(head->chars[item[i]-'a']);
    }
    
    head = head->chars[item[i]-'a'];
  } 
  head->flag = true;
}

void listNode(Node * node, char * buffer, int index) {
  int i;

  if(node != NULL) {
    if(node->flag) {
      buffer[index] = 0;
      printf("%s ",buffer);
    }
    for( i = 0; i < 26; i++) {
      buffer[index] = 'a' + i;
      listNode(node->chars[i],buffer,index + 1);
    }
  }
}
void list(Tree *d) {
  char buffer[1024];
  int index = 0;
  listNode(d->root,buffer,index);
}

bool preFind(Tree * d, char * prefix) {
  int i;
  Node *p;
  p = d->root;
  for(i = 0; i < strlen(prefix); i++) {

    if(p->chars[prefix[i]-'a'] == NULL) {
      return false;
    }

    p = p->chars[prefix[i]-'a'];
  }
  return true;
}

void preList(Tree *d, char * prefix) {
  int i;
  Node * p;
  p = d->root;
  char buffer[1024];
  strcpy(buffer,prefix);
  int index = strlen(prefix);
  for(i = 0; i < strlen(prefix); i++) {
    p = p->chars[prefix[i]-'a'];
  }

  listNode(p,buffer,index);
}

