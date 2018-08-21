#include <stdio.h>
#define SIZE 6

int rear = -1;
int front = 0;
int cnt = 0;

char queue[SIZE];

int add(char data) {
	if (cnt == SIZE) {//overflow인지 검사
		printf("Circular Queue is Full!\n");
		return -1;
	}
	cnt++;
	queue[++rear%SIZE] = data;
	return 0;
}

char delete(void) {
	if (cnt == 0) {
		printf("Circular Queue is Empty!\n");
		return '\0'; //null문자 : char 인 경우이기 때문에 null문자 반환
	}
	cnt--;
	return queue[front++%SIZE];
}

int main(void) {
	add('A'); add('B'); add('C');
	printf("delete: %c\n", delete()); //delete : A
	printf("delete: %c\n", delete()); //delete : B
	printf("delete: %c\n", delete()); //delete : C
	// Queue is Empty!
	printf("delete: %c\n", delete()); //delete :

	add('D'); add('E'); add('F'); add('G');
	add('H'); add('I'); 
	add('J'); // Circular Queue is Full!

	for (int i = 0; i < SIZE; i++) {
		printf("%d : %c\n", i, queue[i]);
	}

	return 0;
}