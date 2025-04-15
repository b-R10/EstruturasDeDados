#include "lista.h"

int main() {
  Lista *lista1 = (Lista *)malloc(sizeof(Lista));

  inicializar(lista1);

  printf("Tamanho da lista: %d\n", retornar_tamanho(lista1));
  imprimir_lista(lista1);

  Registro reg;
  reg.chave = 1;
  
  inserir_inicio(lista1, reg);
  
  reg.chave = 2;
  
  inserir_inicio(lista1, reg);

  printf("Tamanho da lista: %d\n", retornar_tamanho(lista1));
  imprimir_lista(lista1);

  

  return 0;
}