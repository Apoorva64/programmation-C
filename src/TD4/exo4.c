#include <stdio.h>
#include "stdarg.h"
#include "string.h"

void print_int(int value, int base) {
    if (value < 0) {
        putchar('-');
        value = -value;
    }
    if (value >= base) {
        print_int(value / base, base);
    }
    if (value % base > 9) {
        putchar(value % base + 'A' - 10);
    } else {
        putchar(value % base + '0');
    }
}

void Printf(char format[], ...) {
    unsigned int format_len = strlen(format);
    va_list ap;
            va_start(ap, format);
    for (unsigned int i = 0; i < format_len; i++) {

        if (format[i] == '%' && i + 1 < format_len) {
            switch (format[i + 1]) {
                case 'd': {
                    int value = va_arg(ap, int);
                    print_int(value, 10);
                    i++;
                    break;
                }
                case 'x': {
                    int value = va_arg(ap, int);
                    print_int(value, 16);
                    i++;
                    break;
                }

                case 'c': {
                    char value = va_arg(ap, int);
                    putchar(value);
                    i++;
                    break;
                }
                case 's': {
                    char *value = va_arg(ap, char *);
                    while (*value != '\0') {
                        putchar(*value);
                        value++;
                    }
                    i++;
                    break;
                }
                case 'f': {
                    double value = va_arg(ap, double);
                    char buffer[40]; // On suppose ici que 40 caractères suffisent pour un float
                    snprintf(buffer, 40, "%f", value);
                    Printf("%s", buffer);
                    i++;
                    break;
                }
                case '%': {
                    putchar('%');
                    i++;
                    break;
                }


                default:
                    putchar('%');
                    break;
            }
        } else {
            putchar(format[i]);
        }
    }
            va_end(ap);


}


int main() {
    Printf("DEBUT\n%s%c c'est moi.\nTest nombres: 0x%x et %d et un négatif %d\n",
           "salut", ',', 161, 123, -12);
    Printf("Trois nombres sur la même ligne: %d %f %d\n", 1, 2.0, 3);
    Printf("Affichage d'un '%c' et encore un d'une autre façon '%%'\n", '%');
    Printf("Affichage d'un %% non suivi d'un caractère spécial ==> %z...\n");
    Printf("Attention au %% en fin de la chaîne format ==> %");
    Printf("\nFIN\n");
    return 0;
}