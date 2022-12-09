#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
int main() {
	srand(time(0));
	int array_size , flag = 0;
	printf("Array size = ");
		while(scanf("%d", &array_size) != 1 || getchar() != '\n') {
		printf("Wrong input. Try again\n");
		rewind(stdin);
		}
		while(array_size >= 100 || array_size < 0) {
			printf("Wrong input. Try again\n");
			printf("Array size = ");
			while (scanf("%d", &array_size) != 1 || getchar() != '\n') {
				printf("Wrong input. Try again\n");
				rewind(stdin);
				printf("Array size = ");
			}
		}
	char mass[100];
	printf("If you want to enter data into the array, enter 'yes'\n ");
	scanf("%s", &mass);
	double array[100], sum = 0, max = 0;
	for (int i = 0; i < array_size; i++) {
		if (strcmp("yes", mass) == 0) {
			printf("array number %d = ", i+1);
	    while(scanf("%lf", &array[i]) != 1 || getchar() != '\n') {
				printf("Wrong imput. Try again\n");
				printf("array number %d = ", i + 1);
				rewind(stdin);
			}

		} 
		else {
			array[i] = 100 - (rand()%200);
			printf("%d Random number is : %lf\n", i+1,  array[i]);
		}
		if (flag == 1) {
			sum += array[i];
		}
		if (array[i] > 0) {
			flag = 1;
		}
		if (array[i] < 0) {
			array[i] *= -1;
		}
		if (max<array[i]) {
		    max = array[i];
		}
	}
	printf("max number = %lf\n", max);
	printf("sum = %lf\n", sum);
	return 0;
}