#include "stdio.h"
#include "stdarg.h"

void imprimer(char *str, ...) {
    va_list ap;
            va_start(ap, str);
    while (str) {
        printf("%s", str);
        printf("%d", va_arg(ap, int));
        str = va_arg(ap, char*);
    }
            va_end(ap);
}


int main() {
    char *t[] = {"Hello", "World"};


}