#include <stdio.h>
#include <stdlib.h>

void citire(float **v, int *n)
{
    printf("Numarul de studenti: ");
    scanf("%d", n);
    *v = (float *)calloc(*n, sizeof(float));

    for (int i = 0; i < *n; i++)
    {

        printf("Media studentului %d : ", i + 1);
        scanf("%f", (*v) + i);
    }
}

void citire_extinsa(float **v, int *n)
{
    *n += 2;
    *v = (float *) realloc(*v, (*n) * sizeof(float));

    for (int i = *n - 2; i < *n; i++)
    {
        printf("Media studentului %d : ", i + 1);
        scanf("%f", (*v) + i);
    }
}

int main()
{
    int n, numarStud = 0;
    float *v;

    citire(&v, &n);
    citire_extinsa(&v, &n);

    for (int i = 0; i < n; i++) {
        printf("%lf ", v[i]);

        if (v[i] > 9.50)
            numarStud++;
    }

    printf("\nNumar de studenti care au media mai mare decat 9.50: %d", numarStud);
}
