#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Citire_vector(int *n, float **medie){
    printf("Numar studenti: ");
    scanf("%d",n);
    *medie = (float*)malloc(*n * sizeof(float));

    for(int i = 0; i < *n; i++){
        printf("Medie student: ");
        scanf("%f",(*medie) + i);
    }
} 

void Citire_extinsa(int *n, float **medie){
    *medie = (float*)realloc(*medie,((*n) + 2) * sizeof(float));

    for(int i = *n; i < *n + 2; i++){
        printf("Medie student: ");
        scanf("%f",(*medie) + i);
    }
}


int main(){

    int n, count = 0;
    float *medie;

    Citire_vector(&n,&medie);
    Citire_extinsa(&n,&medie);

    for(int i = 0; i < n + 2; i++){
        if(medie[i] > 9.5){
            count++;
        }
    }

    printf("/n Nr elevi peste 9.5: %d ",count);

}