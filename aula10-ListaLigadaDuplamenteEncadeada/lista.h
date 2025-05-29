#include <stdio.h>
#include <stdlib.h>

typedef int Tipochave;
typedef struct {
  Tipochave chave;
} Registro;

typedef struct Aux_Elemento{
  struct Aux_Elemento *anterior;
  Registro r;
  struct Aux_Elemento *proximo;
} Elemento;

typedef Elemento *PONT;
typedef struct {
  PONT inicio;
} Lista;

void iniciar(Lista *l);
int tamanho(Lista *l);
void imprimir(Lista *l);
Elemento* buscar(Lista *l, Tipochave ch);
void inserir(Lista *l, Registro r);
void excluir(Lista *l, Tipochave ch);