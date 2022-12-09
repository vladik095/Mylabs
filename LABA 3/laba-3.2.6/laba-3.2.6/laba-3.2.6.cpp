#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
int main() {
	srand(time(0));
	int array_size;
	printf("Array size = ");
	while (scanf("%d", &array_size) != 1 || getchar() != '\n') {
		printf("Wrong input. Try again\n");
		rewind(stdin);
	}
	while (array_size >= 100 || array_size < 0) {
		printf("Wrong input. Try again\n");
		printf("Array size = ");
		while (scanf("%d", &array_size) != 1 || getchar() != '\n') {
			printf("Wrong input. Try again\n");
			rewind(stdin);
			printf("Array size = ");
		}
	}

	double array[100];
	char mass[50];
	printf("If you want to enter data into the array, enter 'yes'\n ");
	scanf("%s", &mass);
	for (int i = 0; i < array_size; i++) {
		if (strcmp("yes", mass) == 0) {
			printf("array number %d = ", i + 1);
			while (scanf("%lf", &array[i]) != 1 || getchar() != '\n') {
				printf("Wrong imput. Try again\n");
				printf("array number %d = ", i + 1);
				rewind(stdin);
			}

		} else {
			array[i] = 100 - (rand() % 200);
			printf("%d Random number is : %lf\n", i + 1, array[i]);
		}
	}
	int k;
	printf("k = ");
	while (scanf("%d", &k) != 1 || k < 1 || getchar() != '\n') {
		printf("Wrong imput. Try again\n");
		rewind(stdin);
	}
	int temp = k;
	int i = k;
	//int fl = array_size;
	for (int i = k - 1; i < array_size; i += k) {
		for (int j = i + 1; j < array_size; j++)
			array[j - 1] = array[j];
		array_size--;
		i--;
	}
	for (int i = 0; i < array_size; i++)
		printf("%f ", array[i]);

	return 0;
}
