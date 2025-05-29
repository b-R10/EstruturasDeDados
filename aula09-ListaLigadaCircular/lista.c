#include "lista.h"

void iniciarLista(Lista *l) {
  l->no = (PONT)malloc(sizeof(Elemento));
  l->no->proximo = l->no;
}

int tamanho(Lista *l) {
  PONT aux = l->no->proximo;
  int tamanho=0;
  while (aux != l->no) {
    tamanho++;
    aux = aux->proximo;
  }
  return tamanho;
}

void imprimirLista(Lista *l) {
  PONT aux = l->no->proximo;
  while(aux != l->no) {
    printf(" %d ", l->no->r.chave);
    aux = aux->proximo;
  }
}

PONT busca(Lista *l, TipoChave ch) {
  PONT posicao = l->no->proximo;
  l->no->r.chave = ch;
  while(posicao->r.chave != ch)
    posicao = posicao->proximo;
  if(posicao != l->no)
    return posicao;
  return NULL;
}

PONT buscaOrdenada(Lista *l, TipoChave ch) {
  PONT posicao = l->no->proximo;
  l->no->r.chave = ch;
  while(posicao->r.chave < ch)
    posicao = posicao->proximo;
  if((posicao != l->no) && (posicao->r.chave == ch))
    return posicao;
  return NULL;
}

PONT buscaSequencialAux(Lista *l, TipoChave ch, PONT *anterior) {
  *anterior = l->no;
  PONT atual = l->no->proximo;
  l->no->r.chave = ch;
  while(atual->r.chave < ch) {
    *anterior = atual;
    atual = atual->proximo;
  }
  if((atual != l->no) && (atual->r.chave == ch))
    return atual;
  return NULL;
}

bool inserirElemento(Lista *l, Registro r) {
  PONT anterior, i;
  i = buscaSequencialAux(l, r.chave, &anterior);
  if(i != NULL)
    return false;
  i = (PONT)malloc(sizeof(Elemento));
  i->r = r;
  i->proximo = anterior->proximo;
  anterior = i->proximo;
  return true;
}

bool excluirElemento(Lista *l, TipoChave ch) {
  PONT anterior, i;
  i = buscaSequencialAux(l, ch, &anterior);
  if(i == NULL)
    return false;
  anterior->proximo = i->proximo;
  free(i);
  return true;
}

void reiniciarLista(Lista *l) {
  PONT aux = l->no->proximo;
  while(aux != l->no) {
    PONT limpar = aux;
    aux = aux->proximo;
    free(limpar);
  }
  l->no->proximo = l->no;
}