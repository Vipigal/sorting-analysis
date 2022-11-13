#include "recQuicksort.hpp"


void Particao(int Esq, int Dir, int *i, int *j, Item *A){
	Item x, w;
	*i = Esq; *j = Dir;
	x = A[(*i + *j)/2]; /* obtem o pivo x */
	do
	{
		while (x.chave > A[*i].chave) (*i)++;
		while (x.chave < A[*j].chave) (*j)--;
		if (*i <= *j){
			w = A[*i]; A[*i] = A[*j]; A[*j] = w;
			(*i)++; (*j)--;
			trocas++;
		}
		comparacoes++;
	} while (*i <= *j);
}

void Ordena(int Esq, int Dir, Item *A){
  	int i, j;
	Particao(Esq, Dir, &i, &j, A);
	if (Esq < j) Ordena(Esq, j, A);
	comparacoes++;
	if (i < Dir) Ordena(i, Dir, A);
	comparacoes++;
}

void recQuickSort(Item *A, int n){
	Ordena(0, n-1, A);
	std::cout << "comparacoes: " <<comparacoes<< std::endl;
	std::cout << "trocas: " <<trocas<< std::endl;
	comparacoes=0;
	trocas=0;
}


