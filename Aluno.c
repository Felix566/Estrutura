#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipoaluno{//estrutura do Aluno;
	char nome[30];
	char serie[15];
	char matricula[30];
	struct Aluno* proximo;
}Aluno;

typedef struct tipolista{//estrutura que contem um ponteiro para apontar para o inicio da lista;
	Aluno* inicio;
}Lista;

void adicionar(Lista* lista){//inserindo alunos na lista;
	char n[30];
	char s[15];
	char m[30];
	printf("Inserindo informacoes do Aluno:\n\n");
	printf("Informe o nome do Aluno\n");
	fflush(stdin);
	gets(n);
	printf("Informe a serie:\n");
	fflush(stdin);
	gets(s);
	printf("Informe o numero da Matricula:\n");
	fflush(stdin);
	gets(m);
	inserir(lista,n,s,m);
	printf("\n\n");
}

void imprimir(Lista* lista){
	int n;
	printf("Para imprimir todos os alunos da lista digite(1), para imprimir apenas um digite(2):\n");
	scanf("%d",&n);
	if(n==1){
		imprimir_alunos(lista);
	}
	else{
		char m[30];
		printf("Digite a matricula do aluno a qual deseja ver as informacoes:\n");
		fflush(stdin);
		gets(m);
		busca_aluno(lista,m);
	}
}

void remover(Lista* lista){
	char m[30];
	printf("Digite o numero da matricula referente ao aluno que deseja remover:\n");
	fflush(stdin);
	gets(m);
	remover_aluno(lista,m);
}

