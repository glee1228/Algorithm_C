#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
}Node;

Node* root = NULL;

Node* getNode(int data) {
	Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->key = data;
	return newNode;
}
Node* treeSearch(Node* node, int data) {
	Node* childNode = NULL;
	if (node->key == data) {
		return node;
	}
	else if (node->right != NULL && node->key < data) {
		childNode = treeSearch(node->right, data);
	}
	else if (node->left != NULL & node->key > data) {
		childNode = treeSearch(node->left, data);
	}
	if (childNode != NULL) {
		childNode->parent = node;
	}
	return childNode;

}
Node* insertItem(Node* node, int data) {
	if (node == NULL) {
		Node* newNode = getNode(data);
		return newNode;
	}
	if (node->key > data) {
		node->left = insertItem(node->left, data);
	}
	else if (node->key < data) {
		node->right = insertItem(node->right, data);
	}
	return node;
}

void preorder(Node* node) {
	if (node != NULL) {
		printf(" %d", node->key);
		preorder(node->left);
		preorder(node->right);
	}
}

int findElement(Node* node, int data) {
	Node* w = treeSearch(node, data);
	if (w == NULL) {
		printf("X\n");
		return;
	}
	if (w->key != data) {
		printf("X\n");
	}
	else if (w->key == data) {
		printf("%d\n", data);
		return w->key;
	}

}
Node* sibling(Node* w) {
	if (w->parent->left == w) {
		return w->parent->right;
	}
	else if (w->parent->right == w) {
		return w->parent->left;
	}
}
Node* reduceExternal(Node* z) {
	Node* w = z->parent;
	Node* zs = sibling(z);
	if (w->key == root->key) {
		root = zs;
		zs->parent = NULL;
	}
	else {
		Node* g = w->parent;
		zs->parent = g;
		if (w == g->left) {
			g->left = zs;
		}
		else if (w == g->right) {
			g->right = zs;
		}
	}
	free(z);
	free(w);
	return zs;

}
Node* inOrderSucc(Node* w) {
	w = w->right;
	while (w->left != NULL) {
		w = w->left;
	}
	return w;
}
Node* removeElement(Node* node, int data) {
	Node* tNode = NULL;
	if (node == NULL) {
		printf("X\n");
		return NULL;
	}

	if (node->key > data)
		node->left = removeElement(node->left, data);
	else if (node->key < data)
		node->right = removeElement(node->right, data);
	else
	{
		// 자식 노드가 둘 다 있을 경우
		if (node->right != NULL && node->left != NULL)
		{
			tNode = inOrderSucc(node);
			printf("%d\n", node->key);
			node->key = tNode->key;
			node->right = removeElement(node->right, tNode->key);
		}
		else
		{
			tNode = (node->left == NULL) ? node->right : node->left;

			free(node);
			return tNode;
		}
	}

	return node;

}
int main()
{
	char input = 'o';

	while (input != 'q') {
		scanf("%c", &input);
		int data = 0;
		if (input == 'i') {
			scanf("%d", &data);
			if (root == NULL) {
				root = insertItem(root, data);
			}
			insertItem(root, data);
		}
		else if (input == 'd') {
			scanf("%d", &data);
			removeElement(root, data);

		}
		else if (input == 's') {
			scanf("%d", &data);
			findElement(root, data);
		}
		else if (input == 'p') {
			preorder(root);
			printf("\n");
		}
		getchar();
	}

	return 0;
}
