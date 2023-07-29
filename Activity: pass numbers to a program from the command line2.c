// Course answer
#include <stdio.h>
#include <stdlib.h> // for atoi and atof

int main(int argc, char *argv[]) {
	int numberOfPlants;
	double pricePerPlant, cost;
	
	if (argc!=3) {
		printf("Invalid input.\n");
	} else {
		numberOfPlants = atoi(argv[1]);
		pricePerPlant = atof(argv[2]);
		cost = numberOfPlants*pricePerPlant;
		printf("%d plants for %.2lf dollars each cost %.2lf dollars.\n", numberOfPlants, pricePerPlant, cost);
	}
	return 0;
}
