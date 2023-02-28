#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "lib.h"

void nameSort(anime* mas, int size) {
	anime tmp;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strcmp(mas[j].name, mas[j + 1].name) > 0) {
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
	printf("\nAnime successfully sorted!\n");
}


void sortYear(anime* mas, int size) {
	anime tmp;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (mas[j].year > mas[j + 1].year) {
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
	printf("\nAnime successfully sorted!\n");
}

void sortGenre(anime* mas, int size) {
	anime tmp;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (mas[j].enumValue > mas[j + 1].enumValue) {
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
	printf("\nAnime successfully sorted!\n");
}

void sortRating(anime* mas, int size) {
	anime tmp;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (mas[j].rating > mas[j + 1].rating) {
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
	printf("\nAnime successfully sorted!\n");
}

void sortEpisode(anime* mas, int size) {
	anime tmp;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (mas[j].episode > mas[j + 1].episode) {
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
	printf("\nAnime successfully sorted!\n");
}


void sortComment(anime* mas, int  size) {
	anime tmp;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (mas[j].comment > mas[j + 1].comment) {
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
	printf("\nAnime successfully sorted!\n");
}

void sorts(anime* an, int size) {
	if (size == 0) {
		outputStruct(an, size);
		return;
	}
	char name[] = "Sort by(Name\\Genre\\Year\\Episode\\Comment\\Rating):";
	char* str = readStringSafe(name);
	if (strcmp(str, "Name") == 0)
		nameSort(an, size);
	else if (strcmp(str, "Genre") == 0)
		sortGenre(an, size);
	else if (strcmp(str, "Year") == 0)
		sortYear(an, size);
	else if (strcmp(str, "Episode") == 0)
		sortEpisode(an, size);
	else if (strcmp(str, "Comment") == 0)
		sortComment(an, size);
	else if (strcmp(str, "Rating") == 0)
		sortRating(an, size);

}



void preSort(anime* mas, int size) {
	anime tmp;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (mas[j].year > mas[j + 1].year) {
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
}

void twoSort(anime* mas, int size) {
	if (size == 0) {
		outputStruct(mas, size);
		return ;
	}
	preSort(mas, size);
	anime tmp;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if ((mas[j].rating > mas[j + 1].rating) && (mas[j].year == mas[j + 1].year)) {
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
	printf("\nAnime successfully sorted!\n");
}
