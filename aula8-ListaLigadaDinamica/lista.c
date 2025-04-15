#include "lista.h"

void inicializaLista(no **L){
    *L = NULL;
}

void percorreLista(no **L){
    no *P;
    P = L;
    while(P->link != NULL)
    {
        P = P->link;
    }
}

void insereFinalLista(no **L, int valor){
    no *N;
    no *P;
    N = (no *)malloc(sizeof(no));
    N->info = valor;
    if(*L == NULL)
    {
        L = N;
    } else {
        P = L;
        while (P->link != NULL)
        {
            P = P->link;
        }
        P->link = N;
        N->link = NULL;
    }
}