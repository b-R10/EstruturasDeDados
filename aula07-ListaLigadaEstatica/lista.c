#include "lista.h"

void inicializar(LISTA *l){
  int i;
  for(i=0; i<max-1; ++i)
    l->v[i].proximo = i+1;
  l->v[max-1].proximo = inv;
  l->inicio = inv;
  l->disponivel = 0;
}

int tamanho(LISTA *l){
  int i=l->inicio;
  int tamanho = 0;
  while (i != inv){
    tamanho++;
    i = l->v[i].proximo;
  }
  return tamanho;
}

void imprimir(LISTA *l){
  int i = l->inicio;
  printf("\tLista\n");
  while(i != inv){
    printf(" %d ", l->v[i].r.chave);
    i = l->v[i].proximo;
  }
  printf("\n");
}

int buscar_sequencial_ordenada(LISTA *l, TIPOCHAVE ch){
  int i = l->inicio;
  while(i != inv && l->v[i].r.chave < ch)
    i = l->v[i].proximo;
  if(i != inv && l->v[i].r.chave == ch)
    return i;
  else
    return inv;
}

bool inserir_ordenado(LISTA *l, REGISTRO r){
  if(l->disponivel == inv)
    return false;
  int anterior = inv;
  int i = l->inicio;
  TIPOCHAVE ch = r.chave;
  while(i != inv && l->v[i].r.chave < ch){
    anterior = i;
    i = l->v[i].proximo;
  }
  if(i != inv && l->v[i].r.chave == ch)
    return false;
  i = obtencao_NO(l);
  l->v[i].r = r;
  if(anterior == inv){
    l->v[i].proximo = l->inicio;
    l->inicio = i;
  } else {
    l->v[i].proximo = l->v[anterior].proximo;
    l->v[anterior].proximo = i;
  }
  return true;
}

int obtencao_NO(LISTA *l){
  int resultado = l->disponivel;
  if(l->disponivel != inv)
    l->disponivel = l->v[l->disponivel].proximo;
  return resultado;
}

bool excluir(LISTA *l, TIPOCHAVE ch){
  int anterior = inv;
  int i = l->inicio;
  while(i!=inv && l->v[i].r.chave<ch){
    anterior = i;
    i = l->v[i].proximo;
  }
  if(i==inv || l->v[i].r.chave != ch)
    return false;
  if(anterior == inv)
    l->inicio = l->v[i].proximo;
  else
    l->v[anterior].proximo = l->v[i].proximo;
  devolver_NO(l, i);
  return true;
}

void devolver_NO(LISTA *l, int i){
  l->v[i].proximo = l->disponivel;
  l->disponivel = i;
}

void reiniciar(LISTA *l){
  inicializar(l);
}