
/*
ALGORITHME : CHIFFRES ROMAIN
//BUT : Ecrire un algorithme qui demande à l'utilisateur quel type de conversion il veut et qui lui renvoit le chiffre romain d'un nombre
//souhaité ou l'inverse un nombre tiré d'un chiffre romain.
//ENTREE : Un entier ou chiffre romain
//SORTIE : L'entier traduit en chiffre romain ou le chiffre romain traduit en entier

TAILLEMAX = 4 : ENTIER


PROCEDURE init_nbre (var nNbre);
//BUT : demander à l'utilisateur d'entrer un nombre et l'enregistrer dans un tableau
//ENTREE : un entier
//SORTIE : Contact utilisateur
var
    nI : ENTIER

DEBUT
    ECRIRE "Veuillez entrer un entier positif compris entre 1 et 3999."
    TANT QUE ((nNbre < 1) OU (nNbre >3999))
        LIRE nNbre
    FINTANTQUE
    //On redemande à l'utilisateur tant qu'il ne rentre pas un entier positif supérieur à 0
FINPROCEDURE

PROCEDURE traduction_romain(nNbre : ENTIER ; var cResultat : CHAR);
//BUT : Définir les chiffres romain
//ENTREE :
//SORTIE :

var
    nI, nM, nC, nD, nU :ENTIER
    nTab : Tableau[0..3] d'ENTIER

DEBUT
    nTab[0] <- nNbre
    SI (nNbre >= 1000) ALORS
        nM <- 0
        nC <- 1
        nD <- 2
        nU <- 3
    SINON SI ((nNbre >=100) ET (nNbre < 1000)) ALORS
        nC <- 0
        nD <- 1
        nU <- 2
    SINON SI ((nNbre >= 10) ET (nNbre < 100) ALORS
        nD <- 0
        nU <- 1
    SINON
        nU <- 0
    FINSI
    SI (nNbre >= 1000) ALORS
        SI (nNbre DIV 1000 <> 0) ALORS
            POUR nI DE 1 A nNbre DIV 1000 FAIRE
                cResultat <- cResultat + "M"
            FINPOUR
        FINSI
    FINSI
    SI (nNbre >= 100) ALORS
        SI (nNbre MOD 1000 <= 100) ALORS
            cResultat <- cResultat + "CM"
        FINSI
        SI ((nTab[nC] >= 5) ET (nTab[nC] < 9)) ALORS
            cResultat <- cResultat + "D"
        SINON SI (nTab[nC] = 4) ALORS
            cResultat <- cResultat + "CD"
        SINON SI ((nTab[nC] <4) ET (nTab[nC] > 0) ALORS
            POUR nI DE 1 A nTab[nC] FAIRE
                cResultat <- cResultat + "C"
            FINPOUR
        SINON SI ((nTab[nC] > 5) ET (nTab[nC]< 9)) ALORS
            POUR nI DE 1 A nTab[nC]-5 FAIRE
                cResultat <- cResultat + "C"
            FINPOUR
        FINSI
    FINSI
    SI (nNbre >= 10) ALORS
        SI (nNbre MOD 100 <= 10) ALORS
            cResultat <- cResultat + "XC"
        FINSI
        SI ((nTab[nD] >= 5) ET (nTab[nD] < 9)) ALORS
            cResultat <- cResultat + "L"
        SINON SI (nTab[nD] = 4) ALORS
            cResultat <- cResultat + "XL"
        SINON SI ((nTab[nD] < 4) ET (nTab[nD] > 0) ALORS
            POUR nI DE 1 A nTab[nD] FAIRE
                cResultat <- cResultat + "X"
            FINPOUR
        SINON SI ((nTab[nD] > 5) ET (nTab[nD]< 9)) ALORS
            POUR nI DE 1 A nTab[nD]-5 FAIRE
                cResultat <- cResultat + "X"
            FINPOUR
        FINSI
    FINSI
    SI (nNbre >= 1) ALORS
        SI (nTab[nU] = 9) ALORS
            cResultat <- cResultat + "IX"
        FINSI
        SI ((nTab[nU] >= 5) ET (nTab[nU] < 9)) ALORS
            cResultat <- cResultat + "V"
        SINON SI (nTab[nU] = 4) ALORS
            cResultat <- cResultat + "IV"
        SINON SI ((nTab[nU] < 4) ET (nTab[nU] > 0) ALORS
            POUR nI DE 1 A nTab[nU] FAIRE
                cResultat <- cResultat + "I"
            FINPOUR
        SINON SI ((nTab[nU] > 5) ET (nTab[nU] < 9)) ALORS
            POUR nI DE 1 A nTab[nU]-5 FAIRE
                cResultat <- cResultat + "I"
            FINPOUR
        FINSI
    FINSI
FINPROCEDURE

PROCEDURE chiffre_romain
var
    nNbre : ENTIER
    cResultat : char

DEBUT
    init_nombre(nNbre)
    traduction romain(nNbre, cResultat)
FINPROCEDURE

PROCEDURE init_nbreRomain(var cNbRo : CHAINE)
//BUT : demander à l'utilisateur un chiffre romain
//ENTREE : Chiffre romain
//SORTIE :

DEBUT
    ECRIRE "Veuillez entrer un nombre en chiffre romain compris entre 1 et 3999."
    LIRE cNbRo
FINPROCEDURE

PROCEDURE traduction_arabe(cNbRo : CHAINE, var nResultat : ENTIER)
//BUT : Transformer le chiffre romain en chiffre arabe
//ENTREE :
//SORTIE :
var
    nI : ENTIER

DEBUT
    nResultat <- 0
    POUR nI DE 0 A LONGUEUR(cNbRo) FAIRE
    //On va répéter cette boucle jusqu'à la fin de la chaine de caractère
        SI (cNbRo[nI]) = "M" ALORS
            nResultat <- nResultat + 1000
            //Si "M" alors on ajoute 1000 au resultat
        SINON SI ((cNbRo[nI] = "C") ET ((cNbRo[nI+1] = "M") OU (cNbRo[nI+1] = "D"))) ALORS
            nResultat <- nResultat - 100
            //Si "C" est suivi d'un "M" ou d'un "D" on ajoute (-100)
        SINON SI (cNbRo[nI] = "D") ALORS
            nResultat <- nResultat + 500
            //Si "D" on ajoute 500
        SINON SI ((cNbRo[nI] = "C") ET ((cNbRo[nI+1] <> "M") OU (cNbRo[nI+1] <> "D"))) ALORS
            nResultat <- nResultat + 100
            //Si "C" n'est pas suivi d'un "M" ou d'un "D" on ajoute 100
        SINON SI ((cNbRo[nI] = "X") ET ((cNbRo[nI+1] = "C") OU (cNbRo[nI+1] = "L"))) ALORS
            nResultat <- nResultat - 10
            //Si "X" est suivi d'un "C" ou d'un "L" on retire 10
        SINON SI (cNbRo[nI] = "L") ALORS
            nResultat <- nResultat + 50
            //Si "L" on ajoute 50
        SINON SI ((cNbRo[nI] = "X") ET ((cNbRo[nI+1] <> "C") OU (cNbRo[nI+1] <> "L"))) ALORS
            nResultat <- nResultat + 10
            //Si "X" n'est pas suivi de "C" ou de "L" on ajoute 10
        SINON SI ((cNbRo[nI] = "I") ET ((cNbRo[nI+1] = "X") OU (cNbRo[nI+1] = "V"))) ALORS
            nResultat <- nResultat - 1
            //Si "I" est suivi de "X" ou "V" on retire 1
        SINON SI (cNbRo[nI] = "V") ALORS
            nResultat <- nResultat + 5
            //Si "V" on ajoute 5
        SINON SI ((cNbRo[nI] = "I") ET ((cNbRo[nI+1] <> "X") OU (cNbRo[nI+1] <> "V"))) ALORS
            nResultat <- nResultat + 1
            //Si "I" n'est pas suivi de "X" ou "V" on ajoute 1
        SINON
            break
        FINSI
    FINPOUR
FINPROCEDURE

PROCEDURE chiffre_arabe
var
    cNbRo : CHAINE
    nResultat : ENTIER

DEBUT
    init_nbreRomain(cNbRo)
    traduction_arabe(cNbRo, nResultat)
FINPROCEDURE

var
    choix : ENTIER

DEBUT
    ECRIRE "Veuillez choisir ce que vous voulez faire."
    ECRIRE "1 : Chiffre arabe vers romain"
    ECRIRE "2 : Chiffre romain vers arabe"
    ECRIRE "0 : Quittez"
    LIRE choix

    CAS choix PARMI
        1 : chiffre_romain
        2 : chiffre_arabe
        DEFAUT : break
    FINCASPARMI
FIN
*/
