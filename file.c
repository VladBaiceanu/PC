#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE * f1 = fopen("file.txt", "rt");

    char rt;
    rt = getc(f1);
    while(rt != EOF){
        putchar(rt);
        rt = getc(f1);
    }



    fclose(f1);
    return 0;
}