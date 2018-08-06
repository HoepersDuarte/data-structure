#include <stdio.h>
#include <stdlib.h>
#include "arraysequencial.h"

//Prototipação de funções
int menu();

//Inicio do programa principal
int main()
{
	arraySeq* coordenadas;
	int x, y, posicao;
	do
	{
		switch(menu()){
			case 0:
				return 1;
			case 1:
				coordenadas = inicializar();
				printf("inicializar...\n");
				break;
			case 2:
				printf("Capacidade total: %d.\n", getCapacidade(coordenadas));
				break;
			case 3:
				printf("Quantidade de elementos: %d.\n", getQuantidade(coordenadas));
				break;
			case 4:
				printf("Informe coordenadas: ");
				scanf("%d", &x);
				scanf("%d", &y);
				adicionaCoordenada(coordenadas, x, y);
				break;
			case 5:
				printf("Informe coordenadas: ");
				scanf("%d", &x);
				scanf("%d", &y);
				printf("Infome a posicao: ");
				scanf("%d", &posicao);
				adicionaCoordenadak(coordenadas, x, y, posicao);
				break;
			case 6:
				for (int i=0; i<coordenadas->quantidade; i++){
					printf("(%d, %d) ", coordenadas->pontos[i].x, coordenadas->pontos[i].y );
				}
				printf("\n");
				break;
			default:
				break;

		}
	} while (1==1);
	return 0;
}
//Fim do programa principal

//Inicio das funções
int menu(){
	int op;
	printf("1 - Inicializar\n");
	printf("2 - Capacidade de elementos\n");
	printf("3 - Quantidade de elementos\n");
	printf("4 - Adicionar coordenadas - FIM\n");
	printf("5 - Adicionar coordenadas - KEY\n");
	printf("6 - Mostrar vetor\n");
	printf("\n0 - Sair\n");	
	printf("Opcao: ");
	scanf("%d", &op);
	return (op);

}
//Fim das funções