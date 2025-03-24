#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, *vetor;

  if ((vetor = (int *) malloc(100*sizeof(int))) == NULL) {
    printf("Erro na alocacao.");
    exit(EXIT_FAILURE);
  } else {
    for (i = 0; i < 100; ++i) {
      vetor[i] = i;
    }

    for (i = 0; i < 100; ++i) {
      printf("%d\n", vetor[i]);
    }
    
    free(vetor);
  }
  
  
  return 0;
}