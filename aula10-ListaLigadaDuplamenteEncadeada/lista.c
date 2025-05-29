#include "lista.h"

void iniciar(Lista *l){
  l->inicio = NULL;
}

int tamanho(Lista *l){
  int tamanho = 0;
  Elemento *aux = l->inicio;
  while(aux != NULL){
    tamanho++;
    aux = aux->proximo;
  }
  return tamanho;
}

void imprimir(Lista *l){
  printf("Lista\n");
  Elemento *aux = l->inicio;
  while (aux != NULL){
    printf("%d ", aux->r.chave);
    aux = aux->proximo;
  }
}

Elemento* buscar(Lista *l, Tipochave ch){
  Elemento *aux = l->inicio;
  while(aux != NULL){
    if(aux->r.chave == ch)
      return aux;
    aux = aux->proximo;
  }
  return NULL;
}

void inserir(Lista *l, Registro r){
  Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
  novo->r = r;
  novo->anterior = NULL;
  novo->proximo = NULL;

  if(l->inicio == NULL){
    l->inicio = novo;
    return;
  }

  Elemento *atual = l->inicio;
  while(atual->proximo != NULL)
    atual = atual->proximo;

  atual->proximo = novo;
  novo->anterior = atual;
}

void excluir(Lista *l, Tipochave ch){
  Elemento *atual = l->inicio;

  while(atual != NULL && atual->r.chave != ch)
    atual = atual->proximo;
  
  if(atual == NULL)
    return;

  if(atual->anterior != NULL){
    atual->anterior->proximo = atual->proximo;
  } else {
    l->inicio = atual->proximo;
  }

  if(atual->proximo != NULL){
    atual->proximo->anterior = atual->anterior;
  }

  free(atual);
}