#include "lista.h"

int main() {

  Lista *lista1 = (Lista *)malloc(sizeof(Lista));

  inicializarLista(lista1);

  printf("%d", numeroDeElementos(lista1));

  Registro reg1 = CriarRegistro(123, "Breno", 100.00);
  Registro reg2 = CriarRegistro(123, "Breno", 100.00);

  InserirElemento(lista1, reg1, 0);
  InserirElemento(lista1, reg2, 1);

  imprimirLista(lista1);
  

  return 0;
}