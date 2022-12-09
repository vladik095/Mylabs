#include "mylib.h"
#include <stdio.h>
int search_s0(char* s1, char* s2) {
    int j = 0;
    int flag = 0;
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
        printf("flag = %d\n", flag);

        if (flag == 1) {
            printf("True");
            break;
        }
        if (s1[k] == '\0') {
            printf("False");
            break;
        }
    }
    return 0;
}
void task_2(int argc, char** argv) {
    char string_1[] = "String: ";
    char string_2[] = "Search string: ";
    char* s = read_string_safe(string_1);
    char* s2 = read_string_safe(string_2);
    search_s0(s, s2);
}