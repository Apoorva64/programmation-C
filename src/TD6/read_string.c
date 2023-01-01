#include "stdio.h"
#include "stdlib.h"

char *readline();

int main(void) {
    char *s = NULL;
    do {
        printf("Entrer une chaîne: ");
        fflush(stdout);
        s = readline();
        if (s) {
            printf("Chaîne lue : '%s'\n", s);
            free(s);
        }
    } while (s);
    return 0;
}

char *readline() {
    char *line = NULL;
    unsigned int size = 0;
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        line = realloc(line, size + 1);
        line[size++] = (char) c;
    }
    if (c == EOF && size == 0) {
        return NULL;
    }
    line = realloc(line, size + 1);
    line[size] = '\0';
    return line;
}
