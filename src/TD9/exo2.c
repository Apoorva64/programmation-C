#include "stdio.h"

#define CHAR_SIZE 8 /* nombre de bits dans un char */
#define MAX_BIGSET 125 /* nombre de cellules dans un ensemble
*/
#define MAX_VAL (CHAR_SIZE * MAX_BIGSET)
typedef unsigned char BigSet[MAX_BIGSET]; /* un ensemble dans [0 .. MAX_VAL[ */

void BigSet_init(BigSet s) /* initialiser s à l'ensemble vide */
{
    for (int i = 0; i < MAX_BIGSET; i++)
        s[i] = 0;
}

void BigSet_add(BigSet s, int i) /* ajouter i dans s */
{
    s[i / CHAR_SIZE] |= 1 << (i % CHAR_SIZE);
}

void BigSet_remove(BigSet s, int i) /* retirer i de s */
{
    s[i / CHAR_SIZE] &= ~(1 << (i % CHAR_SIZE));
}

int BigSet_is_in(BigSet s, int i) /* 0 si i ∉ s et ≠ 0 sinon */
{
    return s[i / CHAR_SIZE] & (1 << (i % CHAR_SIZE));
}

void BigSet_print(BigSet s) /* afficher les éléments de s */
{
    printf("{");
    for (int i = 0; i < MAX_VAL; i++) {
        if (BigSet_is_in(s, i))
            printf("%d ", i);
    }
    printf("}\n");
}

int main(void) {
    BigSet e1, e2, e3;
    BigSet_init(e1); BigSet_init(e2);
    for (int i = 0; i < 140; i += 12) BigSet_add(e2, i);
    for (int i = 0; i < 140; i += 9) BigSet_add(e1, i);
    printf("e1 = "); BigSet_print(e1);
    printf("e2 = "); BigSet_print(e2);
    printf("e3 = "); BigSet_print(e3);
    return 0;
}