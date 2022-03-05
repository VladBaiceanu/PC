///==================FUNCTII DE INTERSCHIMBARI=====================

//=======SFANTA FUNCTIE DE INTERSCHIMBARE A DOUA VALORI============
void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

//==================INTERSCHIMBARE A DOI VECTORI===================
void swapVectori(int* a, int* b, int n)//Presupunem ca vectorii au aceeasi lungime altfel n-ar avea sens functia
{
    for(int i=0;i<n;i++)
    {
        swap(a + i, b + i);//Trebuie sa luati functia swap
    }
}

///=========================SORTARILE=============================

//E de preferat sa luati si functia de swap ca sa mearga sortarile bn

//=========================BUBBLE SORT============================
void BubbleSort(int *v, int length)
{
    bool sortat = false;
    while(!sortat)
    {
        sortat = true;
        for(int i=0;i<length - 1;i++)
        {
            if(v[i]<v[i+1])
            {
                swap(v+i,v+i+1);
                sortat = false;
            }
        }
    }
}

//=========================INSERTION SORT==========================
void InsertionSort(int *v, int length)
{
    for(int i = 0;i<length;i++)
    {
        int aux = v[i];
        int j = i;
        i--;
        while(aux > v[i] && i >= 0)
        {
            swap(v+i,v+i+1);
            i--;
        }
        i = j;
    }
}

//=========================SELECTION SORT==========================
void SelectionSort(int *v, int length)
{
    for(int i = 0;i<length;i++)
    {
        int min_pos = i;
        for(int j = i + 1;j<length;j++)
        {
            if(v[j]>v[min_pos])
                min_pos = j;
        }
        swap(v + i, v + min_pos);
    }
}

///===============FUNCTII PENTRU PERMUTAREA CIRCULARA==============

//Functia permuta circular la dreapta cu o pozitie vectorul
void PermDreapta(int* v, int length)
{
    int aux;
    aux = v[length - 1];
    for (int i = length - 1; i > 0; --i)
    {
        v[i] = v[i - 1];
    }
    v[0] = aux;
}

//Functia permuta circular la stanga cu o pozitie vectorul
void PermStanga(int* v, int length)
{
    int aux;
    aux = v[0];
    for (int i = 0; i < length; i++)
    {
        v[i] = v[i + 1];
    }
    v[length - 1] = aux;
}

///===================FUNCTII PENTRU CAUTARE=====================

//=====================CAUTARE LINIARA ELEMENT===================
//Chestia va returna -1 daca valoarea nu este in vector altfel va returna pozitia pe care este elementul
int Search(int* v, int n, int value)
{
    for(int i=0;i<n;i++)
    {
        if(v[i]==value)
            return i;
    }
    return -1;
}

//=====================CAUTARE MINIM============================
int Minim(int* v, int n)
{
    int min = v[0];
    for(int i=1;i<n;i++)
    {
        if(min>v[i])
            min=v[i];
    }
    return min;
}

//=====================CAUTARE MAXIM============================
int Maxim(int* v, int n)
{
    int max = v[0];
    for(int i=1;i<n;i++)
    {
        if(max<v[i])
            max=v[i];
    }
    return max;
}

///============FUNCTII PENTRU ELIMINARE ELEMENTE================

//Functia va elimina elementul de pe o anumita pozitie
void EliminareElement(int* v, int* n, int poz)
{
    for(int i=poz;i<n-1;i++)
    {
        v[i]=v[i+1];
    }
    (*n)--;
}

//Functia va elimina x elemente incepand de la pozitia data
void EliminareElemente(int* v, int* n, int poz, int x)
{
    for(int i=poz;i<n-x;i++)
    {
        v[i]=v[i+x];
    }
    (*n)-=x;
}

//Functie ptr eliminarea tuturor aparitiilor unui vector in alt vector
void EliminareHarcore(int* v, int* length1, int* x, int length2)
{
    for (int i = 0; i < *length1; i++)
    {
        if (v[i] == x[0] && i + length2 <= length1)//E posibil sa fie un bug daca vectorul se afla la sfarsit asta e
        {
            int j = i + 1;
            for (; v[j] == x[j - i] && j < *length1; j++);
            if (j - i == length2)
            {
                (*length1) -= length2;
                for (int k = i; k < *length1; k++)
                {
                    v[k] = v[k + length2];
                }
                i = 0;
            }
        }
    }
}

///============FUNCTII PENTRU ALOCARE DINAMICA==================

//Alocare cu functie care returneaza un pointer
int* Alloc(int n)
{
    return (int*)malloc(n*sizeof(int));
}

//Alocare cu functie care returneaza un pointer si initializeaza eleemntele cu 0
int* CAlloc(int n)
{
    return (int*)calloc(n,sizeof(int));
}

//Alocare in functie
void AllocTryhard(int** v, int n)
{
    *v = (int*)malloc(n*sizeof(int));
}

//Realocare in functie
void AllocTryhard(int** v, int n)
{
    *v = (int*)realloc(*v, n*sizeof(int));
}



















