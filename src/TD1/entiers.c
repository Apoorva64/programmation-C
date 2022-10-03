#include <stdio.h>

int main() {
    int counter, number = 1;
    for (counter = 0; number > 0; counter++) {
        printf("Entrer un entier: ");
        if (scanf_s("%d", &number) == 0) {
            printf("invalid input");
            return 1;
        }
    }
    printf("Nombre d'entiers saisis: %d", counter);
    return 0;
}