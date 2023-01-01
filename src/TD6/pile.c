#include <stdlib.h>
#include <stdio.h>

struct element {
    int valeur;
    struct element *suivant;
};
typedef struct element Element;

struct pile {
    Element *premier;
};
typedef struct pile Pile;

Pile *init_pile(void) {
    Pile *pile = malloc(sizeof(*pile));
    pile->premier = NULL;
    return pile;
}

void push_item(Pile *pile, int value) {
    Element *new_element = malloc(sizeof(*new_element));
    if (pile == NULL || new_element == NULL) {
        exit(EXIT_FAILURE);
    }
    new_element->valeur = value;
    new_element->suivant = pile->premier;
    pile->premier = new_element;
}

int pop_item(Pile *pile) {
    if (pile == NULL) {
        exit(EXIT_FAILURE);
    }
    int value = 0;
    Element *element = pile->premier;
    if (pile != NULL && pile->premier != NULL) {
        value = element->valeur;
        pile->premier = element->suivant;
        free(element);
    }
    return value;
}

int top_value(Pile *pile) {
    if (pile == NULL) {
        exit(EXIT_FAILURE);
    }
    int nombreDepile = 0;
    Element *elementDepile = pile->premier;
    if (pile != NULL && pile->premier != NULL) {
        nombreDepile = elementDepile->valeur;
    }
    return nombreDepile;
}

void print_stack(Pile *pile) {
    if (pile == NULL) {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;
    while (actuel != NULL) {
        printf("%d -> ", actuel->valeur);
        actuel = actuel->suivant;
    }
    printf("NULL \n");
}


int main(void) {
    Pile *pile = init_pile();
    push_item(pile, 4);
    push_item(pile, 8);
    push_item(pile, 15);
    push_item(pile, 16);
    push_item(pile, 23);
    push_item(pile, 42);
    print_stack(pile);
    printf("pop : %d \n", pop_item(pile));
    print_stack(pile);
    printf("pop : %d \n", pop_item(pile));
    print_stack(pile);
    printf("top : %d \n", top_value(pile));
    print_stack(pile);
}