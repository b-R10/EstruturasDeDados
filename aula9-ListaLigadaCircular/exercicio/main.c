#include "lista.h"

int main() {
  Lista *lista1 = (Lista *)malloc(sizeof(Lista));

  iniciarLista(lista1);

  printf("tamanho da lista: %d\n", tamanho(lista1));
  
  Registro reg;
  strcpy(reg.nomeCliente, "Breno");
  strcpy(reg.CPF, "1234");
  reg.numeroDaConta[0] = 1;
  reg.numeroDaConta[1] = 5;
  reg.numeroDaConta[2] = 7;
  reg.qtdContas = 3;
  reg.saldo = 100.00;
  
  inserirElemento(lista1, reg);

  printf("tamanho da lista: %d\n", tamanho(lista1));
  
  strcpy(reg.nomeCliente, "Onerb");
  strcpy(reg.CPF, "4321");
  reg.numeroDaConta[0] = 2;
  reg.qtdContas = 1;
  reg.saldo = 200.00;
  
  inserirElemento(lista1, reg);
  
  printf("tamanho da lista: %d\n", tamanho(lista1));
  imprimirLista(lista1);
  
  excluirElemento(lista1, "4321");
  
  printf("tamanho da lista: %d\n", tamanho(lista1));
  imprimirLista(lista1);

  free(lista1);

  return 0;
}