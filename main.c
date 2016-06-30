/* ************************************************************************
* Générateur comics V2
*************************************************************************
* Fonction : Générer des page HTML pour optimiser l'ajout de comics
* sur mon site
*************************************************************************
* Entrée : Nom du comics, Nom du comics avec undersccore a la place des espaces,
* Nombre de pages
*
* Sortie : Fichier HTML et ligne de code a coller dans le menu qui est copié
* dans le presse papier
* ***********************************************************************
* Librairie :
*************************************************************************
* Auteur   : Philippe Skopal                    * Date  : 30/06/2016
* Version  : v2.0                   			* Executable Windows
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fonction de récupération des saisie de l'utilisateur prise de openclassroom
int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    // On lit le texte saisi au clavier
    if (fgets(chaine, longueur, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entrée"
        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace ce caractère par \0
        }
        return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
    }
    else
    {
        return 0; // On renvoie 0 s'il y a eu une erreur
    }
}
int main()
{
    // Partie une on demande les info

        // Création de la chaine de caractère pour le nom du comics sans underscore, pour nommer la page
        char nomComicsSansUnderscore[100];
        // Création de la chaine de caractère pour le nom du comics avec underscore, pour nommer la page dans le menu et le code
        char nomComicsAvecUnderscore[100];
        // Création de la variable qui contiendra le nombre de page du comics
        int nombrePage = 0;

        // on récupère les noms et nombre de page
        printf("Quel est le nom du comics sans underscore : ");
        lire(nomComicsSansUnderscore, 100);

        printf("Quel est le nom du comics avec underscore : ");
        lire(nomComicsAvecUnderscore, 100);

        //récupération du nombre de page du comics
        printf("Nombre de page du comics : ");
        scanf("%d", &nombrePage);
        // test de lecture des variables
        //printf("%s,  %s,  %d \n\n", nomComicsSansUnderscore, nomComicsAvecUnderscore, nombrePage);

    // Partie 2 creéation du fichier html

    // Génération du chemin pour le fopen
    char pathBase[100] = "";
    strcat(pathBase, nomComicsAvecUnderscore);
    strcat(pathBase, ".html");

    FILE* fichier = NULL;

    fichier = fopen(pathBase, "w");

    if (fichier != NULL)
    {
        // Ecriture du header de la page
        fprintf(fichier, "<!DOCTYPE html>\n");
        fprintf(fichier, "<html>\n");
        fprintf(fichier, "<head>\n");
        fprintf(fichier, "    <meta charset=\"utf-8\">\n");
        fprintf(fichier, "    <link rel=\"stylesheet\" href=\"style.css\" />\n");
        fprintf(fichier, "    <title>%s</title>\n", nomComicsSansUnderscore);
        fprintf(fichier, "</head>\n");
        fprintf(fichier, "\n");
        fprintf(fichier, "<body>\n");
        fprintf(fichier, "    <header>\n");
        fprintf(fichier, "    <h1><a class=\"lien2\" href=\"Yiffy_Home_Index.html\"> Yiffy Home</a></br>\n");
        fprintf(fichier, "    </header>\n");
        fprintf(fichier, "\n");
        fprintf(fichier, "    <section id=\"Cats_tongue\">\n");
        fprintf(fichier, "    <h2>%s</h2>\n", nomComicsSansUnderscore);
        fprintf(fichier, "    <p>\n");
        fprintf(fichier, "    <a id=\"Top\" class=\"lien\" href=\"#Down\" > Down of Page </a></br>\n");
        fprintf(fichier, "\n");
        // Ecriture du contenu avec la boucle
        int compteur;

        for (compteur = 0 ; compteur < nombrePage-1 ; compteur++)
        {
            fprintf(fichier,"    <img src=\"Contenu/Yiff/Cats_tongue/Cats_tongue");
            fprintf(fichier,"%d", compteur+1);
            fprintf(fichier,".png\"/> </br></br></br></br>\n");
        }
            fprintf(fichier,"    <img src=\"Contenu/Yiff/Cats_tongue/Cats_tongue");
            fprintf(fichier,"%d", compteur+1);
            fprintf(fichier,".png\"/> </br>\n");
        // Ecriture du footer de la page

        fprintf(fichier, "\n");
        fprintf(fichier, "<a id=\"Down\" class=\"lien\" href=\"#Top\" > Top of page </a>\n");
        fprintf(fichier, "</p>\n");
        fprintf(fichier, "</section>\n");

        fprintf(fichier, "</body>\n");
        fprintf(fichier, "</html>\n");

        fclose(fichier); // On ferme le fichier qui a été ouvert
    }

    return 0;

}
