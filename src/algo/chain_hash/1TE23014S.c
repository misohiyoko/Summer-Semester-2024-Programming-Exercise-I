#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//リストの要素を定義する構造体
typedef struct Cell {
	struct cell* next;	//次の要素を表すポインタ
	int key;			//キー(文字列)
	int value;			//値(数値)
} cell;

//リストに要素を挿入する関数
void insertCell(cell* head, int key, int value) {
	//ここを埋める(課題1を少し変える)
	//ここを埋める
	cell* it = head;
	while(it->next)
	{
		it = it->next;
	}
	cell* new_cell = (cell*)malloc(sizeof(cell));
	new_cell->next = NULL;
	new_cell->value = value;
	new_cell->key = key;
	it->next = new_cell;
}

//リストからkeyに対応する要素を削除する関数
void deleteCell(cell* head, int key) {
	//ここを埋める(課題1を少し変える)
	//ここを埋める
	if(head->key == key)
	{
		cell* next = head->next;
		free(head);
		head = next;
		return;
	}
	cell* it = head;
	while (it->next) {
		cell* next = it->next;
		if (next->key == key) {
			it->next = next->next;
			free(next);
			return;
		}
		it = it->next;
	}
}

//リストからkeyに対応する要素の値を得る関数
int searchCell(const cell* head, int key) {
	//ここを埋める(課題1を少し変える)
	cell *it = head;
	while(it)
	{
		if(it->key == key)
		{
			return it->value;
		}
		it = it->next;
	}
	return -1;
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

const int kTableSize = 10;
cell table[10];

int hash_function(int key) {
	return key % kTableSize;
}

void insertTable(int key, int value) {
	//ここを埋める
	insertCell(&table[hash_function(key)], key, value);
}

void deleteTable(int key) {
	//ここを埋める
	deleteCell(&table[hash_function(key)], key);
}

int searchTable(int key) {
	//ここを埋める
	return searchCell(&table[hash_function(key)], key);
}

void printTable() {
	for (int i = 0; i < kTableSize; i++) {
		printCell(&table[i]);
	}
	printf("\n");
}

int main() {

	insertTable(1, 1);
	insertTable(2, 2);
	insertTable(3, 3);
	insertTable(12, 12);
	insertTable(13, 13);
	insertTable(22, 22);
	printTable();

	deleteTable(12);
	deleteTable(3);
	printTable();

	printf("%d\n", searchTable(22));
	printf("%d\n", searchTable(4));
	return 0;
}
