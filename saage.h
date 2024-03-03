#ifndef SAAGE_H
#define SAAGE_H
#include "greffe.h"
#define MAX_MOT 200
#define NOEUD_VIDE(mot) (((mot == '0'))? 1: 0 )
#define NOEUD_EXIST(mot) (((mot == '1'))? 1: 0 )
#define MOT_VIDE(tokens) ((strcmp(tokens , " ") == 0)? 1: 0 )
#define NOEUD_STRING_VIDE(mot)  ((strcmp(mot , " NULL") == 0)? 1: 0 )
#define FORMAT(code , format) ((strstr(code , format ) )? 1 : 0)
#define MOT_IDENTIQUE(mot , tokens)((strcmp(tokens , mot) == 0)? 1: 0 )

typedef struct{
    char *code;
    int taille_max;
}Memo;


int  Copier_Chiffre(char *mot , Memo * p , int i);
int creation_Memo(Memo *p);
int verification_mot(char * mot);
int creation_code_adapter_arbre(Memo * p);
Arbre construire_arbre_binaire(char * mot);
Arbre saisir_arbre_binaire();
void affiche(Arbre A , FILE * out, int nombre_espace );
int test_format(char * nom_de_fichier );
int serialise(char * nom_de_fichier, Arbre A);
int deserialise(char * nom_de_fichier, Arbre * A);
#endif
