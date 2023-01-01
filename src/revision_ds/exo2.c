#define MIN 5
#define MAX 9

#include "stdio.h"


int main(void) {
    int c;
    int char_index = 0;
    while ((c = getchar()) != EOF) {
        char_index++;
        if (char_index <= MAX && char_index >= MIN) {
            continue;
        }
        if (c == '\n') {
            char_index = 0;
        }
        printf("%c", c);

    }
}