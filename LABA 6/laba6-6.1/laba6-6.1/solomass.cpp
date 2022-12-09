#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <time.h>  
#include <stdlib.h>   
#define N 1000
#define P 1000

void size_array(int* n) {
	printf("Input size array: ");
	while (scanf("%d", &*n) != 1 || getchar() != '\n' || *n < 0) {
		printf("Wrong input. Try again!\n");
		printf("Size array = ");
		rewind(stdin);
	}
}

int* memory(int n) {
	return (int*)malloc(n * sizeof(int));
}
void scanf_array(int n, int* b) {
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i + 1);
		while (scanf("%d", &b[i]) != 1 || getchar() != '\n') {
			printf("Wrong input. Try again!\n");
			printf("a[%d] = ", i + 1);
			rewind(stdin);
		}
	}
}
void random(int* mas, int size_arr) {
	for (int i = 0; i < size_arr; i++)
	{
		mas[i] = -10 + rand() % 21;
	}
}
void print_array(int n, int* b) {
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\n");
}
void swap(int *a, int *b) {
	int temp = 0;
	temp = *b;
	*b = *a;
	*a = temp;
}

void selection_sort(int* arr, int size) {
	double t1 = clock();
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] < 0) {
				int min_index = i;
				for (int j = i + 1; j < size; j++) {
					if (arr[j] < arr[min_index]) {
						min_index = j;
					}
				}
				if (min_index != i) {
					swap(&arr[i], &arr[min_index]);
				}
			}
		}
		double t2 = clock();
		double t3 = (t2 - t1) / CLOCKS_PER_SEC;
		printf("\nSorting time selection sort = %lf\n", t3);
}


void quick_sort(int* arr, int l, int r) {
	if (l >= r) {
		return;
	}
	int i = l, j = r, num = arr[(l + r) / 2];
	while (i <= j) {
		while (arr[i] < num) {
			i++;
		}
		while (arr[j] > num) {
			j--;
		}
		if (i >= j) {
			break;
		}
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
	}
	quick_sort(arr, l, j);
	quick_sort(arr, j + 1, r);
}
void quick_s(int* arr, int size) {
	double t1 = clock();
	quick_sort(arr, 0, size - 1);
	double t2 = clock();
	double t3 = (t2 - t1) / CLOCKS_PER_SEC;
	printf("\nSorting time quick sort = %lf\n", t3);
}






void selection_sort_worst(int* arr, int size) {
	double t1 = clock();
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] < 0) {
				int min_index = i;
				for (int j = i + 1; j < size; j++) {
					if (arr[j] < 0 && arr[j] > arr[min_index]) {
						min_index = j;
					}
				}
				if (min_index != i) {
					swap(&arr[i], &arr[min_index]);
				}
			}
		}
	selection_sort(arr,size);
	double t2 = clock();
	double t3 = (t2 - t1) / CLOCKS_PER_SEC;
	printf("\nSorting time selection sort (worst case) = %lf\n", t3);
}



