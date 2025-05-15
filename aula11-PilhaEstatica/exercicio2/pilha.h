#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10

typedef int TipoChave;

typedef struct {
  TipoChave chave;
} TipoItem;

typedef struct {
  TipoItem item[max];
  int topo;
} Pilha;

void inicializa(Pilha *p);
void reinicializa(Pilha *p);
int tamanho(Pilha p);
bool isVazia(Pilha p);
TipoChave topo(Pilha p);
bool PUSH(Pilha *p, TipoItem item);
TipoItem POP(Pilha *p);
void imprime(Pilha p);