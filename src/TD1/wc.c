#include <stdio.h>

int main() {
    int c, lines, words, characters;
    lines = words = characters = 0;
    while ((c = getchar()) != EOF) {
        characters++;
        if (c == '\n')
            ++lines;
        if (c == ' ' || c == '\n' || c == '\t')
            ++words;
    }
    printf("%d %d %d", lines, words, characters);
    return 0;
}