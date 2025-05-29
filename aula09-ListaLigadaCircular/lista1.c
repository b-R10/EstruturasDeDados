#include "lista1.h"

void inicializar(Lista *l){
  l->No = (PONT)malloc(sizeof(Elemento));
  l->No->proximo = l->No;
}

int tamanho(Lista *l){
  PONT aux = l->No->proximo;
  int tam = 0;
  while(aux != l->No){
    tam++;
    aux = aux->proximo;
  }
  return tam;
}

void imprimir(Lista *l){
  PONT aux = l->No->proximo;
  while(aux != l->No){
    printf(" %d ", aux->r.chave);
    aux = aux->proximo;
  }
  printf("\n\n");
}

PONT busca(Lista *l, TIPOCHAVE ch){
  PONT posicao = l->No->proximo;
  l->No->r.chave = ch;
  while(posicao->r.chave != ch)
    posicao = posicao->proximo;
  if(posicao != l->No)
    return posicao;
  return NULL;
}

PONT busca_seq_aux(Lista *l, TIPOCHAVE ch, PONT *anterior){
  *anterior = l->No;
  PONT atual = l->No->proximo;
  l->No->r.chave = ch;
  while(atual->r.chave < ch){
    *anterior = atual;
    atual = atual->proximo;
  }
  if((atual != l->No) && (atual->r.chave == ch))
    return atual;
  return NULL;
}

bool inserir(Lista *l, REGISTRO r){
  PONT anterior, i;
  i = busca_seq_aux(l, r.chave, &anterior);
  if(i != NULL)
    return false;
  i = (PONT)malloc(sizeof(Elemento));
  i->r = r;
  i->proximo = anterior->proximo;
  anterior->proximo = i;
  return true;
}

bool excluir(Lista *l, TIPOCHAVE ch){
  PONT anterior, i;
  i = busca_seq_aux(l, ch, &anterior);
  if(i == NULL)
    return false;
  anterior->proximo = i->proximo;
  free(i);
  return true;
}

void reiniciar(Lista *l){
  PONT aux = l->No->proximo;
  while(aux != l->No){
    PONT limpar = aux;
    aux = aux->proximo;
    free(limpar);
  }
  l->No->proximo = l->No;
}