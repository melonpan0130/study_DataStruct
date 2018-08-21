#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node *link;
};

void deleteNode(struct node *p) {
	if (p != NULL) {
		deleteNode(p->link);
		free(p);
	}
}

int main() {
	struct node *head, *p;
	char ch;
	printf("한 문자 입력 : ");
	scanf_s("%c", &ch, 1);
	getchar(); //엔터가 들어감
	head = (struct node *)malloc(sizeof(struct node));
	p = head;
	p->data = ch;
	do {
		printf("한 문자 입력 : "); scanf_s("%c", &ch, 1); getchar();
		if (ch == '0') break;
		p->link = (struct node *)malloc(sizeof(struct node));
		p = p->link;
		p->data = ch;
	} while (1);
	p->link = NULL;

	//printing
	p = head;
	int i = 1;
	while (p != NULL) {
		printf("%d) %c \n", i, p->data);
		p = p->link;
		i++;
	}
	
	//delete
	p = head;
	deleteNode(p);
	return 0;
}