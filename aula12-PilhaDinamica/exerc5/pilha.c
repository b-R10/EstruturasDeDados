#include "pilha.h"

void iniciar(Pilha *p){
  p->topo = NULL;
}

int tamanho(Pilha *p){
  PONT var = p->topo;
  int tam = 0;
  while(var != NULL){
    tam++;
    var = var->prox;
  }
  return tam;
}

bool isVazia(Pilha *p){
  if(p->topo == NULL)
    return true;
  return false;
}

void imprimir(Pilha *p){
  PONT var = p->topo;
  printf("\n************Pilha*************\n");
  while(var != NULL){
    printf("\t %d \n", var->r.chave);
    var = var->prox;
  }
}

bool push(Pilha *p, Registro r){
  PONT novaPilha = (PONT)malloc(sizeof(Elemento));
  novaPilha->r = r;
  novaPilha->prox = p->topo;
  p->topo = novaPilha;
  return true;
}

bool pop(Pilha *p, Registro *r){
  if(p->topo == NULL)
    return false;
  *r = p->topo->r;
  PONT limpar = p->topo;
  p->topo = p->topo->prox;
  free(limpar);
  return true;
}
