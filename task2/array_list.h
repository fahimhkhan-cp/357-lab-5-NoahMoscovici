#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    int capacity;
    char **array;
} array_list;

array_list* array_list_new(int capacity);
void array_list_add_to_end(array_list *al, char *string);
