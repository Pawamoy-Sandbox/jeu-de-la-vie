/** \file grille.c
 * \brief gestion des grilles (code source)
 */

#include "../include/grille.h"

void alloue_grille (int l, int c, grille* g){
	g->nbl = l;
	g->nbc = c;
	g->cellules = (int**) malloc (l * sizeof(int*));
	assert(g->cellules != NULL);	
	int i,j;
	for (i=0; i<l; ++i){ 
		g->cellules[i] = (int*) malloc (c * sizeof(int));
		assert(g->cellules[i] != NULL);	
	}
	for (i=0; i<l; ++i) for (j=0; j<c; ++j) set_morte(i,j,*g);
	
	return;
}

void libere_grille (grille* g){
	int i, l = g->nbl;
	for (i=0; i<l; ++i) free(g->cellules[i]);
	free (g->cellules);
	g->nbl = 0; 
	g->nbc = 0;
	g->cellules = NULL;
	return;
}

void init_grille_from_file (char * filename, grille* g){
	FILE * pfile = NULL;
	pfile = fopen(filename, "r");
	assert (pfile != NULL);
	
	int i,j,n,l,c,vivantes=0;
	
	fscanf(pfile, "%d", & l);
	fscanf(pfile, "%d", & c);
	
	alloue_grille(l,c,g);
	
	fscanf(pfile, "%d", & vivantes);
	for (n=0; n< vivantes; ++n){
		fscanf(pfile, "%d", & i);
		fscanf(pfile, "%d", & j);
		set_vivante(i,j,*g);
	}
	
	int nonviables = 0;
	fscanf(pfile, "%d", & nonviables);
	for (n=0; n< nonviables; ++n){
		fscanf(pfile, "%d", & i);
		fscanf(pfile, "%d", & j);
		set_nonviable(i,j,*g);
	}
	
	fclose (pfile);
	return;
}

void set_ne_viellit_pas(int i, int j, grille g){} 
void set_viellit(int i, int j, grille g){ 
	g.cellules[i][j] = (g.cellules[i][j] + 1) % 9;
}

void copie_grille (grille gs, grille gd){
	int i, j;
	for (i=0; i<gs.nbl; ++i) for (j=0; j<gs.nbc; ++j) gd.cellules[i][j] = gs.cellules[i][j];
	return;	
}

int grilles_egales(grille a, grille b){
	int i,j;
	for (i=0; i<a.nbl; i++){
		for (j=0; j<a.nbc; j++){

			if (est_vivante(i,j,a) && est_vivante(i,j,b)) ;
			// du fait qu'on ne prend pas l'âge en compte
			// si une colonie oscille mais s'éteint après x pas de temps
			// à cause du vieillissement
			// on dira tout de même qu'elle est oscillante.
			// tout dépend du moment où on lance le test.
			// en fait si la période p est inférieure au temps de vie restant x
			// la colonie est considérée comme oscillante
			else if (!(est_vivante(i,j,a)) && !(est_vivante(i,j,b))) ;
			else if (!(est_viable(i,j,a)) && !(est_viable(i,j,b))) ;
			else return 0;
		}
	}
	return 1;
}
