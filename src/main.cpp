#include <iostream>
#include <fstream>
#include "recQuicksort.hpp"
#include "medQuicksort.hpp"
#include "selQuicksort.hpp"
#include "pileQuicksort.hpp"
#include "dumbPileQuicksort.hpp"
#include "heapsort.hpp"
#include "msgassert.h"
#include "dados.hpp"


//VARIAVEIS GLOBAIS:
int comparacoes=0;
int copias=0;


void printItemKey(Item* v, int n){
	for(int i=0;i<n;i++){
		std::cout<<v[i].chave<<std::endl;
	}
}

void printarDesempenhoNaSaida(std::ofstream &output, int versao){
	output<<"Versao "<<versao<<": "<<" "<<"Comparacoes: "<<comparacoes<<" "<<"Copias: "<<copias<<std::endl;
	comparacoes=0;
	copias=0;
}

void printHeapItemKey(Item* v, int n){
	for(int i=1;i<n;i++){
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
	std::ifstream input(nomeArquivoEntrada);
	erroAssert(input,"Nao foi possivel abrir o arquivo de input! Favor inserir entrada valida com a flag -i");
	std:: ofstream output(nomeArquivoSaida);
	erroAssert(output,"Nao foi possivel abrir o arquivo de output! Favor inserir entrada valida com a flag -o");
	erroAssert(versaoQs>=1&&versaoQs<=6,"Por favor insira uma versao valida para teste do quicksort (1, 2, 3, 4 ou 5)");
	erroAssert(seed, "Por favor inserir seed de aleatoriedade valida com a flag -s");
	

	//erroAssert()
	int numeroTestes = 0;
	int tamanhoRegistro = 0;
	Item* registros;
	input>>numeroTestes;
	for(int i=0;i<numeroTestes;i++){
		input>>tamanhoRegistro;
		if(versaoQs==6){
			//inicializa o vetor para ser ordenado por quicksort, como vai de 1-N, a posicao 0 nao eh utilizada
			int tamanhoHeap=tamanhoRegistro+1;
			registros = new Item[tamanhoHeap];
			preencheVetorHeap(registros, tamanhoHeap, seed);

		}else{
			registros = new Item[tamanhoRegistro];
			preencheVetor(registros, tamanhoRegistro, seed);
		}
		switch (versaoQs){
			case 1:
				recQuickSort(registros,tamanhoRegistro);
				// printItemKey(registros, tamanhoRegistro);
				printarDesempenhoNaSaida(output,versaoQs);
				break;
			case 2:
				erroAssert(numeroMedianas>0,"Ao utilizar a versao de medianas do quicksort, voce deve fornecer um numero de medianas maior que 0 com a flag -k!");
				medQuickSort(registros,tamanhoRegistro,numeroMedianas);
				printItemKey(registros, tamanhoRegistro);
				break;
			case 3:
				erroAssert(numeroParticoes>0,"Ao utilizar a versao de selecao do quicksort, voce deve fornecer um numero de medianas maior que 0 com a flag -m!");
				selQuickSort(registros,tamanhoRegistro,numeroParticoes);
				printItemKey(registros, tamanhoRegistro);
				break;
			case 4:
				pileQuickSort(registros, tamanhoRegistro);
				printItemKey(registros, tamanhoRegistro);
				break;
			case 5:
				iterativeQsort(registros, tamanhoRegistro);
				printItemKey(registros, tamanhoRegistro);
				break;
			case 6:
				Heapsort(registros, tamanhoRegistro);
				//heap vai de 1-N
				printHeapItemKey(registros, tamanhoRegistro+1);
				break;	
			}
		delete[] registros;

	}

	/* 
	descomentar para analisar vetor nao ordenado:
	printItemKey(registros, N);
	std::cout << std::endl;
	*/

	



	return 0;
}