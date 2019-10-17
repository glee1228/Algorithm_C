#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
}Node;

Node* root = NULL;

Node* makeNewNode(int data) {
	Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	return newNode;

}
bool isExternal(Node* node) {
	if(node==NULL){
		return true;
	}
	else{
		return false;
	}
}

Node* treeSearch(Node* node, int data) {
	Node* childNode = NULL;
	if (node->key == data) {
		return node;
	}
	else if (node->key < data && !isExternal(node->right)) {
		childNode = treeSearch(node->right, data);
	}
	else if (node->key > data && !isExternal(node->left)) {
		childNode = treeSearch(node->left, data);
	}
	if (childNode != NULL) {
		childNode->parent = node;
	}
	return childNode;
}



Node* insertItem(Node* node, int data) {
	
	if (node == NULL) {
		node = makeNewNode(data);
		return node;
	}
	if (data < node->key) {
		node->left=insertItem(node->left, data);
	}
	else if (data > node->key)
	{
		node->right=insertItem(node->right, data);
	}
	return node;
	
}
void findElement(int data) {
	Node* node=treeSearch(root, data);
	if (node == NULL) {
		printf("X \n");
	}
	else if (node->key == data) {
		printf("%d \n", node->key);
	}
	
	
}
Node* inOrderSucc(Node* node) {
	Node* w = node->right;
	while (w->left != NULL) {
		w = w->left;
	}
	return w;
}

void removeElement(int data) {
	Node* node = treeSearch(root, data);
	if(node == NULL) {
		printf("X \n");
	}
	if (node->key == data && isExternal(node->left) && isExternal(node->right)) {
		printf("%d", node->key);
		free(node);
	}
	else if (node->key == data &&!isExternal(node->right)) {
		printf("%d", node->key);
		Node* succ;
		Node* tmp;
		succ=inOrderSucc(node);
		tmp->parent = node->parent;
		node->parent = succ->parent;
		succ->parent = tmp->parent;
		succ->right = node->right;
		
		free(node);
	}
	else if (node->key == data && !isExternal(node->left)) {
		printf("%d", node->key);
		
		node->left->parent = node->parent;
		node->parent->left = node->left;
		free(node);
	}
	else if (node->key==data&&!isExternal(node->right)&&isExternal(node->left)){
		printf("%d", node->key);

		free(node);
	}
	

}
void preorder(Node* root) {
	if (root != NULL) {
		printf("%d \n", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}
int main() {


	char input = 'o';
	

	while (input != 'q') {
		int value = 0;
		scanf_s("%c", &input);


		if (input == 'i') {
			scanf_s("%d", &value);
			if (root == NULL) {
				root = insertItem(root, value);
			}
			insertItem(root,value);
			//printf("%d\n",0);
		}
		else if (input == 'd') {
			//printf("%d\n",removeMax());
		}
		else if (input == 'p') {
			preorder(root);
		}
		else if (input == 's') {
			scanf_s("%d", &value);
			findElement(value);
		}
		getchar();
	}

	return 0;
}

