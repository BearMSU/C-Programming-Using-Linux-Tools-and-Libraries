// Activity: find the end of the file (course solution)
#include <stdio.h>

int main(void) {
	FILE *ifile;
	int N, done, best;
	double myClass, otherClass;
	
	ifile = fopen("gradeComparison.txt", "r");
	
	fscanf(ifile, "%lf", &myClass);
	N=1;
	done = 0;
	best = 1;
	
	while (!done) {
		done = fscanf(ifile, "%lf", &otherClass) == EOF;
		if (!done) {
			N++;
			if (otherClass>myClass) {
				done = 1;
				best = 0;
			}
		}
	}
	
	fclose(ifile);
	
	if (best) {
		printf("Yes\n");
	} else {
		printf("No %d\n", N);
	}
	
	return 0;
}
