#include <iostream>
#include "mergesort.hpp"



void printItemKey(Item* v, int n){
	for(int i=0;i<n;i++){
		std::cout<<v[i].chave<<std::endl;
	}
}



int main(int argc, char const *argv[]){

	Item v[10];
	for(int i=0;i<10;i++){
		v[i].chave=rand()%10;
	}


	printItemKey(v,10);
	mergeSort(v,0,9);
	std::cout << std::endl;
	printItemKey(v,10);


	return 0;
}
