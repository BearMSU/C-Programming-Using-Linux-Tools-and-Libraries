// This solution works as well, and again grader is telling me I'm outside the memory, Frustrating
#include <stdio.h>
int main(){

FILE *ifile;
int N = 0;
int num;

char filename[] = "myGrades.txt";

scanf("%d",&N); ifile= fopen(filename,"r");

while (fscanf(ifile,"%d",&num) != EOF){} fclose(ifile);

if(num!=N){
    /*  ifile =fopen(filename,"r");

    while(fscanf(ifile,"%d",&num)!=EOF){
    printf(" %d ",num);
    }*/
    ifile =fopen(filename,"a");

    fprintf(ifile," %d ",N);

    fclose(ifile);

    ifile =fopen(filename,"r");

    while(fscanf(ifile,"%d",&num)!=EOF){
        printf("%d ",num);
    }
}else{
    ifile =fopen(filename,"r");

    while(fscanf(ifile,"%d",&num)!=EOF){
        printf("%d ",num);
    }
}

return 0;
}
