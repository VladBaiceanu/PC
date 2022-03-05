#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LUNG_NUME 20
typedef struct
  {char nume[LUNG_NUME];
   int zi,luna,an;
   char loc_nastere[LUNG_NUME];
  }PERSOANA;
intw main (void)
  { FILE *f;
    int n,i;
    PERSOANA p;
    if ((f=fopen("exemplu.dat","rb")) ==NULL)
     {printf("Fisierul %s nu poate fi deschis \n", "exemplu.dat");
      exit(1);
     }
    fseek(f,0L,2);
    n=ftell(f)/sizeof(PERSOANA);
    fseek(f,0L,0);
    for (i=1; i<=n;i++)
      {fread(&p,sizeof(PERSOANA),1,f);
       printf("%20s, %d %d %d, %20s \n",
	      p.nume,p.zi,p.luna,p.an,p.loc_nastere);
      }
    fclose(f);
    getchar();
    return 0;
  }
