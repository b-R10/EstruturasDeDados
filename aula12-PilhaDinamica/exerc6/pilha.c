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

int buscarCarro(Pilha *p, int placa, Registro *reg, int *pos) {
  Pilha aux;
  iniciar(&aux);
  int found = 0, idx = 0;
  Registro r;
  while (!isVazia(p)) {
    pop(p, &r);
    push(&aux, r);
    if (r.chave == placa) {
      found = 1;
      *reg = r;
      *pos = idx;
      break;
    }
    idx++;
  }
  while (!isVazia(&aux)) {
    pop(&aux, &r);
    push(p, r);
  }
  return found;
}