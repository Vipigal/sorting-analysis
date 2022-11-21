#include "mergesort.hpp"

// Merge two subarrays L and M into arr
void merge(Item* A, int Esq, int meio, int Dir) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = meio - Esq + 1;
    int n2 = Dir - meio;

	Item* L = new Item[n1];
	Item* M = new Item [n2];

    for (int i = 0; i < n1; i++){
        L[i] = A[Esq + i];
		copias++;
	}

    for (int j = 0; j < n2; j++){
        M[j] = A[meio + 1 + j];
		copias++;
	}


    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = Esq;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i].chave <= M[j].chave) {
            A[k] = L[i];
			copias++;
            i++;
        } else {
            A[k] = M[j];
			copias++;
            j++;
        }comparacoes++;
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        A[k] = L[i];
		copias++;
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = M[j];
		copias++;
        j++;
        k++;
    }
	delete[] L;
	delete[] M;
}

void mergeSort(Item *A, int Esq, int Dir){
	if (Esq >= Dir){
		return;
	}
	int meio = (Esq + Dir) / 2;
	mergeSort(A, Esq, meio);
	mergeSort(A, meio + 1, Dir);
	merge(A,Esq, meio, Dir);
}