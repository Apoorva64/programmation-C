#include <stdarg.h>
#include <stdio.h>

void cat_strings(char str1[], ...) {
    va_list ap;
            va_start(ap, str1);
    while (str1 != NULL) {
        printf("%s", str1);
        str1 = va_arg(ap, char *);
    }
            va_end(ap);
}


int main() {
    cat_strings("es", "sai", NULL);
}