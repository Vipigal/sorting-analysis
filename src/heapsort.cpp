#include "heapsort.hpp"

void Refaz(int Esq, int Dir, Item *A){
	int i, j;
	Item x;
	i = Esq;
	j = i * 2;
	x = A[i];
	copias++;
	while (j <= Dir){
		if (j < Dir){
			if (A[j].chave < A[j + 1].chave)
				j++;
			comparacoes++;
		}
		if (x.chave >= A[j].chave){
			comparacoes++;
			break;
		} comparacoes++;
		A[i] = A[j];
		copias++;
		i = j;
		j = i * 2;
	}
	A[i] = x;
	copias++;
}


void Constroi(Item *A, int n){
	int Esq;
	Esq = n / 2 + 1;
	while (Esq > 1){
		Esq--;
		Refaz(Esq, n, A);
	}
}

void heapSort(Item *A, int n){
	//todo: adaptar para calcular com index 0
	int Esq, Dir;
	Item x;
	Constroi(A, n); /* constroi o heap */
	Esq = 1;
	Dir = n;
	while (Dir > 1){
		/* ordena o vetor */
		x = A[1];
		A[1] = A[Dir];
		A[Dir] = x;
		copias+=3;
		Dir--;
		Refaz(Esq, Dir, A);
	}
}