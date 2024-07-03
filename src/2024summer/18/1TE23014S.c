//
// Created by 児玉源太郎 on 2024/07/01.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT(VAR) printf("Input " #VAR ": "); scanf("%lf", &VAR);

double f(double x)
{
    if(x > 2 || x < -2)
    {
        return 0;
    }
    return sqrt(4 - x * x);
}

int main(int argc, char const **argv)
{
    double a, b, division;

    int repeat = 0;
    do
    {
        INPUT(a)
        INPUT(b)
        INPUT(division)
        double h = (b - a) / division;
        double odd = 0;
        double even = 0;

        for(int i = 0; i < division; i++)
        {
            odd += f(a + (2 * i + 1) * h);
            even += f(a + (2 * i) * h);
        }

        const double ans = h / 3.0 * (f(a) + f(a + 2.0 * division * h) + 4.0 * odd + 2.0 * even);
        printf("area = %lf\n", ans);
        printf("Repeat? (1: Yes, 0: No): ");
        scanf("%d", &repeat);
    }while(repeat);
}


// Output example
// In: 0 2 10000
// area = 3.141859
// In: 0 2 10000000
// area = 3.141593