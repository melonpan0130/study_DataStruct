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
		printf("%d -> ", p->data); // ���
		preOrder(p->llink); // ���� �̵�
		preOrder(p->rlink); //������ �̵�
	}
}

void inOrder(struct node *p) {
	if (p != NULL) {
		inOrder(p->llink); //���� �̵�
		printf("%d -> ", p->data); // ���
		inOrder(p->rlink); //������ �̵�
	}
}

void postOrder(struct node *p) {
	if (p != NULL) {
		inOrder(p->llink); // ���� �̵�
		inOrder(p->rlink); //������ �̵�
		printf("%d -> ", p->data); // ���
	}
}

void delete(struct node *p) {
	if (p != NULL) {
		delete(p->llink); // �������� �̵�
		delete(p->rlink); // ���������� �̵�
		printf("%d -> ", p->data);
		free(p);
	}
}

int main(void) {
	int a[] = { 3,5,7,10,15,17,20,25,28,31,33,35 };
	int n;
	struct node* root;
	n = sizeof(a) / sizeof(int);
	printf("��� ���� ���� : ");
	root = binaryTree(a, 0, n - 1);
	printf("end");
	printf("\n���� ���� : ");
	preOrder(root);
	printf("end");
	printf("\n�������� : ");
	inOrder(root);
	printf("end");
	printf("\n�������� : ");
	postOrder(root);
	printf("end");
	printf("\n��� ���ż��� : ");
	delete(root);
	printf("end\n");

	return 0;
}