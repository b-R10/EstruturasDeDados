#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoTag {
    int info;
    struct NoTag *link;
} no;

void percorreLista(no **L);