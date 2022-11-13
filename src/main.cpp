#include <iostream>
#include <fstream>
#include "recQuicksort.hpp"
#include "medQuicksort.hpp"
#include "selQuicksort.hpp"
#include "pileQuicksort.hpp"
#include "msgassert.h"
#include "dados.hpp"

int comparacoes=0;
int trocas=0;


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
	//std::ifstream input(nomeArquivoEntrada);
	// erroAssert(input,"Nao foi possivel abrir o arquivo de input! Favor inserir entrada valida com a flag -i");
	// erroAssert(nomeArquivoSaida,"QDSq");
	// seed=10;
	// versaoQs=4;
	erroAssert(versaoQs>=1&&versaoQs<=5,"Por favor insira uma versao valida para teste do quicksort (1, 2, 3, 4 ou 5)");
	erroAssert(seed, "Por favor inserir seed de aleatoriedade valida com a flag -s");
	

	//erroAssert()


	int N = 20;
	Item* registros = new Item[N];
	preencheVetor(registros, N, seed);

	/* 
	descomentar para analisar vetor nao ordenado:
	printItemKey(registros, N);
	std::cout << std::endl;
	*/

	switch (versaoQs){
	case 1:
		recQuickSort(registros,N);
		break;
	case 2:
		erroAssert(numeroMedianas>0,"Ao utilizar a versao de medianas do quicksort, voce deve fornecer um numero de medianas maior que 0 com a flag -k!");
		medQuickSort(registros,N,numeroMedianas);
		break;
	case 3:
		erroAssert(numeroParticoes>0,"Ao utilizar a versao de selecao do quicksort, voce deve fornecer um numero de medianas maior que 0 com a flag -m!");
		selQuickSort(registros,N,numeroParticoes);
		break;
	case 4:
		pileQuickSort(registros, N);
		break;
	case 5:
		//TODO: QS EMPILHA INTELIGENTE
		break;	
	}
	printItemKey(registros, N);



	return 0;
}