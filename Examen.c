#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Baiceanu Vlad 321AB
typedef struct{
    char denumire[15];
    float cantitate;
}Reteta;
//in main FILE *f = fopen("camara.bin", "rb+");
void citire_camara(FILE *f, char cumparaturi_main[][][],char avertizari_main[]){   // fisierul binar de forma: denumire(string) cantitate(float)
    fseek(f,SEEK_END);
    int n = ftell(n)/Reteta;
    rewind(f);
    Reteta *v = (Reteta*) malloc(sizeof(Reteta)*n);
    fread(v, sizeof(Reteta), n, f);
    int m;
    printf("Introdu numar ingrediente pentru reteta: ");
    scanf("%d", &m);
    fflush(stdin);
    char ingrediente[m][15];
    int ingrediente_cantitati[m];
    char buff[15];
    float buff_cantitate[m];
    for(int i = 0; i < m; i++){
        printf("ingredientul nr %d\n", i+1);
        scanf("%s", buff);
        strcpy(ingrediente[i],buff);
        fflush(stdin);
        printf("Cantitatea ingredientului\n\n");
        scanf("%f", buff_cantitate[i]);
        fflush(stdin);
    }

    int count = 0;
    int not_found = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(strcmp(v[i].denumire, ingrediente[j]) == 0 || v[i].cantitate == buff_cantitate[j]){
                count++;
            }
            else{
                not_found++;
            }
        }
    }
    char **tablou_avertizare = (char**)malloc(count*sizeof(char*));
    char ***tablou_cumaparaturi = (char***) malloc(not_found* sizeof(char*));
    float buff2[not_found];
    int k = 0;
    int l = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(strcmp(v[i].denumire, ingrediente[j]) == 0 || v[i].cantitate == buff_cantitate[j]){
                    tablou_avertizare[i] = (char*)malloc(strlen(ingrediente[j])*sizeof(char));
                    strcpy(tablou_avertizare[k], ingrediente[j];
                    k++;

            }
            else{
                buff2[l] = buff_cantitate[j];
                tablou_cumaparaturi[l] = (char*)malloc(strlen(ingrediente[j]) * sizeof(char));
                strcpy(tablou_cumaparaturi[l], ingrediente[j];
                tablou_cumaparaturi[l][strlen(ingrediente[j])][] = (float**) malloc(sizeof(float));
                tablou_cumaparaturi[l][strlen(ingrediente[j])][0] = buff2[j];
            }
        }
    }
    strcpy(cumparaturi_main, tablou_cumparaturi);
    strcpy(avertizari_main, tablou_avertizari);
    for(int i = 0; i  < not_found; i++){
        cumparaturi_main[i] = buff[i];
    }

    fclose(f);
}



int main() {
    FILE *f = fopen("camara.bin", "rb+");
    fseek(f,SEEK_END);
    int n = ftell(n)/Reteta;
    rewind(f);
    Reteta *v = (Reteta*) malloc(sizeof(Reteta)*n);
    fread(v, sizeof(Reteta), n, f);

    int m = 0;
    printf("Introdu numar ingrediente pentru reteta: "); //o sa mai faca odata aceasta citire in main dar nu am avut timp sa modific
    scanf("%d", &m);                                     //pentru a citi numai in main
    fflush(stdin);
    char ingrediente[m][15];
    int ingrediente_cantitati[m];
    char buff[15];
    float buff_cantitate[m];
    for(int i = 0; i < m; i++){
        printf("ingredientul nr %d\n", i+1);
        scanf("%s", buff);
        strcpy(ingrediente[i],buff);
        fflush(stdin);
        printf("Cantitatea ingredientului\n\n");
        scanf("%f", buff_cantitate[i]);
        fflush(stdin);
    }
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(strcmp(v[i].denumire, ingrediente[j]) == 0 || v[i].cantitate > buff_cantitate[j])){
                    count++;
                }
        }
    }



    char ***cumparaturi_main;
    char **avertizari_main;
    //trebuie alocate dinamic aceste tablouri dar nu am mai avut timp
    citire_camera(f, cumparaturi_main, avertizari_main);

    if(count == m){
        printf("Toate ingredientele sunt in camara")
    }

    else{
        for(int i < st) //aici vreau sa afisez tablourile cumparaturi_main, avertizari_main
    }

    fclose(f);
    return 0;
}