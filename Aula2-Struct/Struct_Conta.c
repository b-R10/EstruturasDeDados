#include <stdio.h>

struct Conta {
  int num_conta;
  char tipo_conta;
  char nome[80];
  float saldo;
};

int main() {

  struct Conta vcliente[100];
  int quantidade, i;

  printf("Quantos clientes?");
  scanf("%d", &quantidade);

  while (i < quantidade) {
    printf("Digite o numero da conta %d: ", i);
    scanf("%d%*c", &vcliente[i].num_conta);
    
    printf("Digite o tipo da conta %d: ", i);
    scanf("%1[^\n]%*c", &vcliente[i].tipo_conta);
    
    printf("Digite o nome da conta %d: ", i);
    scanf("%79[^\n]%*c", vcliente[i].nome);
    
    printf("Digite o saldo da conta %d: ", i);
    scanf("%f", &vcliente[i].saldo);
    
    i++;
  }

  printf("\nImprime dados dos clientes");
  printf("\nNro Cta Tipo Cta Nome Cliente Saldo Cta");
  for (i=0; i<quantidade; ++i) {
    printf("\n%3d %c %s %.2f", 
        vcliente[i].num_conta, 
        vcliente[i].tipo_conta, 
        vcliente[i].nome,
        vcliente[i].saldo
      );
  }
  
  return 0;
}
