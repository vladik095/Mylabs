#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

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
void scanf_array(int n, int* b) {
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i + 1);
		scanf("%d", &b[i]);
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
void scan_matrix(int** a, int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("Array number %d %d\n", i + 1, j + 1);
			scanf("%d", &a[i][j]);
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
			*a = (int*)realloc(a, *col * sizeof(int));
			j--;
		}
	}
}
void print_matrix(int** a, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

}
void clearing_memory(int** a, int row) {
	for (int i = 0; i < row; i++) {
		free(a[i]);
	}
	free(a);
}
