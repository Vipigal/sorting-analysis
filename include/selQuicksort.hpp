#ifndef QUICKSORT_SEL
#define QUICKSORT_SEL

#include "dados.hpp"

void sParticao(int Esq, int Dir, int *i, int *j, Item *A, int m);
void sOrdena(int Esq, int Dir, Item *A, int m);
/*Realiza o procedimento de quicksort com a alteracao da mediana:
	recebe um parametro a mais (int m) que determina o cap de ordenacoes das particoes
*/
void selQuickSort(Item *A, int n, int m);




#endif