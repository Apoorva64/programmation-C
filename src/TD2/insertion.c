#include <limits.h>
#include <malloc.h>
#include "stdio.h"

void print_array(int array[], int size) {
    printf("[");
    if (array[0] == INT_MIN) {
        printf("..., ");
    }
    for (int i = 0; i < size; i++) {
        if (array[i] != INT_MIN) {
            printf("%d, ", array[i]);
        }
    }
    printf("]");
    printf("\n");
}


void insert_in_sorted_array(int *array, int value, int array_size) {
    int i = 0;

    while (array[i] < value && i < array_size) {
        i++;
    }
    if (i == array_size) {
        // left shift all elements
        for (int j = 0; j < array_size - 1; j++) {
            array[j] = array[j + 1];
        }
        array[array_size - 1] = value;
    } else if (i == 0) {
        // right shift all elements
        for (int j = array_size - 1; j > 0; j--) {
            array[j] = array[j - 1];
        }
        array[0] = value;
    } else {
        i--;
        for (int j = 0; j < i; j++) {
            array[j] = array[j + 1];
        }
        array[i] = value;
    }

}


int main() {
    int array_size;
    printf("enter a letter to quit\n");
    // ask for buffer size
    printf("Enter the size of the buffer: ");
    if (scanf_s("%d", &array_size) == 0) {
        printf("invalid input");
        return 1;
    }
    printf("\n");


    int *sorted_array = malloc(array_size * sizeof(int));

    for (int i = 0; i < array_size; i++) {
        sorted_array[i] = INT_MIN;
    }

    while (1) {
        int value;
        printf("enter a number: ");
        if (scanf_s("%d", &value) == 0) {
            break;
        }
        printf("\n");
        insert_in_sorted_array(sorted_array, value, array_size);
        print_array(sorted_array, array_size);
    }

    return 0;
}