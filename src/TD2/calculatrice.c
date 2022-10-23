#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {

    char *possible_operations = "+-/*";

    while (1) {
        float number_1;
        float number_2;
        char operation;
        bool found_operation = false;
        // read first number
        scanf_s("%e", &number_1, 50);


        // read the operation
        while (!found_operation && (scanf_s("%c", &operation, 1)) != EOF) {
            for (int i = 0; i < strlen(possible_operations); ++i) {
                if (operation == possible_operations[i]) {
                    found_operation = true;
                    break;
                }
            }
        }

        // read second number
        scanf_s("%e", &number_2, 50);


        switch (operation) {
            case '*':
                printf("= %G\n", number_1 * number_2);
                break;
            case '/':
                printf("= %G\n", number_1 / number_2);
                break;
            case '+':
                printf("= %G\n", number_1 + number_2);
                break;
            case '-':
                printf("= %G\n", number_1 - number_2);
                break;

            default:
                printf("error");
                break;

        }

    }
}