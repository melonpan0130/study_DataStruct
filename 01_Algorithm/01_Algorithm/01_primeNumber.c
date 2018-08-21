#include <stdio.h>
#include <math.h>
#include <time.h>

void main(void) {
	int i, j, k = 0, d;
	int a = 100000000, b = 1000010000; //a=100000000, b=1000010000�� ����
	clock_t before, after; //�ð��� ���ϴ� �Լ�

	before = clock(); // ���� ���ϱ� ���� �ð�
	for (i = a; i <= b; i++) {
		d = i / 2;
		for (j = 2; j <= d; j++) {
			if (i % j == 0) {
				k = 1;
				break;
			}
		}
		if (k == 0) printf("%d, ", i);
		k = 0;
	}
	after = clock(); // ���� ����
	printf("\n%.3lf�� �ҿ�\n\n", (double)(after - before) / 1000);

	before = clock();
	k = 0;
	for (i = a; i <= b; i++) {
		if (i % 2 == 0) continue;
		d = (int)sqrt((double)i);
		for (j = 2; j <= d; j++) {
			if (i % j == 0) {
				k = 1;
				break;
			}
		}
		if (k == 0) printf("%d, ", i);
		k = 0;
	}
	after = clock();

	printf("\n%.3lf�� �ҿ�\n\n", (double)(after - before) / 1000);
}
