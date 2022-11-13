#ifndef DADOS_H
#define DADOS_H

#include <string>
#include <iostream>

extern int comparacoes;
extern int trocas;

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
std::string geraString(int size);


#endif