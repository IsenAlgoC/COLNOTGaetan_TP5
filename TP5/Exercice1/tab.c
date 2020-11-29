#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

int initTab(int* tab, int size) {
	if ((size < 0) || (&tab == NULL)) { // test si tableau vaut NULL
		return -1;
	}
	for (int i = 0; i < size; ++i) { 
		*(tab + i) = 0;
	}
	return tab;
}

int afficheTab(int* tab, int size, int nbElts) {
	if ((size < 0) || (&tab == NULL) || (size < nbElts)) { // test si tableau vaut NULL, ...
		return -1;
	}
	for (int i = 0; i < nbElts; ++i) { // on affiche jusqu'au nombre total d'éléments
		printf("%d", *(tab+i));
	}
	return 0;
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int elements) {
	int* tmp;
	tmp = realloc(tab, elements * sizeof(int));
	if (*nbElts == *size) { // test sur la correspondance entre le nombre d'éléments et la taille
		if (tab == NULL) { // test si tableau vaut NULL
			printf("Memoire insuffisante");
			return -1;
		}
		else { //on modifie le tableau grâce à un pointeur temporaire puis on ajoute le nouvelle élément à la place voulu
			*tab = *tmp;
			*size = *size + TAILLEAJOUT; //on augmente la taille
			*nbElts = *nbElts + 1;
			*(tab + *nbElts) = elements;
			}
		}
	else {
		return -1;
	}
	return *nbElts;
}