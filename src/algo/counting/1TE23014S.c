#include <stdio.h>
#include <stdlib.h>

//カウンティングソートを行う関数
//配列は0オリジンであることに注意
void counting_sort(int src[], int dest[], int temp[], int n, int k) {
	//ここを埋める
	for (int i = 0; i < k; i++) {
		temp[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		temp[src[i]]++;
	}
	for (int i = 1; i < k; i++) {
		temp[i] += temp[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		dest[temp[src[i]] - 1] = src[i];
		temp[src[i]]--;
	}
}


int main() {
	int n;										// ソート列の個数
	int k;										// 数値の範囲(0～k-1)

	//データ入力
	scanf("%d", &n);
	scanf("%d", &k);

	int* src = (int*)malloc(sizeof(int) * n);	// ソートを行う入力配列
	int* dest = (int*)malloc(sizeof(int) * n);	// ソートされた配列
	int* temp = (int*)malloc(sizeof(int) * k);	// 補助的な配列

	for (int i = 0; i < n; i++) {
		scanf("%d", &src[i]);
	}

	//ソート
	counting_sort(src, dest, temp, n, k);

	//データ出力
	for (int i = 0; i < n; i++) {
		printf("%d, ", dest[i]);
	}

	free(src);
	free(dest);
	free(temp);
	return 0;
}