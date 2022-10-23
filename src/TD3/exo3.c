
#include <stdio.h>

void strcpy(char s1[], char s2[]) {
    unsigned int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
}

int strcmp(char s1[],char s2[]){
    unsigned int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return -1;
        }
        i++;
    }
    return 1;
}

void strupper(char s[]){
    unsigned int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        }
        i++;
    }
}


int main() {
    char *string1 = "abcd";
    char *string2 = "aaa";
    strcpy(string1, string2);

    printf("%s\n", string1);

    printf("%d\n", strcmp("abc", "z"));
    printf("%d\n", strcmp("abc", "abd"));
    printf("%d\n", strcmp("trié", "triée"));
}