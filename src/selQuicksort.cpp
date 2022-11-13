#include "selQuicksort.hpp"

#define Troca(A, B){Item C; C=A; A=B; B=C;}

void selectionSort (Item *v, int Esq, int Dir){
	int i, j, Min;

	for (i = Esq; i < Dir; i++){
		Min = i;
		for (j = i + 1 ; j <= Dir; j++){
			if (v[j].chave < v[Min].chave)
			Min = j;
			comparacoes++;
		}
		Troca(v[i], v[Min]);
		trocas++;
	}
}


void sParticao(int Esq, int Dir, int *i, int *j, Item *A){
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

void sOrdena(int Esq, int Dir, Item *A, int m){
  	int i, j;
	int size = Dir-Esq;
	if(size<=m){
		selectionSort(A, Esq, Dir);
		comparacoes++;
		return;
	}
	comparacoes++;

	sParticao(Esq, Dir, &i, &j, A);
	if (Esq < j) sOrdena(Esq, j, A, m);
	comparacoes++;
	if (i < Dir) sOrdena(i, Dir, A, m);
	comparacoes++;
}

void selQuickSort(Item *A, int n, int m){
	sOrdena(0, n-1, A, m);
	std::cout << "comparacoes: " <<comparacoes<< std::endl;
	std::cout << "trocas: " <<trocas<< std::endl;
	comparacoes=0;
	trocas=0;
}


