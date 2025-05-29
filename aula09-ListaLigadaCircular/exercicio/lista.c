#include "lista.h"

void iniciarLista(Lista *l) {
  l->no = (PONT)malloc(sizeof(Elemento));
  l->no->proximo = l->no;
}

int tamanho(Lista *l) {
  PONT aux = l->no->proximo;
  int tamanho=0;
  while (aux != l->no) {
    tamanho++;
    aux = aux->proximo;
  }
  return tamanho;
}

void imprimirLista(Lista *l) {
  PONT aux = l->no->proximo;
  while(aux != l->no) {
    printf("Nome: %s\t", aux->r.nomeCliente);
    printf("CPF: %s\t", aux->r.CPF);
    for(int i=0; i<aux->r.qtdContas; ++i) {
      printf("Numero da conta: %d\t", aux->r.numeroDaConta[i]);
    }
    printf("Saldo: %f\n", aux->r.saldo);
    aux = aux->proximo;
  }
}

PONT buscaAux(Lista *l, char cpf[maxCPF], PONT *anterior) {
  *anterior = l->no;
  PONT atual = l->no->proximo;
  while (atual != l->no) {
    if (strcmp(atual->r.CPF, cpf) == 0) {
      return atual;
    }
    *anterior = atual;
    atual = atual->proximo;
  }
  return NULL;
}

bool inserirElemento(Lista *l, Registro r) {
  PONT anterior, i;
  i = buscaAux(l, r.CPF, &anterior);
  if(i != NULL)
    return false;
  i = (PONT)malloc(sizeof(Elemento));
  i->r = r;
  i->proximo = anterior->proximo;
  anterior->proximo = i;
  return true;
}

bool excluirElemento(Lista *l, char cpf[maxCPF]) {
  PONT anterior, i;
  i = buscaAux(l, cpf, &anterior);
  if(i == NULL)
    return false;
  anterior->proximo = i->proximo;
  free(i);
  return true;
}

void reiniciarLista(Lista *l) {
  PONT aux = l->no->proximo;
  while(aux != l->no) {
    PONT limpar = aux;
    aux = aux->proximo;
    free(limpar);
  }
  l->no->proximo = l->no;
}