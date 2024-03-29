#include "saage.h"

/*reallocation d'une chaine de caractére renvoie 1 si l'opération s'est effectuer sinon 0*/
static int reallouer(Memo * p){

    char *t = (char *) malloc(p->taille_max *2 * sizeof(char) );
    if(!p->code){
        free(p->code);
        fprintf(stderr , "problème d'allocation\n");
        return 0;
    } 
    strcpy(t , p->code);
    p->code = t;
    t = NULL;
    p->taille_max *= 2;
    return 1;
    
}


/*initialisation d'une chaine de caracère renvoie 
1 si l'opération s'est bien déroulé sinon 0 en cas d'échec*/
static int creation_Memo(Memo *p){
    p->code = (char *)calloc( MAX_MOT, sizeof(char));
    if(p->code){
        p->taille_max = MAX_MOT;
        return 1;

    }
    fprintf(stderr ,"il s'est produit une erreur\n");

    free(p->code);
    return 0;
}

/*creation d'un arbre à partir d'une chaine de caractère renvoie un arbre sinon NULL en cas d'échec*/
static Arbre construire_arbre_binaire(char * mot){
    mot = strtok(NULL , "*");
    if(mot){
       
        if(NOEUD_VIDE(*mot))
            return NULL;
        
        if(NOEUD_EXIST(*mot))
            mot = strtok(NULL , "*");
    
        

        if(!mot)
            return NULL;
        Arbre a = alloue_noeud(mot);
    
        if(!a){
            liberer(&a);
            exit(EXIT_FAILURE);

        }
        a->fg = construire_arbre_binaire(mot);
        a->fd = construire_arbre_binaire(mot);
        
       return a;
   }

    return NULL;
}

/* écrit d’abord dans le fichier  le sous-arbre gauche ensuite le sous-arbre droit en respectant les conventions données*/
static void affiche(Arbre A , FILE * out, int nombre_espace ){
    int i ;
    char espace[MAX_MOT] = "    ";
    if(!A){
        return;
    }
    
    for(i = 1 ; i < nombre_espace ; i++){
            strcat(espace , "    ");
    } 
    fprintf(out , "%sValeur : %s\n",espace , A->val);
    
   
    if(A->fg){
        fprintf(out ,"%sGauche :\n" , espace);
        affiche(A->fg , out , nombre_espace + 1); 
    } 
    else if(!A->fg)
        fprintf(out ,"%sGauche : NULL\n" ,espace);

    if(A->fd ){
        fprintf(out ,"%sDroite :\n", espace);
        affiche(A->fd , out  , nombre_espace + 1);
    }
    else if(!A->fd)
        fprintf(out ,"%sDroite : NULL\n",espace);

        

    
}

/*teste si le format (qu'il contient .saage) du fichier est correct il renvoie 1 sinon 0.*/
static char * test_format(char * nom_de_fichier , int modifier , Memo *p){
    int test = strlen(nom_de_fichier) < 6 && !FORMAT(nom_de_fichier , ".")? 1 : (!MOT_IDENTIQUE( nom_de_fichier + strlen(nom_de_fichier) - 6 , ".saage") && !FORMAT(nom_de_fichier , "."))? 1 :0;
    creation_Memo(p);
    strcpy(p->code , "data/");
    if(test){
        if(modifier){
            strcat(p->code , nom_de_fichier);
            fprintf(stderr, "Attention vous avez oublier de mettre le format .saage\n");
            strcat(p->code , ".saage");
        }
        return (!modifier) ? NULL : p->code;
    }
    if((strlen(nom_de_fichier) >= 6 && MOT_IDENTIQUE( nom_de_fichier + strlen(nom_de_fichier) - 6 , ".saage"))){
        strcat(p->code , nom_de_fichier);
        return p->code;
    }
    return  NULL ;
}



int serialise(char * nom_de_fichier, Arbre A){
    Memo p;
    nom_de_fichier = test_format(nom_de_fichier , 1 , &p);
    if (!nom_de_fichier){
        fprintf(stderr , "le format du fichier est incorrecte\n");
        return 0;
    }

    FILE * out = fopen ( nom_de_fichier , "w");
    if(p.code) 
        free(p.code);
    if(!out){
        fprintf(stderr , "le fichier ne s'est pas ouvert\n");
        return 0;
    }
    if(!A){
        fprintf(stderr , "Arbre n'existe pas \n");
        fclose(out);
        return 0;

    }

    fprintf(out, "Valeur : %s\n" , A->val);
    fprintf(out , "Gauche : \n");
    int nombre_espace = 1;
    
    affiche(A->fg , out , nombre_espace);
    fprintf(out , "Droite : \n");
    affiche(A->fd , out , nombre_espace);
    fclose(out);
    return 1;

}

int deserialise(char * nom_de_fichier, Arbre * A){ 
   Memo tmp , p;
    char ligne[MAX_MOT] , *direction , *mot ;
   
    int taille_chaine = 0; 

    FILE * out = fopen ( nom_de_fichier , "r") ;
    if(!out){
        printf("le fichier out ne s'est pas ouvert \n");
        return 0;
    }
    if(!test_format(nom_de_fichier , 0 , &tmp)){
        printf("le format n'est pas le bon\n");
        fclose(out);
        return 0;
    }
    if(tmp.code)
        free(tmp.code);


    if(!creation_Memo(&p)){
        fprintf(stderr , "erreur au niveau de la creation de memo \n");
        fclose(out);
        return 0;
    }
    for( ; fgets(ligne , MAX_MOT , out) ; ){
        
        direction = strtok(ligne , ":\n");
        mot = strtok(NULL , ":\n");

        if(p.taille_max <= strlen(p.code) + strlen(mot)){ 
            if(!reallouer(&p)){
                free(p.code);
                fclose(out);
                return 0;
            }
        }

        if(direction && mot && !strstr(direction , "Gauche") && !strstr(direction , "Droite") && !strstr(direction , "Valeur") ){
            fprintf(stderr , "le fichier est incorrect\n");
            free(p.code);
            fclose(out);
            return 0;
        }
        if(direction && mot && (strstr(direction , "Gauche") || strstr(direction , "Droite")) && !((MOT_IDENTIQUE(mot , " ")  || MOT_IDENTIQUE(mot , " NULL")))){

            fprintf(stderr , "le fichier est incorrect2 %d\n" , MOT_IDENTIQUE(mot , " "));
            free(p.code);
            fclose(out);
            return 0;

        }
        taille_chaine = 1;
        
        if(mot && NOEUD_STRING_VIDE(mot)){
            strcat(p.code , "*0");
            if(MOT_IDENTIQUE(p.code + strlen(p.code) - 1, " "))strcat(p.code , "*");
        }
        else if (mot && !MOT_VIDE(mot)){
            strcat(p.code , "*1");
            strcat(p.code , "*");
            if(!strncmp(mot , " ", strlen(" "))){
                strcat(p.code , mot + 1);
            }
            else
                strcat(p.code , mot);
           
        }
        
        

    }
  

    if(taille_chaine){
        char * mot = strtok(p.code , "*");
        *A = construire_arbre_binaire(mot);
        free(p.code);
    
    }
    fclose(out);
    return taille_chaine;
}


