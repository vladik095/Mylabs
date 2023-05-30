#pragma once
#pragma once
#include "stack-link.h"
#include "liba.h"

void pair_search(Node* list, char* w1, char* w2);
void used(Node* head, char* word_1, char* word_2);
int benefit(Node* first, Node* second);
int check_stack(char* str, Node* list);
void filling_the_stack(char* name, Node** head);
void compressing_file(Node* list, char* name);
void compress();