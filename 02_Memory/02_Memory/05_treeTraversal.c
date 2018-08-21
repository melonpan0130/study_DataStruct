#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *llink;
	int data;
	struct node* rlink;
};

struct node *binaryTree(int a[], int left, int right) {
	struct node *p = NULL;
	int mid;

	if (left <= right) {
		p = (struct node *)malloc(sizeof(struct node));
		mid = (left + right) / 2;
		p->data = a[mid];
		printf("%d -> ", p->data);
		p->llink = binaryTree(a, left, mid - 1);
		p->rlink = binaryTree(a, mid + 1, right);
	}
	return p;
}

void preOrder(struct node *p) {
	if (p != NULL) {
		printf("%d -> ", p->data); // 출력
		preOrder(p->llink); // 왼쪽 이동
		preOrder(p->rlink); //오른쪽 이동
	}
}

void inOrder(struct node *p) {
	if (p != NULL) {
		inOrder(p->llink); //왼쪽 이동
		printf("%d -> ", p->data); // 출력
		inOrder(p->rlink); //오른쪽 이동
	}
}

void postOrder(struct node *p) {
	if (p != NULL) {
		inOrder(p->llink); // 왼쪽 이동
		inOrder(p->rlink); //오른쪽 이동
		printf("%d -> ", p->data); // 출력
	}
}

void delete(struct node *p) {
	if (p != NULL) {
		delete(p->llink); // 왼쪽으로 이동
		delete(p->rlink); // 오른쪽으로 이동
		printf("%d -> ", p->data);
		free(p);
	}
}

int main(void) {
	int a[] = { 3,5,7,10,15,17,20,25,28,31,33,35 };
	int n;
	struct node* root;
	n = sizeof(a) / sizeof(int);
	printf("노드 생성 순서 : ");
	root = binaryTree(a, 0, n - 1);
	printf("end");
	printf("\n전위 운행 : ");
	preOrder(root);
	printf("end");
	printf("\n준위운행 : ");
	inOrder(root);
	printf("end");
	printf("\n후위운행 : ");
	postOrder(root);
	printf("end");
	printf("\n노드 제거순서 : ");
	delete(root);
	printf("end\n");

	return 0;
}