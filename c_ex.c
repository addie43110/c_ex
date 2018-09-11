/* A collection of exercises from the book C Programming: A Modern Approach by K. N. King
  Taken from Chapter 2
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> /* for pi */

/* declare functions before they are used in main here */
float volume_of_sphere(int radius);



void printCheck() {
	printf("        *\n");
	printf("       *\n");
	printf("      *\n");
	printf("*    *\n");
	printf(" *  *\n");
	printf("  **\n");
}

int main(void) {
  /*print check */
	printCheck();
  /* volume of a sphere */
  int radius;
  printf("Enter a radius (integer): ");
  scanf("%d", &radius);
  printf("Volume of sphere with %d radius: %f\n", radius, volume_of_sphere(radius));

	return 0;
}


float volume_of_sphere(int radius){
  return 4.0/3.0*M_PI*radius*radius*radius;
}
