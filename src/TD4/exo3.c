#include <stdio.h>
#include "stdarg.h"

int evaluer(char operateur, int operande, ...) {
    va_list ap;
            va_start(ap, operande);
    int result = operande;
    operande = va_arg(ap, int);


    switch (operateur) {
        case '+':
            while (operande >= 0) {
                result += operande;
                operande = va_arg(ap, int);
            }
            break;
        case '-':
            while (operande >= 0) {

                result -= operande;
                operande = va_arg(ap, int);
            }
            break;

        case '*':
            while (operande >= 0) {
                result *= operande;
                operande = va_arg(ap, int);
            }
            break;

        case '/':
            while (operande >= 0) {
                result /= operande;
                operande = va_arg(ap, int);
            }
            break;

        default:
            printf("error");
    }
            va_end(ap);
    return result;

}

int main() {
    printf("%d\n", evaluer('+', 1, 2, 3, -1));
    printf("%d\n", evaluer('-', 10, evaluer('*', 2, 2, 2, -1), 2, -1));
}