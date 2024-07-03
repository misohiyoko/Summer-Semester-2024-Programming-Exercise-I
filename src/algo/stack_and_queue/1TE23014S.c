#include <stdio.h>

//スタックの実装
int top = 0;	// 最後に挿入された要素の格納場所(=要素数)
int MAX = 8;	// スタック,キューに格納できる数
int S[8];		// 要素を格納するサイズMAXの配列

int STACK_EMPTY(){
	// ここを埋める
	return top > 0;
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
	if (STACK_EMPTY())
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
int Q[8];				// 要素を格納するサイズMAXの配列
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

int main() {
	//スタックのテスト
	PUSH(1);
	PUSH(2);
	PUSH(3);
	printf("%d\n", POP());
	PUSH(4);
	PUSH(5);
	printf("%d\n", POP());
	printf("%d\n", POP());
	PUSH(6);
	PUSH(7);
	PUSH(8);
	PUSH(9);
	PUSH(10);
	PUSH(11);
	PUSH(12);
	printf("%d\n", POP());
	printf("%d\n", POP());
	printf("%d\n", POP());
	printf("%d\n", POP());
	printf("%d\n", POP());
	printf("%d\n", POP());
	printf("%d\n", POP());
	printf("%d\n", POP());
	printf("%d\n", POP());

	//キューのテスト
	ENQUEUE(1);
	ENQUEUE(2);
	printf("%d\n", DEQUEUE());
	ENQUEUE(3);
	ENQUEUE(4);
	ENQUEUE(5);
	ENQUEUE(6);
	printf("%d\n", DEQUEUE());
	printf("%d\n", DEQUEUE());
	printf("%d\n", DEQUEUE());
	ENQUEUE(7);
	ENQUEUE(8);
	ENQUEUE(9);
	ENQUEUE(10);
	printf("%d\n", DEQUEUE());
	ENQUEUE(11);
	ENQUEUE(12);
	ENQUEUE(13);
	ENQUEUE(14);
	printf("%d\n", DEQUEUE());
	printf("%d\n", DEQUEUE());
	printf("%d\n", DEQUEUE());
	printf("%d\n", DEQUEUE());
	printf("%d\n", DEQUEUE());
	printf("%d\n", DEQUEUE());
	printf("%d\n", DEQUEUE());
	printf("%d\n", DEQUEUE());
	printf("%d\n", DEQUEUE());

	return 0;
}

