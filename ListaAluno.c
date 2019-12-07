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

Lista* cria_lista(){//função para criar a lista;
	Lista* lista=(Lista*)malloc(sizeof(Lista*));
	lista->inicio=NULL;
	return lista;
}

void inserir(Lista* lista, char n[30], char s[15], char m[30]){//procedimento para inserir alunos na lista;
	Aluno* novo=(Aluno*)malloc(sizeof(Aluno));
	strcpy(novo->nome,n);
	strcpy(novo->serie,s);
	strcpy(novo->matricula,m);
	novo->proximo=lista->inicio;
	lista->inicio=novo;
}

int estaVazia(Lista* lista){
	if(lista->inicio==NULL){
		return 0;
	}
	else{
		return 1;
	}
}

void imprimir_alunos(Lista* lista){
	int x=estaVazia(lista);
	if(x==0){
		printf("A lista esta vazia !\n\n");
	}
	else{
		Aluno* aux=lista->inicio;
		while(aux!=NULL){
			printf("Nome: %s\n",aux->nome);
			printf("Serie: %s\n",aux->serie);
			printf("Matricula: %s\n\n",aux->matricula);
			aux=aux->proximo;
		}
	}
	
}

void busca_aluno(Lista* lista, char n[30]){
	int x=estaVazia(lista);
	if(x==0){
		printf("A lista esta vazia!\n\n");
	}
	else{
		Aluno* aux=lista->inicio;
		int cont=0;
		while(aux!=NULL){
			int res=strcmp(aux->matricula,n);
			if(res==0){
				printf("====O Aluno referente a busca eh:====\n\n");
				printf("Nome: %s\n",aux->nome);
				printf("Serie: %s\n",aux->serie);
				printf("Matricula: %s\n\n",aux->matricula);
				cont++;
			}
			aux=aux->proximo;
		}
		if(cont==0){
			printf("O aluno nao existe !\n\n");
		}
	}
}

void remover_aluno(Lista* lista, char m[30]){
	Aluno* p=lista->inicio;//ponteiro para percorrer a lista;
	Aluno* a=NULL;//ponteiro para guardar o anterior;
	int x;
	while(p!=NULL && (strcmp(p->matricula,m))!=0){
		a=p;
		p=p->proximo;
	}
	if(p==NULL){
		printf("O aluno nao existe !\n\n");
	}
	if(a==NULL){
		lista->inicio=p->proximo;
	}
	else{
		a->proximo=p->proximo;
	}
	free(p);
	printf("Aluno removido com sucesso!\n");	
}
