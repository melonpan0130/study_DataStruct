#include <stdio.h>

void BubbleSort(int a[], int n) {
	int i = 1, j, temp, chk = 1;
	while (chk == 1) {
		chk = 0;
		for (j = 0; j < n - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				chk = 1; 
			}
		}
		i++;
	}
}

int main() {
	int a[] = { 7,12,6,11,3,8,5,2 };
	int n = sizeof(a) / sizeof(int);
	int i;
	printf("정렬 전 : ");
	for (i = 0; i < n; i++)printf("%4d", a[i]);
	BubbleSort(a, n);
	printf("\n정렬 후 : ");
	for (i = 0; i < n; i++)printf("%4d", a[i]);
	printf("\n");
	return 0;
}