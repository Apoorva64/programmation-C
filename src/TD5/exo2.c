#include "stdio.h"

void map(int (*f)(int), int *array, size_t array_size) {
    for (unsigned int i = 0; i < array_size; ++i) {
        array[i] = f(array[i]);
    }
}


int double_int(int a) {
    return a * 2;
}

int main(void) {
    int tab[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    map(double_int, tab, 5);

    for (int i = 0; i < 5; ++i) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}