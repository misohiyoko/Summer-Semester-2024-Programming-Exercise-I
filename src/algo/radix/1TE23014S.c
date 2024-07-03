#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//自然数nに関してd桁目の数値を得る関数
int getDigitValue(int n, int d){
	return (n % (int) pow(10, d + 1)) / (int) pow(10, d);
}

//基数ソートを行う関数
void radix_sort_impl(int src[], int dest[], int n, int d){
	//ここを埋める
	int k = 10;
	int temp[k];
	for (int i = 0; i < k; i++) {
		temp[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		temp[getDigitValue(src[i], d)]++;
	}
	for (int i = 1; i < k; i++) {
		temp[i] += temp[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		dest[temp[getDigitValue(src[i], d)] - 1] = src[i];
		temp[getDigitValue(src[i], d)]--;
	}
}

//基数ソートを呼ぶ関数
void radix_sort(int data[], int n, int d){
	int* dest = (int*)malloc(sizeof(int) * n);
	for(int i = 0;i < d;i++){
		radix_sort_impl(data, dest, n, i);
		for(int j =0;j < n;j++){
			data[j] = dest[j];
		}
		for (int j = 0; j < n; j++) {
			printf("%d, ", data[j]);
		}
		printf("\n");
	}
	free(dest);
}


int main() {
	int n;										// ソート列の個数
	int d;										// 桁数

	//データ入力
	scanf("%d", &n);
	scanf("%d", &d);

	int* data = (int*)malloc(sizeof(int) * n);	// ソートを行う入力配列
	

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	//ソート
	radix_sort(data, n, d);

	//データ出力
	for (int i = 0; i < n; i++) {
		printf("%d, ", data[i]);
	}

	free(data);
	return 0;
}