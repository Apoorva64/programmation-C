#include <stdio.h>
#include "stdarg.h"

float mean(int count, ...) {
    va_list ap;
    double sum = 0;
    va_start(ap, count);
    for (int i = 0; i < count; ++i) {
        sum += va_arg(ap,
        double);
    }
    va_end(ap);
    return (float) (sum / (double) count);

}

int sum(int count, ...) {
    va_list ap;
    int sum = 0;
    va_start(ap, count);
    for (int i = 0; i < count; ++i) {
        sum += va_arg(ap,
        int);
    }
    va_end(ap);
    return sum;
}


void imprimer(char *str, ...) {
    va_list ap;
    va_start(ap, str);
    while (str != NULL) {
        int tmp = (int) va_arg(ap,
        int);
        printf("%s%d", str, tmp);
        str = va_arg(ap,
        char*);
    }
    va_end(ap);
}

int main(void) {
//    printf("Moyenne = %f \n", mean(5, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    int x = 1, y = 2;
    imprimer("Valeur de x=", x, " Valeur de y=", y, " => x+y=", x + y, NULL);
}
