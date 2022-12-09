#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void sizeMatrix_row(int* row) {
	printf("Input size row: ");
	while (scanf("%d", &*row) != 1 || getchar() != '\n' || *row < 0) {
		printf("Wrong input. Try again!\n");
		printf("Size row = ");
		rewind(stdin);
	}
}
void sizeMatrix_col(int* col) {
	printf("Input size col: ");
	while (scanf("%d", &*col) != 1 || getchar() != '\n' || *col < 0) {
		printf("Wrong input. Try again!\n");
		printf("Size col = ");
		rewind(stdin);
	}
}

int** allocateMemory(int row, int col) {
	int** a;
	a = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		a[i] = (int*)malloc((col + 1) * sizeof(int));
	}
	return a;
}

void proverka_input(int** mass, int i, int j) {

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
				mas[i][j] = -50 + rand() % 150;
		}
	}
}


void print_matrix(int** a, int row, int col) {
	printf("\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


void swap(int* a, int* b) {
	int temp = 0;
	temp = *b;
	*b = *a;
	*a = temp;
}

void shellSort_sum(int** a, int row, int col) {
	for (int i = 0; i < row;i++)
	{
		int sum = 0;
		for (int j = 0; j < col; j++)
		{
			if ((j + 1) % 2 == 0) {
				sum += a[i][j];
			}
		}
		a[i][col] = sum;
		printf("Amount on line  %d = %d\n", i + 1, sum);
	}
}



void  shell_sort(int** a, int row, int col) {
	int m = col;
	shellSort_sum(a, row, col);
	for (int s = row / 2; s > 0; s /= 2) {
	for (int i = s; i < col; ++i) {
		for (int j = i - s; j >= 0 && a[j][col] < a[j + s][col]; j -= s) {
			for (int k = 0; k <= col; k++) {
				int temp = a[j][k];
				a[j][k] = a[j + s][k];
				a[j + s][k] = temp;
			}
			}
		}
	}
}

void clearing_memory(int** a, int row) {
	for (int i = 0; i < row; i++) {
		free(a[i]);
	}
	free(a);
}
