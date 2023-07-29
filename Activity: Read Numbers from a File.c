// Activity: read numbers from a file (my solution)

#include <stdio.h>

int main(void) {
	FILE *ifile;  /* ifile is a variable name - you could use any other name here.
	However, the '*' is important - we are working with a pointer.
	We call this a file pointer. */
	int i, grade, N;
	double avg;
	double total = 0;
	
	
	ifile = fopen("studentGrades.txt", "r"); /* open file for reading.
	The "r" stands for reading. */
	
	fscanf(ifile, "%d", &N); // Read first number in file
	
	for (i = 0; i<N; i++) {
		fscanf(ifile, "%d", &grade);
		total += grade;
	}
	avg = total/N;
	printf("%.2lf\n", avg);
	fclose(ifile); /* closes the file */
	return 0;
}
