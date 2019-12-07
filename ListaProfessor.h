typedef struct tipoprofessor{
}Professor;

typedef struct tipoListaProf{
}ListaProf;

ListaProf* cria_listaP();

void inserir_professores(ListaProf* lista, char n[30], char m[30]);

int estaVaziaP(ListaProf* lista);

void imprimir_professor(ListaProf* lista);

void busca_professor(ListaProf* lista, char n[30]);

void remover_professor(ListaProf* lista, char m[30]);
