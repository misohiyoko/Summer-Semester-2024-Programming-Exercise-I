//
// Created by genta on 2024/06/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const **argv){
    for(int i = 0; i <= 50; i += 1){
        printf("%2f %4f\n", i / 10.0f, 0.5f*9.80665f*i*i);
    }
}