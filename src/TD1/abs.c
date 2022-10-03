#include <stdio.h>
#include <math.h>

int main() {
    int number;
    printf("enter a number:\n");
    if (scanf_s("%d", &number) == 0) {
        printf("invalid input");
        return 1;
    }

    printf("The number in abs is %d", abs(number));
    return 0;
}
