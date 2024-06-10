//
// Created by genta on 2024/06/07.
//


#include <stdio.h>

/**
 * @brief Echo back input value
 * @details Non number input is undefined. Float value will be rounded.
 * @return Always 0
 */
int main(){
    int i;
    printf("i ? ");
    scanf("%d",&i);
    printf("i = %d\n",i);
    return 0;
}