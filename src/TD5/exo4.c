#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void print_reverse(char *string) {
    for (int i = (int) strlen(string) - 1; i >= 0; --i) {
        printf("%c", string[i]);
    }
}


int main(int argc, char *argv[]) {
    bool reverse = false;
    if (strcmp(argv[1], "-r") == 0) {
        reverse = true;
    }

    for (int i = (reverse ? 2 : 1); i < argc; ++i) {
        if (reverse) {
            print_reverse(argv[i]);
        } else {
            printf("%s", argv[i]);
        }
        printf(" ");
    }
    printf("\n");
    return 0;
}
