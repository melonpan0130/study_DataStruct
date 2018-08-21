#include<stdio.h>
#include<malloc.h>

struct node {
	struct node *llink;
	char data;
	struct node *rlink;
};

struct node **queue;
int rear = -1, front = 0;
int nodeCnt = 0;

struct node *newNode(char value) {
	struct node *p;

	p = (struct node *)malloc(sizeof(struct node));
	p->llink = NULL;
	p->data = value;
	p->rlink = NULL;

	return p;
}

struct node *createBinaryTree(char a[]) {
	struct node *root;

	root = newNode(a[0]);
	root->llink = newNode(a[1]);
	root->llink->llink = newNode(a[2]);
	root->llink->llink->rlink = newNode(a[3]);
	root->llink->rlink = newNode(a[4]);
	root->rlink = newNode(a[5]);
	root->rlink->llink = newNode(a[6]);
	root->rlink->llink->rlink = newNode(a[7]);
	root->rlink->llink->rlink->llink = newNode(a[8]);
	root->rlink->rlink = newNode(a[9]);

	return root;
}

void deleteNode(struct node *p) {
	if (p != NULL) {
		deleteNode(p->llink);
		deleteNode(p->rlink);
		printf("%c->", p->data);
		free(p);
	}
}

void preOrder(struct node *p) {
	if (p != NULL) {
		printf("%c->", p->data);
		preOrder(p->llink);
		preOrder(p->rlink);
	}
}

void inOrder(struct node *p) {
	if (p != NULL) {
		inOrder(p->llink);
		printf("%c->", p->data);
		inOrder(p->rlink);
	}
}

void postOrder(struct node *p) {
	if (p != NULL) {
		postOrder(p->llink);
		postOrder(p->rlink);
		printf("%c->", p->data);
	}
}

void add(struct node *p) {
	if (rear == nodeCnt - 1) {
		printf("\nQudue is Full!");
		return;
	}
	queue[++rear] = p;
}

struct node *delete(void) {
	if (rear < front) {
		printf("\nQudue is Empty!");
		return NULL;
	}
	return queue[front++];
}

void levelOrder(struct node *p) {
	
	printf("%c", p->data);
	add(p);
	/*
	while ((p = delete()) != NULL) {
		if (p->llink != NULL) {
			printf("->%c", p->llink->data);
			add(p->llink);
		}
		if (p->rlink != NULL) {
			printf("->%c", p->rlink->data);
			add(p->rlink);
		}
	}
	 또는 */
	p = delete();
	while (p != NULL) {
		if (p->llink != NULL) add(p->llink);
		if (p->rlink != NULL) add(p->rlink);
		p = delete();
		printf("->%c", p->data);
	}
}

int main(void) {
	char a[] = { 'L', 'E', 'B', 'C', 'I', 'R', 'O', 'Q', 'P', 'T' };
	struct node *root;

	root = createBinaryTree(a); // 첫 번째 생성된 노드의 주소가 리턴되어 root에 들어간다.
	nodeCnt = sizeof(a) / sizeof(char);

	printf("\n전위 운행 결과: ");
	preOrder(root);
	printf("\b\b  ");
	printf("\n중위 운행 결과: ");
	inOrder(root);
	printf("\b\b  ");
	printf("\n후위 운행 결과: ");
	postOrder(root);
	printf("\b\b  "); 

	queue = (struct node **)malloc(sizeof(struct node *) * nodeCnt);
	printf("\n레벨 운행 결과: ");
	levelOrder(root);

	printf("\n노드 사라지는 순서: ");
	deleteNode(root);
	printf("\b\b  \n");

	free(queue);

	return 0;
}