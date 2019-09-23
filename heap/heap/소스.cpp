#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_SIZE 100
#define ARRAY_SIZE 10

//main() 함수
//- 인자: 없음
//- 반환값 : 없음
//- 내용 : 반복적으로 i, d, p 명령에 따라 insertItem, removeMax, printHeap 함수를 각각 호출 수행, q 명령 입력 시 종료.
//◦ insertItem(key) 함수
//- 인자 : 정수 key
//- 반환값 : 없음
//- 내용 : n 위치에 key 삽입, upHeap(n) 호출 수행 후 n(총 키 개수)을 갱신
//- 시간 성능 : O(log n)
//◦ removeMax() 함수
//- 인자 : 없음
//- 반환값 : 삭제된 키(정수)
//- 내용 : downHeap 호출 수행 후 n(총 키 개수)을 갱신
//- 시간 성능 : O(log n)
//◦ upHeap(i) 함수
//- 인자 : 배열 인덱스 i
//- 반환값 : 없음
//- 내용 : 힙 내 위치 i에 저장된 키를 크기에 맞는 위치로 상향 이동
//- 시간 성능 : O(log n)
//◦ downHeap(i) 함수
//- 인자 : 배열 인덱스 i
//- 반환값 : 없음
//- 내용 : 힙 내 위치 i에 저장된 키를 크기에 맞는 위치로 하향 이동
//- 시간 성능 : O(log n)
//◦ printHeap() 함수
//- 인자 : 없음
//- 반환값 : 없음
//- 내용 : 힙에 저장된 키들을 레벨순서로 인쇄
//- 시간 성능 : O(n)
void swap(int* a, int* b);
void insertItem(int data);
void upHeap(int i);
void downHeap(int i);
int removeMax();
void printHeap();

int H[HEAP_SIZE];
int n = 0; 
void printHeap() {
	for (int i = 1; i < n + 1; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");

}

void swap(int* a, int* b) {
	int tmp = *a; 
	*a = *b; 
	*b = tmp;
}

void init() {
	n = 0;
}

int size() {
	return n;
}

void upHeap(int i) {
	int child = i;
	int parent = child / 2;
	while (child > 1 && H[parent] < H[child]) {
		swap(&H[parent], &H[child]);
		child = parent;
		parent = child / 2;
	}
}

void insertItem(int data) {
	H[++n] = data;
	upHeap(n);
}


void downHeap(int i) {
	int parent = i;
	int child = parent * 2;

	
	if (child + 1 <= n) {
		child = (H[child] > H[child + 1]) ? child : child + 1;
	}
	while (child <= n && H[parent] < H[child]) {
		swap(&H[parent], &H[child]);
		parent = child;
		child = child * 2;
		if (child + 1 <= n) {
			child = (H[child] > H[child + 1]) ? child : child + 1;
		}
	}	

}
int removeMax() {
	
	int result = H[1];

	swap(&H[1], &H[n]);
	n--;

	// downheap
	downHeap(1);

	return result;
}

void buildHeap() {
	int parent = n / 2;
	int child = n;
	int start_parent = n / 2;


	for (int i = parent; i >= 1; i--) {
		//printf("%d\n", i);
		//printHeap();
		downHeap(i);
	}

}
int main() {

	int arr[ARRAY_SIZE];
	/*char input = 'o';
	int value = 0;


	while (input != 'q') {
		
		scanf_s("%c", &input);
		

		if (input == 'i') {
			scanf_s("%d", &value);
			insertItem(value);
			printf("%d\n",0);
		}
		else if (input == 'd') {
			printf("%d\n",removeMax());
		}
		else if (input == 'p') {
			printHeap();
		}
		getchar();
	}*/
	int numofInput = 0;
	int value[30];
	scanf_s("%d", &numofInput);
	n = numofInput;
	for (int i= 1; i <= numofInput; i++) {
		scanf_s("%d", &H[i]);
		//insertItem(value[i]);
		
	}
	buildHeap();

	printHeap();
	return 0;
}

//필요 함수 :
//◦ main() 함수
//- 인자 : 없음
//- 반환값 : 없음
//- 내용 : rBuildHeap(1) 또는 buildHeap() 호출하여 힙 생성 후, 힙을 인쇄하고 종료.
//◦ rBuildHeap(i) 함수
//- 인자 : 정수 i(부분 힙의 루트 인덱스)
//- 반환값 : 없음
//- 내용 : 재귀 방식으로 상향식 힙 생성
//- 시간 성능 : O(n)
//◦ buildHeap() 함수
//- 인자 : 없음
//- 반환값 : 없음
//- 내용 : 비재귀 방식으로 상향식 힙 생성
//- 시간 성능 : O(n)
//◦ downHeap(i) 함수 : 문제 1의 downHeap과 동일
//◦ printHeap() 함수 : 문제 1의 printHeap과 동일