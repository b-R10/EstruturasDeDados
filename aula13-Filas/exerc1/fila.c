#include "fila.h"

void iniciar(Fila *f){
  f->ini = 0;
  f->fim = 0;
  f->cont = 0;
}

bool isVazia(Fila *f){
  return (f->cont == 0);
}

bool isCheia(Fila *f){
  return (f->cont == maxsize);
}

int inserir(Fila *f, int x){
  if(isCheia(f))
    return -1;
  else {
    f->item[f->fim] = x;
    f->cont++;
    if(f->fim == maxsize-1)
      f->fim = 0;
    else
      f->fim++;
    return(f->fim);
  }
}

int remover(Fila *f){
  if(isVazia(f))
    return -1;
  else {
    int aux = f->item[f->ini];
    if(f->ini != maxsize-1)
      f->ini++;
    else
      f->ini = 0;
    f->cont--;
    return aux;
  }
}

void imprimir(Fila f){
  printf("\tFila:");
  for(int i=0; i<f.cont; ++i){
    printf(" %d ", f.item[i]);
  }
  printf("\n");
}