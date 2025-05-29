#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 30

typedef int Tipochave;

typedef struct {
  Tipochave chave;
} Tipoitem;

typedef struct {
  Tipoitem item[MAXTAM];
  int topo;
} Pilha;

void inicializa(Pilha *p);
int vazia(Pilha p);
void push(Tipoitem x, Pilha *p);
void pop(Pilha *p, Tipoitem *item);
int tamanho(Pilha p);
void imprime(Pilha p);