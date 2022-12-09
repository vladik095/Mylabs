#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


long long scanf_N(long long* indexN) {
    printf("N = ");
    while (scanf("%lld", &*indexN) != 1 || getchar() != '\n' || *indexN < 0 || *indexN > 100) {
        printf("Wrong input. Try again!\n");
        printf("N = ");
        rewind(stdin);
    }
    return *indexN;
}


int main() {
    long long row = 0, col = 0, N, cnt = 0;
    double array_size[100][100];
    long long min_element = 1e9;
    scanf_N(&N);
    row = N;
    col = N;
    char mass[100];
    printf("If you want to enter data into the array, enter 'yes'\n ");
    scanf("%s", &mass);

    if (strcmp("yes", mass) == 0)
        for (long long i = 0; i < row; i++) {
            for (long long j = 0; j < col; j++) {
                printf("array  %lld %lld =  ", i + 1, j + 1);
                while (scanf("%lf", &array_size[i][j]) != 1 || getchar() != '\n') {
                    if (N == 2) {
                        min_element > array_size[i][j + 1];
                        min_element = array_size[i][j + 1];
                        if (N == 2) {
                            min_element > array_size[i + 1][j + 1];
                            min_element = array_size[i + 1][j + 1];
                        }
                    }
                    printf("Wrong input. Try again!\n");
                    printf("array  %lld %lld =  ", i + 1, j + 1);
                    rewind(stdin);
                }
            }
        } else {
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
            printf("%0.f ", array_size[a][b]);
            printf("\t");
        }
        printf("\n");
        printf("\v");

    }

    for (long long i = 0; i <= row / 2; i++) {

        for (long long j = col - cnt - 1; j < col; j++) {

            if (min_element > array_size[i][j]) {
                min_element = array_size[i][j];
            }
        }
        printf("\n");
        cnt++;
    }

    cnt = 0;
    long long temp_row = row / 2;
    long long temp_col = col / 2;
    for (long long i = temp_row; i < row; i++) {

        for (long long j = temp_col + cnt; j < col; j++) {

            if (min_element > array_size[i][j]) {
                min_element = array_size[i][j];
            }
        }
        printf("\n");
        cnt++;
    }
        if (N == 0) {
            printf("No elements found");
        } else
            printf("Minimum element = %lld", min_element);

    return 0;
}