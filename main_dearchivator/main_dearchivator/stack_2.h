#pragma once
typedef struct Node
{
    char* word;
    int count;
    int len;
    int used;
    int used_text;
    char* swap_word;
    struct Node* next;
} Node;
void pushBack(Node** head, char* word);

struct Node* pop(struct Node* head);
void delete_stack(struct Node** head);