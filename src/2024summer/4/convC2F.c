//
// Created by genta on 2024/06/08.
//

#include <stdio.h>

/**
 * @brief Convert celsius to fahrenheit
 * @param celsius Celsius degree temperature in float.
 * @return Fahrenheit degree temperature in float.
 */
float convC2F(float celsius){
    return 1.8f*celsius + 32;
}

/**
 * @brief Convert celsius input to fahrenheit
 * @return Always 0
 */
int main(){
    float c;
    printf("c ? ");
    scanf("%f",&c);
    printf("f = %f\n", convC2F(c));
    return 0;
}

