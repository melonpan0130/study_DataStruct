#include<stdio.h>

int n;

void PreOrder(char a[], int node_num) {
	if (node_num<n && a[node_num] != NULL) {
		printf("%c -> ", a[node_num]); // 출력
		PreOrder(a, node_num * 2); //왼쪽 이동
		PreOrder(a, node_num * 2 + 1); //오른쪽 이동
	}
}

void InOrder(char a[], int node_num) {
	if (node_num<n && a[node_num]!=NULL) {
		InOrder(a, node_num*2); //왼쪽 이동
		printf("%c -> ", a[node_num]); // 출력
		InOrder(a, node_num * 2+1); //오른쪽 이동
	}
}

void PostOrder(char a[], int node_num) {
	if (node_num<n && a[node_num] != NULL) {
		PostOrder(a, node_num * 2); //왼쪽 이동
		PostOrder(a, node_num * 2 + 1); //오른쪽 이동
		printf("%c -> ", a[node_num]); // 출력
	}
}

void main(void) {
	char a[] = { NULL, 'A', 'B', 'C', 'D', 'E',NULL,'F',NULL,NULL,'G',NULL, NULL,NULL,'H','I',NULL,NULL,NULL,NULL, NULL,'J' };

	n = sizeof(a) / sizeof(char);

	printf("전위 운행 : ");
	PreOrder(a, 1); printf("end\n");
	printf("준위 운행 : ");
	InOrder(a, 1); printf("end\n");
	printf("후위 운행 : ");
	PostOrder(a, 1); printf("end\n");

	return 0;
}