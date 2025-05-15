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

bool pilhasIguais(Pilha *p1, Pilha *p2){
  Pilha *aux1 = (Pilha*)malloc(sizeof(Pilha));
  Pilha *aux2 = (Pilha*)malloc(sizeof(Pilha));

  iniciar(aux1);
  iniciar(aux2);

  bool iguais = true;
  Registro r1, r2;

  while(!isVazia(p1) && !isVazia(p2)){
    pop(p1, &r1);
    pop(p2, &r2);

    if(r1.chave != r2.chave)
      iguais = false;
    
    push(aux1, r1);
    push(aux2, r2);

    if(!iguais)
      break;
  }

  if(!isVazia(p1) || !isVazia(p2))
    iguais = false;

  while(!isVazia(aux1)){
    pop(aux1, &r1);
    push(p1, r1);
  }

  while(!isVazia(aux2)){
    pop(aux2, &r2);
    push(p2, r2);
  }

  return iguais;
}