#include "dumbPileQuicksort.hpp"

void swap(Item* A, int i, int j) { 
    Item temp = A[i];
    A[i] = A[j];
    A[j] = temp;
	copias+=3;
}

int partition(Item* A, int p, int start, int end) {
    int l = start;
    int h = end - 2;
    Item piv = A[p];
    swap(A,p,end-1);

    while (l < h) {
        if (A[l].chave < piv.chave) {
            l++;
			comparacoes++;
        } else if (A[h].chave >= piv.chave) { 
            h--;
			comparacoes++;
        } else { 
            swap(A,l,h);
			comparacoes++;
        }
    }
    int idx = h;
    if (A[h].chave < piv.chave) idx++;
	comparacoes++;
    swap(A,end-1,idx);
    return idx;
}

void iterativeQsort(Item* A, int n) { 
	Pilha* pilha = new Pilha();
	
	pilha->empilhaInt(0);
	pilha->empilhaInt(n);
    while (!pilha->vazia()) {
        int end = pilha->desempilhaInt();
        int start = pilha->desempilhaInt();
        if (end - start < 2) continue;
        int p = start + ((end-start)/2);
        p = partition(A,p,start,end);

		pilha->empilhaInt(p+1);
		pilha->empilhaInt(end);

		pilha->empilhaInt(start);
		pilha->empilhaInt(p);
    }
}