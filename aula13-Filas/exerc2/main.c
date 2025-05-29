#include "fila.h"

int main(){
  Fila *fila1 = (Fila*)malloc(sizeof(Fila));

  iniciar(fila1);
  
  int x = 0, y;

  while(x != 4){

    printf("Insira a opcao desejada:\n"
            "1 - Inserir\n"
            "2 - Remover\n"
            "3 - Imprimir\n"
            "4 - Verificar se está cheia\n"
            "5 - Verificar se está vazia\n"
            "4 - Sair\n");
    
    scanf("%d", &x);

    switch (x)
    {
    case 1:
      printf("valor a ser inserido: \n");
      scanf("%d", &y);
      inserir(fila1, y);
      break;
    case 2:
      printf("valor removido: %d\n", remover(fila1));
      break;
    case 3:
      imprimir(*fila1);
      break;
    case 4:
      break;
    default:
      printf("Erro\n");
      break;
    }

  }
  
  return 0;
}