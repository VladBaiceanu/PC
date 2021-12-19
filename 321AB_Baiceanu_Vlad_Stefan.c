//Baiceanu Vlad Stefan 321AB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct caracteristici{
    char tip[10];
    char categorie[2];
    float suprafata;
};
struct proprietate{
    char strada[20];
    int nr;
    struct caracteristici caracteristici;

};
float *citire(int n, struct proprietate *vector){
   float * impozite;
   struct proprietate aux;
   impozite=(float*)malloc(n*sizeof(float));
   for(int i=0; i<n; i++){
       fflush(stdin);
       printf("Strada: ");
       gets(aux.strada);
       fflush(stdin);
       printf("Numarul imobilului:");
       scanf("%d",&aux.nr);
       fflush(stdin);
       printf("Tip proprietate(casa/curte)");
       gets(aux.caracteristici.tip);
       fflush(stdin);
       while(strcmp(aux.caracteristici.tip,"casa")!=0 && strcmp(aux.caracteristici.tip,"curte")!=0 ){
           printf("TIP INCORECT, REINTRODUCETI TIPUL:");
           gets(aux.caracteristici.tip);
           fflush(stdin);
       }
       printf("Categorie:");
       gets(aux.caracteristici.categorie);
       fflush(stdin);
       while(strcmp(aux.caracteristici.categorie,"A")!=0 && strcmp(aux.caracteristici.categorie,"B")!=0 && strcmp(aux.caracteristici.categorie,"C")!=0)
       {   printf("CATEGORIE INCORECTA, REINTRODUCETI CATEGORIA:");
           gets(aux.caracteristici.categorie);
           fflush(stdin);
       }
      printf("Suprafata:");
       scanf("%f", &aux.caracteristici.suprafata);
       fflush(stdin);

       vector[i]=aux;
   }

     for(int i=0; i<n; i++)
         for(int j=i+1; j<n; j++){
             if(strcmp(vector[i].strada,vector[j].strada)==0 && vector[i].nr==vector[j].nr){
                 strcpy(vector[j].strada,"DUPLICAT"); //am marcat ca este duplicat;
                 vector[j].nr=0;
                 vector[j].caracteristici.suprafata=0;
             }
         }
     for(int i=0; i<n; i++){
           float CAT;
           float TIP;
           if( strcmp(vector[i].caracteristici.categorie,"A")==0)
               CAT=1.25;
           if( strcmp(vector[i].caracteristici.categorie,"B")==0)
               CAT=0.85;

           if( strcmp(vector[i].caracteristici.categorie,"C")==0)
               CAT=0.6;
           if(strcmp(vector[i].caracteristici.tip,"casa")==0)
               TIP=1;
           if(strcmp(vector[i].caracteristici.tip,"curte")==0)
              TIP=0.33;

           impozite[i]=TIP*CAT*vector[i].caracteristici.suprafata;
     }

     return impozite;
}

struct proprietate *suprafmic(int nrInreg, int *nrSupraf, struct  proprietate* vector){
    *nrSupraf=0;
    float min;
    for(int i=0; i<nrInreg;i++){
        if(vector[i].caracteristici.suprafata<min && strcmp(vector[i].strada,"DUPLICAT")!=0)
            min=vector[i].caracteristici.suprafata;
    }
      int count=0;
     for(int i=0; i<nrInreg;i++){
         if(min==vector[i].caracteristici.suprafata)
             count++;
     }
     *nrSupraf=count;
    struct proprietate *ret;
     ret=(struct proprietate*)malloc(count*sizeof(struct proprietate));
     int j=0;
     for(int i=0;i<nrInreg;i++){
        if(vector[i].caracteristici.suprafata==min) {
            ret[j]=vector[i];
            j++;
        }
     }
         return ret;
}


int main() {
    int n;
    printf("Dati numarul de proprietati:");
    scanf("%d",&n);
    fflush(stdin);
    struct proprietate *vect;
    vect=(struct proprietate* )malloc(n*sizeof (struct proprietate));
    float *impozite;
    impozite= citire(n,vect);
    float maxImpozite=0;
    for(int i=0; i<n;i++){
        if(impozite[i]>maxImpozite)
            maxImpozite=impozite[i];
    }
    for(int i=0; i<n; i++){
        if(impozite[i]==maxImpozite){
            printf("Strada: %s\n", vect[i].strada);
            printf("Numarul: %d\n", vect[i].nr);
        }//de cate ori imi gaseste impozitul maxim il afiseaza;

    }
  struct proprietate *strazile;
    int* nrStrazi;
    strazile= suprafmic(n,&nrStrazi,vect);

     return 0;
}