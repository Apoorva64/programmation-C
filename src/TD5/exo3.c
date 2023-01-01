#include <stdio.h>

int iterate(int (*f)(int, int), int *array, size_t array_size) {
    int result = array[0];
    for (unsigned int i = 1; i < array_size; ++i) {
        result = f(result, array[i]);
    }
    return result;
}

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}


int main(void) {
    int tab[] = {1, 2, 3, 4, 5};
    printf("%d\n", iterate(&add, tab, 5));
    printf("%d\n", iterate(&multiply, tab, 5));
    printf("%d\n", iterate(&max, tab, 5));
    printf("%d\n", iterate(&min, tab, 5));
    return 0;
}

