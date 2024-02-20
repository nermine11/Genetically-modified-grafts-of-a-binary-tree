<<<<<<< HEAD
#ifndef ENSEMBLE_H
#define ENSEMBLE_H

=======
#ifndef ARBRES_BINAIRES_H
#define ARBRES_BINAIRES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
>>>>>>> 62ad666e37c398c8cf8192fe903bc7e0bd608b90
#define  MAX_MOT 100
#define NOEUD_EXIST(tokens) (tokens && (strcmp(tokens , "1") == 0)? 1: 0 )
#define NOEUD_VIDE(tokens) (tokens && (strcmp(tokens , "0") == 0)? 1: 0 )

typedef struct _noeud {
    char *s ;
    struct _noeud * fg , * fd ;
} Noeud , * Arbre ;


Arbre cree_A_1(void);
Arbre cree_A_2(void);
Arbre cree_A_3(void);

Arbre construire_arbre_binaire(char * mot , const char separateur[3]);

<<<<<<< HEAD



=======
>>>>>>> 62ad666e37c398c8cf8192fe903bc7e0bd608b90
#endif
