#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "dados.hpp"

void Refaz(int Esq, int Dir, Item *A);
Item RetiraMax(Item *A, int n);
void Constroi(Item *A, int n);
void Heapsort(Item *A, int n);


#endif // !