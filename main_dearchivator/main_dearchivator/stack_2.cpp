#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_2.h"

void pushBack(Node** head, char* word)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->word = (char*)malloc(sizeof(char) * (strlen(word) + 1));
    strcpy(tmp->word, word);
    tmp->next = *head;
    tmp->swap_word = 0;
    *head = tmp;
}


struct Node* pop(struct Node* head) {
    if (head == NULL) {
        printf("Stack is empty.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void delete_stack(struct Node** head) {
    while (*head != NULL) {
        *head = pop(*head);
    }
}

