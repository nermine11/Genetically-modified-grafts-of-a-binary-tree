#ifndef SAAGE_H
#define SAAGE_H
#include "greffe.h"






int serialise(char * nom_de_fichier, Arbre A);
/*sauvegarde un arbre dans un fichier en cas de succès on renverra 1 sinon 0.*/
int deserialise(char * nom_de_fichier, Arbre * A);
/*créer  un arbre à partir d'un fichier en cas de succès on renverra 1 sinon 0.*/

#endif
