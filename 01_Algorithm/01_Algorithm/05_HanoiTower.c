#include <stdio.h>

void HanoiTower(int n, char a, char b, char c) {
	if (n == 1)printf("n: %d   a: %c  b: %c  c: %c     원판 %d, %c->%c\n", n, a, b, c, n, a, c, n);
	else {
		HanoiTower(n - 1, a, c, b);
		printf("n: %d   a: %c  b: %c  c: %c     원판 %d, %c->%c\n", n, a, b, c, n, a, c);
		HanoiTower(n - 1, b, a, c);
	}
}

int main() {
	int n = 4;
	HanoiTower(n, 'A', 'B', 'C');
	return 0;
}