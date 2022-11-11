#include "pileQuicksort.hpp"


void QuickSortNaoRec(Item* A, int n)
{
	TipoPilha pilha;
	Item item; // campos esq e dir
	int esq, dir, i, j;
	FPVazia(&pilha);
	esq = 0;
	dir = n-1;
	item.dir = dir;
	item.esq = esq;
	Empilha(item, &pilha);
	do{
		if (dir > esq) {
			Particao(A,esq,dir,&i, &j);
			if ((j-esq)>(dir-i)) {
				item.dir = j;
				item.esq = esq;
				Empilha(item, &pilha);
				esq = i;
			}
			else {
				item.esq = i;
				item.dir = dir;
				Empilha(item, &pilha);
				dir = j;
			}
		}
		else {
			Desempilha(&pilha,&item);
			dir = item.dir;
			esq = item.esq;
		}
 	} while (!Vazia(pilha));
}