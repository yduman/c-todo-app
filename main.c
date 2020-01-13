#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "todo.h"

int main(int argc, char const *argv[])
{
    printf("---- TODO APPLICATION ----");

    Vector *todo_list = vector_init(0);
    char todo_description[1000];
    int todo_priority;
    char *nptr;
    char cmd = ' ';

    do
    {
        printf("\n\nPress:\n");
        printf("'a' to add a new todo\n");
        printf("'p' to print all todos\n");
        printf("'e' to exit the program\n");
        printf("'d' to delete todos by description\n");

        cmd = getchar();

        while (getchar() != '\n')
            ;

        switch (cmd)
        {
        case 'a':
            printf("Please provide a description: ");

            if (fgets(todo_description, sizeof(todo_description), stdin) != NULL)
            {
                nptr = strchr(todo_description, '\n');
                if (nptr)
                {
                    *nptr = '\0';
                }
            }

            do
            {
                printf("Please provide a priority (0-10): ");
                scanf("%d", &todo_priority);
            } while (!(todo_priority >= 0 && todo_priority <= 10));

            while (getchar() != '\n')
                ;

            Todo new_todo = *create_todo(todo_description, todo_priority);
            vector_add(todo_list, new_todo);

            printf("Added todo '%s'\n", todo_description);
            break;
        case 'p':
            printf("\n\nYour todos: \n");
            for (int i = 0; i < todo_list->size; i++)
            {
                Todo t = todo_list->data[i];
                printf("%d: %s - %d\n", i, t.description, t.priority);
            }
            break;
        case 'd':
            printf("Please provide the description you want to delete: ");
            scanf("%s", &todo_description);
            printf("DEBUG :: %s\n", todo_description);

            bool delete_result;
            delete_result = delete_todo_by_description(todo_description, todo_list);

            if (delete_result)
            {
                printf("Deleted todo '%s'\n", todo_description);
            }
            else
            {
                printf("Couldn't find todo with description: '%s'\n", todo_description);
            }
            break;
        case 'e':
            printf("Bye!\n\n");
            break;

        default:
            printf("What is your command?\n\n");
            break;
        }
    } while (cmd != 'e');

    vector_free(todo_list);

    return 0;
}
