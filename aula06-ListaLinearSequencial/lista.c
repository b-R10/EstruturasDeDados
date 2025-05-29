#include "lista.h"

void inicializar(LISTA *l){
  l->N = 0;
}

int tamanho(LISTA l){
  return l.N;
}

void imprimir(LISTA l){
  printf("Lista linear sequencial\n");
  for (int i = 0; i < max; ++i){
    printf("\t%d\n", l.V[i].chave);
  }
}

int buscar(LISTA *l, REGISTRO r){
  int i=0;
  while (i < l->N){
    if (r.chave == l->V[i].chave)
      return i;
    else
      i++;
  }
  return -1;
}

bool inserir(LISTA *l, int pos, REGISTRO r){
  int i;
  if((l->N == max) || (pos < 0) || (pos > max))
    return false;
  for(i=l->N; i>pos; --i)
    l->V[i] = l->V[i-1];
  l->V[i] = r;
  l->N++;
  return true;
}

bool remover(LISTA *l, TIPOCHAVE ch){
  REGISTRO reg;
  reg.chave = ch;
  int pos = buscar(l, reg);
  if(pos == -1)
    return false;
  for(int i=pos; i<l->N; ++i)
    l->V[i] = l->V[i+1];
  l->N--;
  return true;
}

void reiniciar(LISTA *l){
  l->N = 0;
}