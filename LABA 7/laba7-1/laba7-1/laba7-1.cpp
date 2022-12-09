#include "mylib.h"
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

//void (*TASKS[])() = { append,read_string_safe };

int search_s0(char* s1, char* s2) {
    int i = 0;
    int j = 0;
    int flag = 0;
    int cnt = 0;
    int k = 0;
    while (true) {
        j = 0;
        for (; s2[j] != '\0';) {
            if (s1[k] == s2[j]) {
                flag = 1;
            } else {
                flag = 0;
                k++;
                break;
            }
            j++;
            k++;
        }
        if (flag == 1 && (s1[k] == ' ' || s1[k] == ',' || s1[k] == '.' || s1[k] == '!' || s1[k] == '_' || s1[k] == '=' || s1[k] == '-' || s1[k] == ';' || s1[k] == ':' || s1[k] == '\0'))
            cnt++;
        if (s1[k] == '\0') {
            break;
        }
    }
    printf("Cnt = %d\n", cnt);
    return cnt;

}


void Task2(int argc, char** argv) {
    char empty[] = "String: ";
    char word[] = "Word: ";
    char* s = read_string_safe(empty);
    char* s2 = read_string_safe(word);
    search_s0(s, s2);
}