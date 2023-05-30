#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack-link.h"
#include "liba.h"


const int SCAL_FACTOR = 2;

void append(char** s, char c, int* len, int* capacity)
{
    (*len)++;
    if (*capacity < *len)
    {
        *capacity *= SCAL_FACTOR;
        *s = (char*)realloc(*s, sizeof(char) * (*capacity));
    }
    (*s)[(*len) - 1] = c;
}

char* read_string_safe(FILE* fp)
{
    char c;
    int len = 0;
    int capacity = 1;
    char* s = (char*)calloc(sizeof(char),capacity);
    while (((c = fgetc(fp)) != '\n' && c != EOF))
    {
        if (c == EOF)
            break;
        if (c == '\n')
            continue;
        append(&s, c, &len, &capacity);
    }
    append(&s, '\0', &len, &capacity);
    return s;
}

void clearing_memory(Node* list)
{
    for (Node* p = list; p != NULL; p = p->next)
    {
        free(p->word);
        free(p->swap_word);
    }
}

void pair_search(Node* list, char* w1, char* w2)
{
    for (Node* p = list; p != NULL; p = p->next)
    {
        if (strcmp(p->word, w1) == 0)
        {
            p->swap_word = (char*)calloc(strlen(w2) + 1, sizeof(char));
            strcpy(p->swap_word, w2);
            continue;
        }
        if (strcmp(p->word, w2) == 0)
        {
            p->swap_word = (char*)calloc(strlen(w1) + 1, sizeof(char));
            strcpy(p->swap_word, w1);
            continue;
        }
    }
}

void used(Node* head, char* word_1, char* word_2)
{
    for (Node* p = head; p != NULL; p = p->next)
    {
        if (strcmp(p->word, word_1) == 0)
            p->used = 1;
        if (strcmp(p->word, word_2) == 0)
            p->used = 1;
    }
}

void used_rep(Node* head, char* word_1)
{
    for (Node* p = head; p != NULL; p = p->next)
    {
        if (strcmp(p->word, word_1) == 0)
            p->used_text = 1;
    }
}

int benefit(Node* first, Node* second)
{
    int pr = (first->len * first->count + second->len * second->count) - (first->len * second->count + second->len * first->count) - (first->len + second->len) - 2;
    return pr;
}

void counting_repetitions(Node* head)
{
    int prof = 0;
    char* word_first = 0;
    char* word_second = 0;
    while (true)
    {
        int prof_max = 0;
        for (Node* first = head; first != NULL; first = first->next)
        {
            for (Node* second = head; second != NULL; second = second->next)
            {
                prof = benefit(first, second);
                if (prof > prof_max && (first->used != 1) && (second->used != 1))
                {
                    prof_max = prof;
                    word_first = first->word;
                    word_second = second->word;
                }
            }
        }
        if (prof_max > 0)
        {
            used(head, word_first, word_second);
            pair_search(head, word_first, word_second);
        } else
            break;
    }
}

int check_stack(char* str, Node* list)
{
    int fl = 0;
    for (Node* p = list; p != NULL; p = p->next)
    {
        if (strcmp(p->word, str) == 0)
        {
            p->count++;
            fl = 1;
        }
    }
    return fl;
}

void filling_the_stack(char* name, Node** head)
{
    FILE* fp = fopen(name, "r");
    while (!feof(fp))
    {
        char* buffer = read_string_safe(fp);
        char* word = strtok(buffer, " ");
        while (word != NULL)
        {
            if (check_stack(word, *head) != 1)
                pushBack(head, word);
            word = strtok(NULL, " ");
        }
        free(buffer);
        free(word);
    }
    fclose(fp);
}

void compressing_file(Node* list, char* name)
{
    FILE* in = fopen(name, "r");
    FILE* ou = fopen("compress.txt", "w+");
    bool first = true;
    for (Node* q = list; q != NULL; q = q->next)
    {
        if (q->used != 0 && q->used_text != 1)
        {
            if (first)
            {
                fprintf(ou, "%s", q->word);
                fprintf(ou, " %s", q->swap_word);
            } else
            {
                fprintf(ou, " %s", q->word);
                fprintf(ou, " %s", q->swap_word);
            }
            first = false;
            used_rep(list, q->swap_word);
        }
    }
    int info_size = 0;
    fseek(ou, 0, SEEK_END);
    info_size = ftell(ou);
    fclose(ou);
    ou = fopen("compress.txt", "a+");
    fputs(" /* ", ou);
    while (!feof(in))
    {
        char* buffer = read_string_safe(in);
        first = true;
        char* word = strtok(buffer, " ");
        while (word != NULL)
        {
            for (Node* p = list; p != NULL; p = p->next)
            {
                if ((strcmp(word, p->word) == 0) && (p->used == 0))
                {
                    if (first)
                        fprintf(ou, "%s", word);
                    else
                        fprintf(ou, " %s", word);
                    first = false;
                    continue;
                }
                if ((strcmp(word, p->word) == 0) && (p->used != 0))
                {
                    if (first)
                        fprintf(ou, "%s", p->swap_word);
                    else
                        fprintf(ou, " %s", p->swap_word);
                    first = false;
                    break;
                }
            }
            word = strtok(NULL, " ");
        }
        free(buffer);
        free(word);
        if (!feof(in))
            fprintf(ou, "\n");
    }
    int old_size = 0;
    fseek(in, 0, SEEK_END);
    old_size = ftell(in);
    fseek(in, 0, SEEK_SET);
    int new_size = 0;
    fseek(ou, 0, SEEK_END);
    new_size = ftell(ou);
    fseek(ou, 0, SEEK_SET);
    printf("Before compression --> %d\n", old_size);
    printf("Info size --> %d\n", info_size);
    printf("File size --> %d\n", new_size);
    fclose(in);
    fclose(ou);
}


void compress()
{
    char name[] = "text.txt";
    Node* head = NULL;
    filling_the_stack(name, &head);
    counting_repetitions(head);
    compressing_file(head, name);
    clearing_memory(head);
    delete_stack(&head);
}