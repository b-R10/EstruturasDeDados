#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Lista_linear.h"

int main() {
  Lista *lista1 = criarLista();
  inicializarLista(lista1);

  Registro novoReg;
  for (int i = 0; i < 10; i++)
  {
    novoReg = criarRegistro(i);
    if (inserirElemento(lista1, novoReg, i)) {
      printf("Elemento inserido\n");
    } else {
      printf("Elemento não inserido\n");
    }
  }

  imprimirLista(lista1);
  
  free(lista1);
  return 0;
}