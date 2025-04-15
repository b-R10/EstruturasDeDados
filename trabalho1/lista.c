#include "lista.h"

void inicializar(Lista *l) {
  l->inicio = (PONT)malloc(sizeof(Elemento));
  l->inicio->anterior = NULL;
  l->inicio->sucessor = NULL;
}

int retornar_tamanho(Lista *l) {
  int tamanho = 0;
  PONT aux = l->inicio;
  while (aux->sucessor != NULL) {
    tamanho++;
    aux = aux->sucessor;
  }
  return tamanho;
}

void imprimir_lista(Lista *l) {
  PONT aux = l->inicio;
  while(aux->sucessor != NULL) {
    printf(" %d ", aux->r.chave);
    aux = aux->sucessor;
  }
  printf("\n");
}

void inserir_inicio(Lista *l, Registro reg) {
  PONT novo = (PONT)malloc(sizeof(Elemento));
  novo->r = reg;
  novo->anterior = NULL;
  novo->sucessor = l->inicio;
  l->inicio->anterior = novo;
  l->inicio = novo;
}

void inserir_final(Lista *l, Registro reg) {
  
}