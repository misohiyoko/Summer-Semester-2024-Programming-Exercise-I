//
// Created by genta on 2024/06/08.
//

#include <stdio.h>

float convC2F(float celsius){
    return 1.8f*celsius + 32;
}

int main(){
    float c;
    printf("c ? ");
    scanf("%f",&c);
    printf("f = %f\n", convC2F(c));
    return 0;
}

