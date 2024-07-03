//
// Created by 児玉源太郎 on 2024/06/29.
//
//
// Created by genta on 2024/06/23.
//

#include <stdio.h>

/**
 *
 * @param A Input array of integers to be calculated
 * @param size Size of the input array
 * @param ans Average of the input array
 * @return Success or failure of the calculation
 */
int average(int A[], int size, float *ans);

/**
 *
 * @param A Input array of integers to be calculated
 * @param size Size of the input array
 * @param ans Dispersion of the input array
 * @return Success or failure of the calculation
 */
float dispersion(int A[], int size, float *ans);

int average(int A[], int size, float* ans)
{
    if(size <= 0)
    {
        return -1;
    }
    float avg = 0;
    for (int i = 0; i < size; i++)
    {
        avg += A[i];
    }
    avg /= size;
    *ans = avg;
    return 0;
}

float dispersion(int A[], int size, float* ans)
{
    if(size <= 0)
    {
        return -1;
    }
    float avg = 0;
    average(A, size, &avg); // average() is called to calculate the average
    float disp = 0;
    for (int i = 0; i < size; i++)
    {
        disp += (A[i] - avg) * (A[i] - avg);
    }
    disp /= size;
    *ans = disp;
    return 0;
}

// Test code
// The average of the array {1, 2, 3, 4, 5} is 3.0
// The dispersion of the array {1, 2, 3, 4, 5} is 2.0
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    float avg = 0;
    float disp = 0;
    average(A, 5, &avg);
    dispersion(A, 5, &disp);
    printf("Average: %f\n", avg);
    printf("Dispersion: %f\n", disp);
    return 0;
}