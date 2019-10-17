#include<stdio.h>
#include<stdlib.h>


#define ARRAY_SIZE 50

int n;

struct Partition {   
	int LT[ARRAY_SIZE];
	int EQ;            
	int GT[ARRAY_SIZE];
}Partition;

int* merge(int LT[], int EQ, int GT[]) {
	int arr[ARRAY_SIZE];
	return arr;
}
int findPivotIndex(int A[], int l, int r) {
	int k;

	return k;
}
struct Partition partition(int A[], int k) {
	struct Partition P;

	return P;
}
void quickSort(int A[]) {
	int size = sizeof(A) / sizeof(A[0]);
	int k;
	int l = 0;
	int r = n - 1;
	struct Partition pt;
	if (size > 1) {
		k = findPivotIndex(A,l,r);
		pt = partition(A, k);
		
		quickSort(pt.LT);
		quickSort(pt.GT);
		A = merge(pt.LT, pt.EQ, pt.GT );
	}
}

void printArray(int A[]) {

	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}
int main() {

	int numofInput = 0;
	int value[30];
	int A[ARRAY_SIZE];

	scanf("%d", &numofInput);
	n = numofInput;
	for (int i = 0; i < numofInput; i++) {
		scanf("%d", &A[i]);

	}
	quickSort(A);
	printArray(A);

	return 0;
}