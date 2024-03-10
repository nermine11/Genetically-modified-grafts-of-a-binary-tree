#ifndef SAAGE_H
#define SAAGE_H
#include "greffe.h"





int reallouer(Memo * p);
void affiche(Arbre A , FILE * out, int nombre_espace );
char * test_format(char * nom_de_fichier , int modifier, Memo *p);
int serialise(char * nom_de_fichier, Arbre A);
int deserialise(char * nom_de_fichier, Arbre * A);
void nom(char * fichier , char mot[MAX_MOT]);

#endif
