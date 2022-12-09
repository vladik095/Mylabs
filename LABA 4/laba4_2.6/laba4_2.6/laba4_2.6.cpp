#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int scanf_row(int* prow) {
	printf("row = ");
	while (scanf("%d", &*prow) != 1 || getchar() != '\n' || *prow < 0 || *prow > 100) {
		printf("Wrong input. Try again\n");
		printf("row = ");
		rewind(stdin);
	}
	return *prow;
}

int scanf_col(int* pcol) {
	printf("col = ");
	while (scanf("%d", &*pcol) != 1 || getchar() != '\n' || *pcol < 0 || *pcol > 100) {
		printf("Wrong input. Try again\n");
		printf("col = ");
		rewind(stdin);
	}
	return *pcol;
}

int main() {
	int row, col;
	double array_size[100][100];
	scanf_row(&row);
	scanf_col(&col);
	char mass[100];
	printf("If you want to enter data into the array, enter 'yes'\n ");
	scanf("%s", &mass);

	if (strcmp("yes", mass) == 0)
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				printf("ar %d %d =  ", i + 1, j + 1);
				while (scanf("%lf", &array_size[i][j]) != 1 || getchar() != '\n') {
					printf("Wrong input. Try again!\n");
					printf("array  %d %d =  ", i + 1, j + 1);
					rewind(stdin);
				}
			} 
		} else {
			srand(time(NULL));
			for (int i = 0; i < row; i++) {  
				for (int j = 0; j < col; j++)   
					array_size[i][j] = -99 + rand() % 200;
			}
		}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%0.2lf ", array_size[i][j]);
		printf("\t");
		}
		printf("\n");
		printf("\v");
	}
	for (int i = 0; i < row; i++)
	{
		
		for (int j = 0; j < col; j++)
		{
			if (array_size[i][j] < 0) {
				printf("String %d\n", i + 1);
				for (int сnt = 0; сnt < row; сnt++)
					array_size[сnt][i] /= 2.0;
			break;
			}
		}
	}
	printf("\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%0.2lf ", array_size[i][j]);
		printf("\t");
		}
		printf("\n");
		printf("\v");

	}
	return 0;
}