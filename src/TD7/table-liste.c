#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "table.h"

//
// Fonctions elementaires de manipulation de la table
//
struct t_table {
    char *elt;
    int *occurrences;
    struct t_table *suivant;
};


/* Creation d'une table vide */
Table creer_table(void) {
    return malloc(sizeof(struct t_table));
}

/* Insertion d'un élément dans la table triée. Si l'élément est déjà
 * présent dans la table, le compteur d'occurrences est incrémenté.
 * La fonction renvoie le nombre actuel d'occurrences de elt */
int ajouter_table(Table *table, char *elt) {
    Table *tmp = table;
    while (*tmp != NULL) {
        if (strcmp((*tmp)->elt, elt) == 0) {
            (*tmp)->occurrences++;
            return (*tmp)->occurrences;
        }
        tmp = &(*tmp)->suivant;
    }

    *tmp = creer_table();
    (*tmp)->elt = elt;
    (*tmp)->occurrences = 1;
    // insert at the correct place in the list (alphabetical order)
    while (*table != NULL && strcmp((*table)->elt, elt) < 0) {
        table = &(*table)->suivant;
    }
    (*tmp)->suivant = *table;

    return 1;
}

/* Impression triée des éléments de la table */
void imprimer_table(Table table) {
    Table tmp = table;
    while (tmp != NULL) {
        printf("%s %d fois dans le texte", tmp->elt, tmp->occurrences);
        tmp = tmp->suivant;
    }
}

/* Appel d'une fonction sur chacun des éléments de la table */
void appliquer_table(Table table, t_fonction fonction) {
    Table tmp = table;
    while (tmp != NULL) {
        fonction(tmp->elt, tmp->occurrences);
        tmp = tmp->suivant;
    }
}

/* Recherche du nombre d'occurrences d'un élément */
int rechercher_table(Table table, char *elt) {}

/* Destruction d'une table */
void detruire_table(Table *table) {}
