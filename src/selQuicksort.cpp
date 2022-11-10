#include "selQuicksort.hpp"


void sParticao(int Esq, int Dir, int *i, int *j, Item *A, int m){
	Item x, w;
	*i = Esq; *j = Dir;

	// x = A[(*i + *j)/2]; /* obtem o pivo x */
	// do
	// {
	// 	while (x.chave > A[*i].chave) (*i)++;
	// 	while (x.chave < A[*j].chave) (*j)--;
	// 	if (*i <= *j){
	// 		w = A[*i]; A[*i] = A[*j]; A[*j] = w;
	// 		(*i)++; (*j)--;
	// 	}
	// } while (*i <= *j);
}

void sOrdena(int Esq, int Dir, Item *A, int m){
  	int i, j;
	sParticao(Esq, Dir, &i, &j, A, m);
	if (Esq < j) sOrdena(Esq, j, A, m);
	if (i < Dir) sOrdena(i, Dir, A, m);
}

void selQuickSort(Item *A, int n, int m){
	sOrdena(0, n-1, A, m);
}


