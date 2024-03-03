#ifndef ARBRES_BINAIRES_H
#define ARBRES_BINAIRES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _noeud {
    char *val ;
    struct _noeud * fg , * fd ;
}Noeud, *Arbre;

typedef struct{
    char *code;
    int taille_max;
}Memo;


Noeud * alloue_noeud(char * s);
void liberer(Arbre * A);
Arbre cree_A_1(void);
Arbre cree_A_2(void);
Arbre cree_A_3(void);


#endif
