// Actvitiy: use the math library
// My solution (course solution is the same)
#include <stdio.h>
#include <math.h>


int main(void) {
	int num;
	double root;
	double e;
	scanf("%d", &num);
	root = sqrt(num);
	e = exp(1);
	printf("%.8lf\n", root);
	printf("%.10lf\n", e);
	printf("gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.c -lm -o program\n");
  return 0;
}
