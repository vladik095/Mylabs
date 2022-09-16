#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int m, n1, n3, n5;
	printf("m = ");
	if (scanf("%d", &m) != 1 || m < 10 || m > 50) {
		printf("FAIL\n");
		return 0;
	}
	for (n5 = 0; n5 <= m / 5; n5++) {
		for (n3 = 0; n3 <= 10 - n5; n3++) {
			//printf("%d %d\n" , n5 , n3);
			n1 = 10 - n5 - n3;
			if (n5 * 5 + n3 * 3 + n1 == m) {
				printf("YES\nCount of 5 = %d\nCount of 3 = %d\nCount of 1 = %d", n5 , n3 , n1);
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}