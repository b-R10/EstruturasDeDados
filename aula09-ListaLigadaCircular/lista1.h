#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct Aux_Elemento {
  REGISTRO r;
  struct Aux_Elemento *proximo;
} Elemento;

typedef Elemento *PONT;
typedef struct {
  PONT No;
} Lista;

void inicializar(Lista *l);
int tamanho(Lista *l);
void imprimir(Lista *l);
PONT busca(Lista *l, TIPOCHAVE ch);
PONT busca_seq_aux(Lista *l, TIPOCHAVE ch, PONT *anterior);
bool inserir(Lista *l, REGISTRO r);
bool excluir(Lista *l, TIPOCHAVE ch);
void reiniciar(Lista *l);