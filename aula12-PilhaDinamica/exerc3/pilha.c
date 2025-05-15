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
  PONT limpar = p->topo;
  p->topo = p->topo->prox;
  free(limpar);
  return true;
}

void inverter_aux(Pilha *p, Pilha *aux, Registro *reg){
  for(int i=0; i<10; ++i){
    pop(p, reg);
    push(aux, *reg);
  }
}

void inverter(Pilha *p){
  Pilha *aux1 = (Pilha *)malloc(sizeof(Pilha));
  Pilha *aux2 = (Pilha *)malloc(sizeof(Pilha));
  Registro reg;
  iniciar(aux1);
  iniciar(aux2);
  inverter_aux(p, aux1, &reg);
  inverter_aux(aux1, aux2, &reg);
  inverter_aux(aux2, p, &reg);
}