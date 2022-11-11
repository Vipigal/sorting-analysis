#include <iostream>

#define Troca(A, B){Item C; C=A; A=B; B=C;}

struct Item{
	//chave do registro
	int chave;
	//15 cadeias de string com 200 caracteres cada
	std::string cadeias[15];
	//10 numeros reais
	double numeros[10];

};

void printItemKey(Item* v, int n){
	for(int i=0;i<n;i++){
		std::cout<<v[i].chave<<std::endl;
	}
}



void selectionSort (Item *v, int Esq, int Dir){
	int i, j, Min;
	for (i = Esq; i < Dir; i++){
		Min = i;
		for (j = i + 1 ; j <= Dir; j++){
			if (v[j].chave < v[Min].chave)
				Min = j;
		}
		Troca(v[i], v[Min]);
	}
}


int main(int argc, char const *argv[]){

	Item v[5];
	for(int i=0;i<5;i++){
		v[i].chave=rand()%10;
	}


	printItemKey(v,5);
	selectionSort(v,0,4);
	std::cout << std::endl;
	printItemKey(v,5);


	return 0;
}
