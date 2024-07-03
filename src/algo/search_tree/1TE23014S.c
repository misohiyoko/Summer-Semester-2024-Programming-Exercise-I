#include <limits.h>
#include <stdio.h>

//スタックの実装
int top = 0;	// 最後に挿入された要素の格納場所(=要素数)
#define MAX 65535	// スタック,キューに格納できる数
int S[MAX];		// 要素を格納するサイズMAXの配列

int STACK_EMPTY(){
	// ここを埋める
	return top == 0;
}

void PUSH(int x) {
	// ここを埋める
	if (top < MAX) {
		S[top++] = x;
	}else
	{
		printf("Overflow\n");
	}
}

int POP() {
	// ここを埋める
	if (top > 0)
	{
		return S[--top];
	}else
	{
		printf("Underflow\n");
		return -1;
	}
}


//キューの実装
int head = 0;			// キューの先頭の位置
int tail = 0;			// 次に追加される位置
int Q[MAX];				// 要素を格納するサイズMAXの配列
int full = 0;			// キューに全て格納されているかを返す変数

void ENQUEUE(int x) {
	// ここを埋める
	if (!full)
	{
		Q[tail] = x;
		tail = (tail + 1) % MAX;
		if (tail == head)
		{
			full = 1;
		}
	}else
	{
		printf("Overflow\n");
	}
}

int DEQUEUE() {
	// ここを埋める
	if(head != tail || full)
	{
		int x = Q[head];
		head = (head + 1) % MAX;
		full = 0;
		return x;
	}else
	{
		printf("Underflow\n");
		return -1;
	}
}


//木の実装

const int max_length = 65536;
int size = 0;
int data[65536];

//要素indexに対する親要素のインデックス
int parent(int index) {
	return (int) ((index - 1) / 2);
}

//要素indexに対する左ノードのインデックス
int left(int index) {
	return 2 * index + 1;
}

//要素indexに対する右ノードのインデックス
int right(int index) {
	return 2 * index + 2;
}

//要素の挿入
void insert(int value) {
	if (size < max_length) {
		data[size++] = value;
	}
}

//探索アルゴリズム
//今回の木構造は配列なので配列を走査すれば探索できるが、
//木構造が常に配列で実装されている保証は無いため講義資料にあるやり方で探索をしてみること

//値としてvalueを持つノードを深さ優先探索し, そのノードの配列dataにおけるインデックスを返す関数
int depth_first_search(int value) {
	// ここを埋める
	PUSH(0);
	while (!STACK_EMPTY()) {
		int index = POP();
		if (data[index] == value) {
			return index;
		}
		if (right(index) < size) {
			PUSH(right(index));
		}
		if (left(index) < size) {
			PUSH(left(index));
		}
	}
	return -1;
}

//値としてvalueを持つノードを幅優先探索し, そのノードの配列dataにおけるインデックスを返す関数
int breadth_first_search(int value) {
	// ここを埋める
	ENQUEUE(0);
	while(head != tail || full){
		int index = DEQUEUE();
		if (data[index] == value) {
			return index;
		}
		if (left(index) < size) {
			ENQUEUE(left(index));
		}
		if (right(index) < size) {
			ENQUEUE(right(index));
		}
	}
	return -1;
}

int main() {
	//データ入力
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int d;
		scanf("%d", &d);
		insert(d);
	}

	//探索する数の入力
	int target;
	scanf("%d", &target);

	//深さ優先探索
	printf("%d\n", depth_first_search(target));

	//幅優先探索
	printf("%d\n", breadth_first_search(target));

	return 0;
}