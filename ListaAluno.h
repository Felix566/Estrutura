typedef struct tipoaluno{
}Aluno;

typedef struct tipoLista{
}Lista;

Lista* cria_lista();

void inserir(Lista* lista, char n[30], char s[15], char m[30]);

int estaVazia(Lista* lista);

void imprimir_alunos(Lista* lista);

void busca_aluno(Lista* lista, char n[30]);

void remover_aluno(Lista* lista, char m[30]);
