#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct aux_Elemento {
  struct aux_Elemento *anterior;
  REGISTRO r;
  struct aux_Elemento *proximo;
} Elemento;

typedef Elemento *PONT;
typedef struct {
  PONT inicio;
} LISTA;

void inicializar(LISTA *l);
int retornar_tamanho(LISTA *l);
void imprimir_lista(LISTA *l);
void inserir_inicio(LISTA *l, REGISTRO reg);
void inserir_final(LISTA *l, REGISTRO reg);
int buscar_chave(LISTA *l, TIPOCHAVE ch);
bool remover_inicio(LISTA *l);
bool remover_final(LISTA *l);
bool remover_chave(LISTA *l, TIPOCHAVE ch);
void reinicializar_lista(LISTA *l);