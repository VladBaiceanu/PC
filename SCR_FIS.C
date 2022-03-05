#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LUNG_NUME 20
typedef struct
  {char nume[LUNG_NUME];
   int zi,luna,an;
   char loc_nastere[LUNG_NUME];
  }PERSOANA;

int main(void)
  {FILE *f;
   int n,i;
   PERSOANA p;
   if ((f=fopen("exemplu.dat","wb")) ==NULL)
     {printf("Fisierul %s nu poate fi deschis \n", "exemplu.dat");
      exit(1);
     }
   printf("introduceti date de la tastatura:\n");
   printf("Cate persoane inregistrati?: ");
   scanf("%d", &n);
   for (i=1; i<=n;i++)
     { printf("persoana %d\n", i);
       printf("numele=");
       fflush(stdin);
       gets(p.nume);
       printf("zi-luna-an nastere=");
       scanf("%d%d%d", &p.zi, &p.luna, &p.an);
       printf("loc nastere=");
       fflush(stdin);
       gets(p.loc_nastere);
       fwrite(&p, sizeof(PERSOANA),1,f);
     }
   fclose(f);
   return 0;
  }
