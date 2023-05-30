#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "liba_2.h"
#include "stack_2.h"
#include "decompres.h"
#include <stdlib.h>
void menu(int task)
{
	while (true)
	{
		printf("1. Decompress\n");
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
			decompress();
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
