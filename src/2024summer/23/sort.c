//
// Created by 児玉源太郎 on 2024/07/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define M 100001



// 変数の値を入れ替える関数
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}




//枢軸を基準に要素を並び替える関数
int partition(int data[], int begin, int end) {
    //ここを埋める
    for (int i = begin; i < end; i++) {
        if (data[i] <= data[end]) {
            swap(&data[begin], &data[i]);
            begin++;
        }
    }
    swap(&data[end], &data[begin]);
    return begin;
}

//クイックソートを行う関数
void quicksort(int data[], int begin, int end) {
    //ここを埋める
    if(begin < end){
        int p = partition(data, begin, end);
        quicksort(data, begin, p-1);
        quicksort(data, p+1, end);
    }
}

void bubble(int data[], int begin, int end)
{
    for(int i = begin; i < end - 1; i++)
    {
        for(int j = i; j < end; j++)
        {
            if(data[j] < data[i])
            {
                swap(&data[j], &data[i]);
            }
        }
    }

}

int main(){
    FILE *fp;
    fp = fopen("./data3.txt", "r");
    int A[M];
    int BubbleSorted[M];
    int QuickSorted[M];
    int MergeSorted[M];
    int ret, n;

    for(int i = 0; i < M; i++)
    {
        ret = fscanf(fp, "%d", &A[i]);
        if(ret == EOF)
        {
            n = i + 1;
            break;
        }
    }
    fclose(fp);
    memcpy(BubbleSorted, A, n);
    memcpy(QuickSorted, A, n);
    memcpy(MergeSorted, A, n);

    time_t t = time(NULL);
    bubble(MergeSorted, 0, n);
    printf("%ld \n",time(NULL) - t);


    t = time(NULL);
    quicksort(QuickSorted, 0, n);
    printf("%ld \n", time(NULL) - t);

    t = time(NULL);
}