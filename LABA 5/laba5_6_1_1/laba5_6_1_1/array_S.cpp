#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void size_k(int* k) {
	printf("Input size k: ");
	while (scanf("%d", &*k) != 1 || getchar() != '\n' || *k < 0) {
		printf("Wrong input. Try again!\n");
		printf("Size k: ");
		rewind(stdin);
	}
}void SizeMatrix_row(int* row) {
	printf("Number of rows: ");
	while (scanf("%d", &*row) != 1 || getchar() != '\n' || *row < 0) {
		printf("Wrong input. Try again!\n");
		printf("Number of rows: ");
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


void proverka_input(int **a,int i, int j) {

	printf("Array number %d %d = \n", i + 1, j + 1);
	while (scanf("%d", &a[i][j]) != 1 || getchar() != '\n' || a[i][j] < -1) {
		printf("Wrong input. Try again!\n");
		printf("Array number % d % d = \n", i + 1, j + 1);
		rewind(stdin);
	}
}

void input_matrix(int** a, int row, int cnt) {
	for (int i = 0; i < row; i++) {
		cnt = 0;
		for (int j = 0;; j++) {
			cnt++;
			a[i] = (int*)realloc(a[i], cnt * sizeof(int));
			proverka_input(a,i,j);
			if (a[i][j] == -1) {
				break;
			}
		}
	}
		}
		

		

	
void del_col_after_k(int** a, int *row,int k) {
	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < k; j++) {
			a[i] = (int*)realloc(a[i], k * sizeof(int));
		}

	}
}



void print_fir(int** a, int row) {
	printf("\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0;; j++) {
			if (a[i][j] == -1) {
				break;
			}
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
}

void print_mtr(int** a, int row,int k) {
	printf("\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0;j < k; j++) {
			if (a[i][j] == -1) {
				break;
			}
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
}

void clearing_memory(int **mass, int row) {
	for (int i = 0; i < row; i++)
		free(mass[i]);
	free(mass);
}