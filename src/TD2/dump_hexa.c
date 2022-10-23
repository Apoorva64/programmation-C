#include "stdio.h"

void print_buffer(char *buffer, int size) {
    // print the buffer
    for (int i = 0; i < size; i++) {
        printf("%02x ", buffer[i]);
    }
    if (size < 16) {
        for (int i = 0; i < 16 - size; i++) {
            printf("   ");
        }
    }
    printf("| ");
    for (int i = 0; i < size; i++) {
        if (buffer[i] >= 32 && buffer[i] <= 126) {
            printf("%c", buffer[i]);
        } else {
            printf(".");
        }
    }
    printf("\n");
}


int main() {
    // read 16 characters from stdin
    char buffer[16];
    int buffer_counter = 0;
    while ((scanf_s("%c", &buffer[buffer_counter], 1)) != EOF) {
        buffer_counter++;
        if (buffer_counter == 16) {
            print_buffer(buffer, buffer_counter);
            buffer_counter = 0;
        }
    }
    if (buffer_counter != 0) {
        print_buffer(buffer, buffer_counter);
    }
}