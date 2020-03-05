/*
*************************************************************************
*                                                                       *
*       N° de projet :              Pr01                                *
*       Nom du projet :             Bataille-navale                     *
*       Version :                   0.1                                 *
*       Développer par :            Timothée Rapin                      *
*       Date de création :          04.03.2020                          *
*       Date de mise à jour :       05.03.2020                          *
*       Nouveautés :                Affichage grille                    *
*                                                                       *
*************************************************************************
*/

#include <stdio.h>

// tableau

int col = 0;
int ligne = 0;
int tableau[10][10];


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

int fonctionGrille(){

    int iFonction = 0;
    int jFonction = 0;
    char lettre = 65;


    // Affichage numéro de collones

    printf("\n\n     ");
    for(iFonction = 1; iFonction <= 10; iFonction++){
        printf("%-6d", iFonction);
    }


    // Affichage bordure haute

    printf("\n  %c", 201);
    for(iFonction = 1; iFonction < 10; iFonction++){
        printf("%c%c%c%c%c%c",205,205,205,205,205,203);
    }
    printf("%c%c%c%c%c%c",205,205,205,205,205,187);


    // Affichage tableau

    for(iFonction = 0; iFonction < 9; iFonction++){
        printf("\n%c ",lettre);
        lettre++;
        for(jFonction = 0; jFonction < 10; jFonction++){
            printf("%c  %d  ",186,tableau[iFonction][jFonction]);
        }
        printf("%c",186);


        // Ligne intermediaire

        printf("\n  %c",204);
        for(jFonction = 1; jFonction < 10; jFonction++){
            printf("%c%c%c%c%c%c",205,205,205,205,205,206);
        }
        printf("%c%c%c%c%c%c",205,205,205,205,205,185);
    }


    // Affichage dernière ligne

    iFonction = 9;
    printf("\n%c ",lettre);
    lettre++;
    for(jFonction = 0; jFonction < 10; jFonction++){
        printf("%c  %d  ",186,tableau[iFonction][jFonction]);
    }
    printf("%c",186);


    // dernière bordure

    printf("\n  %c",200);
    for(jFonction = 1; jFonction < 10; jFonction++){
        printf("%c%c%c%c%c%c",205,205,205,205,205,202);
    }
    printf("%c%c%c%c%c%c",205,205,205,205,205,188);


    return 0;
}

int main() {
    setbuf(stdout,0);


    // Déclarations + initialisations

    int menu = 0;
    int i = 0;
    int grille;

    for(ligne = 0; ligne < 10; ligne++){
        for(col = 0; col < 10; col++){
            tableau[ligne][col] = 0;
        }
    }



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

        grille = fonctionGrille();


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