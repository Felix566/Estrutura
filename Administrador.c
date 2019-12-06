//bibliotecas do sistema;

#include<stdio.h>
#include<stdlib.h>

//bibliotecas criadas;

#include"ListaAluno.h"
#include"Aluno.h"

void menu(){//interface para o usuario;
	
	Lista *lista=cria_lista();
	int cont=0;
	int n;
	while(cont!=4){
		printf("=========MENU=========\n\n");
		printf("1 . Inserir\n");
		printf("2 . Imprimir\n");
		printf("3 . Remover\n");
		printf("4 . Sair\n");
		scanf("%d",&n);
		if(n<0 || n>4){
			printf("Essa opcao nao existe, entre com outra !\n");
		}
		else if(n==4){
			cont=4;
		}
		else{
			switch(n){
				case 1:adicionar(lista); break;
				case 2:imprimir(lista); break;
				case 3: remover(lista); break;
				defalt: printf("ERRO\n");
			}
		}
	}
}


main(){
	menu();
}
