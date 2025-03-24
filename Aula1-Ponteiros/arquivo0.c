#include <stdio.h>

#define max 5

int main() {
  int vetor[max] = {0,1,2,3,4};

  for (int i = 4; i >= 0; --i) {
    printf("%d", *(vetor + i));
  }

  return 0;
}