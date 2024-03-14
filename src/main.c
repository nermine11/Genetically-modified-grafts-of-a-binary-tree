#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "saage.h"
#include "greffe.h"
#include "arbres_binaires.h"




int main(int argc, char *argv[]){
   Arbre A = NULL , B = NULL;
    int indice_fichier = 2 , indice_fichier2 = 3 , i , taille_fichier , taille;
    char nom_fichier[MAX_MOT] , fichier[MAX_MOT] ;
    if (argc < 3){ // si l'utilisateur rentre aucun fichier dans l'argument du main

        fprintf(stderr ,"il faut avoir au moins 3 arguments\n");
        return 1;
    }

   if (!(strcmp(argv[1], "-E"))&& argc == 3){ // effectue l'option -E 
        printf("Saisir un code :\n");
        if(construit_arbre(&A))//construit un arbre à l'aide de la saisi d'une phrase 
            if(!serialise(argv[indice_fichier],  A)){// enregistre dans le fichier pris en argument
                fprintf(stderr , "il y a eu un probleme pour la sérialisation du fichier \n" );
                liberer(&A);
                return 1;
            };
        liberer(&A);
        return 0;
   } 
   
    if (!(strcmp(argv[1], "-G")) && argc == 4){//effectue l'option -G

        if(!deserialise(argv[indice_fichier], &A)){// convertir le premier fichier pris en argument en un arbre
            fprintf(stderr , "il y a eu un probleme pour la désérialisation du fichier %s\n", argv[indice_fichier]);
            liberer(&A);
            return 1;

        }
        if(!deserialise(argv[indice_fichier2], &B)){// convertir le deuxieme fichier pris en argument en un arbre
            fprintf(stderr , "il y a eu un probleme pour la désérialisation du fichier %s\n", argv[indice_fichier2]);
            liberer(&A);
            liberer(&B);
            return 1;
        
        }
        if(expansion(&A, B) == -1){//réalisation de la greffe de l'abre A dans B

            fprintf(stderr , "Probleme lié à l'expansion \n");
            liberer(&A);
            liberer(&B);
            return 1;
        }
        
        //creation du fichier après la greffe

        /*--------retire le format .saage------*/
        taille_fichier = strlen(argv[indice_fichier2]) + 1;
        taille = VALEUR_ABSOLUE(  MAX_MOT  - (taille_fichier - 18));

        char * ptr = argv[indice_fichier];
        
        for(i = 0 ; *ptr != '\0' ; i++ , ptr++ ){
            if(*ptr == '.')
                break;
        
            if(i < taille) fichier[i] = *ptr;
        
        }
        /*----------------------*/
        
        strcpy(nom_fichier , fichier);
        strcat(nom_fichier , "_apres_greffe_de_");
        strcat(nom_fichier ,argv[indice_fichier2] );
        //-----------------------//
   
        if(!serialise(nom_fichier , A)){ // réalisation de la sauvegarde
            fprintf(stderr , "il y a eu un probleme pour la sérialisation du fichier \n" );
            liberer(&A);
            liberer(&B);
            return 1; 
        }
        liberer(&A);
        liberer(&B);
        return 0;

    }
}//main
