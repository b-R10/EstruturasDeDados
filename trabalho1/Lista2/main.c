#include "lista.h"

int main() {
  LISTA *lista1 = (LISTA*)malloc(sizeof(LISTA));

  inicializar(lista1);

  printf("tamanho: %d\n", retornar_tamanho(lista1));

  REGISTRO r;
  for (int i = 0; i < 20; i += 2){
    r.chave = i;  
    inserir_chave(lista1, r);
  }
  
  imprimir_lista(lista1);

  r.chave = 7;
  inserir_chave(lista1, r);

  imprimir_lista(lista1);

  printf("chave: %d", buscar_chave(lista1, 4));

  remover_chave(lista1, 8);

  imprimir_lista(lista1);

  reinicializar_lista(lista1);
  
  return 0;
}