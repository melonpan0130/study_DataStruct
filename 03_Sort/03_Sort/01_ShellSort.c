#include<stdio.h>

void ShellSort(int a[], int n) {
	int t, i, j, key;
	for (t = n / 2; t > 0; t /= 2) {
		for (i = t; i < n; i++) {
			key = a[i];
			for (j = i - t; j >= 0; j -= t) {
				if (a[j] > key)
					a[j + t] = a[j];
				else break;
			}
			a[j + t] = key;
		}
	}
}// shell sort


int main(void) {
	int a[] = { 17,8,20,11,5,12,15,7 };
	int i, n = sizeof(a) / sizeof(int);

	printf("정렬 전 : ");
	for (i = 0; i < n; i++)printf("%d    ", a[i]);
	ShellSort(a, n);
	printf("\n정렬 후 : ");
	for (i = 0; i < n; i++)printf("%d    ", a[i]);
	printf("\n");

	return 0;
}