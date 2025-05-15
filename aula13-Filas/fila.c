#include "fila.h"

void iniciar(Fila *f){
  f->ini = 0;
  f->fim = 0;
  f->cont = 0;
}

int isVazia(Fila *f){
  if(f->cont == 0)
    return true;
  else
    return false;
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
    else {
      f->ini = 0;
    }
    f->cont--;
    return aux;
  }
}

bool isCheia(Fila *f){
  if(f->cont == maxsize)
    return true;
  else
    return false;
}