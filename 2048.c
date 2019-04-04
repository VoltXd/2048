/*
 =============================================================================
 Nom         : 2048.c
 Auteur      : Pierre-Alexandre Peyronnet
 Description : Version console du jeu "2048"
 =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>

void generePlateau(int *) ;
void affichPlateau(const int * , int) ;
void taille(const int * , int *) ;
int commandePlateau(int * , char) ;
int verifPlateau(const int *) ;

int main()
{
    srand(time(NULL)) ;
    char dir ;
    int c[16] = {0} , i , trigger = 0 , score = 0 , point , tours = 1 , verifCom , verifEntrer ;
    // Affichage des regles
    printf("2048\nBut : Assembler les nombres de meme valeur jusqu'a 2048\nCommandes :\nHaut : z + Enter\nBas : s + Enter\nGauche : q + enter\nDroite : d + Enter\n\n\n") ;
    _getch() ;
    generePlateau(c) ;
    affichPlateau(c , score) ;
    while(trigger == 0)
    {
        printf("\n\nTour %d\nChoisir une direction : ", tours) ;
        for (verifEntrer = 0 ; verifEntrer == 0 ; printf("Veuillez entrer une touche correcte : "))
        {
            dir = 0 ;
            scanf("%c", &dir) ;
            getchar() ;
            if (dir == 'Z' || dir == 'z' || dir == 'D' || dir == 'd' || dir == 'Q' || dir == 'q' || dir == 'S' || dir == 's')
            {
                break ;
            }
        }
        point = commandePlateau(c , dir) ;
        if (point == -1) //Verifie si le joueur a choisie une direction correcte
        {
            while (point == -1)
            {
                if (verifPlateau(c) == 0)
                {
                    break ;
                }
                printf("Manipulation impossible, veuillez rejouer : ") ;
                for (verifEntrer = 0 ; verifEntrer == 0 ; printf("Veuillez entrer une touche correcte : "))
                {
                    dir = 0 ;
                    scanf("%c", &dir) ;
                    getchar() ;
                    if (dir == 'Z' || dir == 'z' || dir == 'D' || dir == 'd' || dir == 'Q' || dir == 'q' || dir == 'S' || dir == 's')
                    {
                        break ;
                    }
                }
                point = commandePlateau(c , dir) ;
            }
        }
        verifCom = verifPlateau(c) ;
        if (verifCom > 0)
        {
            score = score + point ;
            affichPlateau(c , score) ;
            tours++ ;
        }
        else
        {
            // Cas de defaite
            affichPlateau(c , score) ;
            printf("\n\nVous avez perdu...") ;
            break ;
        }
        for (i = 0 ; i < 16 ; i++)
        {
            if (c[i] == 2048)
            {
                // Cas de victoire
                trigger = 1 ;
                printf("\n\nFelicitation, vous avez gagne !!!") ;
            }
        }
        dir = 0 ;
    }
    printf("\nNombre total de tours : %d\nScore final : %d", tours , score) ;
    _getch() ;
    return 0 ;
}

void generePlateau(int *c) //Cree la grille de debut de partie
{
    int a , b ;
    a = rand() % 16 ;
    b = rand() %16 ;
    if (a == b)
    {
        b = rand() %16 ;
    }
    if (rand() % 25 == 0)
    {
        c[a] = 4 ;
    }
    else
    {
        c[a] = 2 ;
    }
    if (rand() % 25 == 0)
    {
        c[b] = 4 ;
    }
    else
    {
        c[b] = 2 ;
    }
}

void affichPlateau(const int *c , int score) //Affiche le tableau tour par tour et affiche le score
{
    int i , sizeTab[16] ;
    taille(c , sizeTab) ;
    printf("\n _______________________________                Score : %d\n|	|	|	|	|\n|", score) ;
    for (i = 0 ; i < 4 ; i++)
    {
        if (sizeTab[i] == -1)
        {
            printf("       |") ;
        }
        if (sizeTab[i] == 0)
        {
            printf("   %d   |", c[i]) ;
        }
        if (sizeTab[i] == 1)
        {
            printf("   %d  |", c[i]) ;
        }
        if (sizeTab[i] == 2)
        {
            printf("  %d  |", c[i]) ;
        }
        if (sizeTab[i] == 3)
        {
            printf("  %d |", c[i]) ;
        }
    }
    printf("\n|_______|_______|_______|_______|\n|	|	|	|	|\n|") ;
    for (; i < 8 ; i++)
    {
        if (sizeTab[i] == -1)
        {
            printf("       |") ;
        }
        if (sizeTab[i] == 0)
        {
            printf("   %d   |", c[i]) ;
        }
        if (sizeTab[i] == 1)
        {
            printf("   %d  |", c[i]) ;
        }
        if (sizeTab[i] == 2)
        {
            printf("  %d  |", c[i]) ;
        }
        if (sizeTab[i] == 3)
        {
            printf("  %d |", c[i]) ;
        }
    }
    printf("\n|_______|_______|_______|_______|\n|	|	|	|	|\n|") ;
    for (; i < 12 ; i++)
    {
        if (sizeTab[i] == -1)
        {
            printf("       |") ;
        }
        if (sizeTab[i] == 0)
        {
            printf("   %d   |", c[i]) ;
        }
        if (sizeTab[i] == 1)
        {
            printf("   %d  |", c[i]) ;
        }
        if (sizeTab[i] == 2)
        {
            printf("  %d  |", c[i]) ;
        }
        if (sizeTab[i] == 3)
        {
            printf("  %d |", c[i]) ;
        }
    }
    printf("\n|_______|_______|_______|_______|\n|	|	|	|	|\n|") ;
    for (; i < 16 ; i++)
    {
        if (sizeTab[i] == -1)
        {
            printf("       |") ;
        }
        if (sizeTab[i] == 0)
        {
            printf("   %d   |", c[i]) ;
        }
        if (sizeTab[i] == 1)
        {
            printf("   %d  |", c[i]) ;
        }
        if (sizeTab[i] == 2)
        {
            printf("  %d  |", c[i]) ;
        }
        if (sizeTab[i] == 3)
        {
            printf("  %d |", c[i]) ;
        }
    }
    printf("\n|_______|_______|_______|_______|") ;
}

void taille(const int *c , int *t) //Permet de trier les nombres par taille
{
    int i ;
    for (i = 0 ; i < 16 ; i++)
    {
        if (c[i] == 0)
        {
            t[i] = -1 ;
        }
        else
        {
            t[i] = log10(c[i]) ;
        }
    }
}

int commandePlateau(int *c , char dir) //Applique le choix du joueur puis ajoute 2 ou 4 dans une case aleatoire
{
    int i , test = 0 , sommePoint = 0 , verifIn = 0 , verifCombin[16] = {0} ;
    if (dir == 'Z' || dir == 'z') //Déplacement vers le haut
    {
        while (test != 1)
        {
            test++ ;
            for (i = 4 ; i < 16 ; i++) //Deplacement des lignes, sauf la 1ere
            {
                if ((c[i-4] == 0 || c[i-4] == c[i]) && c[i] != 0 && verifCombin[i] == 0 && verifCombin[i-4] == 0) //Deplacement possible
                {
                    test-- ;
                    if (c[i-4] == 0) //Si la case du dessus est vide
                    {
                        c[i-4] = c[i] ;
                        c[i] = 0 ;
                    }
                    else //La case du dessus contient le meme nombre
                    {
                        sommePoint = sommePoint + c[i-4] + c[i] ;
                        c[i-4] = c[i-4] + c[i] ;
                        c[i] = 0 ;
                        verifCombin[i-4] = 1 ;
                    }
                }
            }
            verifIn++ ;
        }
        if (verifIn == 1)
        {
            return -1 ;
        }
    }
    if (dir == 'S' || dir == 's') //Deplacement vers le bas
    {
        while (test != 1)
        {
            test++ ;
            for (i = 11 ; i >= 0 ; i--) //Deplacement des lignes, sauf la 4eme
            {
                if ((c[i+4] == 0 || c[i+4] == c[i]) && c[i] != 0 && verifCombin[i] == 0 && verifCombin[i+4] == 0) //Deplacement possible
                {
                    test-- ;
                    if (c[i+4] == 0) //La case du dessous est vide
                    {
                        c[i+4] = c[i] ;
                        c[i] = 0 ;
                    }
                    else //La case du dessous contient le meme nombre
                    {
                        sommePoint = sommePoint + c[i+4] + c[i] ;
                        c[i+4] = c[i+4] + c[i] ;
                        c[i] = 0 ;
                        verifCombin[i+4] = 1 ;
                    }
                }
            }
            verifIn++ ;
        }
        if (verifIn == 1)
        {
            return -1 ;
        }
    }
    if (dir == 'Q' || dir == 'q') //Deplacement vers la gauche
    {
        while (test != 1)
        {
            test++ ;
            for (i = 1 ; i < 4 ; i++) //Deplacement de la 1ere ligne
            {
                if ((c[i-1] == 0 || c[i-1] == c[i]) && c[i] != 0 && verifCombin[i] == 0 && verifCombin[i-1] == 0) //Deplacement possible
                {
                    test-- ;
                    if (c[i-1] == 0) //La case de gauche est vide
                    {
                        c[i-1] = c[i] ;
                        c[i] = 0 ;
                    }
                    else //La case de gauche contient le meme nombre
                    {
                        sommePoint = sommePoint + c[i-1] + c[i] ;
                        c[i-1] = c[i-1] + c[i] ;
                        c[i] = 0 ;
                        verifCombin[i-1] = 1 ;
                    }
                }
            }
            for (i = 5 ; i < 8 ; i++) //Deplacement de la 2nd ligne
            {
                if ((c[i-1] == 0 || c[i-1] == c[i]) && c[i] != 0 && verifCombin[i] == 0 && verifCombin[i-1] == 0) //Deplacement possible
                {
                    test-- ;
                    if (c[i-1] == 0) //La case de gauche est vide
                    {
                        c[i-1] = c[i] ;
                        c[i] = 0 ;
                    }
                    else //La case de gauche contient le meme nombre
                    {
                        sommePoint = sommePoint + c[i-1] + c[i] ;
                        c[i-1] = c[i-1] + c[i] ;
                        c[i] = 0 ;
                        verifCombin[i-1] = 1 ;
                    }
                }
            }
            for (i = 9 ; i < 12 ; i++) //Deplacement de la 3eme ligne
            {
                if ((c[i-1] == 0 || c[i-1] == c[i]) && c[i] != 0 && verifCombin[i] == 0 && verifCombin[i-1] == 0) //Deplacement possible
                {
                    test-- ;
                    if (c[i-1] == 0) //La case de gauche est vide
                    {
                        c[i-1] = c[i] ;
                        c[i] = 0 ;
                    }
                    else //La case de gauche contient le meme nombre
                    {
                        sommePoint = sommePoint + c[i-1] + c[i] ;
                        c[i-1] = c[i-1] + c[i] ;
                        c[i] = 0 ;
                        verifCombin[i-1] = 1 ;
                    }
                }
            }
            for (i = 13 ; i < 16 ; i++) //Deplacement de la 4eme ligne
            {
                if ((c[i-1] == 0 || c[i-1] == c[i]) && c[i] != 0 && verifCombin[i] == 0 && verifCombin[i-1] == 0) //Deplacement possible
                {
                    test-- ;
                    if (c[i-1] == 0) //La case de gauche est vide
                    {
                        c[i-1] = c[i] ;
                        c[i] = 0 ;
                    }
                    else //La case de gauche contient le meme nombre
                    {
                        sommePoint = sommePoint + c[i-1] + c[i] ;
                        c[i-1] = c[i-1] + c[i] ;
                        c[i] = 0 ;
                        verifCombin[i-1] = 1 ;
                    }
                }
            }
            verifIn++ ;
        }
        if (verifIn == 1)
        {
            return -1 ;
        }
    }
    if (dir == 'D' || dir == 'd') //Deplacement vers la droite
    {
        while (test != 1)
        {
            test++ ;
            for (i = 2 ; i >= 0 ; i--) //Deplacement 1ere ligne
            {
                if ((c[i+1] == 0 || c[i+1] == c[i]) && c[i] != 0 && verifCombin[i] == 0 && verifCombin[i+1] == 0) //Deplacement possible
                {
                    test-- ;
                    if (c[i+1] == 0) //La case de droite est vide
                    {
                        c[i+1] = c[i] ;
                        c[i] = 0 ;
                    }
                    else //La case de droite contient le meme nombre
                    {
                        sommePoint = sommePoint + c[i+1] + c[i] ;
                        c[i+1] = c[i+1] + c[i] ;
                        c[i] = 0 ;
                        verifCombin[i+1] = 1 ;
                    }
                }
            }
            for (i = 6 ; i >= 4 ; i--) //Deplacement 2ere ligne
            {
                if ((c[i+1] == 0 || c[i+1] == c[i]) && c[i] != 0 && verifCombin[i] == 0 && verifCombin[i+1] == 0) //Deplacement possible
                {
                    test-- ;
                    if (c[i+1] == 0) //La case de droite est vide
                    {
                        c[i+1] = c[i] ;
                        c[i] = 0 ;
                    }
                    else //La case de droite contient le meme nombre
                    {
                        sommePoint = sommePoint + c[i+1] + c[i] ;
                        c[i+1] = c[i+1] + c[i] ;
                        c[i] = 0 ;
                        verifCombin[i+1] = 1 ;
                    }
                }
            }
            for (i = 10 ; i >= 8 ; i--) //Deplacement 3ere ligne
            {
                if ((c[i+1] == 0 || c[i+1] == c[i]) && c[i] != 0 && verifCombin[i] == 0 && verifCombin[i+1] == 0) //Deplacement possible
                {
                    test-- ;
                    if (c[i+1] == 0) //La case de droite est vide
                    {
                        c[i+1] = c[i] ;
                        c[i] = 0 ;
                    }
                    else //La case de droite contient le meme nombre
                    {
                        sommePoint = sommePoint + c[i+1] + c[i] ;
                        c[i+1] = c[i+1] + c[i] ;
                        c[i] = 0 ;
                        verifCombin[i+1] = 1 ;
                    }
                }
            }
            for (i = 14 ; i >= 12 ; i--) //Deplacement 4ere ligne
            {
                if ((c[i+1] == 0 || c[i+1] == c[i]) && c[i] != 0 && verifCombin[i] == 0 && verifCombin[i+1] == 0) //Deplacement possible
                {
                    test-- ;
                    if (c[i+1] == 0) //La case de droite est vide
                    {
                        c[i+1] = c[i] ;
                        c[i] = 0 ;
                    }
                    else //La case de droite contient le meme nombre
                    {
                        sommePoint = sommePoint + c[i+1] + c[i] ;
                        c[i+1] = c[i+1] + c[i] ;
                        c[i] = 0 ;
                        verifCombin[i+1] = 1 ;
                    }
                }
            }
            verifIn++ ;
        }
        if (verifIn == 1)
        {
            return -1 ;
        }
    }
    int cAlea ; //Un case aleatoire doit prendre la valeur 2 ou 4
    cAlea = rand() % 16 ;
    while (c[cAlea] != 0)
    {
        cAlea = rand() % 16 ;
    }
    if (rand() % 25 == 0)
    {
        c[cAlea] = 4 ; //La nouvelle case a 4% de chance d'avoir un 4
    }
    else
    {
        c[cAlea] = 2 ;
    }
    return sommePoint ; //Renvoie les points obtenues lors du tour
}

int verifPlateau(const int *c) //Verifie si le joueur a perdu ou si il peut continuer de jouer
{
    int i , j , result = 0 ;
    for (i = 5 ; i < 7 ; i++) // Verification de l'interieur du jeu (les cases pas chiantes...(en faite si...))
    {
        if (c[i+1] == 0 || c[i-1] == 0 || c[i-4] == 0 || c[i+4] == 0 || c[i+1] == c[i] || c[i-1] == c[i] || c[i+4] == c[i] || c[i-4] == c[i])
        {
            result++ ;
        }
    }
    for (i = 9 ; i < 11 ; i++)
        {
            if (c[j+1] == 0 || c[j-1] == 0 || c[j-4] == 0 || c[j+4] == 0 || c[j+1] == c[j] || c[j-1] == c[j] || c[j+4] == c[j] || c[j-4] == c[j])
            {
                result++ ;
            }
        }
    for (i = 1 ; i < 3 ; i++) //Verification des cases centre-Haut
    {
        if (c[i-1] == 0 || c[i+1] == 0 || c[i+4] == 0 || c[i-1] == c[i] || c[i+1] == c[i] || c[i+4] == c[i])
        {
            result++ ;
        }
    }
    for (i = 13 ; i < 15 ; i++) //Verification des cases centre-Bas
    {
        if (c[i-1] == 0 || c[i+1] == 0 || c[i-4] == 0 || c[i-1] == c[i] || c[i+1] == c[i] || c[i-4] == c[i])
        {
            result++ ;
        }
    }
    for (i = 4 ; i < 12 ; i = i + 4) //Verification des cases centre-Gauche
    {
        if (c[i-4] == 0 || c[i+1] == 0 || c[i+4] == 0 || c[i-4] == c[i] || c[i+1] == c[i] || c[i+4] == c[i])
        {
            result++ ;
        }
    }
    for (i = 7 ; i < 15 ; i = i + 4) //Verification des cases centre-Haut
    {
        if (c[i-1] == 0 || c[i-4] == 0 || c[i+4] == 0 || c[i-1] == c[i] || c[i-4] == c[i] || c[i+4] == c[i])
        {
            result++ ;
        }
    }
    if (c[1] == 0 || c[4] == 0 || c[1] == c[0] || c[4] == c[0]) //Verif coin haut-gauche
    {
        result++ ;
    }
    if (c[2] == 0 || c[4] == 0 || c[2] == c[3] || c[4] == c[3]) //Verif coin haut-droite
    {
        result++ ;
    }
    if (c[13] == 0 || c[8] == 0 || c[13] == c[12] || c[8] == c[12]) //Verif coin bas-gauche
    {
        result++ ;
    }
    if (c[14] == 0 || c[11] == 0 || c[14] == c[15] || c[11] == c[15]) //Verif coin bas-droite
    {
        result++ ;
    }
    return result ;
}



//A FAIRE
//DE LA COULEUR SVP !!!
