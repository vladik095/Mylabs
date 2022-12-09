#include <stdlib.h>
#include <string.h>
#include "Task_1.h"
#include "Task_2.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    while (true) {
        printf_s("Enter Task (1-2)\n");
        int task;
        while (!scanf_s("%d", &task)  || task > 2 || task < 1 || getchar() != '\n') {
            printf_s("Invalid task number!\n");
            rewind(stdin);
        }
        void (*task_run[2]) (int, char**) = { task_1, task_2 };
        ((*task_run[task - 1])(argc, argv));
        printf_s("\n\n");
        rewind(stdin);
    }
}