// Activity: write numbers to a file (my solution)
// Solution currently gets marked incorrect even though it works.
// Still testing
#include <stdio.h>

int main(void) {
	FILE *ifile;
	int grade, newGrade;
	
	scanf("%d", &newGrade);
	
	ifile = fopen("myGrades.txt", "r");
	
	while (fscanf(ifile, "%d", &grade) != EOF);
	fclose(ifile);
	
	if (grade!=newGrade) {
		ifile = fopen("myGrades.txt", "a");
		fprintf(ifile, " %d", newGrade);
		fclose(ifile);
	}
	ifile = fopen("myGrades.txt", "r");
        while (fscanf(ifile, "%d", &grade) != EOF){
                printf("%d ", grade);
        }
        fclose(ifile);

	return 0;
}
