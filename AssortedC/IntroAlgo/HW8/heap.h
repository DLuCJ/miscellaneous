/* Heap sort function definitions 
 * 
 *
 * Author: Daniel Lu
 * Date:   3/3/2014
 */


#include <stdbool.h>

int * make(char **, int);
void term(int* n);
void list(int *nums, int size);
bool overflow(long long val);
void heapify(int * n, int i, int heapsize);
void swap(int * a, int * b);
void buildHeap(int * nums, int size);
void sort(int * nums, int size);
