// Final Project: Find the radius of a star (Course Solution)

#include <stdio.h>
#include <math.h>

#define Tsun 3500.0

struct star {
    char name[50];
    int temperature;
    double luminosity;
    double radius;
    char classification;
};

void printStars(struct star mystars[], int N); 
int readStars(struct star mystars[]);
void computeRadii(struct star mystars[], int N);
void classifyStars(struct star mystars[], int N);

int main(void) {
    struct star mystars[50];
    int N;
    
    N = readStars(mystars);
    computeRadii(mystars, N);
    classifyStars(mystars, N);
    printStars(mystars, N);
        
    return 0;
}

void printStars(struct star mystars[], int N) {
    int i;
    for (i=0; i<N; i++) {
        printf("%s is a ", mystars[i].name);
        if (mystars[i].classification == 'M') {
        	printf("Main Sequence Star\n");
        } else if (mystars[i].classification == 'G') {
            printf("Giant\n");
        } else if (mystars[i].classification == 'S') {
        	printf("Supergiant\n");
        } else if (mystars[i].classification == 'W') {
        	printf("White Dwarf\n");
        } else if (mystars[i].classification == 'N') {
        	printf("Unclassified Star\n");
        } else {
        	printf(" !!! Warning: '%c' not a valid classification code!!!\n", mystars[i].classification);
        }
        printf("Temp = %d Kelvin, Lum = %.4lf Sol, Rad = %.2lf * R_Sun\n\n", mystars[i].temperature, mystars[i].luminosity, mystars[i].radius);
    }
}

void classifyStars(struct star mystars[], int N){
	double R, L;
	int i;
	char C;

	for (i=0; i<N; i++) {
		L = mystars[i].luminosity;
		R = mystars[i].radius;	
		if ((L>=0.01) && (L<=1000000.0) && (R>=0.1) && (R<=10.0)) {
			C = 'M';
		} else if ((L>=1000.0) && (L<=100000.0) && (R>=10.0) && (R<=100.0)) {
			C = 'G';
		} else if ((L>=100000.0) && (L<=1000000.0) && (R>100.0)) {
			C = 'S';
		} else if (R<=0.01) {
			C = 'W';
		} else {
			C = 'N';
		}
		mystars[i].classification = C;
	}
}

void computeRadii(struct star mystars[], int N){
	double R;
	int i, T;
	double L;
	
	for (i=0; i<N; i++) {
		T = mystars[i].temperature;
		L = mystars[i].luminosity;
		R = (Tsun/T)*(Tsun/T)*sqrt(L);	
		mystars[i].radius = R;
	}
}

int readStars(struct star mystars[]) {
	int N = 0;
	FILE *ifile;
	struct star s = {"blank", 0, 0.0, 0.0, 'N'};
	
	ifile = fopen("stardata.txt", "r");
	while (fscanf(ifile, "%s%d%lf\n", s.name, &s.temperature, &s.luminosity) != EOF) {
		mystars[N] = s;
		N++;
	}
	fclose(ifile);
