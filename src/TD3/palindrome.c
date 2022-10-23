#include <stdio.h>
#include "string.h"

int palindrome(const char str[]) {
    unsigned int string_length = strlen(str);
    unsigned int left_pointer = 0;
    unsigned int right_pointer = string_length - 1;
    while (left_pointer < right_pointer) {
        if (str[left_pointer] == ' ') {
            left_pointer++;
            continue;
        }
        if (str[right_pointer] == ' ') {
            right_pointer--;
            continue;
        }

        if (str[left_pointer] != str[right_pointer]) {
            return 0;
        }
        left_pointer++;
        right_pointer--;
    }

    return 1;
}

int main() {
    printf("test: %d\n", palindrome("karine alla en irak"));
    printf("test: %d\n", palindrome("kayak"));
    printf("test: %d\n", palindrome("X"));
    printf("test: %d\n", palindrome("test"));
    printf("test: %d\n", palindrome("test test"));
}