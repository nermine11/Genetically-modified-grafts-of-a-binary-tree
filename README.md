NOM PRENOM TP

# Genetically-modified-grafts-of-a-binary-tree
Nous devons réaliser un programme qui effectue la greffe d'un Arbre B dans un arbre A. Pour cela, vous aurez la possibilité de choisir entre d'option. En effet,

L'option -E n'effectue pas la greffe, mais permet de saisir un arbre sur le terminal. Exemple : Commande pour activer l'option -E : ./saage -E Exemple1.saage Le programme vous demandera de saisir un code. Saisissez cela en guise d'exemple : 1 "arbre\n" 1 "binaire\n" 0 0 1 "ternaire\n" 0 0 un fichier du nom de Exemple1.saage sera créé dans le dossier data/.

Pour effectuer la greffe, vous devez utiliser l'option -G. Exemple d'utilisation : ./saage -G A_1.saage B.saage Un fichier du nom de A_1_apres_greffe_de_B.saage contiendra l'arbre B greffé dans l'arbre A_1 qui sera mis dans le dossier data/.

La greffe n'est pas bien effectuée dans l'arbre A_3 , sinon le reste fonctionne. Les problèmes rencontrés sont l'expansion qui a pris du temps à se faire et certains cas d'erreurs. À traité dans la fonction construire_arbre()
