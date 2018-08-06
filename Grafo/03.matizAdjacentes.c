#include <stdio.h>
#include <stdlib.h>

typedef struct digraph{
	int numVertice;
	int **matriz_adj;
}digraph_t;


int main(){
	digraph_t *digrafo = criaDIGRAFO(5);
}

digraph_t *criaDIGRAFO(int num_vertice){
	digraph_t *G = malloc(sizeof(digraph_t));
	if(!digraph_t){
		printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMORIA PARA O DIRGRAFO \n SAINDO... \n");
		exit(EXIT_FAILURE);
	}
	G->numVertice = num_vertice;
	G->matriz_adj = criaMatriz(num_vertice, num_vertice, 0);

	return G;
}