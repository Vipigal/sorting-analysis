#include "medQuicksort.hpp"

//insertionSort
void Insercao(Item *v, int n) {
	int i,j;
	Item aux;
	for (i = 1; i < n; i++) {
		aux = v[i];
		copias++;
		j = i - 1;
		while (( j >= 0 ) && (aux.chave < v[j].chave)) {
			comparacoes++;
			v[j + 1] = v[j];
			copias++;
			j--;
		} comparacoes++;
		v[j + 1] = aux;
		copias++;
	}
}

Item calculaMediana(Item* v, int Esq, int Dir, int k){
	//escolhe os k primeiros itens para se calcular sua mediana
	//como as chaves sao aleatorias, os k primeiros itens tambem serao aleatorios, mesmo se esses em si tiverem uma ordem
	Item* aux = new Item[k];
	int size = Dir - Esq;
	if(k<size){
		
		//copia os elementos do registro para um vetor auxiliar
		for(int i=0;i<k;i++){
			aux[i].chave=v[i+Esq].chave;
			copias++;
		}
		//ordena esse vetor auxiliar e retora sua mediana
		Insercao(aux,k);
		return aux[k/2];
	}else{
		//caso o tamanho do vetor seja menor que k, pegaremos a mediana de todos os elementos do vetor
		for(int i=0;i<size;i++){
			aux[i].chave=v[i+Esq].chave;
			copias++;
		}
		Insercao(aux,size);
		return aux[size/2];
	}


}


void Particao(int Esq, int Dir, int *i, int *j, Item *A, int k){
	Item x, w;
	*i = Esq; *j = Dir;
	//pegar k primeiros itens do vetor e achar sua mediana.
	//se k>n, pegar os primeiros n itens.
	//x=mediana
	x=calculaMediana(A, Esq, Dir, k); //obtem o pivo x

	do
	{
		while (x.chave > A[*i].chave){
			comparacoes++;
			(*i)++;
		} 
		while (x.chave < A[*j].chave){
			comparacoes++;
			(*j)--;
		} 
		if (*i <= *j){
			w = A[*i]; A[*i] = A[*j]; A[*j] = w;
			(*i)++; (*j)--;
			copias+=3;
		}
	} while (*i <= *j);
}

void Ordena(int Esq, int Dir, Item *A, int k){
  	int i, j;
	Particao(Esq, Dir, &i, &j, A, k);
	if (Esq < j) Ordena(Esq, j, A, k);
	if (i < Dir) Ordena(i, Dir, A, k);
}

void medQuickSort(Item *A, int n, int k){
	Ordena(0, n-1, A, k);
}


