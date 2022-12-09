#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int scanf_row(int* prow) {
		printf("raw = ");
	while (scanf("%d", &*prow) != 1 || getchar() != '\n' || *prow < 0 || *prow > 100){
		printf("Wrong input. Try again\n");
		printf("raw = ");
		rewind(stdin);
	}
	return *prow;
}


int scanf_array(int* prow, int* pcol , int* frst) {
	//int ar[100][100];
	for (int i = 0; i < *prow; i++)
	{
		for (int j = 0; j < *pcol; j++)
		{
			int* sc = frst;
			scanf("%d", &sc);
			frst++;
		}
	}
	return *prow;
}



int scanf_col(int* pcol) {
	printf("col = ");
	while (scanf("%d", &*pcol) != 1 || getchar() != '\n' || *pcol < 0|| *pcol > 100) {
		printf("Wrong input. Try again\n");
		printf("col = ");
		rewind(stdin);
	}
		return *pcol;
}

int swap(int *a, int *b) {
	int p = *a;
	*a = *b;
	*b = p;
	return 0;
}






//int input_matrix(int* praw, int* pcol) {
//	double* A[100][100];
//	for (int i = 0; i < *praw; i++)
//	{
//		for (int j = 0; j < *pcol; j++)
//		{
//			scanf("%d", &*A[i][j]);
//		}
//	}
//	return *praw, *pcol;
//}

//for (int a = 0; a < *praw; a++)
//{
//	for (int b = 0; b < *pcol; b++)
//	{
//		printf("%d ", *pA[a][b]);
//	}
//	printf("\n");
//}


