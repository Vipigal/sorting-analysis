#ifndef QUICKSORT_REC
#define QUICKSORT_REC

#include "dados.hpp"

void Particao(int Esq, int Dir, int *i, int *j, Item *A);
void Ordena(int Esq, int Dir, Item *A);
/*Realiza o procedimento de quicksort padrao com recusividade: */
void recQuickSort(Item *A, int n);




#endif