#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c, N;
	printf("a = ");
	if (scanf("%d", &a) != 1) {
		printf("FAIL");
			return 0;
	}
	printf("b = ");
	if (scanf("%d", &b) != 1) {
		printf("FAIL");
		return 0;
	}
	printf("c = ");
	if (scanf("%d", &c) != 1) {
		printf("FAIL");
		return 0;
	}
	printf("N = ");
	if (scanf("%d", &N) != 1) {
		printf("FAIL");
		return 0;
	}
	if (a % N == 0)
		printf("N divides a\n");
	else
		printf("N is not a divisor\n");
	if (b % N == 0)
		printf("N divides b\n");
	else
		printf("N is not b divisor\n");
	if (c % N == 0)
		printf("N divides c\n");
	else
		printf("N is not c divisor\n");
	return 0;
}