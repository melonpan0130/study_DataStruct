#include <stdio.h>

void InsertionSort(int a[], int n) {
	int i, j, key;
	for (i = 0; i < n; i++) {
		key = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (key < a[j])a[j + 1] = a[j];
			else break;
		}
		a[j + 1] = key;
	}
}

int main() {
	int a[] = { 7,12,6,11,3,8,5,2 };
	int n = sizeof(a) / sizeof(int);
	int i;
	printf("정렬 전 : ");
	for (i = 0; i < n; i++)printf("%4d", a[i]);
	InsertionSort(a, n);
	printf("\n정렬 후 : ");
	for (i = 0; i < n; i++)printf("%4d", a[i]);
	printf("\n");
	return 0;
}