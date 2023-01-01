

#include <stdio.h>

int nombre_Z(int nb) {
    if (nb == 0) {
        return 0;
    }
    if (nb < 0) {
        nb = -nb;
    }
    int nb_cpy = nb;
    int product = 1;
    while (nb > 0) {
        if (nb % 10 > 0) {
            product *= nb % 10;
        } else {
            product *= nb;
        }
        nb /= 10;
    }
    return product != 0 && nb_cpy % product == 0;
}

int main(void) {
    printf("nombre_Z(216) = %d\n", nombre_Z(216));
    printf("nombre_Z(89) = %d\n", nombre_Z(89));
    for (int i = 10; i < 100; i++)
        if (nombre_Z(i)) printf("%d\n", i);


}