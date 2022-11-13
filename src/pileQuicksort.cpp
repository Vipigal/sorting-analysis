#include "pileQuicksort.hpp"
#include "recQuicksort.hpp"

Pilha::Pilha(){
	tamanho=0;
	topo=nullptr;
}

int Pilha::getTamanho() const {
	return tamanho;
}
bool Pilha::vazia() const{
	return !tamanho;
}

void Pilha::empilha(Item item){
	No *nova;
	nova = new No();
	nova->chave = item;
	nova->prox = topo;
	topo = nova;
	tamanho++;
}
Item Pilha::desempilha(){
	Item aux; No *p;
	if(tamanho == 0)
		throw "A pilha está vazia!";
	aux = topo->chave;
	p = topo;
	topo = topo->prox;
	delete p;
	tamanho--;
	return aux;
}

void Pilha::limpa(){
	while(!vazia())
		desempilha();
}

Pilha::~Pilha(){
	limpa();
}



void pileQuickSort(Item* A, int n)
{
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
			pilha->desempilha();
			dir = item.dir;
			esq = item.esq;
		}
 	} while (!pilha->vazia());
}