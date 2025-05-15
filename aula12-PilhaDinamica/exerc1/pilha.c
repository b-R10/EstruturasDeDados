#include "pilha.h"

void iniciar(Pilha *p){
  p->topo = NULL;
}

bool isVazia(Pilha *p){
  return (p->topo == NULL);
}

void imprimir(Pilha *p){
  PONT var = p->topo;
  printf("\n************Pilha*************\n");
  while(var != NULL){
    printf("%d ", var->r.chave);
    var = var->prox;
  }
  printf("\n");
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
  PONT limpar = (PONT)malloc(sizeof(Elemento));
  limpar = p->topo;
  p->topo = p->topo->prox;
  free(limpar);
  return true;
}