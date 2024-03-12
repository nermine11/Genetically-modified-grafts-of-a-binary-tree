#ifndef SAAGE_H
#define SAAGE_H
#include "greffe.h"






void affiche(Arbre A , FILE * out, int nombre_espace );
/* écrit d’abord dans le fichier  le sous-arbre gauche ensuite le sous-arbre droit en respectant les conventions données*/
char * test_format(char * nom_de_fichier , int modifier, Memo *p);
/*teste si le format (qu'il contient .saage) du fichier est correct il renvoie 1 sinon 0.*/
int serialise(char * nom_de_fichier, Arbre A);
/*sauvegarde un arbre dans un fichier en cas de succès on renverra 1 sinon 0.*/
int deserialise(char * nom_de_fichier, Arbre * A);
/*créer  un arbre à partir d'un fichier en cas de succès on renverra 1 sinon 0.*/
void nom(char * fichier , char mot[MAX_MOT]);
/*retire le format .saage*/
#endif
