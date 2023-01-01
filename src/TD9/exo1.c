#include "stdio.h"

void print_int(int i, int base) {
    if (i < 0) {
        putchar('-');
        i = -i;
    }
    if (i >= base) {
        print_int(i / base, base);
    }
    if (i % base < 10) {
        putchar('0' + i % base);
    } else {
        putchar(' ');
        print_int(i % base, 10);

    }
}

void en_binaire_recursive(int i) {
    print_int(i, 2);
}

int is_bigger_than_2_binary(int i) {
    int xor = i ^ (i >> 2);
    return xor & (xor + 1);
}

void en_binaire_c(int i) {
    if ((i & (1 << 31)) != 0) {
        putchar('-');
        i = ~i + 1;
    }
    if (is_bigger_than_2_binary(i)) {
        en_binaire_c(i >> 1);
    }
    putchar('0' + (i & 1));
}


int main(void) {
    en_binaire_c(-128);

    return 0;
}