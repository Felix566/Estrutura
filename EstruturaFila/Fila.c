#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int numero;
	struct nodo* proximo;
}Nodo;

typedef struct{
	Nodo* inicio;
}Fila;

const int TRUE=1;
const int FALSE=0;

Fila* criarFila(){
	Fila* fila=(Fila*)malloc(sizeof(Fila));
	fila->inicio=NULL;
	return fila;
}

void push(Fila* fila,int n){
	Nodo* novo=(Nodo*)malloc(sizeof(Nodo));
	novo->numero=n;
	novo->proximo=NULL;
	if(fila->inicio==NULL){
		fila->inicio=novo;
	}
	else{
		Nodo* aux=fila->inicio;
		while(aux->proximo=NULL){
			aux=aux->proximo;
		}
		aux->proximo=novo;
	}
}

int pop(Fila* fila){
	Nodo* aux=fila->inicio;
	int resultado=aux->numero;
	fila->inicio=aux->proximo;
	free(aux);
	return resultado;
}

int estaVazia(Fila* fila){
	if(fila->inicio==NULL){
		return TRUE;
	}
	return FALSE;
}

void Menu(){
	printf("\n=====MENU=====\n");
	printf("1-Inserir:\n");
	printf("2-Remover:\n");
	printf("3-Sair:\n\n");
}

main(){
	Fila*fila=criarFila();
	int n;
	int valor=0;
	do{
		Menu();
		scanf("%d",&valor);
		if(valor==1){
			while(n!=0){
				push(fila,n);
				printf("Informe um numero:");
				scanf("%d",&n);
			}
			system("cls");
		}
		else if(valor==2){
			while(estaVazia(fila)==FALSE){
				n=pop(fila);
			}
			printf("\nNumeros removidos com sucesso!\n\n");
		}
		if(valor==3){
			exit(1);
		}
	}while(valor!=0);
}
