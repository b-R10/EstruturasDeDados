#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct aux_elemento {
  struct aux_elemento *anterior;
  REGISTRO r;
  struct aux_elemento *proximo;
} ELEMENTO;

typedef ELEMENTO* PONT;
typedef struct {
  PONT inicio;
} LISTA;

void inicializar(LISTA *l);
int retornar_tamanho(LISTA *l);
void imprimir_lista(LISTA *l);
void inserir_chave(LISTA *l, REGISTRO reg);
int buscar_chave(LISTA *l, TIPOCHAVE ch);
bool remover_chave(LISTA *l, TIPOCHAVE ch);
void reinicializar_lista(LISTA *l);