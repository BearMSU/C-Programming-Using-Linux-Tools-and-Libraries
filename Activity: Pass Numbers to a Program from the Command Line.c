#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h> // for atoi and atof

int main(int argc, char *argv[]) {
	int amt;
	double price;
	double total;
	
	if (argc == 3) {
		amt = atoi(argv[1]);
		price = atof(argv[2]);
		total = amt * price;
		printf ("%d plants for %.2lf dollars each cost %.2lf dollars\n", amt, price, total);
	}
	else
	{
		printf("Invalid input.");
	}
	
	return 0;
}
