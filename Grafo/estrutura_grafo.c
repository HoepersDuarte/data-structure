/*Graph.c*/
#include <stdio.h>
#include <stdlib.h>

/* no da lista adjacente*/
typedef struct no {
	int vertice;			//indice do vetor da lista de agjacencia
	struct no *prox;		//ponteiro para o proximo no
}no_t;

/*estrutura dp grafo. um grafo é um vetor da lista de adjacencia.
o tamanho do vetor sera o numero de vertices do grafo */
typedef struct grafo{
	int num_vertices;		//numero de vertices
	no_t *VETOR_list_adj;	//vetor da lista de adjacencia
}grafo_t;


void addARESTA(grafo_t, int, int);
no_t* criaNO(int);
void mostrarGRAFO(grafo_t);
grafo_t* criaGRAFO(int);


int main() {
	grafo_t *dir_grafo = criaGRAFO(5);
	addARESTA(dir_grafo, 0, 1);
	addARESTA(dir_grafo, 0, 4);
	addARESTA(dir_grafo, 1, 2);
	addARESTA(dir_grafo, 1, 3);
	addARESTA(dir_grafo, 1, 4);
	addARESTA(dir_grafo, 2, 3);
	addARESTA(dir_grafo, 2, 3);

	return 0;
}


// cria um grafo com n vertices
grafo_t *criaGRAFO(int n){
	int i;
	grafo_t *grafo = (grafo_t*)malloc(sizeof(grafo_t));
	if(!grafo){
		printf("[ERRO FATAL]: incapaz de alocar memoria para o grafo\n");
		exit(EXIT_FAILURE);
	}

	grafo->num_vertices = n;

	// cria um vetor de lista adjacente
	grafo->VETOR_list_adj = (no_t*)malloc(n * sizeof(no_t));
	if (!grafo->VETOR_list_adj){
		printf("[ERRO FATAL]: incapaz de alocar memoria para o vetor de lista adjacente\n");
		exit(EXIT_FAILURE);
	}

	for(i=0; i<n; i++){
		grafo->VETOR_list_adj[i].prox = NULL;
	}

	return grafo;
}



void addARESTA(grafo_t *grafo, int origem, int destino){
	no_t *novoNO = criaNO(dest);
	novoNO->prox = grafo->VETOR_list_adj[origem].prox;
	grafo->VETOR_list_adj[origem].prox = novoNO;
}


no_t *criaNO(int v){
	no_t *novoNO = (no_t*)malloc(sizeof(no_t));
	if (!novoNO){
		printf("[ERRO FATAL]: incapaz de alocar memoria para o vetor de lista adjacente\n");
		exit(EXIT_FAILURE);
	}

	novoNO->vertice = v;
	novoNO->prox = NULL;

	return novoNO;
}

void mostrarGRAFO(grafo_t *grafo){
	int i;
	for(i=0; i<grafo->num_vertices; i++){
		no_t *elemento;
		elemento = grafo->VETOR_list_adj[i]
		printf(" %d -> ", elemento->vertice);
		if(elemento.prox!=NULL){
			no_t *auxi = elemento->prox;
			while(1){
				printf(" %d -> ", auxi->vertice);
				if (auxi->prox==NULL)
					break;

				auxi = auxi->prox;
			}
		printf("\n");
		}
		
	}
}