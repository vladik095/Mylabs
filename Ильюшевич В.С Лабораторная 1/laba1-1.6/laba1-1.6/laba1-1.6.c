#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	float  a, S, H;
	printf("a = ");
	if (scanf("%f", &a) != 1) {
		printf("FAIL");
		return 0;
	}
	if (a < 0) {
		printf("Try again");
		return 0;
	}
	S = (a * a / 4 * sqrt(3));
	H = (a / 2 * sqrt(3));
	printf("Square = %.3f\n", S);
	printf("Height = %.3f\n", H);
	return 0;
}