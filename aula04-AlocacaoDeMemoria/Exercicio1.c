#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i;

  scanf("%d", &n);

  int *vetor = (int *) malloc(n * sizeof(int));

  if (vetor == NULL) {
    exit(EXIT_FAILURE);
  } else {
    for (i = 0; i < n; ++i) { 
      scanf("%d", &vetor[i]);
    }
    
    for (i = n-1; i >= 0; --i) {
      printf("%d ", vetor[i]);
    }

    free(vetor);
  }
  return 0;
}