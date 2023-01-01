#include <malloc.h>
#include "stdio.h"


char *strcpy(char *dest, const char *src) {
    char *p = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    return p;
}

size_t strlen(const char *s) {
    size_t count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}

char *strdup(const char *s) {
    size_t len = strlen(s);
    char *out = malloc(sizeof(char) * (len + 1));
    out[len] = '\0';
    strcpy(out, s);
    return out;

}

char *strchr(const char *s, int c) {
    char *cp = strdup(s);
    while (*cp != '\0' || *cp != c) {
        cp++;
    }
    return cp;
}

int main(void) {
    char *str1 = "hello";
    char *str1cpy = strdup(str1);
    printf("%s", str1cpy);
}
