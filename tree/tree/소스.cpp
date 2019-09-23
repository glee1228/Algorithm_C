#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node; // 노드 구조체
Node* makeNewNode() {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = 0;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
} // 노드 할당 및 반환
void maketree(Node* root, int* n) {
	Node* tmp = root;
	int data, L, R;
	scanf("%d%d%d", &data, &L, &R);
	tmp->data = data;
	*n -= 1;
	if (L) { //왼쪽으로 생성
		tmp->left = makeNewNode();
		maketree(tmp->left, n);
	}
	if (R) {//오른쪽으로 생성
		tmp->right = makeNewNode();
		maketree(tmp->right, n);
	}
} //트리 생성
void find(Node* root, char* buff) {
	printf(" %d", root->data);
	if (*buff == 'L') {
		find(root->left, buff + 1);
	}//방향에 맞게 한글자씩 재귀 처리
	else if (*buff == 'R') {
		find(root->right, buff + 1);
	}
	else
		return;
}
int main(void) {
	Node* tree = makeNewNode();

	int n, s;
	char op[101];
	scanf("%d", &n);
	maketree(tree, &n);
	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		scanf("%s", op);
		find(tree, op);
		printf("\n");
	}
	return 0;
}