#include "lista.h"

int main() {
  LISTA *lista1 = (LISTA *)malloc(sizeof(LISTA));

  inicializar(lista1);

  printf("tamanho: %d\n", retornar_tamanho(lista1));

  REGISTRO r;
  for(int i=2; i<12; ++i){
    r.chave = i;
    inserir_inicio(lista1, r);
  }

  r.chave = 12;
  inserir_final(lista1, r);
  
  printf("tamanho: %d\n", retornar_tamanho(lista1));

  imprimir_lista(lista1);
  
  printf("chave: %d\n", buscar_chave(lista1, 3));

  remover_inicio(lista1);
  
  imprimir_lista(lista1);

  remover_final(lista1);

  imprimir_lista(lista1);

  remover_chave(lista1, 6);

  imprimir_lista(lista1);
  
  reinicializar_lista(lista1);
  
  imprimir_lista(lista1);
  
  return 0;
}