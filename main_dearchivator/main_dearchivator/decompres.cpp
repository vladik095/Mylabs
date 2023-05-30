#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack_2.h"
#include <stdlib.h>
#include <string.h>

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
    char* s = (char*)malloc(sizeof(char) * capacity);
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
    }
}

void input_stack(char* name, Node** head, int* main_flag)
{
    char* copy = 0;
    copy = (char*)calloc((strlen(name) + 1), sizeof(char));
    strcpy(copy, name);
    if (strcmp(copy, "/*") == 0)
    {
        (*main_flag) = 1;
        return;
    }
    if ((*main_flag) != 1)
        pushBack(head, copy);
    free(copy);
}

void info_stack(Node** head, char* name)
{
    FILE* fp = fopen(name, "r");
    int main_flag = 0;
    while (!feof(fp))
    {
        char* buffer = read_string_safe(fp);
        char* word = strtok(buffer, " ");
        while (word != NULL)
        {
            input_stack(word, head,&main_flag);
            if (main_flag == 1)
            {
                fclose(fp);
                free(buffer);
                return;
            }
            word = strtok(NULL, " ");
        }
    }
}

void info_swap(Node* head)
{
    for (Node* p = head; p != NULL; p = p->next->next)
    {
        if (p->next != NULL)
        {
            p->swap_word = p->next->word;
            p->next->swap_word = p->word;
        } else
        {
            break;
        }
        if (p->next->next == NULL)
        {
            break;
        }
    }
}

void decompressing_file(Node* list)
{
    FILE* ff = fopen("compress.txt", "r");
    FILE* fp = fopen("final_compress.txt", "w");
    int fl = 0;
    int main_fl = 0;
    while (!feof(ff))
    {
        char* buffer = read_string_safe(ff);
        bool first = true;
        char* word = strtok(buffer, " ");
        while (word != NULL)
        {
            fl = 0;
            if (strcmp(word, "/*") == 0)
            {
                main_fl = 1;
                 word = strtok(NULL, " ");
                continue;
            }
            if (main_fl == 1)
            {
                for (Node* p = list; p != NULL; p = p->next)
                {
                    if ((strcmp(word, p->word) == 0))
                    {
                        if (first)
                            fprintf(fp, "%s", p->swap_word);
                        else
                            fprintf(fp, " %s", p->swap_word);
                        first = false;
                        fl = 1;
                        break;
                    }
                }
            }
            if ((fl != 1) && (main_fl == 1))
            {
                if (first)
                    fprintf(fp, "%s", word);
                else
                    fprintf(fp, " %s", word);
                first = false;
            }
            word = strtok(NULL, " ");
        }
        free(buffer);
        free(word);
        if (!feof(ff))
            fprintf(fp, "\n");
    }
    int old_size = 0;
    fseek(ff, 0, SEEK_END);
    old_size = ftell(ff);
    fseek(ff, 0, SEEK_SET);
    int new_size = 0;
    fseek(fp, 0, SEEK_END);
    new_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    printf("File decompressed!\n\n");
    printf("Before decompression --> %d\n", old_size);
    printf("File size --> %d\n\n", new_size);
    fclose(fp);
    fclose(ff);
}

void decompress()
{
    char name[] = "compress.txt";
    Node* head = NULL;
    info_stack(&head, name);
    info_swap(head);
    decompressing_file(head);
    clearing_memory(head);
    delete_stack(&head);
}