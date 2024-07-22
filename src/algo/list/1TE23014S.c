#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//リストの要素を定義する構造体
typedef struct  {
	struct cell* next;	//次の要素を表すポインタ
	char key[256];		//キー(文字列)
	int value;			//値(数値)
} cell;

//リストの先頭
//NULLは次の要素が無いことを表す
cell head = { NULL, "head", -1 };

//リストに要素を挿入する関数
void insertCell(cell* head, char key[], int value) {
	//ここを埋める
	cell* it = head;
	while(it->next)
	{
		it = it->next;
	}
	cell* new_cell = (cell*)malloc(sizeof(cell));
	new_cell->next = NULL;
	new_cell->value = value;
	memccpy(new_cell->key, key, 0, 256);
	it->next = new_cell;
}

//リストからkeyに対応する要素を削除する関数
void deleteCell(cell* head, char key[]) {
	//ここを埋める
	if(strcmp(head->key, key) == 0)
	{
		cell* next = head->next;
		free(head);
		head = next;
		return;
	}
	cell* it = head;
	while (it->next) {
		cell* next = it->next;
		if (strcmp(next->key, key) == 0) {
			it->next = next->next;
			free(next);
			return;
		}
		it = it->next;
	}
}

//リストからkeyに対応する要素の値を得る関数
int searchCell(const cell* head, char key[]) {
	//ここを埋める
	cell *it = head;
	while(it)
	{
		if(strcmp(it->key, key) == 0)
		{
			return it->value;
		}
		it = it->next;
	}
	return -1;
}

//リストを全てクリアする関数
void clearCell(cell* head) {
	cell* it = head;
	while (it->next) {
		cell* tmp1 = it->next;
		cell* tmp2 = tmp1->next;
		it->next = tmp2;
	}
}

//リストを全て表示する関数
void printCell(const cell* head) {
	printf("[ ");
	const cell* it = head;
	while (it->next) {
		cell* tmp = it->next;
		printf("%d, ", tmp->value);
		it = it->next;
	}
	printf("]\n");
}

int main() {
	insertCell(&head, "one", 1);
	insertCell(&head, "two", 2);
	insertCell(&head, "three", 3);
	printCell(&head);	//[1, 2, 3]

	deleteCell(&head, "two");
	printCell(&head);	//[1, 3]

	insertCell(&head, "four", 4);
	insertCell(&head, "five", 5);
	deleteCell(&head, "five");
	printCell(&head);	//[1, 3, 4]

	printf("%d\n", searchCell(&head, "three"));	// 3
	searchCell(&head, "two");					//not found

	clearCell(&head);
	printCell(&head);	//[]
	return 0;
}
