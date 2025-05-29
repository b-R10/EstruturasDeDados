#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 30

typedef int Tipochave;

typedef struct {
  Tipochave chave;
} TipoItem;

typedef struct {
  TipoItem item[MAXTAM];
  int topo;
} Pilha;

void inicializa(Pilha *p);
int vazia(Pilha p);
void push(TipoItem x, Pilha *p);
void pop(Pilha *p, TipoItem *item);
int tamanho(Pilha p);
void imprime(Pilha p);
int verificar(char *expressao);