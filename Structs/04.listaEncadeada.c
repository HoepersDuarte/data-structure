#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
	int codigo;
	float valor;
	struct elemento *p_prox;
}Elemento;

typedef struct {
	Elemento *p_inicio;
}Lista;

Elemento* lista_criarElemento(int, float);
void lista_percorrer(Lista*);
void lista_inserirInicio(Lista*, int, float);
void lista_inserirFinal(Lista*, int, float);
void lista_remover(Lista*, int);
void lista_procurar(Lista*, int); 

int main() {
	int i, id;
	Lista* minhaLista;
	minhaLista = (Lista*) malloc(sizeof(Lista));
	minhaLista->p_inicio = NULL;
	for (i=30; i>0; i--){
		lista_inserirInicio(minhaLista, i, i*10.0);
	}
	lista_inserirFinal(minhaLista, 34, 34.0);
	lista_inserirFinal(minhaLista, 35, 35.0);
	lista_percorrer(minhaLista);

	printf("Digite um Codigo: ");
	scanf("%d", &id);
	lista_remover(minhaLista, id);
	lista_percorrer(minhaLista);

}

Elemento* lista_criarElemento(int cod, float val){
	Elemento *novoElemento;
	novoElemento = (Elemento*) malloc(sizeof(Elemento));
	novoElemento->codigo = cod;
	novoElemento->valor = val;
	novoElemento->p_prox = NULL;
	return novoElemento;
}

void lista_inserirInicio(Lista* lista, int cod, float val) {
	Elemento *novoElemento;
	novoElemento = (Elemento*) malloc(sizeof(Elemento));
	novoElemento->codigo = cod;
	novoElemento->valor = val;
	novoElemento->p_prox = lista->p_inicio;
	lista->p_inicio = novoElemento;
}

void lista_inserirFinal(Lista* lista, int cod, float val){
	if (lista->p_inicio==NULL)
		lista_inserirInicio(lista, cod, val);
	else {
		Elemento* novoElemento = lista_criarElemento(cod,val);
		Elemento* p_aux = lista->p_inicio;
		while (p_aux->p_prox != NULL) {
			p_aux = p_aux->p_prox;
		}
		p_aux->p_prox = novoElemento;
	}
}

void lista_remover(Lista *lista, int cod) {
	Elemento *p_aux = lista->p_inicio;
	while (p_aux != NULL) {
		
	}
}


void lista_percorrer(Lista* lista){
	if (lista->p_inicio == NULL)
		printf("Lista Vazia.... \n");
	else {
		Elemento *p_aux;
		p_aux = lista->p_inicio;
		while (p_aux != NULL) {
			printf("CODIOG: %d \tVALOR: %.2f\n", p_aux->codigo, p_aux->valor);
			p_aux = p_aux->p_prox;
		}
	}
}

void lista_procurar(Lista* lista, int cod){
	int i, x=0;
	Elemento *p_aux;
	p_aux = lista->p_inicio;
	while (p_aux != NULL) {
		if (p_aux->codigo == cod){
			printf("CODIOG: %d \tVALOR: %.2f\n", p_aux->codigo, p_aux->valor);
			x = 1;
		}
		p_aux = p_aux->p_prox;

	}
	if (x!=1){
		printf("Elemento não Encontrado\n");
	}
}