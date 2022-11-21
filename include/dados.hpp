#ifndef DADOS_H
#define DADOS_H

#include <string>
#include <iostream>

#define Troca(A, B){Item C; C=A; A=B; B=C;}

extern int comparacoes;
extern int copias;

//esse Item representa um registro de memoria
struct Item{
	//chave do registro
	int chave;
	//15 cadeias de string com 200 caracteres cada
	std::string cadeias[15];
	//10 numeros reais
	double numeros[10];

	int dir, esq;

};

//TODO: Funcoes preenche cadeia, numeros e chave
void preencheVetor(Item* v, int N, int seed);
void preencheVetorHeap(Item* v, int N, int seed);
std::string geraString(int size);
void printaCusto();

struct No{
	Item chave;
	int chaveInteira;
	No* prox;
};

class Pilha{
	public:
		Pilha();

		int getTamanho() const;
		bool vazia() const;

		void empilha(Item item);
		void empilhaInt(int n);
		Item desempilha();
		int desempilhaInt();

		void limpa();



		~Pilha();
	private:
		No* topo;
		int tamanho;
};




#endif