#define max 30
#define inv -1

typedef int TipoChave;

typedef struct {
  TipoChave chave;
} Registro;

typedef struct {
  Registro V[max];
  int N;
} Lista;

Lista* criarLista();

Registro criarRegistro(int i);

void inicializarLista(Lista *L);

int tamanho(Lista *L);

void imprimirLista(Lista *L);

int buscarElemento(Lista *L, TipoChave ch);

bool inserirElemento(Lista *L, Registro reg, int i);

bool removerElemento(Lista *L, TipoChave ch);

void reiniciarLista(Lista *L);