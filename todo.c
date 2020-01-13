#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "todo.h"

Vector *vector_init(size_t size)
{
    Vector *vec = malloc(sizeof(Vector));
    vec->size = size;
    vec->capacity = size;

    if (size)
    {
        vec->data = calloc(size, sizeof(Todo));
    }
    else
    {
        vec->data = NULL;
    }

    return vec;
}

void vector_resize(Vector *vector)
{
    if (vector->size >= vector->capacity)
    {
        vector->capacity = 2 * vector->size;
        vector->data = realloc(vector->data, sizeof(Todo) * vector->capacity);
    }
}

void vector_free(Vector *vector)
{
    free(vector->data);
    free(vector);
}

void vector_add(Vector *vector, Todo todo)
{
    vector->size++;
    vector_resize(vector);
    vector->data[vector->size - 1] = todo;
}

bool vector_delete(Vector *vector, int index)
{
    if (vector == NULL || index >= vector->size)
    {
        printf("vector_delete: array is either null or index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    for (int i = index; i < vector->size; ++i)
    {
        vector->data[i] = vector->data[i + 1];
    }

    vector->size--;
    vector_resize(vector);

    return true;
}

Todo vector_get(Vector *vector, int index)
{
    if (index > vector->capacity || index < 0)
    {
        printf("vector_get: index out of bounds\n");
        exit(1);
    }

    return vector->data[index];
}

int vector_get_size(Vector *vector)
{
    return vector->size;
}

Todo *create_todo(char description[], int priority)
{
    Todo *todo = malloc(sizeof(Todo));
    todo->completed = false;
    strcpy(todo->description, description);
    todo->priority = priority;

    return todo;
}

bool delete_todo_by_description(char description[], Vector *todo_list)
{
    bool result;

    for (int i = 0; i < todo_list->size; ++i)
    {
        Todo t = todo_list->data[i];
        int compare_result = strcmp(t.description, description);
        if (compare_result == 0)
        {
            result = vector_delete(todo_list, i);
        }
    }

    return result;
}
