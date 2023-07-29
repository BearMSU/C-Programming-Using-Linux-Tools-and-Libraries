// Activity: read numbers from a file (course solution)
#include <stdio.h>

int main(void) {
	FILE *ifile;  
	int i, N, grade, sum;
	double average;
	
	sum = 0;
	
	ifile = fopen("studentGrades.txt", "r"); 
	
	fscanf(ifile, "%d", &N); 
	
	for (i = 0; i<N; i++) {
		fscanf(ifile, "%d", &grade);
		sum += grade;
	}
	
	fclose(ifile); 
	average = (double) sum / N;
	printf("%.2lf\n", average);
	
	return 0;
}
