#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int SCALE_FACTOR = 2;

int max(int a, int b)
{
    return a >= b ? a : b;
}

int isspace(int c)
{
    return c == ' ' || c == '\n' || c == '\t';
}

void flush()
{
    while (getchar() != '\n')
        continue;
}

int length(char* s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

int ispunct(int c)
{
    if (c >= 128)
        return 0;
    if ((unsigned)c - '!' < '^' && (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'))
        return 0;
    return 1;
}

void append(char** s, char c, int* len, int* capacity)
{
    (*len)++;
    if (*capacity < *len)
    {
        *capacity *= SCALE_FACTOR;
        *s = (char*)realloc(*s, sizeof(char) * (*capacity));
    }
    (*s)[(*len) - 1] = c;
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
    return s;
}

void insertionsort(char** a, int* lengths, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        while (j >= 0 && lengths[j] > lengths[j + 1])
        {
            char* tmp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = tmp;
            int tmp2 = lengths[j];
            lengths[j] = lengths[j + 1];
            lengths[j + 1] = tmp2;
            j--;
        }
    }
}

void strcopy(char* src, char** dest)
{
    int size = length(src);
    int i = 0;
    (*dest) = (char*)calloc(size + 1, sizeof(char));
    while (src[i] != '\0')
    {
        (*dest)[i] = src[i];
        i++;
    }
    (*dest)[i] = '\0';
}

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        printf("Invalid arguments count\n");
        return 1;
    }
    int n = argc - 1;
    char** s = (char**)malloc(sizeof(char*) * n);
    int* lengths = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        strcopy(argv[i + 1], &s[i]);
    for (int i = 0; i < n; i++)
    {
        int len = length(s[i]);
        bool word = true;
        int curlen = 0;
        for (int j = 0; j < len; j++)
        {
            if (!isspace(s[i][j]) && !ispunct(s[i][j]))
                curlen++;
            else if (isspace(s[i][j]) || ispunct(s[i][j]))
            {
                if (curlen > 0)
                {
                    lengths[i] = max(lengths[i], curlen);
                    curlen = 0;
                }
            }
        }
        if (curlen > 0)
            lengths[i] = max(lengths[i], curlen);
    }
    insertionsort(s, lengths, n);
    for (int i = n - 1; i >= 0; i--)
        printf("%s\n", s[i]);
    for (int i = 0; i < n; i++)
        free(s[i]);
    free(s);
    free(lengths);
    return 0;
}