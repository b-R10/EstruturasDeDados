#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10

typedef char TipoChave;

typedef struct {
  TipoChave vetor[max];
  int topo;
} Pilha;

void inicializa(Pilha *p);
int tamanho(Pilha p);
bool isVazia(Pilha p);
TipoChave topo(Pilha p);
bool PUSH(Pilha *p, TipoChave chave);
TipoChave POP(Pilha *p);
void imprime(Pilha p);