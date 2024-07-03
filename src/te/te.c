//
// Created by 児玉源太郎 on 2024/07/02.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x) {
    return x;
}
double g(double x) {
    return 1;
}
double newton(double x0, double delta, int limit) {
    double x = 0;
    for (int i = 0; i < limit; i++) {
        if ((fabs(f(x)) < delta) || (i == limit -1)) {
            return x;
        } else {
            x -= f(x) / g(x);
        }
    }
    return 0;
}
int main () {
    printf("%lf \n",newton (1.0, 1.0, 5));
}