#include "stdio.h"
#include "malloc.h"

struct Element {
    int value;
    struct Element *next;
};
typedef struct Element Element;

struct List {
    struct Element *first;
};
typedef struct List List;

List *init_list(void) {
    List *list = malloc(sizeof(*list));
    list->first = NULL;
    return list;
}

void prepend_element(List *list, int value) {
    Element *new_element = (Element *) malloc(sizeof(Element));
    new_element->value = value;
    new_element->next = NULL;
    if (list->first != NULL) {
        new_element->next = list->first;
    }
    list->first = new_element;
}

void append_element(List *list, int value) {
    Element *new_element = (Element *) malloc(sizeof(Element));
    new_element->value = value;
    new_element->next = NULL;
    if (list->first == NULL) {
        list->first = new_element;
        return;
    }
    Element *current = list->first;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_element;

}

void insert_element(List *list, int value) {
    Element *new_element = (Element *) malloc(sizeof(Element));
    new_element->value = value;
    new_element->next = NULL;
    if (list->first == NULL) {
        list->first = new_element;
        return;
    }
    Element *current = list->first;
    Element *previous = NULL;
    while (current != NULL && current->value < value) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        new_element->next = list->first;
        list->first = new_element;
    } else {
        new_element->next = current;
        previous->next = new_element;
    }

}


void print_linked_list(List *list) {
    int counter = 0;
    Element *current = list->first;
    while (current != NULL) {
        printf("Element %d: %d \t", counter, current->value);
        current = current->next;
        counter++;
    }

}

void delete_element_linked_list(List *list, int value) {
    Element *current = list->first;
    Element *previous = NULL;
    while (current != NULL && current->value != value) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (previous == NULL) {
        list->first = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void delete_elements_linked_list(List *list, int value) {
    Element *current = list->first;
    Element *previous = NULL;
    while (current != NULL) {
        if (current->value == value) {
            if (previous == NULL) {
                list->first = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
        }
        previous = current;
        current = current->next;
    }
}


int find_element_linked_list(List *list, int value) {
    Element *current = list->first;
    int counter = 0;
    while (current != NULL) {
        if (current->value == value) {
            return counter;
        }
        current = current->next;
        counter++;
    }
    return -1;
}


int main(void) {
    List *list = init_list();
    prepend_element(list, 2);
    append_element(list, 4);
    insert_element(list, 3);

    print_linked_list(list);
}