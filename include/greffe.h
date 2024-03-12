#ifndef GREFFE_H
#define GREFFE_H

#include "arbres_binaires.h"



int copie(Arbre * dest, Arbre source);
/*on copie dans *dest l’arbre source On retourne 0 si l’allocation échoue, sinon on retourne 1.*/
int expansion(Arbre * a, Arbre b);
/*qui modifie l’arbre *A de sorte qu’après l’appel de fonctions,*/ 
/*celui-ci contienne la greffe de l’arbre B sur A. */
/*Celle-ci renverra 1 en cas de succès et 0 en cas d’échec.*/










#endif
