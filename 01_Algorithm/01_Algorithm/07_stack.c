#include <stdio.h>
#define SIZE 6

int stack[SIZE];
int top = -1;

int push(int data) {
	if (top == SIZE - 1) {
		printf("Stack is Full!\n");
		return -1;
	}
	stack[++top] = data;
	return 0;
}

int pop(void) {
	if (top == -1) {
		printf("Stack is Empty!\n");
		return -1;
	}
	return stack[top--];
}

int main(void) {
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70); //stack is Full!
	printf("%d\n", pop()); //60
	printf("%d\n", pop()); //50
	printf("%d\n", pop()); //40
	printf("%d\n", pop()); //30
	printf("%d\n", pop()); //20
	printf("%d\n", pop()); //10
	printf("%d\n", pop()); //Stack is Empty!

	push(80); 
	push(90);
	return 0;
}