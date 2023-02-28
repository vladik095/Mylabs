#pragma once
#include <stdio.h>
enum genre {
	ACTION, ADVENTURE, DRAMA, FANTASY, SUSPENSE
};
typedef struct {
	char* name;
	enum genre janr;
	int enumValue;
	int year;
	int episode;
	int comment;
	double rating;
} anime;
char* append(char** s, int c, int* len, int* capacity);
char* readStringSafe(char* prompt);
int enumScan(char* str);
anime * delStruct(anime* an, int* size);
anime* addStruct(anime* an, int* size);
void printEnum(int sx);
void scanStruct(anime* an, int size);
void outputStruct(anime* k, int size);
void menu(anime* an, int size);
void volumeAnime(int *size);
char * inputGenre(anime* an);
void volumeYear(int* size);
void volumeEpisode(int* size);
void volumeComment(int* size);
void volumeRating(double* size);