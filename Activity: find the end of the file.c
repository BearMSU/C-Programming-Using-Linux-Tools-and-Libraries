// Activity: find the end of the file (my solution)
#include <stdio.h>

int main(void) {
	FILE *ifile;
	double currentGrade, otherGrade;
	double bestGrade = 0;
	int classNumber = 1;
	
	ifile = fopen("gradeComparison.txt", "r");
	
	fscanf(ifile, "%lf", &currentGrade);
	while (fscanf(ifile, "%lf", &otherGrade) != EOF) {
		if (otherGrade > bestGrade) {
			bestGrade = otherGrade;
			classNumber++;
		}
	}
	
	if (currentGrade > bestGrade) {
		printf("Yes\n");
	} else {
		printf("No %d\n", classNumber);
	}
	
	return 0;
}
