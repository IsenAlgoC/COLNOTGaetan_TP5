#define TAILLEINITIALE 100
#include "structureetfct.h"


TABLEAU newArray() {
	TABLEAU* tab;
	tab = malloc(sizeof(TABLEAU));
	if (tab== NULL) { // on v�rifie si l'allocation est possible
		(tab->elt) = malloc(TAILLEINITIALE * sizeof(int));
		tab->size = TAILLEINITIALE;
		tab->eltsCount = 0;
	}
	return *tab; //on retourne le tableau
}


int main(){
	TABLEAU tab1 = newArray();
	tab1.size = 20; 
	for (int i = 0; i = 42; ++i) {
		*tab1.elt = aleatoire(1, 30); //probl�me de pointeur "Exception lev�e�: violation d'acc�s en �criture."
	}
	/*setElement(*tab1, 13, 42);
	displayElements(*tab1, 1, 20);
	deleteElements(*tab1, 12, 14);
	displayElements(*tab1, 1, 20);*/
	return EXIT_SUCCESS;
}
