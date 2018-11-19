#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define TAILLEMAX 3
#define TAILLECHIFFRE 24

void init_nbre (int *pNbre);
void traduction_romain(int *pResultat, int nNbre);
void chiffre_romain();
void traduction_arabe(char* cNbRo, int nBateau);
void chiffre_arabe ();

//BUT : Ecrire un algorithme qui demande à l'utilisateur quel type de conversion il veut et qui lui renvoit le chiffre romain d'un nombre
//souhaité ou l'inverse un nombre tiré d'un chiffre romain.
//ENTREE : Un entier ou chiffre romain
//SORTIE : L'entier traduit en chiffre romain ou le chiffre romain traduit en entier
int main()
{
    int nChoix = 0;

    printf("Veuillez choisir ce que vous voulez faire.\n1 : Chiffre arabe vers romain\n2 : Chiffre romain vers arabe\n0 : Quitter\n");
    scanf("%d", &nChoix);

    switch(nChoix){
        case 1 : chiffre_romain(); break;
        case 2 : chiffre_arabe(); break;
        default : break;
    }
    system("pause");
    return 0;
}

void init_nbre (int *pNbre){
//BUT : demander à l'utilisateur d'entrer un nombre et l'enregistrer dans un tableau
//ENTREE : un entier
//SORTIE : Contact utilisateur
    int nBateau =0;
    do{
        printf("Veuillez entrer un entier positif compris entre 1 et 3999.\n");
        scanf("%d", &nBateau);
    }while ((nBateau< 1) || (nBateau > 3999));
    *pNbre = nBateau;
    //On redemande à l'utilisateur tant qu'il ne rentre pas un entier positif supérieur à 0 et inférieur à 4000
}

void traduction_romain(int *pResultat, int nNbre){
//BUT : Définir les chiffres romain
//ENTREE :
//SORTIE :

    int nI = 0;
    char cBateau[TAILLECHIFFRE] = "";

    //On ne rentre que si le nombre entré par l'utilisateur est supérieur ou égale à 1000
    if (nNbre >= 1000){
        if (nNbre / 1000 != 0){
            for(nI=1;nI<=nNbre/1000;nI++){
                strcat(cBateau, "M");
                //On écrit "M" pour chaque division par 1000 possible
            }
        }
        nNbre = nNbre - ((nI-1) * 1000);
        //On enlève 1000 n fois le nombre de division effectuée
    }
    if (nNbre >= 100){
    //On entre que si le nombre entré est supérieur à 100
        if (nNbre >= 900){
            strcat(cBateau, "CM");
            nNbre-=900;
            //Si c'est = 900 on écrit "CM" puis on retire 900 du nombre
        }else if ((nNbre >= 500) && (nNbre < 900)){
            strcat(cBateau, "D");
            //Si c'est compris entre 500 et 899 on écrit "D"
            if ((nNbre >= 500) && (nNbre < 600))
                nNbre = nNbre - 500;
                //Si c'est compris entre 500 et 599, on retire 500 du nombre
        }else if ((nNbre >= 400) && (nNbre < 500)){
            strcat(cBateau, "CD");
            nNbre-=400;
            //Si c'est compris entre 400 et 499 on écrit "CD" et retire 400 du nombre
        }else if ((nNbre < 400) && (nNbre >= 100)){
            for (nI=1;nI<=nNbre/100;nI++){
                strcat(cBateau, "C");
                //Si c'est compris entre 100 et 400 on écrit "C" n * le nombre diviser par 100
            }
            nNbre = nNbre - ((nI-1) * 100);
            //On retire 100 du nombre n * le nombre d'itération de la boucle précédente
        }
        if ((nNbre >= 600) && (nNbre < 900)){
            for (nI=1;nI<=(nNbre/100)-5;nI++){
                strcat(cBateau, "C");
                //Si c'est compris entre 600 et 899 on ecrit "C" n * le nombre diviser par 100, le tout - 5
            }
            nNbre = (nNbre - 500) - ((nI-1) * 100);
            //Ici on retire 500 et on retire également 100 * le nombre d'itération de la boucle précédente
        }
    }
    if (nNbre >= 10){
    //Même principe que pour les centaines avec les dizaines
        if (nNbre >= 90){
            strcat(cBateau, "XC");
            nNbre-=90;
        }
        if ((nNbre >= 50) && (nNbre < 90)){
            strcat(cBateau, "L");
            if ((nNbre >= 50) && (nNbre < 60))
                nNbre = nNbre - 50;
        }else if ((nNbre >= 40) && (nNbre < 50)){
            strcat(cBateau, "XL");
            nNbre-=40;
        }else if ((nNbre < 40) && (nNbre >= 10)){
            for (nI=1;nI<=nNbre/10;nI++){
                strcat(cBateau, "X");
            }
            nNbre = nNbre - ((nI-1) * 10);
        }
        if ((nNbre >= 60) && (nNbre < 90)){
            for (nI=1;nI<=(nNbre/10)-5;nI++){
                strcat(cBateau, "X");
            }
            nNbre = (nNbre - 50) - ((nI-1) * 10);
        }
    }
    if (nNbre >= 1){
    //Même principe mais on ne retire plus rien car ce n'est pas nécessaire
        if (nNbre == 9){
            strcat(cBateau, "IX");
        }else if ((nNbre > 4) && (nNbre < 9)){
            strcat(cBateau, "V");
        }else if (nNbre == 4){
            strcat(cBateau, "IV");
        }else if ((nNbre < 4) && (nNbre > 0)){
            for (nI=1;nI<=nNbre;nI++){
                strcat(cBateau, "I");
            }
        }
        if ((nNbre > 5) && (nNbre < 9)){
            for(nI=1;nI<=nNbre-5;nI++){
                strcat(cBateau, "I");
            }
        }
    }
    puts(cBateau);
}

void chiffre_romain(){
//BUT : Afficher le chiffre romain du nombre que l'utilisateur a rentré
//ENTREE : Un entier compris entre 1 et 3999
//SORTIE : L'entier écrit en chiffre romain

    int nNbre = 0;
    int nResultat;

    init_nbre(&nNbre);
    traduction_romain(&nResultat, nNbre);
}

/*void init_nbreRomain(char *pNbRo[]){
//BUT : demander à l'utilisateur un chiffre romain
//ENTREE : Chiffre romain
//SORTIE :

    printf("Veuillez entrer un nombre en chiffre romain compris entre 1 et 3999.\n");
    scanf("%s", *pNbRo);
}*/

void traduction_arabe(char* cNbRo, int nBateau){
//BUT : Transformer le chiffre romain en chiffre arabe
//ENTREE : Chiffre romain
//SORTIE : Chiffre arabe

    int nI = 0, nJ = 0;

    printf("Veuillez entrer un nombre en chiffre romain compris entre I et MMMCMXCIX.\n");
    fflush(stdin);
    scanf("%s", &cNbRo[0]);
    for(nJ=0;nJ<=strlen(cNbRo);nJ++){
        cNbRo[nJ] = toupper(cNbRo[nJ]);
    }
    do{
    //On va répéter cette boucle jusqu'à la fin de la chaine de caractère
        if (cNbRo[nI] == 'M'){
            nBateau += 1000;
            //Si "M" alors on ajoute 1000 au resultat
        }else if ((cNbRo[nI] == 'C') && ((cNbRo[nI+1] == 'M') || (cNbRo[nI+1] == 'D')))
            nBateau -=100;
            //Si "C" est suivi d'un "M" ou d'un "D" on ajoute (-100)
        else if (cNbRo[nI] == 'D')
            nBateau += 500;
            //Si "D" on ajoute 500
        else if ((cNbRo[nI] == 'C') && ((cNbRo[nI+1] != 'M') || (cNbRo[nI+1] != 'D'))){
            nBateau += 100;
            //Si "C" n'est pas suivi d'un "M" ou d'un "D" on ajoute 100
        }else if ((cNbRo[nI] == 'X') && ((cNbRo[nI+1] == 'C') || (cNbRo[nI+1] == 'L')))
            nBateau -= 10;
            //Si "X" est suivi d'un "C" ou d'un "L" on retire 10
        else if (cNbRo[nI] == 'L')
            nBateau += 50;
            //Si "L" on ajoute 50
        else if ((cNbRo[nI] == 'X') && ((cNbRo[nI+1] != 'C') || (cNbRo[nI+1] != 'L')))
            nBateau += 10;
            //Si "X" n'est pas suivi de "C" ou de "L" on ajoute 10
        else if ((cNbRo[nI] == 'I') && ((cNbRo[nI+1] == 'X') || (cNbRo[nI+1] == 'V')))
            nBateau -= 1;
            //Si "I" est suivi de "X" ou "V" on retire 1
        else if (cNbRo[nI] == 'V')
            nBateau += 5;
            //Si "V" on ajoute 5
        else if ((cNbRo[nI] == 'I') && ((cNbRo[nI+1] != 'X') || (cNbRo[nI+1] != 'V')))
            nBateau += 1;
            //Si "I" n'est pas suivi de "X" ou "V" on ajoute 1
        else
            break;
        nI++;
    }while (cNbRo[nI] != '\0');
    printf("%d\n", nBateau);
}

void chiffre_arabe (){
//BUT : afficher le chiffre arabe traduit du chiffre romain entrer par l'utilisateur
//ENTREE : Le chiffre romain
//SORTIE : Le chiffre traduite en chiffre arabe

    char cNbRo[TAILLECHIFFRE] = "";
    int nResultat = 0;

    traduction_arabe(cNbRo, nResultat);
}
