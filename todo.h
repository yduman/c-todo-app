#include <stdbool.h>

#ifndef TODO_H
#define TODO_H

typedef struct
{
    char description[1000];
    int priority;
    bool completed;
} Todo;

Todo *create_todo(char description[], int priority);

#endif
