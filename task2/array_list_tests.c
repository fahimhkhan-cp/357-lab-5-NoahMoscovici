#include "checkit.h"
#include "array_list.h"

void test_array_list_basic(void) {
    array_list *list = array_list_new(4);

    array_list_add_to_end(list, "First");
    array_list_add_to_end(list, "Second");
    array_list_add_to_end(list, "Third");

    checkit_string(list->array[0], "First");
    checkit_string(list->array[1], "Second");
    checkit_string(list->array[2], "Third");
    checkit_int(list->size, 3);
}

void test_array_list_resize(void) {
    array_list *list = array_list_new(2);

    array_list_add_to_end(list, "One");
    array_list_add_to_end(list, "Two");
    array_list_add_to_end(list, "Three");
    array_list_add_to_end(list, "Four");
    array_list_add_to_end(list, "Five");

    checkit_string(list->array[0], "One");
    checkit_string(list->array[1], "Two");
    checkit_string(list->array[2], "Three");
    checkit_string(list->array[3], "Four");
    checkit_string(list->array[4], "Five");

    checkit_int(list->size, 5);

    // Check the capacity to ensure it was resized
    checkit_int(list->capacity >= 5, 1);
}


int main(void) {
    test_array_list_basic();
    test_array_list_resize();

    return 0;
}
