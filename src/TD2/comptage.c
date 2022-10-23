#include <stdio.h>

int main() {
    // count the different characters in the input
    int c;
    int counters[128] = {0};
    while ((c = getchar()) != EOF) {
        counters[c]++;
    }
    for (int i = 0; i < 128; i++) {
        if (counters[i] > 0 && i != '\n' && i != '\t' && i != ' ') {
            printf("%c: %d times\n", i, counters[i]);
        }
    }
    return 0;

}