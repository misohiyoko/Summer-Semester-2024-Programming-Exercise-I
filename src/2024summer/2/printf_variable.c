//
// Created by genta on 2024/06/10.
//

#include <stdio.h>

/**
 * @brief print multiple numbers
 * @details print uint, float, int and float in this order
 * @return always 0
 */
int main(){
    int u;
    unsigned int i;
    float f, j;
    i = 77;
    j = 3.14f;
    u = -255;
    f = 10.0f;
    printf("i = %u\n", i);
    printf("j = %f\n", j);
    printf("u = %d\n", u);
    printf("f = %3.1f\n", f);
    return 0;
}