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
void print_us_bills(int d_amt);

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

	/* US dollar bills */
	int us_d;
	printf("Enter a U.S. dollar amount (integer) and I will tell you the partition of US bills required: ");
	scanf("%d", &us_d);
	print_us_bills(us_d);

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

void print_us_bills(int d_amt){
	int num_20, num_10, num_5, num_1;
	num_20=0; num_10=0; num_5=0; num_1=0;
  
  /* 20s */
  num_20 = d_amt/20;
  d_amt -= num_20*20;
	printf("$20 bills: %d\n", num_20);
  
  /* 10s */
  num_10 = d_amt/10;
  d_amt -= num_10*10;
	printf("$10 bills: %d\n", num_10);

  /* 5s */
  num_5 = d_amt/5;
  d_amt -= num_5*5;
	printf("$5 bills: %d\n", num_5);

  /* 1s */
  num_1 = d_amt;
	printf("$1 bills: %d\n", num_1);
}
