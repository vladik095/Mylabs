#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "lib.h"
#include "Sorts.h"



int main() {
	int size = 0;
	volumeAnime(&size);
	anime* an = (anime*)malloc(size * sizeof(anime));
	scanStruct(an, size);
	menu(an, size);
	return 0;
}

