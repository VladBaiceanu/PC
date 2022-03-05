#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LUNG_NUME 20
typedef struct
  {char nume[LUNG_NUME];
   int zi,luna,an;
   char loc_nastere[LUNG_NUME];
  }PERSOANA;
typedef struct
  { int index;
    char cheie[LUNG_NUME];
  }INDEX;

int constr_tablou_index (FILE *fis, INDEX tabl[], int nr_max)
  { /*citeste componentele din fisierul dat, extrage chei (nume),
      returneaza nr. componente gasite*/
    int nr_gasite=0;
    int depl=0; /*pt. trecerea la componenta urmatoare*/
    int k;
    fseek(fis, 0L,SEEK_END);
    nr_gasite=ftell(fis)/sizeof(PERSOANA);
    fseek(fis,0L,SEEK_SET);
    for (k=0; k<nr_gasite && nr_gasite<nr_max;k++)
       { tabl[k].index=k; /*se completeaza cp. indice*/
	 fgets(tabl[k].cheie, LUNG_NUME,fis);
	 depl += sizeof(PERSOANA);
	 fseek(fis, depl, SEEK_SET);
       }
    return nr_gasite;
  }

/*compara 2 elemente de tip INDEX*/
int compara (const void * a, const void *b)
  { return strcmp (((INDEX *)a)->cheie,((INDEX *)b)->cheie);
  }

/*sorteaza tabloul index ce are "nr" elemente cu "QSORT"*/
void sort_tablou (INDEX tabl[], int nr)
  { qsort(tabl,nr,sizeof(INDEX),compara);
  }

/*citeste inf. din fis. original si le scrie pe ecran in
  ordinea indicata de tabloul index sortat cnform criteriului
  stabilit*/
void scrie_inf_din_fisier (FILE *fis, INDEX tabl[], int val_max_indice)
  { PERSOANA p;
    int k;
    for(k=0; k < val_max_indice; k++)
      {if (fseek(fis,sizeof(PERSOANA)*tabl[k].index,0))
	 exit(1);
       fread(&p,sizeof(PERSOANA),1,fis);
       printf("%20s, %d %d %d, %20s \n",p.nume,p.zi,p.luna,p.an,p.loc_nastere);
      }
  }

/*functia "main"*/
#define NR_MAX_COMPONENTE 100
int main (void)
  {FILE * fisier;
   INDEX tabl[NR_MAX_COMPONENTE];
   int nr_inreg_citite;
   if ((fisier=fopen("exemplu.dat","rb")) ==NULL)
      {printf("Fisierul %s nu poate fi deschis \n", "exemplu.dat");
       exit(1);
      }
   nr_inreg_citite=constr_tablou_index (fisier,tabl,NR_MAX_COMPONENTE);

   sort_tablou(tabl,nr_inreg_citite);
   scrie_inf_din_fisier(fisier,tabl,nr_inreg_citite);
   getchar();
   return 0;
  }
