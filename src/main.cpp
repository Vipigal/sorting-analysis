#include <iostream>
#include "recQuicksort.hpp"
#include <math.h>

void printItem(Item* v, int n){
	for(int i=0;i<n;i++){
		std::cout<<v[i].chave<<std::endl;
	}
}


int main(int argc, const char** argv) {
	Item v[5];
	for(int i=0;i<5;i++){
		v[i].chave=rand()%6;
	}
	std::cout<<"PARTICAO NAO ORDENADA:"<<std::endl;
	printItem(v,5);
	recQuickSort(v,5);
	std::cout<<"PARTICAO ORDENADA:"<<std::endl;
	printItem(v,5);

	return 0;
}