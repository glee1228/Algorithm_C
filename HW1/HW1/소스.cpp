#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char elem;
	struct Node* prev;
	struct Node* next;
}Node; // ��� ����

typedef struct List {
	struct Node* header;
	struct Node* trailer;
}List; // ����Ʈ ����

Node* createNode(char item) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->elem = item;
	tmp->next = tmp->prev = NULL;
	return tmp;
} // ���ο� ��� ����

Node* add(List list, int position, const char item) {
	Node* tmp = list.header; //���ο� ��尡 �� �ڸ��� ���� ��带 ����Ű�� ������
	Node* newNode = createNode(item); //�Է��� ��� ����
	Node* Right;  //�Է��� ��� ������ ��带 ����Ű�� ������

	while (--position) {
		if (tmp->next == NULL) {
			printf("invalid position\n");
			return;
		}
		tmp = tmp->next;
	} //��ȸ
	
	if (tmp->next == NULL) {
		printf("invalid position\n");
		return;
	}
	Right = tmp->next;
	newNode->next = Right;
	newNode->prev = tmp;
	tmp->next = newNode;
	if (Right) {
		Right->prev = newNode;
	}
	return tmp;
}

char Delete(List list, int position) {
	Node* tmp = list.header;
	int i = 0;
	if (list.header->next == list.trailer || position <= 0)
	{
		printf("invalid position\n");
		return 0;
	}//�Ѱ��� ������ ���� ����� �ٷ� ����
	for (tmp; tmp != list.trailer && i < position; tmp = tmp->next, i++);
	//header���� �����ؼ� trailer ���� �����鼭 position �� �ش��ϴ� ������ �̵�
	if (tmp == list.trailer)
	{
		printf("invalid position\n");
		return 0;
	}
	if (tmp != list.header)
		tmp->prev->next = tmp->next;
	if (tmp != list.trailer)
		tmp->next->prev = tmp->prev;
	free(tmp);
}


char get_entry(List list, int position) {
	Node* tmp = list.header;
	if (position == 0) {
		printf("invalid position\n");
		return 0;
	}
	while (position--) {
		if (tmp->next == NULL) {
			printf("invalid position\n");
			return 0;
		}
		tmp = tmp->next;
	}//��ȸ

	if (tmp->next == NULL) {
		printf("invalid position\n");
		return 0;
	}//Ʈ���Ϸ� ������� Ȯ��
	printf("%c\n", tmp->elem);
	return tmp->elem;
}

void print(List list) {
	Node* tmp = list.header->next;
	while (tmp->next != NULL) {
		printf("%c", tmp->elem);
		tmp = tmp->next;
	}//��ȸ
	printf("\n");
}

void init_list(List* list) {
	list->header = createNode(0); 
	list->trailer = createNode(0);
	list->header->next = list->trailer;
	list->trailer->prev = list->header;
} //���, Ʈ���Ϸ� ��� �Ҵ� �� �ʱ�ȭ

void free_list(Node* list) {
	Node* tmp = list;
	if (tmp->next != NULL) {
		free_list(list->next);
	}//��� ȣ��
	free(tmp);
}

int main(void) {
	List list; // ����Ʈ ����
	char op, item; // �Է� ������ ����, ������
	int position; // �Է� ��ġ
	int num_op; // ������ ����
	init_list(&list); // ����Ʈ �ʱ�ȭ (���, Ʈ���Ϸ� ��� �Ҵ� �� �ʱ�ȭ)
	scanf_s("%d", &num_op); // ���� ���� �Է�
	for (int i = 0; i < num_op; ++i) {
		getchar(); // ���� �Ǵ� ���๮�� �б�
		scanf_s("%c", &op); // ���� ����

		switch (op) {
		case 'A': // ����
			scanf_s("%d %c", &position, &item);
			add(list, position, item);
			break;
		case 'D': // ����
			scanf_s("%d", &position);
			Delete(list, position);
			break;
		case 'G': // ����
			scanf_s("%d", &position);
			get_entry(list, position);
			break;
		case 'P': // ���
			print(list);
			break;
		}
	}

	free_list(list.header); // ����Ʈ�� ��� ����
	
	return 0;
}