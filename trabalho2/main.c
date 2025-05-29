#include "arvore_binaria.h"

int main(){
  No arvore1 = criaArvore(2);

  arvore1 = inserir(arvore1, 3);
  arvore1 = inserir(arvore1, 8);
  arvore1 = inserir(arvore1, 7);
  arvore1 = inserir(arvore1, 1);
  arvore1 = inserir(arvore1, 5);

  preInPosOrdem(arvore1);
  
  printf("\n");

  arvore1 = remover(arvore1, 5);

  preInPosOrdem(arvore1);
  
  No buscaChave = busca_chave(arvore1, 3);
  printf("Chave: %d\n", buscaChave->info);
  
  No sucessor1 = sucessor(arvore1);
  printf("Sucessor: %d\n", sucessor1->info);

  No predecessor1 = predecessor(arvore1);
  printf("Predecessor: %d\n", predecessor1->info);

  No minimo1 = minimo(arvore1);
  printf("Minimo: %d\n", minimo1->info);

  No maximo1 = maximo(arvore1);
  printf("Maximo: %d\n", maximo1->info);
}