## Final project: Find the radius of a star

### Statement:

Finding the radius of a star is not as easy as simply measuring it. In fact, the radius is calculated from other data that is measured, namely the star's brightness (also called luminosity) and its surface temperature. More precisely, the surface temperature cannot be directly measured either but is itself computed, but let's not go there here.

You are given a file, stardata.txt, with star data: Each line of the file starts with the name of a star (a string), followed by the star's temperature (in Kelvin), followed by the star's luminosity (measured in terms of the Sun's luminosity).

Here are **two sample** lines from the file stardata.txt:

    Vega 9600 50
    Sirius_B 25000 0.0295

Your first task is to write a function which reads this data into an array of structures, with the structure declaration and function call already given to you in the provided code. The function needs to return an integer, namely the number of stars read and stored in the array.

You next task is to write a function that computes the radius of each star in this array (in terms of the Sun's radius) and stores this radius in the appropriate location in the array of structures. The formula to compute a star's radius (in terms of the Sun's radius) is

$R = (Ts/T)^2 * \sqrt{L}$,

where TS=3500 is the temperature (in Kelvin) of the sun, T is the temperature of the star and L is the luminosity of the star in terms of the Sun's luminosity. 

Your final task is to write a function which classifies each star in the array of structures as from the Main Sequence (store an 'M' in the appropriate location in the structure), a Giant ('G'), a Supergiant ('S'), or a White Dwarf ('W'). If a star falls into neither of these categories store an 'N' in the appropriate location.

Here are the classification rules (note that these are not exactly what astronomers use, but it's good enough for our purposes):

Main Sequence (M): 
Luminosity between 10-2 and 106 times that of the sun;
Radius between 0.1 and 10 times that of the sun.

Giants (G):  
Luminosity between 103 and 105 times that of the sun;
Radius between 10 and 100 times that of the sun.

Supergiants (S):
Luminosity between 105 and 106 times that of the sun;
Radius greater than 100 times that of the sun.

White Dwarfs (W):
Radius less than 0.01 times that of the sun.

Neither (N):
Anything else

You are given the structure declaration along with a main() function and a printStars() function. Do not modify any of these. Your job is to write the three functions which are called within the main() function.

In case you modify it by mistake and wish to revert your code:

    #include <stdio.h>
    // add additional header files here

    struct star {
        char name[50];
        int temperature;
        double luminosity;
        double radius;
        char classification;
    };

    void printStars (struct star mystars[], int N);
    // add your prototypes here

    // Do not modify the main() function!
    int main(void) {
        struct star mystars[50];
        int N;

        N = readStars(mystars);
        computeRadii(mystars, N);
        classifyStars(mystars, N);
        printStars(mystars, N);

        return 0;
    }

    // Do not modify the printStars() function!
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
                printf("Uclassified Star\n");
            } else {
                printf(" !!! Warning: '%c' not a valid classification code!!!\n", mystars[i].classification);
            }
            printf("Temp = %d Kelvin, Lum = %.41lf Sol, Rad = %.2lf * R_Sun\n\n", mystars[i].temperature, mystars[i].luminosity, mystars[i].radius);
        }
    }

    // add the function readStars(), computeRadii() and classifyStars() here.
