#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int TipoChave;

typedef struct {
  TipoChave chave;
} Registro;

typedef struct Aux_elemento {
  Registro r;
  struct Aux_elemento *anterior;
  struct Aux_elemento *sucessor;
} Elemento;

typedef Elemento *PONT;
typedef struct {
  PONT inicio;
} Lista;

void inicializar(Lista *l);

int retornar_tamanho(Lista *l);

void imprimir_lista(Lista *l);

void inserir_inicio(Lista *l, Registro reg);