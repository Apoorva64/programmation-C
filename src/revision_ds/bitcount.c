#include<stdio.h>

int bit_count(unsigned int count) {
    int number_of_bits = 0;
    while (count > 0) {
        if (count % 2 == 0) number_of_bits++;
        count /= 2;
    }
    return number_of_bits;
}


int main(void) {

    printf("%d", bit_count(10));
}