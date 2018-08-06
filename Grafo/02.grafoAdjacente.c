#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int vertice;
	struct no *prox;	
}no_t;


typedef struct grafo {
	int num_vertices;
	no_t *VETOR_list_adj;
}grafo_t;


grafo_t *criaGRAFO(int);
void addARESTA(grafo_t*, int, int);
no_t *criaNO(int);
void mostrarGRAFO(grafo_t*);
void destroiGRAFO(grafo_t*);
void removerARCO(grafo_t*, int, int);
int main();


int main() {
	grafo_t *dir_grafo = criaGRAFO(5);
	addARESTA(dir_grafo, 0, 1);
	addARESTA(dir_grafo, 0, 4);
	addARESTA(dir_grafo, 1, 2);
	addARESTA(dir_grafo, 1, 3);
	addARESTA(dir_grafo, 1, 4);
	addARESTA(dir_grafo, 2, 3);
	addARESTA(dir_grafo, 3, 4);
	addARESTA(dir_grafo, 3, 0);

	printf("\nGRAFO DIRECIONADO - DIGRAFO");
	mostrarGRAFO(dir_grafo);
	//removerARCO(dir_grafo, 0, 1);
	//removerARCO(dir_grafo, 0, 4);
	//removerARCO(dir_grafo, 1, 2);
	//removerARCO(dir_grafo, 1, 3);
	//removerARCO(dir_grafo, 1, 4);
	mostrarGRAFO(dir_grafo);
	destroiGRAFO(dir_grafo);
	

	return 0;
}

//CRIA UM GRAFO COM N VERTICES
grafo_t *criaGRAFO(int n){
	int i;
	grafo_t *grafo = (grafo_t*)malloc(sizeof(grafo_t));
	if(!grafo){
		printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMORIA PARA O GRAFO \n SAINDO... \n");
		exit(EXIT_FAILURE);
	}

	grafo->num_vertices = n;

	//CRIA UM VETOR DE LISTA ADJACENTES
	grafo->VETOR_list_adj = (no_t*)malloc(n * sizeof(no_t));
	if(!grafo->VETOR_list_adj){
		printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMORIA PARA o VETOR ADJACENTES \n SAINDO... \n");
		exit(EXIT_FAILURE);
	}

	for(i=0; i<n; i++)
		grafo->VETOR_list_adj[i].prox = NULL;

	return grafo;
}


//ADCIONAR UMA ARESTA PARA O GRAFO
void addARESTA(grafo_t *grafo, int origem, int dest){
	//ADCIONA UMA ARESTA DA ORIGEM PARA O DESTINO NA LISTA DE ADJACENTES
	no_t *novoNO = criaNO(dest);
	novoNO->prox = grafo->VETOR_list_adj[origem].prox;
	grafo->VETOR_list_adj[origem].prox = novoNO;

	novoNO = criaNO(origem);
	novoNO->prox = grafo->VETOR_list_adj[dest].prox;
	grafo->VETOR_list_adj[dest].prox = novoNO;
}

//CRIA UM NO NA LISTA ADJACENTES
no_t *criaNO(int v){
	no_t *novoNO = (no_t*)malloc(sizeof(no_t));
	if (!novoNO){
		printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMORIA PARA UM NOVO NO \n SAINDO... \n");
		exit(EXIT_FAILURE);
	}

	novoNO->vertice = v;
	novoNO->prox = NULL;

	return novoNO;
}


//IMPRIMIR A LISTA DE ADJACENCIA DO GRAFO
void mostrarGRAFO(grafo_t* grafo){
	int i;
	for(i=0; i<grafo->num_vertices; i++){
		printf("\n %d ", i);
		no_t *elemento = grafo->VETOR_list_adj[i].prox;
		while(elemento){
			printf("-> %d ", elemento->vertice);
			elemento = elemento->prox;
		}

	}
	printf("\n");
}

void removerARCO(grafo_t *grafo, int origem, int fim){
	if (grafo->num_vertices>origem){
		no_t *elemento = &grafo->VETOR_list_adj[origem];
		if(elemento) {
			no_t *anterior = elemento;
			while(elemento){
				if(elemento->vertice==fim){
					if(elemento->prox){
						anterior->prox = elemento->prox;
						removerARCO(grafo, fim, origem);
						break;
					}
					else {
						anterior->prox = NULL;
						removerARCO(grafo, fim, origem);
						break;
					}
				}
				anterior = elemento;
				elemento = elemento->prox;
			}
		}
	}
}

//DESTRUIR O GRAFO
void destroiGRAFO(grafo_t* grafo){
	if(grafo){
		if (grafo->VETOR_list_adj){
			int v;
			//LIBERAR OS NOS
			for(v=0; v < grafo->num_vertices; v++){
				no_t *primeiro = grafo->VETOR_list_adj[v].prox;
				while(primeiro){
					no_t *tmp = primeiro;
					primeiro = primeiro->prox;
					free(tmp);
				}
			}
			//LIBERAR O VETOR DA LISTA ADJACENTES
			free(grafo->VETOR_list_adj);
		}
		//LIBERAR O GRAFO
		free(grafo);
	}
}

