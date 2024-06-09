//
// Created by genta on 2024/06/08.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const **argv){
    if(argc < 4){
        return 1;
    }
    char **endptr = NULL;
    const float a = strtof(argv[1], endptr);
    const float b = strtof(argv[2], endptr);
    const float c = strtof(argv[3], endptr);
    const float discriminant = b*b-4*a*c;
    if(discriminant > 0){
        const float ans_rational = (-b)/(2*a);
        const float ans_irrational = (sqrtf(discriminant))/(2*a);
        printf("%f , %f\n", ans_rational + ans_irrational, ans_rational - ans_irrational);
    }else if(discriminant < 0){
        const float ans_real = (-b)/(2*a);
        const float ans_imag = (sqrtf(-discriminant))/(2*a);
        printf("%f + i%f , %f - i%f\n", ans_real, ans_imag, ans_real, ans_imag);
    }else{
        printf("%f\n", (-b)/(2*a));
    }
    return 0;
}

