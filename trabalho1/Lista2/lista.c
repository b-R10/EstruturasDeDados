#include "lista.h"

void inicializar(LISTA *l){
  l->inicio = NULL;
}

int retornar_tamanho(LISTA *l){
  PONT aux = (PONT)malloc(sizeof(ELEMENTO));
  int tamanho = 0;
  if(l->inicio == NULL)
    return tamanho;
  else {
    aux = l->inicio;
    tamanho++;
    while(aux->proximo != NULL){
      tamanho++;
      aux = aux->proximo;
    }
    return tamanho;
  }
}

void imprimir_lista(LISTA *l){
  if(l->inicio == NULL){
    printf("Lista vazia\n");
    return;
  }
  printf("Lista:\n");
  PONT aux = l->inicio;
  while(aux != NULL){
    printf(" %d ", aux->r.chave);
    aux = aux->proximo;
  }
  printf("\n");
}

void inserir_chave(LISTA *l, REGISTRO reg){
  PONT novo = (PONT)malloc(sizeof(ELEMENTO));
  if(novo == NULL) {
    printf("Erro ao alocar memória.\n");
    return;
  }
  novo->r = reg;
  novo->proximo = NULL;
  novo->anterior = NULL;
  if (l->inicio == NULL) {
    l->inicio = novo;
    return;
  }
  PONT aux = l->inicio;
  if (reg.chave < aux->r.chave) {
    novo->proximo = aux;
    aux->anterior = novo;
    l->inicio = novo;
    return;
  }
  while (aux->proximo != NULL && aux->proximo->r.chave < reg.chave) {
    aux = aux->proximo;
  }
  if (aux->r.chave == reg.chave) {
    free(novo); // Avoid memory leak
    return;
  }
  novo->proximo = aux->proximo;
  novo->anterior = aux;
  if (aux->proximo != NULL) {
    aux->proximo->anterior = novo;
  }
  aux->proximo = novo;
}

int buscar_chave(LISTA *l, TIPOCHAVE ch){
  PONT aux = l->inicio;
  while(aux->r.chave < ch)
    aux = aux->proximo;
  if(aux->r.chave == ch)
    return aux->r.chave;
  else
    return -1;
}

bool remover_chave(LISTA *l, TIPOCHAVE ch) {
  if (l->inicio == NULL) {
    printf("Lista vazia. Não é possível remover.\n");
    return false;
  }
  PONT aux = l->inicio;
  while (aux != NULL && aux->r.chave != ch) {
    aux = aux->proximo;
  }
  if (aux == NULL) {
    printf("Chave %d não encontrada.\n", ch);
    return false;
  }
  if (aux->anterior != NULL) {
    aux->anterior->proximo = aux->proximo;
  } else {
    l->inicio = aux->proximo;
  }
  if (aux->proximo != NULL) {
    aux->proximo->anterior = aux->anterior;
  }
  free(aux); 
  return true;
}

void reinicializar_lista(LISTA *l) {
  PONT aux = l->inicio;
  while (aux != NULL) {
    PONT apagar = aux;
    aux = aux->proximo;
    free(apagar);
  }
  l->inicio = NULL;
}