#include <stdio.h>

int main() {
    printf("+--------+--------+\n");
    for (float celsius = 0; celsius <= 20; celsius += 0.5f) {
        double fahrenheit = celsius * 9 / 5 + 32;
        printf("| %5.1fC | %5.1fF |\n", celsius, fahrenheit);
    }
    printf("+--------+--------+\n");
}