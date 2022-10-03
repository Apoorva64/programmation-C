#include <stdio.h>


int main() {
    int c, counter = 2;
    printf("1 ");
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == '\n') {
            printf("%d ", counter);
            counter++;
        }
    }
    return 0;
}