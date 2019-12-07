#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipoaluno{//estrutura do Professor;
	char nome[30];
	char matricula[30];
	struct Professor* proximo;
}Professor;

typedef struct tipolista{//estrutura que contem um ponteiro para apontar para o inicio da lista;
	Professor* inicio;
}ListaProf;

void adicionar_professores(ListaProf* lista){//inserindo professores na lista;
	char n[30];
	char m[30];
	printf("Inserindo informacoes do Professor:\n\n");
	printf("Informe o nome do Professor:\n");
	fflush(stdin);
	gets(n);
	printf("Informe o numero da Matricula:\n");
	fflush(stdin);
	gets(m);
	inserir(lista,n,m);
	printf("\n\n");
}

void imprimir_prof(ListaProf* lista){
	int n;
	printf("Para imprimir todos os professores da lista digite(1), para imprimir apenas um digite(2):\n");
	scanf("%d",&n);
	if(n==1){
		imprimir_professores(lista);
	}
	else{
		char m[30];
		printf("Digite a matricula do professor a qual deseja ver as informacoes:\n");
		fflush(stdin);
		gets(m);
		busca_professor(lista,m);
	}
}

void remover_prof(ListaProf* lista){
	char m[30];
	printf("Digite o numero da matricula referente ao professor que deseja remover:\n");
	fflush(stdin);
	gets(m);
	remover_professor(lista,m);
}
