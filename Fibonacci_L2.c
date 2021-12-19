#include <stdio.h>
#include <stdlib.h>

int main(){
    int prev = 0;
    int curr = 1;
    int next = prev + curr;

    int n;
    scanf("%d",&n);

    printf("%d\n%d\n",prev,curr);
    for(int i = 3; i <= n; i++){
        printf("%d\n",next);
        prev = curr;
        curr = next;
        next = prev + curr;
    }

    return 0;
}

