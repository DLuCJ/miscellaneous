/* Function definitions for stack functions, and definition for Stack struct
 *
 * Author: Daniel Lu
 * Date:   1/29/2014
 */

#include <stdbool.h>


typedef struct _Node {
  int data;
  struct _Node * next;
  struct _Node * prev;
}Node;

typedef struct _Stack {
  Node * head;
  int size;
}Stack;

Stack *  _make();
void _del(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
int push(Stack * s, int item);
int pop(Stack * s);
void list(Stack * s);
int peek(Stack *s);
