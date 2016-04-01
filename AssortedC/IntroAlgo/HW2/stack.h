
/* Function definitions for stack functions, and definition for Stack struct
 *
 * Author: Daniel Lu
 * Date:   1/22/2014
 */

#include <stdbool.h>

typedef struct _Stack {
  int * stack;
  int place;
  int SIZE;
}Stack;

Stack *  _make(int size);
void _del(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
int push(Stack * s, int item);
int pop(Stack * s);
void list(Stack * s);
