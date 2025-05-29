#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TipoChave;

typedef struct {
  TipoChave chave;
} Registro;

typedef struct aux {
  Registro r;
  struct aux *prox;
} Elemento;

typedef Elemento *PONT;
typedef struct {
  PONT topo;
} Pilha;

void iniciar(Pilha *p);
int tamanho(Pilha *p);
void imprimir(Pilha *p);
bool isVazia(Pilha *p);
bool push(Pilha *p, Registro r);
bool pop(Pilha *p, Registro *r);
bool teste(Pilha *p1, Pilha *p2);