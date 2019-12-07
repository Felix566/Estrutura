#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct tipoprofessor{//estrutura do Professor;
	char nome[30];
	char matricula[30];
	struct Professor* proximo;
}Professor;

typedef struct tipoListaProf{//estrutura que contem um ponteiro para apontar para o inicio da lista;
	Professor* inicio;
}ListaProf;

ListaProf* cria_listaP(){//função para criar a lista;
	ListaProf* lista=(ListaProf*)malloc(sizeof(ListaProf*));
	lista->inicio=NULL;
	return lista;
}

void inserir_professores(ListaProf* lista, char n[30], char m[30]){//procedimento para inserir professores na lista;
	Professor* novo=(Professor*)malloc(sizeof(Professor));
	strcpy(novo->nome,n);
	strcpy(novo->matricula,m);
	novo->proximo=lista->inicio;
	lista->inicio=novo;
}

int estaVaziaP(ListaProf* lista){
	if(lista->inicio==NULL){
		return 0;
	}
	else{
		return 1;
	}
}

void imprimir_professores(ListaProf* lista){
	int x=estaVaziaP(lista);
	if(x==0){
		printf("A lista esta vazia !\n\n");
	}
	else{
		Professor* aux=lista->inicio;
		while(aux!=NULL){
			printf("Nome: %s\n",aux->nome);
			printf("Matricula: %s\n\n",aux->matricula);
			aux=aux->proximo;
		}
	}
	
}

void busca_professor(ListaProf* lista, char n[30]){
	int x=estaVaziaP(lista);
	if(x==0){
		printf("A lista esta vazia!\n\n");
	}
	else{
		Professor* aux=lista->inicio;
		int cont=0;
		while(aux!=NULL){
			int res=strcmp(aux->matricula,n);
			if(res==0){
				printf("====O Professor referente a busca eh:====\n\n");
				printf("Nome: %s\n",aux->nome);
				printf("Matricula: %s\n\n",aux->matricula);
				cont++;
			}
			aux=aux->proximo;
		}
		if(cont==0){
			printf("O Professor nao existe !\n\n");
		}
	}
}

void remover_professor(ListaProf* lista, char m[30]){
	Professor* p=lista->inicio;//ponteiro para percorrer a lista;
	Professor* a=NULL;//ponteiro para guardar o anterior;
	int x;
	while(p!=NULL && (strcmp(p->matricula,m))!=0){
		a=p;
		p=p->proximo;
	}
	if(p==NULL){
		printf("O professsor nao existe !\n\n");
	}
	if(a==NULL){
		lista->inicio=p->proximo;
	}
	else{
		a->proximo=p->proximo;
	}
	free(p);
	printf("Professor removido com sucesso!");	
}
