#include "array_list.h"

array_list* array_list_new(int capacity) {
    // malloc array list memory
    array_list *al = (array_list*) malloc(sizeof(array_list));

    if (al == NULL) {
        printf("Couldn't allocate memory for array list");
    }

    // set array as allocated for capacity
    al->array = (char **) malloc(capacity * sizeof(char *));

    if (al->array == NULL) {
        printf("Couldn't allocate memory for array");
    }

    // set size and capacity
    al->size = 0;
    al->capacity = capacity;

    return al;
}

void array_list_add_to_end(array_list *al, char *string) {
    // check if needs to be resized
    if (al->size >= al->capacity) {
        // increase capacity by 5
        al->capacity += 5;
        al->array = (char **) realloc(al->array, al->capacity * sizeof(char *));

        // check if cant realloc
        if (al->array == NULL) {
            printf("Can't reallocate memory");
        }
    }

    // add new string to end of array
    al->array[al->size] = strdup(string);
    // increase size
    al->size++;
}
