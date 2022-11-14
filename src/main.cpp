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

void printarDesempenhoNaSaida(std::ofstream &output, int versao, int numMedianas=0, int numParticoes=0){
	switch (versao)
	{
	case 2:
		output<<"Versao "<<versao<<": "<<"k: "<<numMedianas<<" "<<"Comparacoes: "<<comparacoes<<" "<<"Copias: "<<copias<<std::endl;
		break;
	case 3:
		output<<"Versao "<<versao<<": "<<"m: "<<numParticoes<<" "<<"Comparacoes: "<<comparacoes<<" "<<"Copias: "<<copias<<std::endl;
		break;
	
	default:
		output<<"Versao "<<versao<<": "<<" "<<"Comparacoes: "<<comparacoes<<" "<<"Copias: "<<copias<<std::endl;
		break;
	}

	comparacoes=0;
	copias=0;
}

void printHeapItemKey(Item* v, int n){
	for(int i=1;i<n;i++){
		std::cout<<v[i].chave<<std::endl;
	}
}


int main(int argc, const char** argv) {
	//inicializacao de variaveis utilizadas para guardar as flags de comando:
	int versaoQs=0;
	int seed=0;
	std::string nomeArquivoEntrada="";
	std::string nomeArquivoSaida="";
	int numeroMedianas=0;
	int numeroParticoes=0;

	//For loop que le e armazena essas flags:
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

	//Asserts para testar se as flags sao validas
	std::ifstream input(nomeArquivoEntrada);
	erroAssert(input,"Nao foi possivel abrir o arquivo de input! Favor inserir entrada valida com a flag -i");
	std:: ofstream output(nomeArquivoSaida, std::ios_base::app);
	erroAssert(output,"Nao foi possivel abrir o arquivo de output! Favor inserir entrada valida com a flag -o");
	erroAssert(versaoQs>=1&&versaoQs<=6,"Por favor insira uma versao valida para teste do quicksort (1, 2, 3, 4 ou 5)");
	erroAssert(seed, "Por favor inserir seed de aleatoriedade valida com a flag -s");
	
	//Inicializa as variaveis para leitura do input
	int numeroTestes = 0;
	int tamanhoRegistro = 0;
	Item* registros;

	//Le o numero de casos de teste
	input>>numeroTestes;

	//For loop principal: Roda numeroTestes vezes e cada iteracao realiza uma ordenacao de um certo tipo com um certo numero de registros.
	for(int i=0;i<numeroTestes;i++){
		input>>tamanhoRegistro;
		if(versaoQs==6){
			//inicializa e preenche o vetor para ser ordenado pelo HeapSort, de indices [1...N]. A posicao 0 nao eh utilizada.
			int tamanhoHeap=tamanhoRegistro+1;
			registros = new Item[tamanhoHeap];
			preencheVetorHeap(registros, tamanhoHeap, seed);

		}else{
			//inicializa e preenche o vetor normalmente, de indices [0...N].
			registros = new Item[tamanhoRegistro];
			preencheVetor(registros, tamanhoRegistro, seed);
		}

		//Para cada versao diferente do quicksort, uma funcao de um modulo diferente sera chamada e sua saida sera printada no output.
		switch (versaoQs){
			case 1:
				recQuickSort(registros,tamanhoRegistro);
				printarDesempenhoNaSaida(output,versaoQs);
				break;
			case 2:
				erroAssert(numeroMedianas>0,"Ao utilizar a versao de medianas do quicksort, voce deve fornecer um numero de medianas maior que 0 com a flag -k!");
				medQuickSort(registros,tamanhoRegistro,numeroMedianas);
				printarDesempenhoNaSaida(output,versaoQs,numeroMedianas);
				break;
			case 3:
				erroAssert(numeroParticoes>0,"Ao utilizar a versao de selecao do quicksort, voce deve fornecer um numero de medianas maior que 0 com a flag -m!");
				selQuickSort(registros,tamanhoRegistro,numeroParticoes);
				printarDesempenhoNaSaida(output,versaoQs,0,numeroParticoes);
				break;
			case 4:
				pileQuickSort(registros, tamanhoRegistro);
				printarDesempenhoNaSaida(output,versaoQs);
				break;
			case 5:
				iterativeQsort(registros, tamanhoRegistro);
				printarDesempenhoNaSaida(output,versaoQs);
				break;
			case 6:
				Heapsort(registros, tamanhoRegistro);
				//heap vai de 1-N
				printHeapItemKey(registros, tamanhoRegistro+1);
				break;	
			}
		delete[] registros;

	}
	input.close();
	output.close();



	return 0;
}