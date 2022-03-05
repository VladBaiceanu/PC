#include <stdlib.h>

int main()
{
    int n, m, **v;

    scanf("%d",&n);
    scanf("%d",&m);

    v=(int**)malloc(n*sizeof(int*));

    //Citire
    for(int i=0;i<n;i++)
    {
        v[i] = (int*)malloc(m*sizeof(int));
        for(int j =0;j<m;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }

    //Chestii


    //Afisare
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }

    //Eliberare memorie
    for(int i=0;i<n;i++)
    {
        free(v[i]);
    }
    free(v);

    return 0;
}
