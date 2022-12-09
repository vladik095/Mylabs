#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
const int SCALE_FACTOR = 2;


char* append(char** s, char c, int* len, int* capacity)
{
    (*len)++;
    if (*capacity < *len)
    {
        *capacity *= SCALE_FACTOR;
        *s = (char*)realloc(*s, sizeof(char) * (*capacity));
    }
    (*s)[(*len) - 1] = c;
    return *s;
}

char* read_string_safe(char* prompt)
{
    printf("%s", prompt);
    char c;
    int len = 0;
    int capacity = 1;
    char* s = (char*)malloc(sizeof(char) * capacity);
    bool read_first = true;
    while ((c = getchar()) != '\n' || read_first)
    {
        if (c == '\n')
            continue;
        read_first = false;
        append(&s, c, &len, &capacity);
    }
    append(&s, '\0', &len, &capacity);
    s = (char*)realloc(s, sizeof(char) * len);
    return s;
}
