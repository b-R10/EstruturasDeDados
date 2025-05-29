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

bool pop(Pilha *p, Registro *r);
bool push(Pilha *p, Registro r);
void imprimir(Pilha *p);
bool isVazia(Pilha *p);
int tamanho(Pilha *p);
void iniciar(Pilha *p);
void inverter(Pilha *p);