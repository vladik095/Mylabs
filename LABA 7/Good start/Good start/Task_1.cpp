#include "mylib.h"
#include <stdio.h>


int cnt_words(char* s1, char* word) {
	int start_word = 0;
	int end_word = 0;
	int flag = 0;
	int cnt = 0;
	for (int i = 0; s1[i] != '\0'; i++) {
		if (s1[i] != ' ' && flag != 1) {
			start_word = i;
			flag = 1;
			printf("Start = %d\n", i);
		}
		if (s1[i] == ' ' || s1[i] == '\0') {
			end_word = i;
			flag = 1;
			int last = end_word;
			for (int j = start_word; j < end_word && word[j - start_word] != '\0'; j++) {
				if (word[j - start_word] == s1[j]) {} else {
					flag = 0;
					break;
				}
				last = i;
			}
			if (flag == 1 && s1[last] == ' ') {
				cnt++;
			}
			flag = 0;
		}
	}
	printf("Number of repetitions = %d", cnt);
	return 0;
}
void task_1(int argc, char** argv) {
    char string[] = "String: ";
    char word[] = "Word: ";
    char* s = read_string_safe(string);
    char* s2 = read_string_safe(word);
    cnt_words(s, s2);
}