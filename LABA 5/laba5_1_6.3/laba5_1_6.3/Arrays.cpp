#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void size_array(int* n) {
	printf("Input size array: ");
	while (scanf("%d", &*n) != 1 || getchar() != '\n' || *n < 0) {
		printf("Wrong input. Try again!\n");
		printf("Size array = ");
		rewind(stdin);
	}
}
int* memory(int n) {
	return (int*)malloc(2 * n * sizeof(int));
}
void scanf_array(int n, int *b) {
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i + 1);
		while (scanf("%d", &b[i]) != 1 || getchar() != '\n') {
			printf("Wrong input. Try again!\n");
			printf("a[%d] = ", i + 1);
			rewind(stdin);
		}
	}
}
void add_square_after_number(int n, int* b) {
	for (int i = n - 1; i >= 0; i--) {
		b[i * 2] = b[i];
		b[i * 2 + 1] = b[i] * b[i];
	}
}
void print_array(int n, int* b) {
	for (int i = 0; i < 2 * n; i++)
		printf("%d ", b[i]);
}
//
void SizeMatrix_row(int* row) {
	printf("Input size row: ");
	while (scanf("%d", &*row) != 1 || getchar() != '\n' || *row < 0) {
		printf("Wrong input. Try again!\n");
		printf("Size row = ");
		rewind(stdin);
	}
}
void SizeMatrix_col(int* col) {
	printf("Input size col: ");
	while (scanf("%d", &*col) != 1 || getchar() != '\n' || *col < 0) {
		printf("Wrong input. Try again!\n");
		printf("Size col = ");
		rewind(stdin);
	}
}
int** AllocateMemory(int row, int col) {
	int** a;
	a = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		a[i] = (int*)malloc(col * sizeof(int));
	}
	return a;
}


void proverka_input(int **mass,int i, int j) {

	printf("Array number %d %d = \n", i + 1, j + 1);
	while (scanf("%d", &mass[i][j]) != 1 || getchar() != '\n' || mass[i][j] < -1) {
		printf("Wrong input. Try again!\n");
		printf("Array number % d % d = \n", i + 1, j + 1);
		rewind(stdin);
	}
}

void input_matrix(int** mas, int row, int col) {
	char arr[100];
	printf("If you want to enter data into the array, enter 'yes'\n");
	scanf("%s", &arr);
	if (strcmp("yes", arr) == 0) {
		int i, j;
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				proverka_input(mas, i, j);
			}
		}
	} else {
		srand(time(NULL));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				mas[i][j] = -100 + rand() % 150;
		}
	}
}
void del_column(int** a, int row, int* col, int k) {
	for (int i = 0; i < row; i++) {
		for (int j = k; j < *col - 1; j++) {
			a[i][j] = a[i][j + 1];
		}
	}
	(*col)--;
}
void del_negot_column(int** a, int row, int* col) {
	int flag = 0;
	for (int j = 0; j < *col; j++) {
		flag = 0;
		for (int i = 0; i < row; i++) {
			if (a[i][j] < 0) {
				flag++;
			}
		}
		if (flag == row) {
			del_column(a, row, &*col, j);
			a[j] = (int*)realloc(a[j], *col * sizeof(int));
			j--;
		}
	}
}
void print_matrix(int** a, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void clearing_memory(int** a, int row) {
	for (int i = 0; i < row; i++) {
		free(a[i]);
	}
	free(a);
}


void size_k(int* k) {
	printf("Input size row: ");
	while (scanf("%d", &*k) != 1 || getchar() != '\n' || *k < 0) {
		printf("Wrong input. Try again!\n");
		printf("Size row = ");
		rewind(stdin);
	}
}
int** memory_TS(int row, int cnt) {
	int** a;
	a = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++) {
		a[i] = (int*)malloc(cnt * sizeof(int));
	}
	return a;
}
void realloc_memory(int **a, int row, int cnt) {
	for (int i = 0; i < row; i++) {
		cnt = 0;
		for (int j = 0;; j++) {
			cnt++;
			a[i] = (int*)realloc(a[i], cnt * sizeof(int));
			printf("Array number %d %d = \n", i + 1, j + 1);
			scanf("%d", &a[i][j]);
			if (a[i][j] == -1) {
				break;
			}

		}

	}
}
void del_col_after_k(int **a, int *row, int cnt, int k) {
	for (int i = 0; i < *row; i++) {
		cnt = 0;
		for (int j = 0; j < k; j++) {
			a[i] = (int*)realloc(a[i], k * sizeof(int));
		}

	}
}
void print_mtr(int **a, int row, int k) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < k; j++) {
			if (a[i][j] == -1) {
				break;
			}
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}