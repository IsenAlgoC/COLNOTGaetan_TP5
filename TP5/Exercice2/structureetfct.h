#include <stdio.h>
#include <stdlib.h>

typedef struct Tableau {
	int* elt; // le tableau d’entiers
	int size; // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’éléments dans le tableau
} TABLEAU;

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	int* tmp = tab->elt;
	int taille;
	taille = tab->size + incrementValue; //augmentation de la taille
	tab->elt = (int*)realloc((tab->elt), taille * sizeof(int)); // reallocation de l'élément
	if (tab->elt == NULL) { return -1; } // test si erreur
	return taille;
}

int setElement(TABLEAU* tab, int pos, int element) {
	if ((pos < 0) || (tab == NULL)) { // test pour savoir si la valeur entrée n'entrainera pas une erreur et si tab différent de NULL
		return 0;
	}
	else {
		if (pos > tab->size) { // on règle le problème d'agrandissement en premier lieu
			if (incrementArraySize(tab, pos - tab->size) == 0) {return 0; }
			else { //puis on incrément à la position voulue en prenant chaque donnée de la structure TABLEAU 
				incrementArraySize(tab, pos - tab->size);
				for (int i = tab->size; i = pos; ++i) {
					*(tab->elt + i) = 0;
				}
				*(tab->elt + pos) = element;
				tab->size= incrementArraySize(tab, pos - tab->size);
				tab->eltsCount = tab->eltsCount + 1;
			}
		}
	}
	return pos;
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if ((tab == NULL) || (startPos < 0) || (endPos < 0)) {
		return -1;
	}
	if (startPos >= endPos) {
		for (int i = endPos; i = startPos; ++i) {
			printf("Elt n° %d vaut %d \n", i, *(tab->elt + i)); //affichage de l'element est de sa valeur 
		}
	}
	if (startPos <= endPos) {
		for(int i=startPos; i=endPos; ++i){
			printf("Elt n° %d vaut %d \n", i, *(tab->elt + i)); //affichage de l'element est de sa valeur 
		}
	}
	return 0;
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if ((tab == NULL) || (startPos < 0) || (endPos < 0)) { //on ne peut supprimer des éléments qui n'existent pas
		return -1;
	}
	//on va à reculons dans les deux cas :
	if (startPos >= endPos) {
		int tmp = startPos;
		startPos = endPos;
		endPos = tmp;
		for (int i = 1; i = (startPos - endPos); ++i) { 
			*(tab->elt + endPos + i - 1) = *(tab->elt + startPos + i);
		}
		int nouvelletaille = tab->size - (startPos - endPos);
		tab->elt = (int*)realloc((tab->elt), nouvelletaille * sizeof(int)); //réallocation de la mémoire
		return nouvelletaille;
	}
	else {
		for (int i = 1; i = (endPos - startPos); ++i) { 
			*(tab->elt + startPos + i - 1) = *(tab->elt + endPos + i); 
		}
		int nouvelletaille = tab->size - (endPos - startPos);
		tab->elt = (int*)realloc((tab->elt), nouvelletaille * sizeof(int)); //réallocation de la mémoire
		return nouvelletaille;
	}
}

int aleatoire(int min, int max) {
	int number = (int)(((double)rand() / (RAND_MAX + 1) * (max - min)) + min);
	return number;
}
