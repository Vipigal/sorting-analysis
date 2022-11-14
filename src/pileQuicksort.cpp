#include "pileQuicksort.hpp"
#include "recQuicksort.hpp"


void pileQuickSort(Item* A, int n){

	Pilha* pilha = new Pilha();
	Item item; // campos esq e dir
	int esq, dir, i, j;

	esq = 0;
	dir = n-1;
	item.dir = dir;
	item.esq = esq;
	pilha->empilha(item);
	do{
		if (dir > esq) {
			Particao(esq,dir,&i, &j, A);
			if ((j-esq)>(dir-i)) {
				item.dir = j;
				item.esq = esq;
				pilha->empilha(item);
				esq = i;
			}
			else {
				item.esq = i;
				item.dir = dir;
				pilha->empilha(item);
				dir = j;
			}
		}
		else {
			item=pilha->desempilha();
			dir = item.dir;
			esq = item.esq;
		}
 	} while (!pilha->vazia());

	printaCusto();
}