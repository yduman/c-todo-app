#include <stdbool.h>

#ifndef TODO_H
#define TODO_H

typedef struct
{
    char description[1000];
    int priority;
    bool completed;
} Todo;

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
bool vector_delete(Vector *vector, int index);
Todo vector_get(Vector *vector, int index);
int vector_get_size(Vector *vector);

Todo *create_todo(char description[], int priority);
bool delete_todo_by_description(char description[], Vector *todo_list);

#endif
