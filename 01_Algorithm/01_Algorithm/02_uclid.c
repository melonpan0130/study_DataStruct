#include <stdio.h>

int main() {
	int m, n, r, t;
	
	scanf_s("%d %d", &m, &n);
	if (m < n) {
		t = m;
		m = n;
		n = t;
	}
	r = m % n;
	while ((r=m%n)!=0) {
		m = n;
		n = r;
	}
	printf("쵀대 공약수 : %d\n", n);
	return 0;
}