//
// Created by genta on 2024/06/10.
//

#include <stdio.h>

int counter = 0;
int func1(){
    int counter = 10;
    static int static_counter = 100;

    printf("counter_in_func1 = %d\n", counter);
    printf("static_counter_in_func1 = %d\n", static_counter);
    counter++;
    static_counter++;
    return counter;
}

int main(){
    int i;
    i = func1();
    printf("return value of func1 = %d\n", i);
    printf("counter in main = %d\n", counter);
    i = func1();
    printf("return value of func1 = %d\n", i);
    printf("counter in main = %d\n", counter);
    return 0;
}