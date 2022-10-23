#include <stdio.h>

int indice(const char str[], const char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i++;
    }
    return -1;
}

int indice_droite(const char str[], const char c) {
    int i = 0;
    int max_index = -1;
    while (str[i] != '\0') {
        if (str[i] == c) {
            max_index = i;
        }
        i++;

    }
    return max_index;
}


int main(){
    printf("test: %d\n",indice("Test", 'T'));
    printf("test: %d\n",indice("Test", 't'));
    printf("test: %d\n",indice("Test", 'z'));
    printf("test: %d\n",indice("Tester", 'e'));
    printf("test: %d\n",indice_droite("Test", 'T'));
    printf("test: %d\n",indice_droite("Test", 't'));
    printf("test: %d\n",indice_droite("Test", 'z'));
    printf("test: %d\n",indice_droite("Tester", 'e'));

}