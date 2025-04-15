#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define maxNome 100
#define maxDisciplina 50
#define maxDisciplinas 10
#define maxLista 100
#define inv -1

typedef struct {
  char nome[maxNome];
  int matricula;
  char disciplinas[maxDisciplinas][maxDisciplina];
  int qntdDisciplinas;
} Aluno;

typedef struct {
  Aluno aluno;
  int proximo;
} Nodo;

typedef struct {
  Nodo nos[maxLista];
  int inicio;
  int disponivel;
} Lista;

void iniciarLista(Lista *L);

bool inserirAluno(Lista *L, Aluno aluno);

void listarAluno(Lista *L);

void buscarPorDisciplina(Lista *L, char *disciplina);