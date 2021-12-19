//Scrieți un program care testează dacă un număr natural introdus de la tastatură este prim

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    int n;
    scanf("%d",&n);
    
    if(n <= 1){
        return "Nu este";
    }
    
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return "Nu este";
        }
    }
    
    return "Este";
}




