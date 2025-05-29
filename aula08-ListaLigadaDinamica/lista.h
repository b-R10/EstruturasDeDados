#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoTag
{
  int info;
  struct NoTag *link;
} no;

void inicializa(no **l);
void percorreLista(no *l);
void insereFinal(no **l, int valor);
void removeFinal(no **l);
