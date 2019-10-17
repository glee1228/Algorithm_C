#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NoSuchKey -1

int n;
char* arr;


int rFE3( int l, int r);

int findElement3(int l, int r) {
	return rFE3(l, r);
}
int rFE3(int l, int r) {
	int idx = 0;
	int mid;
	while (idx<n) {
		
		mid = (l + r) / 2;
		if (arr[idx]=='Y') {
			l = mid + 1;
		}
		if (arr[idx] == 'N') {
			r = mid;
		}
		
		
		idx++;
	
	}
	return r;

	

}




int main() {



	int A = 0;
	int B = 0;
	int numofInput;
	scanf_s("%d %d %d", &A, &B, &numofInput);
	n = numofInput;
	arr = (char*)malloc(sizeof(char) * numofInput);
	getchar();
	for (int i = 0; i < numofInput; i++) {
		scanf_s("%c", &arr[i]);
		//insertItem(value[i]);
		
	}
	printf("%d", findElement3(A, B));
	

	free(arr);
	return 0;
}