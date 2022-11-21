#ifndef QUICKSORT_MED
#define QUICKSORT_MED

#include "dados.hpp"

void Particao(int Esq, int Dir, int *i, int *j, Item *A, int k);
void Ordena(int Esq, int Dir, Item *A, int k);
/*Realiza o procedimento de quicksort com a alteracao da mediana:
	recebe um parametro a mais (int k) que determina o numero de elementos usado para o calculo da mediana (3,5,7,...)
*/
void medQuickSort(Item *A, int n, int k);




#endif