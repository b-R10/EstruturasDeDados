#include "arvore_binaria.h"

No getNode() {
  No p;
  p = (No)malloc(sizeof(struct Nodo));
  return p;
}

No vazia() {
  return NULL;
}

No criaArvore(int chave) {
  No raiz;
  raiz = getNode();
  raiz->info = chave;
  raiz->esquerda = NULL;
  raiz->direita = NULL;
  raiz->pai = NULL;
  return raiz;
}

No getEsquerda(No pai) {
  if(pai->esquerda != NULL) {
    return pai->esquerda;
  } else {
    return NULL;
  }
}

No getDireita(No pai) {
  if(pai->direita != NULL) {
    return pai->direita;
  } else {
    return NULL;
  }
}

///////////////////////////////////////////////////////////////////////////

No inserir(No raiz, int chave) {
  if(raiz == NULL)
    raiz = criaArvore(chave);
  else {
    if(chave <= raiz->info) {
      raiz->esquerda = inserir(raiz->esquerda, chave);
      if(raiz->esquerda)
        raiz->esquerda->pai = raiz;
    } else {
      raiz->direita = inserir(raiz->direita, chave);
      if(raiz->direita)
        raiz->direita->pai = raiz;
    }
  } 
  return raiz;
}

No busca_chave(No raiz, int chave) {
  if(raiz == NULL || raiz->info == chave)
    return raiz;
  if(chave < raiz->info)
    return busca_chave(raiz->esquerda, chave);
  else
    return busca_chave(raiz->direita, chave);
}

No remover(No raiz, int chave) {
  if(raiz == NULL) return NULL;
  if(chave < raiz->info) {
    raiz->esquerda = remover(raiz->esquerda, chave);
    if(raiz->esquerda)
      raiz->esquerda->pai = raiz;
  } else if(chave > raiz->info) {
    raiz->direita = remover(raiz->direita, chave);
    if(raiz->direita)
      raiz->direita->pai = raiz;
  } else {
    // caso 1: no folha
    if(raiz->esquerda == NULL && raiz->direita == NULL) {
      free(raiz);
      return NULL;
    } else if(raiz->esquerda == NULL) { // caso 2: no com 1 filho 
      No temp = raiz->direita;
      temp->pai = raiz->pai;
      free(raiz);
      return temp;
    } else if(raiz->direita == NULL){
      No temp = raiz->esquerda;
      temp->pai = raiz->pai;
      free(raiz);
      return temp;
    } else { // caso 3: dois filhos
      No temp = minimo(raiz->direita);
      raiz->info = temp->info;
      raiz->direita = remover(raiz->direita, temp->info);
      if(raiz->direita)
        raiz->direita->pai = raiz;
    }
    
  }
  return raiz;
}

void preOrdem(No raiz) {
  if(raiz != NULL) {
    printf(" %d ", raiz->info);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
  }
}

void inOrdem(No raiz) {
  if(raiz != NULL) {
    inOrdem(raiz->esquerda);
    printf(" %d ", raiz->info);
    inOrdem(raiz->direita);
  }
}

void posOrdem(No raiz) {
  if(raiz != NULL) {
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf(" %d ", raiz->info);
  }
}

No predecessor(No raiz) {
  if(raiz == NULL) return NULL;
  if(raiz->esquerda != NULL)
    return maximo(raiz->esquerda);
  No p = raiz->pai;
  while(p != NULL && raiz == p->esquerda) {
    raiz = p;
    p = p->pai;
  }
  return p;
}

No sucessor(No raiz) {
  if(raiz == NULL) return NULL;
  if(raiz->direita != NULL)
    return minimo(raiz->direita);
  No p = criaArvore(0);
  p = raiz->pai;
  while(p != NULL && raiz == p->direita) {
    raiz = p;
    p = p->pai;
  }
  return p;
}

No minimo(No raiz) {
  if(raiz == NULL) return NULL;
  while(raiz->esquerda != NULL)
    raiz = raiz->esquerda;
  return raiz;
}

No maximo(No raiz) {
  if(raiz == NULL) return NULL;
  while(raiz->direita != NULL)
    raiz = raiz->direita;
  return raiz;
}

void preInPosOrdem(No arvore){
    preOrdem(arvore);
  printf("\n");
  inOrdem(arvore);
  printf("\n");
  posOrdem(arvore);
  printf("\n");
}