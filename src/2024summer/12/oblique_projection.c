//
// Created by 児玉源太郎 on 2024/07/01.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 9.8

#define INPUT(VAR) printf("Input " #VAR ": "); scanf("%lf", &VAR);
#define COMMA ,
#define PRINT_BOTH(FILE, TEXT) printf(TEXT); \
    fprintf(FILE, TEXT);

int main(int argc, char const **argv){
    double v0, theta, t, step_t;
    FILE *fp;
    fp = fopen("oblique_projection.csv", "w");
    INPUT(v0)
    INPUT(theta)
    INPUT(t)
    INPUT(step_t)
    theta = theta * M_PI / 180;
    PRINT_BOTH(fp,"t, x, y \n")
    for(int i = 0; i <= (int)(t / step_t); i += 1){
        const double t_c = i * step_t;

        PRINT_BOTH(fp, "%lf, %lf, %lf\n"COMMA
            t_c COMMA
            v0 * cos(theta) * t_c COMMA
            v0 * sin(theta) * t_c - 0.5 * GRAVITY * t_c * t_c);
    }
    printf("File written to oblique_projection.csv\n");
    fclose(fp);
}

/* Output example
 * In: 10 45 2 0.1
 * Final result: 2.000000, 14.142136, -5.457864
 * File written to oblique_projection.csv
*/