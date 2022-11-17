#include "dados.hpp"
#include <random>


std::string geraString(int size){
    const std::string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

    for (int i = 0; i < size; ++i){
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

void preencheVetor(Item* v, int N, int seed){
	srand(seed);
	for(int i=0;i<N;i++){
		v[i].chave=rand()%N;
		for(int j=0;j<15;j++){
			v[i].cadeias[j]=geraString(200);
		}
		for(int j=0;j<10;j++){
			v[i].numeros[j]=rand();
		}

	}
}

void preencheVetorHeap(Item* v, int N, int seed){
	srand(seed);
	Item x;
	x.chave=-1; //Item vazio.
	v[0]=x;
	for(int i=1;i<N;i++){
		v[i].chave=rand()%N;
		for(int j=0;j<15;j++){
			v[i].cadeias[j]=geraString(200);
		}
		for(int j=0;j<10;j++){
			v[i].numeros[j]=rand();
		}

	}
}

void printaCusto(){
	std::cout << "comparacoes: " <<comparacoes<< std::endl;
	std::cout << "copias: " <<copias<< std::endl;
	comparacoes=0;
	copias=0;
}

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

void Pilha::empilhaInt(int n){
	No *nova;
	nova = new No();
	nova->chaveInteira = n;
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

int Pilha::desempilhaInt(){
	int aux; No *p;
	if(tamanho == 0)
		throw "A pilha está vazia!";
	aux = topo->chaveInteira;
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

