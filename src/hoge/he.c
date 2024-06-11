//
// Created by genta on 2024/06/08.
//

#include <stdio.h>
#define N 10
void f(int x[], int n){
    if(n==10){
        return;
    }else{
        printf("%d",x[n]);

        return f(x,n+1);
    }
}
int main(){
    int array[10];
    int i;
    for (i=0;i<10;i++){
        array[i]=i;
    }
    f(array,0);
    return 0;
}