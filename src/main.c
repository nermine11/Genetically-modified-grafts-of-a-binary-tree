#include "saage.h"



int main(int argc, char *argv[]){
   Arbre A = NULL , B = NULL;
    int indice_fichier = 2 , indice_fichier2 = 3;
    char nom_fichier[MAX_MOT] , fichier[MAX_MOT] ;
    FILE * out = fopen("Arbre.dot" , "a");
    if (argc < 3){

        fprintf(stderr ,"il faut avoir au moins 3 arguments\n");
        return 1;
    }

   if (!(strcmp(argv[1], "-E"))&& argc == 3){
        printf("Saisir un code :\n");
        if(construit_arbre(&A))
            serialise(argv[indice_fichier],  A);
        liberer(&A);
        return 0;
   } 
   
    if (!(strcmp(argv[1], "-G")) && argc == 4){

        if(!deserialise(argv[indice_fichier], &A)){
            fprintf(stderr , "il y a eu un probleme pour la désérialisation du fichier %s\n", argv[indice_fichier]);
            liberer(&A);
            return 0;

        }
        if(!deserialise(argv[indice_fichier2], &B)){
            fprintf(stderr , "il y a eu un probleme pour la désérialisation du fichier %s\n", argv[indice_fichier2]);
            liberer(&A);
            return 0;
        
        }
        if(!expansion(&A, B)){
            fprintf(stderr , "Probleme lié à l'expansion \n");
            liberer(&A);
            liberer(&B);
            return 0;
        }
        
        //creation du fichier après la greffe
        nom(argv[indice_fichier] , fichier);
        strcpy(nom_fichier , fichier);
        strcat(nom_fichier , "_apres_greffe_de_");
        strcat(nom_fichier ,argv[indice_fichier2] );
        //-----------------------//
        if(out){
            creePDF ("Arbre.dot" , "Arbre.pdf" , A);
            system ( " evince  Arbre.pdf   & " ) ;
        }
        serialise(nom_fichier , A);


    }
}//main
