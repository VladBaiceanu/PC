#include <stdlib.h>

int main()
{
    int n, *v;

    scanf("%d",&n);

    v=(int*)malloc(n*sizeof(int));

    //Citire
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }

    //v=realloc(v,n*sizeof(int));

    //Afisare
    for(int i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }

    //Eliberare memorie
    free(v);

    return 0;
}
