/** \file io.c
 * \brief entrees / sorties (code source)
 */

#include "io.h"

/** \brief défini dans jeu.c*/
extern int (*compte_voisins_vivants) (int, int, grille); 
/** \brief défini dans jeu.c*/
extern void (*set_continue_vie) (int, int, grille); 
/** \brief décompte du temps qui passe : variable globale statique : n'est connue que dans io.c*/
static int temps = 0; 

void affiche_trait (int c){
	int i;
	for (i=0; i<c; ++i) printf ("|---");
	printf("|\n");
	return;
}

void affiche_ligne (int c, int* ligne){
	int i;
	for (i=0; i<c; ++i) 
		if (ligne[i] == 0 ) printf ("|   ");
		else if (ligne[i] == -1) printf("| X ");
		else printf ("| %d ",ligne[i]); 
	printf("|\n");
	return;
}

void affiche_grille (grille g){
	int i, l=g.nbl, c=g.nbc;
	printf("\n");
	printf("temps t = %d\n", temps); 
	affiche_trait(c);
	for (i=0; i<l; ++i) {
		affiche_ligne(c, g.cellules[i]);
		affiche_trait(c);
	}	
	printf("\n"); 
	return;
}

void efface_grille (grille g){
	printf("\n\e[%dA",g.nbl*2 + 6); 
}

void debut_jeu(grille *g, grille *gc){
	char c = getchar(); 
	while (c != 'q') // touche 'q' pour quitter
	{ 
		switch (c) {
			case '\n' : 
			{ // touche "entree" pour évoluer
				evolue(g,gc);
				temps++; 
				efface_grille(*g);
				affiche_grille(*g);
				break;
			}
			case 'c' : 
			{ // touche "c" pour activer / desactiver le voisinage cyclique
				if (compte_voisins_vivants == compte_voisins_cyclique){
					compte_voisins_vivants = compte_voisins_non_cyclique;
					printf("voisinage non cyclique    \n");
				}
				else {
					compte_voisins_vivants = compte_voisins_cyclique;
					printf("voisinage cyclique      \n");
				}
				
				while(getchar() != '\n');
				printf("\n\e[%dA",3); 
				break;
			}
			case 'v' : 
			{ // touche "v" pour activer/desactiver le viellissement des cellules
				if (set_continue_vie == set_ne_viellit_pas){
					set_continue_vie = set_viellit;
					printf("viellissement ON     \n");
				}
				else {
					set_continue_vie = set_ne_viellit_pas;
					printf("viellissement OFF    \n");
				}
				while(getchar() != '\n');
				printf("\n\e[%dA",3); 
				break;
			}
			default : 
			{ // touche non traitée
				printf("\n\e[1A");
				break;
			}
		}
		c = getchar(); 
	}
	return;	
}
