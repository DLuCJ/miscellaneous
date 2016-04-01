
#include <stdbool.h>
/*This file includes function definitions for 
 *the stack functions and a struct to store information
 *for initializing and traversing the stack.
 *
 * Author: Daniel Lu
 * Date:   1/14/2014
 */


typedef struct _Stack {
  int * stack;
  int place;
  int SIZE;
}Stack;

Stack* _make(int size);
void _del(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
int push(Stack * s, int item);
int pop(Stack * s);
void list(Stack * s);


