#include <stdio.h>
#include <stdlib.h>


typedef struct pilha {
    int topo; //topo
    struct pilha *proximo;
} Elementos;

void pilha_push();
void pilha_pop();
void pilha_top();
void pilha_show();

Elementos *principal = NULL;

int menu();
int main()
{
	do{
		switch(menu()){
			case 0:
				free(principal);
				exit(0);
                break;
			case 1:
				pilha_push();
				break;
			case 2:
				if(principal != NULL){
					pilha_pop();
				}else{
					printf("Pilha esta vazia\n");
				}
				break;
			case 3:
				if(principal != NULL){
					pilha_top();
				}else{
					printf("Pilha esta vazia\n");
				}
				break;
			case 4:
				if(principal != NULL){
					pilha_show();
				}else{
					printf("Pilha esta vazia\n");
				}
				break;
			default:

				break;
		}
	}while (1 == 1);
}

//Menu de opções.
int menu()
{
	int op;
	printf("1 - Empilhar\n");
	printf("2 - Desempilhar\n");
	printf("3 - Mostrar o topo\n");
	printf("4 - Mostrar  pilha\n");
	printf("0 - Sair\n");
	printf("Selecione uma opcao: ");
	scanf("%d", &op);
	return(op);
}
//Funções
void pilha_push(){
	int val;
	printf("Insira o topo desejado: ");
	scanf("%d", &val);
	Elementos *n_topo = (Elementos*)malloc(sizeof(Elementos));
	n_topo -> topo = val;
	n_topo -> proximo = principal;
	principal  = n_topo;
	printf("\nValor inserido!\n");
    getchar();
}
void pilha_pop(){
	Elementos *aux = (Elementos*)malloc(sizeof(Elementos));
	aux = principal -> proximo;
	free(principal);
	principal = aux;
	printf("\nRemovido!\n");
	getchar();
}
void pilha_top(){
	printf("\nTopo: %d\n", principal -> topo);
}
void pilha_show(){
	int pos = 0;
	Elementos *aux = principal;
	printf("\n");
	while (aux != NULL){
		pos++;
		printf("Posicao: %d - topo: %d\n", pos, aux->topo);
		aux = aux -> proximo;
	}
}