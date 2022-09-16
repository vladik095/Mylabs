#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int  v1, v2, v3;
	float S , sum = 0;
	v1 = 2;
	v2 = 3;
	v3 = 5;
	S = 20;
	int i = 0;
	while (S > 0.00001) {
		float SS = S;
		if (i % 2 == 0) {
			float shmel_time = SS / (v3 + v2);
			sum += v3 * shmel_time;
			printf("%f\n", v3 * shmel_time);
			S -= v2 * shmel_time;
			S -= v1 * shmel_time;
		}
		else {
			float shmel_time = SS / (v3 + v1);
			sum += v3 * shmel_time;
			printf("%f\n", v3 * shmel_time);
			S -= v1 * shmel_time;
			S -= v2 * shmel_time;
		}
		i++;
	}
	printf("%f", sum);
	return 0;
}