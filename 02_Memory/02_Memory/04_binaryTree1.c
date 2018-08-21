#include <stdio.h>
#include <stdlib.h>

struct node{
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
		printf("%d\n", p->data);
		p->llink = binaryTree(a, left, mid - 1);
		p->rlink = binaryTree(a, mid + 1, right);
	}
	return p;
}

void delete(struct node *p) {
	if (p != NULL) {
		delete(p->llink); // 왼쪽으로 직진
		delete(p->rlink); // 오른쪽으로 직진
		printf("%d\t", p->data);
		free(p);
	}
}

int main(void) {
	int a[] = { 3,5,7,10,15,17,20,25,28,31,33,35 };
	int n;
	struct node* root;
	n = sizeof(a) / sizeof(int);
	root = binaryTree(a, 0, n - 1);
	return 0;
}