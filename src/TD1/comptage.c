#include <stdio.h>

int main() {
    unsigned int counter, sum = 0, max = 0;
    int number = 0;
    for (counter = 0; number >= 0; counter++) {
        sum += number;
        if (number > max) {
            max = number;
        }
        printf("Entrer un entier: ");
        if (scanf_s("%d", &number) == 0) {
            printf("invalid input");
            return 1;
        }
    }
    printf("Le maximum des %d nombres saisis est %d. La somme est %d.", counter - 1, max, sum);
    return 0;
}