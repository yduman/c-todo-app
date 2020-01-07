#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
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