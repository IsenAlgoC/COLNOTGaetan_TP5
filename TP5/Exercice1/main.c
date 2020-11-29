#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

int main() {
	int myTab1[10]; //cr�ation tableau de  valeurs
	initTab(myTab1, 10); //initialiser avec des valeurs �gales � 0
	afficheTab(myTab1, 10, 5); //on affiche les 5 premi�res valeurs
	int* myTab2 = NULL; 
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int)); //on alloue la m�moire pour la cr�ation du tableau

	if (myTab1 != NULL) { // on test si la m�moire est suffisante
		initTab(myTab2, TAB2SIZE);
	}
	else {
		printf("m�moire insuffisante");
		return -1;
	}

	initTab(myTab2, TAB2SIZE); //initialiser avec des valeurs �gales � 0

	for (int i = 0; i < 20; i++) { //on rempli de 1 � 20 le tableau
		*(myTab2 + i) = i + 1;
	}
	afficheTab(myTab2, TAB2SIZE, 20); //on affiche les 20 premi�res valeurs


	int tmp1= 20;
	int tmp2 = 42;
	ajoutElementDansTableau(myTab2, &tmp1, &tmp2, 42); // ajout de 42 tout en agrandissant le tableau

	free(myTab2); // on lib�re la m�moire pr�cedemment allou�
	return EXIT_SUCCESS;
}