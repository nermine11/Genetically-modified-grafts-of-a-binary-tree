#ifndef GREFFE_H
#define GREFFE_H

#include "arbres_binaires.h"


//on copie dans *dest l’arbre source On retourne 0 si l’allocation échoue, sinon on retourne 1.
int copie(Arbre * dest, Arbre source);

int expansion(Arbre * a, Arbre b);
//on  greffe l'arbre b sur l'arbre a
// la fonction renvoie 1 en cas de succès et 0 en cas d’échec d'une des fonctions intermediaires










#endif
