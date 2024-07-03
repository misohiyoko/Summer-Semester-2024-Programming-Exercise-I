//
// Created by 児玉源太郎 on 2024/07/01.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT(VAR) printf("Input " #VAR ": "); scanf("%lf", &VAR);

double f(double x)
{
    return x * x - 2.0;
}

double g(double x)
{
    return 2.0 * x;
}

int main(int argc, char const **argv)
{
    double init, epsilon, max_iter_in;
    double x, new_x;
    INPUT(init)
    INPUT(epsilon)
    INPUT(max_iter_in)
    double double_root_eps = epsilon * 10;
    int max_iter = (int)max_iter_in;
    x = init;
    for(int i = 0; i < max_iter; i++)
    {
        new_x = x - f(x) / g(x);
        if(fabs((new_x - x) / new_x) < epsilon || (fabs(new_x) < 1 && fabs(new_x - x) < epsilon))
        {
            if(fabs(g(new_x)) < double_root_eps)
            {
                printf("x = %lf is a double root\n", new_x);
                return 0;
            }
            printf("x = %lf\n", new_x);
            return 0;
        }
        printf("%2d\t\t%lf\t%lf\t%lf \n", i, new_x, f(x), g(x));
        x = new_x;
    }
    printf("Max iteration reached\n");
    return 1;
}

// Output example
// In: 10 0.000001 100
// x = 1.414214