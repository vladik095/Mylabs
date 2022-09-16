#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	long double x, pi = 3.14159265358979, SIN = 0, COS = 0, CTG = 0;
	if (scanf("%lf", &x) != 1) {
		printf("FAIL");
		return 0;
	}
	long long a = x / 360;
	x -= a * 360;
	x = (x * pi) / 180;
	bool f = true;
	long double X = x, F = 1;
	for (int i = 1; i <= 50; i += 2) {
		if (f) {
			SIN += X / F;
		}
		else {
			SIN -= X / F;
		}
		f = !f;
		X *= x;
		X *= x;
		F *= i + 1;
		F *= i + 2;
	}
	X = 1, F = 1, f = true;
	for (int i = 0; i <= 50; i += 2) {
		if (f) {
			COS += X / F;
		}
		else {
			COS -= X / F;
		}
		f = !f;
		X *= x;
		X *= x;
		F *= i + 1;
		F *= i + 2;
	}
	CTG = COS / SIN;
	printf("%lf", CTG);
	return 0;
}