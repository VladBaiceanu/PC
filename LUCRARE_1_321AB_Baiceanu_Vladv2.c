//Baiceanu Vlad Stefan 321AB

#include <stdio.h>
#include <stdlib.h>

int Element_dominant(int n, int v[])
{
    int maxx = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > maxx)
        {
            maxx = v[i];
        }
    }

    int *flag;
    flag = (int *)malloc(maxx * sizeof(int));
    for (int i = 0; i < maxx; i++)
    {
        flag[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        flag[v[i]]++;
    }

    for (int i = 0; i < maxx; i++)
    {
        if (flag[i] > n / 2)
        {
            return i;
        }
    }

    return -1;
}

int *Matrice_dominanta(int **matrix, int m, int n)
{

    int *aux;
    aux = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        aux[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        aux[i] = Element_dominant(m, matrix[i]);
    }

    return aux;
}

int main()
{

    int m, n;

    printf("Se citeste m: ");
    scanf("%d", &m);
    int **a;

    printf("Se citeste n: ");
    scanf("%d", &n);

    a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d]= ", i, j);
            scanf("%d", &a[i][j]);
        }

    int *v;
    v = Matrice_dominanta(a, m, n);

    for (int i = 0; i < m; i++)
    {
        printf("%d\n", v[i]);
    }


    printf("Vectorul dominant este: ");

    for (int i = 0; i < m; i++)
    {
        if(v[i] == -1){
            printf(" Nu exista element dominant (pozitia %d) ",i);
        }

        else{
            printf(" %d ",v[i]);
        }
    }
    return 0;
}