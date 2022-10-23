#include <stdio.h>
#include "string.h"

void suppress_char(char str[], char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            int j = i;
            while (str[j] != '\0') {
                str[j] = str[j + 1];
                j++;
            }
        }
        i++;
    }
}

void suppress_char_opt(char str[], char c) {

    unsigned int len = strlen(str);

    unsigned int read_pointer, write_pointer;
    for (read_pointer = 0, write_pointer = 0; read_pointer < len; ++read_pointer) {
        if (c != str[read_pointer]) {
            str[write_pointer] = str[read_pointer];
            write_pointer++;
        }

    }
}




int main() {
    char *string1 = "abcd";
    suppress_char(string1, 'd');
    printf("%s", string1);
}