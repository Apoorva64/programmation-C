#include "string.h"
#include "stdio.h"


void suppression(char *str, int i, int j) {
    int len = strlen(str);
    j++;
    if (i < 0) {
        i = 0;
    }
    if (j > len) {
        j = len;
    }
    int shift = j - i;

    for (int k = i; k < len; ++k) {
        if (shift + k > len - 1) {
            continue;
        }
        str[k] = str[shift + k];
    }
    str[len - shift] = '\0';
}


int main(void) {

    char s[] = "0123456789";
    suppression(s, 0, 5);
    printf("%s\n", s);
    char s2[] = "0123456789";
    suppression(s2, 1, 8);
    printf("%s\n", s2);
    char s3[] = "0123456789";
    suppression(s3, -3, 100);
    printf("%s\n", s3);


}