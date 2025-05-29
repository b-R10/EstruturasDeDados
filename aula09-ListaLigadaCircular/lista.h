#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TipoChave;

typedef struct {
  TipoChave chave;
} Registro;

typedef struct AuxElemento {
  Registro r;
  struct AuxElemento *proximo;
} Elemento;

typedef Elemento *PONT;
typedef struct {
  PONT no;
} Lista;

void iniciarLista(Lista *l);
int tamanho(Lista *l);
void imprimirLista(Lista *l);
PONT busca(Lista *l, TipoChave ch);
PONT buscaOrdenada(Lista *l, TipoChave ch);
PONT buscaSequencialAux(Lista *l, TipoChave ch, PONT *anterior);
bool inserirElemento(Lista *l, Registro r);
bool excluirElemento(Lista *l, TipoChave ch);
void reiniciarLista(Lista *l);