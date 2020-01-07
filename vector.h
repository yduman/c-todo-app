#include <stdbool.h>
#include "todo.h"

#ifndef VECTOR_H
#define VECTOR_H

typedef struct
{
    size_t size;
    size_t capacity;
    Todo *data;
} Vector;

Vector *vector_init(size_t size);
void vector_resize(Vector *vector);
void vector_free(Vector *vector);
void vector_add(Vector *vector, Todo todo);
Todo vector_get(Vector *vector, int index);
int vector_get_size(Vector *vector);

#endif