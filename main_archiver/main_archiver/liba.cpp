#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "liba.h"
#include "stack-link.h"
#include "compres.h"
#include <stdlib.h>
void menu(int task)
{
	while (true)
	{
		printf("1. Compress\n");
		printf("2. Exit\n");
		task = 0;
		while (!scanf("%d", &task) || task > 2 || task < 1 || getchar() != '\n')
		{
			printf("Wrong option!\nTry again!\n");
			rewind(stdin);
		}
		switch (task)
		{
		case 1:
		{
			compress();
			break;
		}

		case 2:
		{
			exit(0);
		}
		printf("\n");
		}
	}
}
