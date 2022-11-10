#ifndef QUICKSORT_SEL
#define QUICKSORT_SEL

#include "dados.hpp"

void Particao(int Esq, int Dir, int *i, int *j, Item *A, int m);
void Ordena(int Esq, int Dir, Item *A, int m);
void selQuickSort(Item *A, int n, int m);




#endif