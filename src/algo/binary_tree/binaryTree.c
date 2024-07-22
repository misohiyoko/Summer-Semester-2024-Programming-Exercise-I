#include <stdio.h>
#include <stdlib.h>

//ノードを表す構造体
typedef struct Node {
	int key;
	struct node* left;
	struct node* right;
	struct node* parent;
} node;

//根ノード
node* root;

//nodeのキーを得る関数
int key(node* x) {
	return x->key;
}

//nodeの左の子を得る関数
node* left(node* x) {
	return x->left;
}

//nodeの右の子を得る関数
node* right(node* x) {
	return x->right;
}

//nodeの親を得る関数
node* parent(node* x) {
	return x->parent;
}

//左端のノード(最小)を得る関数
node* minimum(node* x) {
	if (!left(x)) {
		return x;
	}
	return minimum(left(x));
}

//nodeの次のノードを得る関数
node* successor(node* x) {
	node* y;
	if (right(x)) {
		return minimum(right(x));
	}
	y = parent(x);
	while (y && x == right(y)) {
		x = y;
		y = parent(y);
	}
	return y;
}

//node以下にあるkeyに対応するノードを返す関数
//見つからなければnullを返す
node* searchNode(int search_key, node* x) {
	//ここを埋める
	if(search_key == x->key)
	{
		return x;
	}
	else if(search_key < x->key)
	{
		if(left(x))
		{
			return searchNode(search_key, left(x));
		}else
		{
			return NULL;
		}
	}
	else if(search_key > x->key)
	{
		if(right(x))
		{
			return searchNode(search_key, right(x));
		}
		else
		{
			return NULL;
		}
	}
}

//新しいノードzを挿入する関数
void insertNode(node* z) {
	//ここを埋める
	node *target_node = root;
	node *target_parent_node = NULL;
	while (target_node != NULL)
	{
		target_parent_node = target_node;
		if(z->key < target_node->key)
		{
			target_node = left(target_node);
		}
		else
		{
			target_node = right(target_node);
		}
	}
	z->parent = target_parent_node;
	if(target_parent_node == NULL)
	{
		root = z;
		return;
	}
	if(z->key < target_parent_node->key)
	{
		target_parent_node->left = z;
	}else
	{
		target_parent_node->right = z;
	}
}

//既に木に存在しているノードzを削除する関数
void deleteNode(node* z) {
	//ここを埋める
	if(z ==NULL)
	{
		return;
	}
	if(z->left == NULL)
	{
		if(z->right == NULL)
		{
			node *parent = z->parent;
			if(z->parent == NULL)
			{
				root = NULL;
				free(z);
			}
		    else if(right(parent) !=NULL && right(parent)->key == z->key)
			{
				parent->right = NULL;
				free(z);
			}
			else
			{
				parent->left = NULL;
				free(z);
			}
		}else
		{
			node *parent = z->parent;
			if(z->parent == NULL)
			{
				root = z->right;
				node *tmp = z->right;
				tmp->parent = NULL;
				free(z);
			}
			else if(right(parent) !=NULL && right(parent)->key == z->key)
			{
				parent->right = z->right;
				node *tmp = z->right;
				tmp->parent = parent;
				free(z);
			}
			else
			{
				parent->left = z->right;
				node *tmp = z->right;
				tmp->parent = parent;
				free(z);
			}
		}
	}else
	{
		if(z->right == NULL)
		{
			node *parent = z->parent;
			if(z->parent == NULL)
			{
				root = z->left;
				node *tmp = z->left;
				tmp->parent = NULL;
				free(z);
			}
			else if(right(parent) !=NULL && right(parent)->key == z->key)
			{
				parent->right = z->left;
				node *tmp = z->left;
				tmp->parent = parent;
				free(z);
			}
			else
			{
				parent->left = z->left;
				node *tmp = z->left;
				tmp->parent = parent;
				free(z);
			}
		}else
		{
			node *parent = z->parent;
			node *z_successor = successor(z);
			node *z_successor_parent = z_successor->parent;
			if(z->parent == NULL)
			{
				root = z_successor;
				if(right(z_successor_parent) != NULL && right(z_successor_parent)->key == z_successor->key)
				{
					z_successor_parent->right = z_successor->left;
					node * tmp =z_successor->left;
					tmp->parent = z_successor_parent;
				}else
				{
					z_successor_parent->left = z_successor->left;
					node * tmp =z_successor->left;
					tmp->parent = z_successor_parent;
				}
				z_successor->parent = NULL;
				z_successor->left = z->left;
				z_successor->right = z->right;
				free(z);
			}
			else if(right(parent) !=NULL && right(parent)->key == z->key)
			{
				parent->right = z_successor;
				if(right(z_successor_parent) != NULL && right(z_successor_parent)->key == z_successor->key)
				{
					z_successor_parent->right = z_successor->left;
					node * tmp =z_successor->left;
					tmp->parent = z_successor_parent;
				}else
				{
					z_successor_parent->left = z_successor->left;
					node * tmp =z_successor->left;
					tmp->parent = z_successor_parent;
				}
				z_successor->parent = parent;
				z_successor->left = z->left;
				z_successor->right = z->right;
				free(z);
			}
			else
			{
				parent->left = successor(z);
				if(right(z_successor_parent)->key == z_successor->key)
				{
					z_successor_parent->right = z_successor->left;
					node * tmp =z_successor->left;
					tmp->parent = z_successor_parent;
				}else
				{
					z_successor_parent->left = z_successor->left;
					node * tmp =z_successor->left;
					tmp->parent = z_successor_parent;
				}
				z_successor->parent = parent;
				z_successor->left = z->left;
				z_successor->right = z->right;
				free(z);
			}
		}
	}
}

//木をクリアする関数(メモリ解放用)
void clearNode(node* x) {
	if (!x) {
		return;
	}
	clearNode(left(x));
	clearNode(right(x));
	free(x);
}

//printTree用の補助関数
void inorder(node* x) {
	if (x) {
		inorder(left(x));
		printf("%d, ", key(x));
		inorder(right(x));
	}
}

//木全体を表示する関数
void printTree() {
	printf("[");
	inorder(root);
	printf("]\n");
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int input;
		scanf("%d", &input);
		node* newNode = (node*)malloc(sizeof(node));
		newNode->key = input;
		insertNode(newNode);
	}
	printTree();
    
    scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int input;
		scanf("%d", &input);
		deleteNode(searchNode(input, root));
	}
	printTree();
	clearNode(root);
	
}
