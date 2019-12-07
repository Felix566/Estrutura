//bibliotecas do sistema;

#include<stdio.h>
#include<stdlib.h>

//bibliotecas criadas;

#include"ListaAluno.h"
#include"Aluno.h"
#include"ListaProfessor.h"
#include"Professor.h"

void menu(){//interface para o usuario;
	
	Lista* lista=cria_lista();
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
				case 1:{
					int x;
					printf("Se desejar adicionar alunos digite(1) se desejar adicionar professores(2)\n");
					scanf("%d",&x);
					if(x==1){
						adicionar(lista);
						system("cls"); 
						break;
					}
					else if(x==2){
						adicionar_professores(lista);
						system("cls");
						break;
					}
					else{
						printf("ERRO\n");
					}
					
				}
				case 2:{
					int x;
					printf("Se desejar imprimir alunos digite(1) se desejar imprimir professores(2)\n");
					scanf("%d",&x);
					if(x==1){
						imprimir(lista);
						break;
					}
					else if(x==2){
						imprimir_prof(lista);
						break;
					}
					else{
						printf("ERRO\n");
					}
				}
				case 3:{
					int x;
					printf("Se desejar remover alunos digite(1) se desejar remover professores(2)\n");
					scanf("%d",&x);
					if(x==1){
					remover(lista);
					break;	
					}
					else if(x==2){
						remover_prof(lista);
						break;
					}
				} 
				defalt: printf("ERRO\n");
			}
		}
	}
}


main(){
	menu();
}
