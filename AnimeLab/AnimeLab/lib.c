#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "lib.h"
#include "Sorts.h"
const int SCAL_FACTOR = 2;

void volumeAnime(int* size) {
	printf("Number of anime viewed: ");
	while (scanf("%d", &*size) != 1 || getchar() != '\n' || *size < 0) {
		printf("Wrong input. Try again!\n");
		printf("Number of anime viewed: ");
		rewind(stdin);
	}
}




void volumeYear(int *size) {
	printf("Year of release: ");
	while (scanf("%d", size) != 1 || getchar() != '\n' || *size < 0) {
		printf("Wrong input. Try again!\n");
		printf("Year of release: ");
		rewind(stdin);
	}
}


void volumeEpisode(int *size) {
	printf("Number of episodes: ");
	while (scanf("%d", size) != 1 || getchar() != '\n' || *size < 0) {
		printf("Wrong input. Try again!\n");
		printf("Number of episodes: ");
		rewind(stdin);
	}
}




void volumeComment(int *size) {
	printf("Number of Comment: ");
	while (scanf("%d", size) != 1 || getchar() != '\n' || *size < 0) {
		printf("Wrong input. Try again!\n");
		printf("Number of comments: ");
		rewind(stdin);
	}
}



void volumeRating(double *size) {
	printf("Number of rating: ");
	while (scanf("%lf", size) != 1 || getchar() != '\n' || *size < 0) {
		printf("Wrong input. Try again!\n");
		printf("Number of rating: ");
		rewind(stdin);
	}
}

char* append(char** s, int c, int* len, int* capacity) {
	(*len)++;
	if (*capacity < *len) {
		*capacity *= SCAL_FACTOR;
		*s = (char*)realloc(*s, sizeof(char) * (*capacity));
	}
	(*s)[(*len) - 1] = c;
	return *s;
}





char* readStringSafe(char* prompt) {
	printf("%s", prompt);
	char c;
	int len = 0;
	int capacity = 1;
	char* s = (char*)malloc(sizeof(char) * capacity);
	bool read_first = true;
	while ((c = getchar()) != '\n' || read_first) {

		if (c == '\n') 
			continue;
		read_first = false;
		append(&s, c, &len, &capacity);
	}
	append(&s, '\0', &len, &capacity);
	s = (char*)realloc(s, sizeof(char) * len);

	return s;
}




int enumScan(char* str) {
	enum genre janr = ACTION;

	if (strcmp(str, "Action") == 0)
		janr = ACTION;
	if (strcmp(str, "Adventure") == 0)
		janr = ADVENTURE;
	if (strcmp(str, "Drama") == 0)
		janr = DRAMA;
	if (strcmp(str, "Fantasy") == 0)
		janr = FANTASY;
	if (strcmp(str, "Suspense") == 0)
		janr = SUSPENSE;
	return janr;
}


anime * delStruct(anime* an, int* size) {
	if (*size == 0) {
		outputStruct(an,*size);
		return an;
	}
	outputStruct(an,*size);
	char name1[] = "Name: ";
	char *anim = readStringSafe(name1);
	for (int i = 0; i < *size; i++) {
		if (strcmp(anim, an[i].name) == 0) {
			for (int k = i; k < (*size) - 1; k++) {
				an[k] = an[k + 1];
			}
			(*size)--;
			i--;
			an = (anime*)realloc(an, (*size) * sizeof(anime));
		}
	}
	return an;
}



anime* addStruct(anime* an, int* size) {
	an = (anime*)realloc(an, ((*size) + 1) * sizeof(anime));
	char empty[] = "Genre: ";
	char name1[] = "Name: ";
	an[*size].name = readStringSafe(name1);
	char* janrStr = readStringSafe(empty);
	enumScan(janrStr);
	an[*size].enumValue = enumScan(janrStr);
	printf("\nYear:");
	scanf("%d", &an[*size].year);
	printf("\nEpisodes:");
	scanf("%d", &an[*size].episode);
	printf("\nComments:");
	scanf("%d", &an[*size].comment);
	printf("\nRating:");
	scanf("%lf", &an[*size].rating);
	(*size)++;
	return an;
}

void printEnum(int sx) {
	switch (sx) {

	case ACTION: {
		printf("%-11s", "Action");
		break;
	}
	case ADVENTURE: {
		printf("%-11s", "Adventure");
		break;
	}
	case DRAMA: {
		printf("%-11s", "Drama");
		break;
	}
	case FANTASY: {
		printf("%-11s", "Fantasy");
		break;
	}
	case SUSPENSE: {
		printf("%-11s", "Suspense");
		break;
	}
	}
}
void  scanStruct(anime* an, int size) {
	char name1[] = "Name: ";
	for (int i = 0; i < size; i++) {
		an[i].name = readStringSafe(name1);
		char* janrStr = inputGenre(an);
		an[i].enumValue = enumScan(janrStr);
		volumeYear(&an[i].year);
		volumeEpisode(&an[i].episode);
		volumeComment(&an[i].comment);
		volumeRating(&an[i].rating);
	}
}

char *inputGenre(anime *an) {
	char empty1[] = "Genre (Action\\Adventure\\Drama\\Fantasy\\Suspense): ";
	char* janrAnime = readStringSafe(empty1);
	while (true) {
		if (strcmp(janrAnime, "Action") == 0)
			break;
		else if (strcmp(janrAnime, "Adventure") == 0)
			break;
		else if (strcmp(janrAnime, "Drama") == 0)
			break;
		else if (strcmp(janrAnime, "Fantasy") == 0)
			break;
		else if (strcmp(janrAnime, "Suspense") == 0)
			break;
	printf("There is no such genre! Try again!\n");
		janrAnime = readStringSafe(empty1);
	}
	return janrAnime;
}
void outputStruct(anime* k, int size) {
	if (size == 0) {
		printf("\nThere is no anime \n");
		return;
	}
	printf("%-11s%-11s%-11s%-11s%-11s%-11s\n", "Name", "Genre", "Year", "Episode", "Comment", "Rating");
	for (int i = 0; i < size; i++) {
		printf("%-11s", k[i].name);
		printEnum(k[i].enumValue);
		printf("%-11d", k[i].year);
		printf("%-11d", k[i].episode);
		printf("%-11d", k[i].comment);
		printf("%-11.1lf", k[i].rating);
		printf("\n");
	}
}

 
void menu(anime * an, int size) {
	while (true) {
		printf("\nWhat do you want to do?\n");
		printf("Choose one option from the list\n");
		printf("1. Print Anime\n");
		printf("2. Add Anime\n");
		printf("3. Delete Anime\n");
		printf("4. Sort\n");
		printf("5. Sort two fields (Year and rating)\n");
		printf("6. Exit\n");
		int task = 0;
		while (!scanf_s("%d", &task) || task > 6 || task < 1 || getchar() != '\n') {
			printf_s("Wrong option!\nTry again!\n");
			rewind(stdin);
		}
		switch (task) {
			case 1: {
				outputStruct(an, size);
				break;
			}
			case 2: {
				an = addStruct(an, &size);
				break;
			}
			case 3: {
				an = delStruct(an, &size);
				break;
			}
			case 4: {
				sorts(an, size);
				break;
			}
			case 5: {
				twoSort(an, size);
				break;
			}
			case 6: {
				exit(0);
			}
				  printf("\n");
		}
	}
}

