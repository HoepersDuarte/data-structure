#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//----------------------------------------------
//ESTRUTURAS

//ARVORE
typedef struct folha {
	int id;
	struct folha* pMenor;
	struct folha* pMaior;
	struct folha* pPai;
}Folha;

typedef struct {
	Folha* raiz;
}Arvore;

//VETOR
typedef struct {
	int key; 
	int cod; 
}vetor;

typedef struct {
	int capacidade;
	int quantidade; 
	vetor *elementos;
}array;

//PILHA
typedef struct pilha {
    int topo; 
    struct pilha *proximo;
} Elementos;

Elementos *principal = NULL;

//LISTA ENCADEADA
typedef struct elemento{
	int codigo;
	float valor;
	struct elemento *p_prox;
}Elemento;

typedef struct {
	Elemento *p_inicio;
}Lista;

//----------------------------------------------
//PROTOTIPAÇÃO

//ARVORE
Arvore* Arvore_inicializar();
Folha* Arvore_inserir(Folha*, int);
void inOrder(Folha*);
void preOrder(Folha*);
void posOrder(Folha*);
Folha* Arvore_removerSubRaiz(Folha*);
Folha* Arvore_remover(Folha*, int);
int Arvore_pesquisa (Folha *subRaiz, int id);

//VETOR
array* Vetor_inicializar();
int Vetor_getCapacidade(array*);
int Vetor_getQuantidade(array*);
void Vetor_adicionaCoordenada(array*, int, int);
int Vetor_getUltimokey(array*);
int Vetor_getUltimoY(array*);
void Vetor_adicionaCoordenadak(array*, int, int, int);

//PILHA
void pilha_push(int);
void pilha_pop();
void pilha_top();
void pilha_show();

//LISTA ENCADEADA

Elemento* lista_criarElemento(int, float);
void lista_percorrer(Lista*);
void lista_inserirInicio(Lista*, int, float);
void lista_inserirFinal(Lista*, int, float);
void lista_remover(Lista*, int);
int lista_procurar(Lista*, int); 

//MENU
int menu();
//----------------------------------------------

int main(){
	Arvore* minhaArvore;
	array* coordenadas;
	Lista* minhaLista;
	int aleatorio, i;
	int key, cod;
	int op;
	
	do{
		switch(menu()){
			case 0:
				exit(0);
				break;
			case 1:
				printf("Estrutura Inicializada.\n");
				minhaArvore = Arvore_inicializar();
				coordenadas = Vetor_inicializar();
				minhaLista = (Lista*) malloc(sizeof(Lista));
				minhaLista->p_inicio = NULL;
				printf("\n");
				printf("\n");
				break;
			case 2:
				for (i=0;i<20;i++){
					aleatorio = rand() % 1000;
					printf("valor: %d\n", aleatorio);
					Vetor_adicionaCoordenada(coordenadas, i, aleatorio);
					minhaArvore->raiz = Arvore_inserir(minhaArvore->raiz, aleatorio);		
				}
				printf("Valores inseridos: %d\n", i); 
				break;
			case 3:
				aleatorio = rand() % 20;
				printf("Índice a ser pesquisado: %d\n\n", aleatorio);
				for (i=0; i<coordenadas->quantidade; i++){
					if (coordenadas->elementos[i].key == aleatorio) {
						printf("Valor a ser encontrador na arvore: %d\n", coordenadas->elementos[i].cod);
						printf("Caminho para encontrar o elemento:\n");
						aleatorio = Arvore_pesquisa(minhaArvore->raiz, coordenadas->elementos[i].cod);
						pilha_push(aleatorio);
						break;
					}
				}
				break;
			case 4:
				if(principal != NULL){
					pilha_top();
				}else{
					printf("Pilha esta vazia\n");
				}
				break;
			case 5:
				if(principal != NULL){
					pilha_show();
				}else{
					printf("Pilha esta vazia\n");
				}
				break;
			case 6:
				aleatorio = rand() % 20;
				printf("Índice a ser pesquisado: %d\n\n", aleatorio);
				for (i=0; i<coordenadas->quantidade; i++){
					if (coordenadas->elementos[i].key == aleatorio) {
						printf("Valor a ser removido da arvore: %d\n", coordenadas->elementos[i].cod);
						minhaArvore->raiz = Arvore_remover(minhaArvore->raiz, coordenadas->elementos[i].cod);
						lista_inserirFinal(minhaLista, aleatorio, coordenadas->elementos[i].cod);
						break;
					}
				}
				break;
			case 7:
				aleatorio = rand() % 20;
				printf("Índice a ser procurado: %d\n\n", aleatorio);
				for (i=0; i<aleatorio; i++){
					if (minhaLista->codigo == aleatorio) {
						printf("Valor a ser reinserido na arvore: %d\n", minhaLista->valor);
						minhaArvore->raiz = Arvore_inserir(minhaArvore->raiz, minhaLista->valor);
						break;
					}
				}
				break;
			case 8:
				printf("Percorrer Arvore!\n");
				printf("Em Ordem: \n");
				inOrder(minhaArvore->raiz);
				printf("\n\nPre Ordem: \n");
				preOrder(minhaArvore->raiz);
				printf("\n\nPos Ordem: \n");
				posOrder(minhaArvore->raiz);
				printf("\n\n\n");
				break;
			default:
				break;
		}
	} while (1==1);
}

//----------------------------------------------
//FUNÇÕES

int menu(){
	int op;
	printf("\n[1] - Inicializar vetor dinâmico");
	printf("\n[2] - Gerar elemento para árvore binária");
	printf("\n[3] - Buscar elemento na árvore binária");
	printf("\n[4] - Último elemento procurado");
	printf("\n[5] - Apresentar todos os itens procurados");
	printf("\n[6] - Excluir item da árvore de busca");
	printf("\n[7] - Reinserir elemento na árvore");
	printf("\n[8] - Percorrer a árvore de busca binária");	
	printf("\n[0] - Sair\n");
	printf("\nOpção: ");
	scanf("%d", &op);
	return op;
}

//----------------------------------------------
//ARVORE
Arvore* Arvore_inicializar() {
	Arvore* pAux;
	pAux = (Arvore*) malloc (sizeof(Arvore));
	pAux->raiz = NULL;
	return pAux;
}

Folha* Arvore_inserir(Folha* subRaiz, int id){
	if (subRaiz == NULL) {
		Folha* pNovoNo;
		pNovoNo = (Folha*) malloc (sizeof(Folha));
		pNovoNo->id = id;
		pNovoNo->pMaior = NULL;
		pNovoNo->pMenor = NULL;
		pNovoNo->pPai = NULL;
		return pNovoNo;
	}
	if (subRaiz->id > id) {
		subRaiz->pMenor = Arvore_inserir(subRaiz->pMenor, id);
		subRaiz->pMenor->pPai = subRaiz;
	} else {
		subRaiz->pMaior = Arvore_inserir(subRaiz->pMaior, id);
		subRaiz->pMaior->pPai = subRaiz;
	}
	return subRaiz;
}

Folha* Arvore_removerSubRaiz(Folha* subRaiz) {  
	Folha *pAux1, *pNovaSubRaiz;
	if (subRaiz->pMenor == NULL) {
	   pNovaSubRaiz = subRaiz->pMaior;
	} else {
		pAux1 = subRaiz; 
		pNovaSubRaiz = subRaiz->pMenor;
		while (pNovaSubRaiz->pMaior != NULL) {
			pAux1 = pNovaSubRaiz; 
			pNovaSubRaiz = pNovaSubRaiz->pMaior;
		}
		if (pAux1 != subRaiz) {
			pAux1->pMaior = pNovaSubRaiz->pMenor;
			pNovaSubRaiz->pMenor = subRaiz->pMenor;
		}
		pNovaSubRaiz->pMaior = subRaiz->pMaior;
	}
	free (subRaiz);
	return pNovaSubRaiz;
}

Folha* Arvore_buscarPai(Folha* subRaiz, int id) {
	if (subRaiz == NULL || subRaiz->id == id)
	   return subRaiz->pPai;
	if (subRaiz->id > id)
	   return Arvore_buscarPai (subRaiz->pMenor, id);
	else
	   return Arvore_buscarPai (subRaiz->pMaior, id);
}

Folha* Arvore_remover(Folha* subRaiz, int id) {
	Folha* pai = Arvore_buscarPai(subRaiz, id);
	if (pai == NULL) {
		subRaiz = Arvore_removerSubRaiz(subRaiz);
	}
	else if ( (pai->pMenor) && (pai->pMenor->id == id) )
		pai->pMenor = Arvore_removerSubRaiz (pai->pMenor);
	else 
		pai->pMaior = Arvore_removerSubRaiz (pai->pMaior);
	return subRaiz;
}

void inOrder(Folha* subRaiz){
	if (subRaiz != NULL) {
		inOrder(subRaiz->pMenor);
		printf("%d ", subRaiz->id);
		inOrder(subRaiz->pMaior);
	}
}

void preOrder(Folha* subRaiz){
	if (subRaiz != NULL) {
		printf("%d ", subRaiz->id);
		preOrder(subRaiz->pMenor);
		preOrder(subRaiz->pMaior);
	}
}

void posOrder(Folha* subRaiz){
	if (subRaiz != NULL) {
		posOrder(subRaiz->pMenor);
		posOrder(subRaiz->pMaior);
		printf("%d ", subRaiz->id);
	}
}

int Arvore_pesquisa (Folha *subRaiz, int id) {
	if (subRaiz->id == id) {
		printf("%d\n", subRaiz->id);
		return subRaiz->id;
	}
	else if (id < subRaiz->id) {
		printf("%d\n", subRaiz->id);
		Arvore_pesquisa(subRaiz->pMenor, id);
	}
	else {
		printf("%d\n", subRaiz->id);
		Arvore_pesquisa(subRaiz->pMaior, id);
	}
} 

//----------------------------------------------
//VETOR
array* Vetor_inicializar(){
	array* novoArray;
	novoArray = (array*) malloc(sizeof(array));
	novoArray -> capacidade = 10;
	novoArray -> quantidade = 0;
	novoArray -> elementos = (vetor*) malloc(sizeof(vetor)*10);
	return novoArray;

};
int Vetor_getCapacidade(array* array){
	return array ->capacidade;
}
int Vetor_getQuantidade(array* array){
	return array ->quantidade;
}


void Vetor_Realocar(array* novoArray, int i) {
	vetor *novoVetor = (vetor *) realloc(novoArray->elementos, sizeof(vetor)*i);
	if (novoVetor != NULL){
		novoArray->elementos = novoVetor;
	}else{
		exit(1);
	}
}

void Vetor_adicionaCoordenada(array* array, int pontokey, int pontocod){
	if (array->quantidade >= array->capacidade){
		array->capacidade = array->capacidade*2;
		Vetor_Realocar(array, array->capacidade);
	}
	array ->elementos[array->quantidade].key = pontokey;
	array ->elementos[array->quantidade].cod = pontocod;
	array -> quantidade++;

}
void Vetor_adicionaCoordenadak(array* array, int pontokey, int pontocod, int posicao){
	if (posicao >= array -> quantidade)
	{
		Vetor_adicionaCoordenada(array, pontokey, pontocod);
	}else{
		for (int i = array -> quantidade; i > posicao; i--){
			array -> elementos[i] = array -> elementos[i-1];
		}
		array -> elementos[posicao].key = pontokey;
		array -> elementos[posicao].cod = pontocod;
		array -> quantidade++;

	}
}

//----------------------------------------------
//PILHA
void pilha_push(int val){
	Elementos *n_topo = (Elementos*)malloc(sizeof(Elementos));
	n_topo -> topo = val;
	n_topo -> proximo = principal;
	principal  = n_topo;
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
	printf("\nTopo da pilha: %d\n", principal -> topo);
}

void pilha_show(){
	int pos = 0;
	Elementos *aux = principal;
	printf("\n");
	while (aux != NULL){
		pos++;
		printf("Posicao: %d - topo: %d\n", pos, aux->topo);
		aux = aux -> proximo;
		pilha_pop();
	}
}

//----------------------------------------------
//LISTA ENCADEADA
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

int lista_procurar(Lista* lista, int cod){
	int i, x=0;
	Elemento *p_aux;
	p_aux = lista->p_inicio;
	while (p_aux != NULL) {
		if (p_aux->codigo == cod){
			return p_aux->valor;
			x = 1;
		}
		p_aux = p_aux->p_prox;
	}
	if (x!=1){
		return -1;
	}
}

//-------------------------------------
//FUNÇÕES DO SISTEMA

