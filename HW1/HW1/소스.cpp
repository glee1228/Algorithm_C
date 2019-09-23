#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char elem;
	struct Node* prev;
	struct Node* next;
}Node; // 노드 정의

typedef struct List {
	struct Node* header;
	struct Node* trailer;
}List; // 리스트 정의

Node* createNode(char item) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->elem = item;
	tmp->next = tmp->prev = NULL;
	return tmp;
} // 새로운 노드 생성

Node* add(List list, int position, const char item) {
	Node* tmp = list.header; //새로운 노드가 들어갈 자리의 왼쪽 노드를 가리키는 포인터
	Node* newNode = createNode(item); //입력할 노드 생성
	Node* Right;  //입력할 노드 오른쪽 노드를 가르키는 포인터

	while (--position) {
		if (tmp->next == NULL) {
			printf("invalid position\n");
			return;
		}
		tmp = tmp->next;
	} //순회
	
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
	}//한개도 없을때 삭제 수행시 바로 리턴
	for (tmp; tmp != list.trailer && i < position; tmp = tmp->next, i++);
	//header부터 시작해서 trailer 까지 돌리면서 position 에 해당하는 값까지 이동
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
	}//순회

	if (tmp->next == NULL) {
		printf("invalid position\n");
		return 0;
	}//트레일러 노드인지 확인
	printf("%c\n", tmp->elem);
	return tmp->elem;
}

void print(List list) {
	Node* tmp = list.header->next;
	while (tmp->next != NULL) {
		printf("%c", tmp->elem);
		tmp = tmp->next;
	}//순회
	printf("\n");
}

void init_list(List* list) {
	list->header = createNode(0); 
	list->trailer = createNode(0);
	list->header->next = list->trailer;
	list->trailer->prev = list->header;
} //헤더, 트레일러 노드 할당 및 초기화

void free_list(Node* list) {
	Node* tmp = list;
	if (tmp->next != NULL) {
		free_list(list->next);
	}//재귀 호출
	free(tmp);
}

int main(void) {
	List list; // 리스트 선언
	char op, item; // 입력 연산의 종류, 아이템
	int position; // 입력 위치
	int num_op; // 연산의 개수
	init_list(&list); // 리스트 초기화 (헤더, 트레일러 노드 할당 및 초기화)
	scanf_s("%d", &num_op); // 연산 개수 입력
	for (int i = 0; i < num_op; ++i) {
		getchar(); // 공백 또는 개행문자 읽기
		scanf_s("%c", &op); // 연산 종류

		switch (op) {
		case 'A': // 삽입
			scanf_s("%d %c", &position, &item);
			add(list, position, item);
			break;
		case 'D': // 삭제
			scanf_s("%d", &position);
			Delete(list, position);
			break;
		case 'G': // 참조
			scanf_s("%d", &position);
			get_entry(list, position);
			break;
		case 'P': // 출력
			print(list);
			break;
		}
	}

	free_list(list.header); // 리스트의 노드 해제
	
	return 0;
}