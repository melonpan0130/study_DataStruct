#include <stdio.h>
#define SIZE 6

int rear = -1;
int front = 0;

char queue[SIZE];

int add(char data) {
	if (rear == SIZE-1) {//overflow인지 검사
		printf("Queue is Full!\n");
		return -1;
	}
	queue[++rear] = data;
	return 0;
}

char Queue_delete(void) {
	if (front > rear) {
		printf("Queue is Empty!\n");
		return '\0'; //null문자 : char 인 경우이기 때문에 null문자 반환
	}
	return queue[front++];
}

int main(void) {
	add('A'); add('B'); add('C');
	printf("delete: %c\n", Queue_delete()); //delete : A
	printf("delete: %c\n", Queue_delete()); //delete : B
	printf("delete: %c\n", Queue_delete()); //delete : C
	// Queue is Empty!
	printf("delete: %c\n", Queue_delete()); //delete :

	add('D'); add('E'); add('F');
	add('G'); // Queue is Full!
	
	return 0;
}