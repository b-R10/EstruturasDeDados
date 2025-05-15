#include <stdio.h>
#include <stdlib.h>

#define maxtam 30

typedef int TipoChave;

typedef struct {
  TipoChave chave;
} TipoItem;

typedef struct {
  TipoItem item[maxtam];
  int topo;
} Pilha;

void inicializa(Pilha *p);

int isVazia(Pilha p);

int tamanho(Pilha p);

void imprime(Pilha p);

void PUSH(Pilha *p, TipoItem x);

void POP(Pilha *p, TipoItem *item);

void inverte(Pilha *p);