#ifndef QUICKSORT_PILHA
#define QUICKSORT_PILHA

#include "dados.hpp"

struct No{
	Item chave;
	No* prox;
};

class Pilha{
	public:
		Pilha();

		int getTamanho() const;
		bool vazia() const;

		void empilha(Item item);
		Item desempilha();

		void limpa();



		~Pilha();
	private:
		No* topo;
		int tamanho;
};

void pileQuickSort(Item* A, int n);

#endif