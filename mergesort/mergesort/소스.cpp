#include<stdio.h>
#include<stdlib.h>


#define ARRAY_SIZE 50


int B[ARRAY_SIZE];
int n;

void mergeSort(int A[]);
void rMergeSort(int A[], int l, int r);
void merge(int A[], int l, int m, int r);
void printArray(int A[]);

void mergeSort(int A[]) {
	rMergeSort(A, 0, n - 1);
	
	return ;
}

void rMergeSort(int A[], int l, int r) {
	int m;
	if (l < r) {
		m = (l + r) / 2;
		/*printf("%d %d %d", l, m, r);
		printf("\n");*/
		rMergeSort(A, l, m);
		
		
		rMergeSort(A, m + 1, r);
		merge(A, l, m, r);
	}
	return ;
}

void merge(int A[],int l,int m, int r) {
	int i = l;
	int k = l;
	int j = m + 1;
	//printArray(A);
	while (i <= m && j <= r) {
		if (A[i] <= A[j]) {
			B[k++] = A[i++];
		}
		else {
			B[k++] = A[j++];
		}
	}
	while (i <= m) {
		B[k++] = A[i++];
	}
	while (j <= r) {
		B[k++] = A[j++];
	}
	for (k = l; k <= r; k++) {
		A[k] = B[k];
	}
	return ;
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

	scanf_s("%d", &numofInput);
	n = numofInput;
	for (int i = 0; i < numofInput; i++) {
		scanf_s("%d", &A[i]);
		
	}
	mergeSort(A);
	printArray(A);
	
	return 0;
}