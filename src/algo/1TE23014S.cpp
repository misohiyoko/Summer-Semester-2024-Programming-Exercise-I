#include <stdio.h>
#include <stdlib.h>

// 変数の値を入れ替える関数
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// 乱数を生成する関数
int get_rand( int min_val, int max_val ) {
    return (int)(( rand() % ( max_val+1 - min_val ) ) + min_val );
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


int main() {
	//データ入力
	int n;
	scanf("%d", &n);
	int* data = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	//ソート
	quicksort(data, 0, n - 1);

	//データ出力
	for (int i = 0; i < n; i++) {
		printf("%d, ", data[i]);
	}

	free(data);
	return 0;
}
