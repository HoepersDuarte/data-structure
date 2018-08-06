#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	int codigo;
	float valor;
	struct elemento *p_prox;
} Elemento;

typedef struct {
	Elemento *p_inicio;
} Lista;

Elemento* criarElemento(int, float);
void percorrer(Lista*);
void inserirInicio(Lista*, int, float);
void inserirFinal(Lista*, int, float);
void remover(Lista*, int);
void procurar(Lista*, int); // Mostrar o valor do código correspondente

int main() {
	int i;
	Lista* minhaLista;
	minhaLista = (Lista*) malloc(sizeof(Lista));
	minhaLista->p_inicio = NULL;
	for (i = 10; i > 0; i--) {
		inserirInicio(minhaLista, i, i*10.0);
	}
	percorrer(minhaLista);
	procurar(minhaLista, 5);
	procurar(minhaLista, 35);
	inserirFinal(minhaLista, 15, 150.0);
	percorrer(minhaLista);
	remover(minhaLista, 5);
	percorrer(minhaLista);
	remover(minhaLista, 25);
	percorrer(minhaLista);
}


void percorrer(Lista* lista) {
	if (lista->p_inicio == NULL)
		printf("Lista vazia...\n");
	else {
		Elemento *p_aux;
		p_aux = lista->p_inicio;
		while (p_aux != NULL) {
			printf("COD: %2d \tVAL: %.2f\n", p_aux->codigo, p_aux->valor);
			p_aux = p_aux->p_prox;
		}
	}
}

Elemento* criarElemento(int cod, float val) {
	Elemento* novoElemento;
	novoElemento = (Elemento*) malloc ( sizeof(Elemento) );
	novoElemento->codigo = cod;
	novoElemento->valor = val;
	novoElemento->p_prox = NULL;
	return novoElemento;
}

void inserirInicio(Lista* lista, int cod, float val) {
	Elemento* novoElemento = criarElemento(cod, val);
	novoElemento->p_prox = lista->p_inicio;
	lista->p_inicio = novoElemento;
}

void inserirFinal(Lista* lista, int cod, float val) {
	if (lista->p_inicio == NULL)
		inserirInicio(lista, cod, val);
	else {
		Elemento* novoElemento = criarElemento(cod, val);
		Elemento *p_aux = lista->p_inicio;
		while (p_aux->p_prox != NULL) {
			p_aux = p_aux->p_prox;
		}
		p_aux->p_prox = novoElemento;
	}
}

void remover(Lista *lista, int cod) {
	Elemento *p_aux = lista->p_inicio;
	while (p_aux != NULL) {
		if (p_aux->p_prox->codigo == cod) {
			Elemento *p_remover = p_aux->p_prox;
			p_aux->p_prox = p_remover->p_prox;
			free(p_remover);
			printf("Removido...\n");
			break;
		}
		p_aux = p_aux->p_prox;
	}
	return;
}

void procurar(Lista *lista, int cod) {
	Elemento *p_aux = lista->p_inicio;
	int encontrado = 0;
	while (p_aux != NULL) {
		if (p_aux->codigo == cod) {
			encontrado = 1;
			printf("Valor encontrado: %.2f\n", p_aux->valor);
		}
		p_aux = p_aux->p_prox;
	}
	if (encontrado == 0)
		printf("Código %d não encontrado\n", cod);
}