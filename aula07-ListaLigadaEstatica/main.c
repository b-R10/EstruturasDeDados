#include "lista.h"

int main(){
  LISTA *lista1 = (LISTA *)malloc(sizeof(LISTA));

  inicializar(lista1);

  printf("Tamanho: %d\n", tamanho(lista1));
  
  REGISTRO reg;
  for (int i = 0; i < 10; ++i){
    reg.chave = i+1;
    inserir_ordenado(lista1, reg);
  }
  
  printf("Tamanho: %d\n", tamanho(lista1));
  
  imprimir(lista1);
  
  printf("Posicao de 3: %d\n", buscar_sequencial_ordenada(lista1, 3));
  
  excluir(lista1, 3);
  
  printf("Tamanho: %d\n", tamanho(lista1));

  imprimir(lista1);

  return 0;
}