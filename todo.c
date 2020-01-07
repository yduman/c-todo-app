#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "todo.h"
#include "vector.h"

Todo *create_todo(char *description, int priority)
{
    Todo *todo = malloc(sizeof(Todo));
    todo->completed = false;
    todo->description = description;
    todo->priority = priority;

    return todo;
}
