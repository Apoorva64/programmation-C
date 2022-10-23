#include <stdio.h>

int main() {
    // read from stdin
    int c;
    int counter = 0;
    while ((c = getchar()) != EOF) {
        if (c == '{') {
            counter++;
        }
        if (c == '}') {
            counter--;
        }
        if (counter < 0) {
            printf("Unexpected '}'");
            return 0;
        }


    }
    if (counter != 0 ) {
        printf("Missing '}': %d", counter);
        return 0;
    }
    printf("Correct");
}
