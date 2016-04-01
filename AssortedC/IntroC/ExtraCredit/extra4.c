/* This program calculates the distance between the two points 
 * and prints out said distance on the screen. 
 * 
 * Author: Daniel Lu
 * Date: 12/4/2013
 */

#include <stdio.h>
#include <math.h>

typedef struct point {
  float x;
  float y;
} POINT;

float distance (POINT p1, POINT p2);
void enter_a_point (POINT *p);

int main(void) {
  POINT p1, p2;
  enter_a_point(&p1); //get x & y values for first point
  enter_a_point(&p2); //get x & y values for second point
  printf( "Distance between the points = %.2f\n", distance(p1 , p2 ));

  return 0;
}

float distance (POINT p1, POINT p2) {
  return sqrt( pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2) );
}

void enter_a_point (POINT *p) {
  printf("\nEnter an X coordinate: ");
  scanf("%f", &(p->x));
  
  printf("\n Enter a y coordinate: ");
  scanf("%f", &(p->y));
}
