#include "lista.h"

void inicializar(LISTA *l){
  l->inicio = NULL;
}

int retornar_tamanho(LISTA *l){
  PONT aux;
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
    printf("lista vazia");
    return;
  }
  PONT aux = (PONT)malloc(sizeof(Elemento));
  printf("Lista:\n");
  aux = l->inicio;
  while (aux != NULL){
    printf(" %d ", aux->r.chave);
    aux = aux->proximo;
  }
  printf("\n");
}

void inserir_inicio(LISTA *l, REGISTRO reg){
  PONT aux = (PONT)malloc(sizeof(Elemento));
  aux->r = reg;
  aux->anterior = NULL;
  if(l->inicio != NULL)
    l->inicio->anterior = aux;
  aux->proximo = l->inicio;
  l->inicio = aux;
}

void inserir_final(LISTA *l, REGISTRO reg){
  PONT aux = (PONT)malloc(sizeof(Elemento));
  PONT novo = (PONT)malloc(sizeof(Elemento));
  aux = l->inicio;
  novo->r = reg;
  while(aux->proximo != NULL)
    aux = aux->proximo;
  aux->proximo = novo;
  novo->anterior = aux;
  novo->proximo = NULL;
}

int buscar_chave(LISTA *l, TIPOCHAVE ch){
  PONT aux = (PONT)malloc(sizeof(Elemento));
  aux = l->inicio;
  while(aux->r.chave != ch){
    aux = aux->proximo;
    if(aux == NULL){
      return -1;
    }
  }
  return aux->r.chave;
}

bool remover_inicio(LISTA *l){
  PONT aux = (PONT)malloc(sizeof(Elemento));
  if(l->inicio == NULL)
    return false;
  aux = l->inicio;
  l->inicio = l->inicio->proximo;
  free(aux);
  return true;
}

bool remover_final(LISTA *l){
  if(l->inicio == NULL)
    return false;
  PONT aux = (PONT)malloc(sizeof(Elemento));
  aux = l->inicio;
  while (aux->proximo != NULL){
    aux = aux->proximo;
  }
  aux->anterior->proximo = NULL;
  free(aux);
  return true;
}

bool remover_chave(LISTA *l, TIPOCHAVE ch){
  if(l->inicio == NULL)
    return false;
  PONT aux;
  aux = l->inicio;
  while(aux != NULL){
    if(aux->r.chave == ch){
      aux->anterior->proximo = aux->proximo;
      aux->proximo->anterior = aux->anterior;
      free(aux);
      return true;
    }
    aux = aux->proximo;
  }
  return false;
}

void reinicializar_lista(LISTA *l){
  PONT atual, apagar;
  atual = l->inicio;
  while (atual != NULL){
    apagar = atual;
    atual = atual->proximo;
    free(apagar);
  }
  l->inicio = NULL;
}