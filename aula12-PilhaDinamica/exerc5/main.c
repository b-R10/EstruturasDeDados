#include "pilha.h"

int main(){
  char texto[MAX], filtrado[MAX];
  Pilha *pilha1 = (Pilha*)malloc(sizeof(Pilha));
  Registro reg;
  int i, j = 0, palindromo = 1;

  printf("Digite o texto:\n");
  fgets(texto, MAX, stdin);

  for(i=0; texto[i] != '\0'; ++i){
    if(texto[i] != ' ' && texto[i] != '.' && texto[i] != '\n'){
      filtrado[j++] = tolower(texto[i]);
    }
  }

  filtrado[j] = '\0';

  iniciar(pilha1);

  for(i=0; i<j; ++i){
    reg.chave = filtrado[i];
    push(pilha1, reg);
  }

  for(i=0; i<j; ++i){
    pop(pilha1, &reg);
    if(reg.chave != filtrado[i]){
      palindromo = 0;
      break;
    }
  }

  if(palindromo)
    printf("é palindromo");
  else
    printf("nao é palindromo");
  
  return 0;
}