#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main() {
	srand(time(0));
	int array_size;
	double array[100];
	int index = 0;
	double Max = 0, New_Max = 0, temp = 0;
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
	int j = 0;
	for (int i = 0; i < array_size; i++) {
		temp = array[i];
		index = 0;
		for (int j = 0; j < array_size; j++) {
			int aboba = array[i];
			if (array[j] == temp && aboba % 2 == 0) {
				index++;
			}
		
			if (index > Max) {
				Max = index;
				New_Max = array[i];
			}

		}
	}	printf("The most frequent number (even) = %lf \n", New_Max);
	return 0;
}