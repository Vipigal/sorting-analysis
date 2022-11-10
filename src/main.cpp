#include <iostream>
#include "recQuicksort.hpp"
#include "medQuicksort.hpp"
#include "selQuicksort.hpp"
#include "msgassert.h"
#include "dados.hpp"


void printItemKey(Item* v, int n){
	for(int i=0;i<n;i++){
		std::cout<<v[i].chave<<std::endl;
	}
}


int main(int argc, const char** argv) {
	/*
		CODIGO PARA SALVAR FLAGS DE COMANDO:
	*/
	int versaoQs=0;
	int seed=0;
	std::string nomeArquivoEntrada="";
	std::string nomeArquivoSaida="";
	int numeroMedianas=0;
	int numeroParticoes=0;
	for(int i=1;i<argc;i++){
		std::string buffer=argv[i];
		if(buffer.compare("-v")==0&&i+1<=argc){
			versaoQs=atoi(argv[i+1]);
		}
		else if(buffer.compare("-s")==0&&i+1<=argc){
			seed=atoi(argv[i+1]);
		}
		else if(buffer.compare("-i")==0&&i+1<=argc){
			nomeArquivoEntrada=argv[i+1];
		}
		else if(buffer.compare("-o")==0&&i+1<=argc){
			nomeArquivoSaida=argv[i+1];
		}
		else if(buffer.compare("-k")==0&&i+1<=argc){
			numeroMedianas=atoi(argv[i+1]);
		}
		else if(buffer.compare("-m")==0&&i+1<=argc){
			numeroParticoes=atoi(argv[i+1]);
		}
	}
	//TODO: TESTAR SE AS FLAGS SAO VALIDAS:
	//erroAssert()
	//awdawd

	int N = 15;
	Item* registros = new Item[N];
	preencheVetor(registros, N);
	printItemKey(registros, N);
	std::cout << std::endl;
	medQuickSort(registros, N, 5);
	printItemKey(registros, N);



	return 0;
}