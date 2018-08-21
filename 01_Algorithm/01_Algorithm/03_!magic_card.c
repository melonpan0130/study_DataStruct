#include <stdio.h>

int main() {
	char choice;
	int answer[4];
	printf("Magic Card\n");
	printf("Think of one number from 1 to 31.\n");
	//card 1
	printf("\n --------------------------\n");
	printf("|%4d | %4d | %4d | %4d | \n", 1, 2, 3, 4);
	printf(" --------------------------\n");
	printf("|%4d | %4d | %4d | %4d |\n ", 5, 6, 7, 8);
	printf(" --------------------------\n");
	printf("|%4d | %4d | %4d | %4d | \n", 9, 10, 11, 12);
	printf(" --------------------------\n");
	printf("|%4d | %4d | %4d | %4d | \n", 13, 14, 15, 16); 
	printf(" --------------------------\n");

	printf("Is it there?(y/n) : ");
	scanf_s("%c", &choice);
	if (choice == 'y') answer[0] = 1;
	else answer[0] = 0;

	//card 2
	printf("\n --------------------------\n");
	printf("|%4d | %4d | %4d | %4d | \n", 3, 4, 7, 8);
	printf(" --------------------------\n");
	printf("|%4d | %4d | %4d | %4d |\n ", 11, 12, 15, 16);
	printf(" --------------------------\n");
	printf("|%4d | %4d | %4d | %4d | \n", 19, 20, 23, 24);
	printf(" --------------------------\n");
	printf("|%4d | %4d | %4d | %4d | \n", 27, 28, 31, 0);
	printf(" --------------------------\n");

	printf("Is it there? (y/n) : ");
	scanf_s("%c", &choice);
	if (choice == 'y') answer[1] = 1;
	else answer[1] = 0;

	return 0;
}