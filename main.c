/*
*************************************************************************
*                                                                       *
*       N° de projet :              Pr01                                *
*       Nom du projet :             Bataille-navale                     *
*       Version :                   0.1                                 *
*       Développer par :            Timothée Rapin                      *
*       Date de création :          04.03.2020                          *
*       Date de mise à jour :       04.03.2020                          *
*       Nouveautés :                Bordure titre                       *
*                                                                       *
*************************************************************************
*/

#include <stdio.h>

int fonctionMenu (){
    int choixMenu = 0;

    printf("\n\n\nMENU :");
    printf("\n\n1) Afficher l'aide");
    printf("\n2) S'authentifier");
    printf("\n3) Choisir une map");
    printf("\n4) Jouer");
    printf("\n5) Afficher les scores");
    printf("\n6) Quiter\n");

    scanf("%d", &choixMenu);

    return choixMenu;
}

int main() {
    setbuf(stdout,0);


    // Déclarations + initialisations

    int menu = 0;
    int i = 0;


    // Titre

    printf("\n\n%c", 201);
    for(i = 0; i < 17; i++){
        printf("%c", 205);
    }
    printf("%c", 187);
    printf("\n%c BATAILLE-NAVALE %c", 186, 186);
    printf("\n%c", 200);
    for(i = 0; i < 17; i++){
        printf("%c", 205);
    }
    printf("%c", 188);


    do {

        // MENU

        menu = fonctionMenu();


        // AIDE

        if (menu == 1) {
            printf("\n\nAIDE :");
        }


        // AUTHENTIFICATION

        if (menu == 2) {
            printf("\n\nAUTHENTIFICATION :");
        }


        // MAPS

        if (menu == 3){
            printf("\n\nMAPS :");
            printf("\n\n1) Choisir une map");
            printf("\n2) Creer une map");
            printf("\n3) Supprimer une map\n");
        }


        // JEU

        if (menu == 4){
            printf("\n\nJEU :");
        }


        // SCORES

        if(menu == 5){
            printf("\n\nSCORES :");
        }


    }while(menu != 6);


    // Fin

    printf("\n\n");
    return 0;
}