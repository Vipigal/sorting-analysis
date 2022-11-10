#include <string>
#include <fstream>
#include <sstream>

#include "selQuicksort.hpp"


void Particao(int Esq, int Dir, int *i, int *j, Item *A, int m){
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

void Ordena(int Esq, int Dir, Item *A, int m){
  	int i, j;
	Particao(Esq, Dir, &i, &j, A, m);
	if (Esq < j) Ordena(Esq, j, A, m);
	if (i < Dir) Ordena(i, Dir, A, m);
}

void selQuickSort(Item *A, int n, int m){
	Ordena(0, n-1, A, m);
}


