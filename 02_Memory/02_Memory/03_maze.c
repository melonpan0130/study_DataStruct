#include <stdio.h>
#define M 12
#define N 16
#define MAX M*N

enum boolean{false, true};
int top = -1;
int stack[MAX][3] = { 0, };

enum boolean push(int x, int y, int d) {
	if (top >= MAX-1) {
		printf("stack overflow\n");
		return false;
	}
	top = top + 1;
	stack[top][0] = x;
	stack[top][1] = y;
	stack[top][2] = d;
	return true;
}

enum boolean pop(int *x, int *y, int *d) {
	if (top == -1) {
		printf("stack underflow\n");
		return false;
	}
	*x = stack[top][0];
	*y = stack[top][1];
	*d = stack[top][2];
	top = top - 1;
	return true;
}

enum boolean mazeSearch(int maze[M][N]) {
	int in_x, in_y, out_x, out_y;
	int view_x, view_y, current_x, current_y;
	int d = 0;//d는 이동할수 있는 0~8 방향중 하나로, 0에서 출발
	int move[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };

	printf("출발 행 : "); scanf_s("%d", &in_x);
	printf("출발 열 : "); scanf_s("%d", &in_y);
	printf("도착 행 : "); scanf_s("%d", &out_x);
	printf("도착 열 : "); scanf_s("%d", &out_y);

	current_x = in_x;
	current_y = in_y;

	while (1) {
		while (d < 8 ) {
			view_x = current_x + move[d][0];
			view_y = current_y + move[d][1];
			if (view_x >= 0 && view_x < M&&view_y >= 0 && view_y < N&&maze[view_x][view_y] == 1) {
				maze[current_x][current_y] = 9;//미로표시
				if (!push(current_x, current_y, d + 1)) return false;
				current_x = view_x;
				current_y = view_y;
				if (current_x == out_x && current_y == out_y) {
					maze[current_x][current_y] = 9;
					return true;
				}
				d = 0;
			}
			else d++;
		}
		maze[current_x][current_y] = 2;//돌아온 경로 표시
		if (pop(&current_x, &current_y, &d) == false)return false;
	}
}

int main(void) {
	//0은 벽, 1은 갈수 있는 통로
	int maze[M][N] = { {1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0},
											{0,1,1,0,0,0,1,0,0,1,0,0,1,0,0,1},
											{1,0,0,1,1,1,1,1,1,0,0,0,1,0,0,1},
											{1,0,0,0,0,1,0,0,0,0,0,1,1,1,1,0},
											{1,1,0,0,0,0,1,0,1,1,1,0,0,0,1,0},
											{0,0,1,0,0,1,0,1,0,0,1,1,0,0,0,1},
											{0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
											{1,0,0,1,0,1,1,1,1,1,0,1,1,0,0,0},
											{1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0},
											{0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,1},
											{1,1,0,0,0,1,1,1,1,1,0,0,1,1,0,1},
											{1,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1} };
	int i, j;

	if (mazeSearch(maze) == false) printf("출구까지 미로 없음!!\n\n");
	else {
		printf("\n미로 찾기 완료\n");
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) 
				if (maze[i][j] == 9)printf("%d ", maze[i][j]); //미로이면 *출력
				 else printf("%d ", maze[i][j]==0?0:1); //미로가 아니면 초기 데이터 출력
			printf("\n");
		}
	}
	printf("\n");

	return 0;
}