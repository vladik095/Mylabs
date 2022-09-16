#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  
int main()
{
	char grt[50];
	printf("Enter the name of the discipline\n");
	if (scanf("%s", grt) != 1)
		if (strcmp("informatics", grt) == 0) {
			printf("exam, test");
			return 0;
		}
	if (strcmp("culturology", grt) == 0) {
		printf("test");
		return 0;
	}
	if (strcmp("math", grt) == 0) {
		printf("exam, test");
		return 0;
	}
	if (strcmp("foreignlanguage", grt) == 0) {
		printf("exam, test");
		return 0;
	}
	if (strcmp("economics", grt) == 0) {
		printf("exam");
		return 0;
	}
	else
		printf("There is no such discipline!");
	return 0;
}