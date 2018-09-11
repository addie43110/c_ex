/* A collection of exercises from the book C Programming: A Modern Approach by K. N. King
  Taken from Chapter 2
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> /* for pi */

/* declare functions before they are used in main here */
void printCheck();
float volume_of_sphere(int radius);
float add_5_tax(float amount);

int main(void) {
  /*print check */
	printCheck();
  /* volume of a sphere */
  int radius;
  printf("Enter a radius (integer): ");
  scanf("%d", &radius);
  printf("Volume of sphere with %d radius: %f\n", radius, volume_of_sphere(radius));
	printf("Enter a price and I will calculate the tax (##.##): ");
	float price;
	scanf("%f", &price);
	printf("Plus 5%% tax yields: $%.2f\n", add_5_tax(price));
	return 0;
}

void printCheck() {
	printf("        *\n");
	printf("       *\n");
	printf("      *\n");
	printf("*    *\n");
	printf(" *  *\n");
	printf("  **\n");
}

float volume_of_sphere(int radius){
  return 4.0/3.0*M_PI*radius*radius*radius;
}

float add_5_tax(float amount){
	return  amount*1.05;
}
