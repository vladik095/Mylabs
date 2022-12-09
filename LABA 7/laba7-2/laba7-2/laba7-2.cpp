#include "mylib.h"
#include <stdio.h>
const int SCALE_FACTOR = 2;




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
        if (flag == 1 && (s1[k] == ' ' || s1[k] == ',' || s1[k] == '.' || s1[k] == '!' || s1[k] == '_' || s1[k] == '=' || s1[k] == '-' || s1[k] == ';' || s1[k] == ':' || s1[k] == '\0')) {
            printf("True");
            break;
        }
        if (s1[k] == '\0') {
            printf("False");
            break;
        }
    }
    // printf("Cnt = %d\n", cnt);
    return cnt;
}

void Task2(int argc, char** argv) {
    char empty[] = "String: ";
    char word[] = "Word: ";
    char* s = read_string_safe(empty);
    char* s2 = read_string_safe(word);
    search_s0(s, s2);
}