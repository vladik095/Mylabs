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


int swap(int* a, int* b) {
	int p = *a;
	*a = *b;
	*b = p;
	return 0;
}




int main() {
	int row, col;
	int array_size[100][100];
	scanf_row(&row);
	scanf_col(&col);
    char mass [100];
	printf("If you want to enter data into the array, enter 'yes'\n");
	scanf("%s", &mass);

	if (strcmp("yes", mass) == 0)
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				printf("ar %d %d =  ", i + 1, j + 1);
				while (scanf("%d", &array_size[i][j]) != 1 || getchar() != '\n') {
					printf("Wrong input. Try again!\n");
					printf("array  %d %d =  ", i + 1, j + 1);
					rewind(stdin);
				}
			}
		} 
	    else {
			srand(time(NULL));
			for (int i = 0; i < row; i++) { 
				for (int j = 0; j < col; j++)   
					array_size[i][j] = -100 + rand() % 200;
			}
		}
		
		for (int a = 0; a < row; a++)
		{
			for (int b = 0; b < col; b++)
			{
				printf("%d ", array_size[a][b]);
			printf("\t");
			}
			printf("\n");
			printf("\v");
			
		}

		int sum = 0;
		int summa[100];
		for (int i = 0; i < row; i++)
		{
			sum = 0;
			for (int j = 0; j < col; j++)
			{
				if (array_size[i][j] % 2 == 0) {
					sum += array_size[i][j];
				}
			}
			summa[i] = sum;
			printf("sum %d = %d \n", i + 1, sum);
		}
	
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < row; j++) {
				if (summa[i] < summa[j]) {
					swap(&summa[i], &summa[j]);
					for (int k = 0; k < col; k++) {
						swap(&array_size[i][k], &array_size[j][k]);
					} 
				}
			}
		}
		printf("\n");
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				printf("%d ", array_size[i][j]);
			printf("\t");
			}
			printf("\n");
			printf("\v");
		}

		return 0;
	}
