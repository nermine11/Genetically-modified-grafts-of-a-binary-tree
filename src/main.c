#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "saage.h"
#include "arbres_binaires.h"
#include "greffe.h"


int option_E(char ** arg , int argc){
    int indice_op = 1;
    char option[] = "-E";
    return (argc == 3 && MOT_IDENTIQUE(arg[indice_op] , option));
}

int option_G(char ** arg , int argc){
    int indice_op = 1;
    char option[] = "-G";
    return (argc == 4 && MOT_IDENTIQUE(arg[indice_op] , option));
}

int main(int argc, char *argv[]){


   int indice_fichier = 2;
    Arbre A = NULL;
    if(option_E(argv , argc) && ((A = saisir_arbre_binaire()))){//je le change ce soir
       
        serialise(argv[indice_fichier],  A);
    }


}