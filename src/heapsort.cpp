#include "heapsort.hpp"

void Refaz(int Esq, int Dir, Item *A){
	int i, j;
	Item x;
	i = Esq;
	j = i * 2;
	x = A[i];
	while (j <= Dir){
		if (j < Dir)
			if (A[j].chave < A[j + 1].chave)
				j++;
		if (x.chave >= A[j].chave)
			break;
		A[i] = A[j];
		i = j;
		j = i * 2;
	}
	A[i] = x;
}

Item RetiraMax(Item *A, int n){
	Item Maximo;
	if (n < 1)
		throw "Erro: heap vazio";
	else{
		Maximo = A[1];
		A[1] = A[n];
		n--;
		Refaz(1, n, A);
	}
	return Maximo;
}

void Constroi(Item *A, int n){
	int Esq;
	Esq = n / 2 + 1;
	while (Esq > 1){
		Esq--;
		Refaz(Esq, n, A);
	}
}

void Heapsort(Item *A, int n){
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
		Dir--;
		Refaz(Esq, Dir, A);
	}
}