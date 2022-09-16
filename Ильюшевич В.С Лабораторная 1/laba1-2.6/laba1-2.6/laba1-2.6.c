#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	long double x, y, x1, y1, x2, y2, R, S;
	printf("Enter the coordinates of the center of the circle\n");
	if (scanf("%lf %lf", &x, &y) != 2) {
		printf("FAIL");
		return 0;
	}
	printf("Enter the coordinates of the point on the circle\n");
	if (scanf("%lf %lf", &x1, &y1) != 2) {
		printf("FAIL");
		return 0;
	}
	printf("Enter the coordinates of the point\n");
	if (scanf("%lf %lf", &x2, &y2) != 2) {
		printf("FAIL");
		return 0;
	}
	S = sqrt(((x2 - x) * (x2 - x)) + ((y2 - y) * (y2 - y)));
	R = sqrt(((x1 - x) * (x1 - x)) + ((y1 - y) * (y1 - y)));
	if (R == S)
		printf("The point lies on a circle");
	else
		printf("The point doesn't lie on a circle");
	return 0;
}