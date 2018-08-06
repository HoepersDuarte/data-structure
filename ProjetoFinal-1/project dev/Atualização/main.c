# include <stdio.h>
# include <stdlib.h>
# include "cabecario.h"

//----------------------------------------------


//Chamada do menu
int menu();

// Fução principal
int main(){
	array* vetor;
	Arvore* Tree;

	int op;
	op = menu();
	while (op != 0){
		switch(op){
			case 0:
				break;
			case 1:
				vetor = Vetor_Inicializar();
				Tree = Arvore_Inicializar();
				break;
			case 2:
				break;
			case 4:
				break;
			case 5:
				break;	
			case 6:
				break;	
			case 7:
				break;
			case 8:
				break;	
		}

	}

}

//criação do menu
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

//VETOR
array* Vetor_Inicializar() {
	array* novoArray;
	novoArray = (array*) malloc(sizeof(array));
	novoArray->capacidade = 10;
	novoArray->quantidade = 0;
	novoArray->elementos = (vetor*) malloc(sizeof(vetor) * 10);
	return novoArray;	
}

void Vetor_Realocar(array* novoArray, int i) {
	vetor *novoVetor = (vetor *) realloc(novoArray->elementos, sizeof(vetor)*i);
	if (novoVetor != NULL){
		novoArray->elementos = novoVetor;
	}else{
		exit(1);
	}
}

void Vetor_Inserir(array* vetor, int cod, float velor) {
	int pos = vetor->quantidade;
	if (vetor->quantidade >= vetor->capacidade){
		vetor->capacidade = vetor->capacidade*2;
		Vetor_Realocar(vetor, vetor->capacidade);
	}
	while ( (vetor->elementos[pos-1].cod > cod) && (pos > 0) )
		vetor->elementos[pos] = vetor->elementos[--pos];
	vetor->elementos[pos].cod = cod;
	vetor->elementos[pos].velor = velor;
	vetor->quantidade++;
}

int Vetor_BuscaSequencial(array* vetor, int cod) {
	int pos = 0;
   	while (pos < vetor->quantidade && vetor->elementos[pos].cod < cod) 
   		++pos;
   	return (vetor->elementos[pos].cod == cod)?pos:-1;
}

int Vetor_BuscaBinaria (array* vetor, int cod) { 
   int p1 = -1, p2 = vetor->quantidade;
   while (p1 < p2-1) {  
      int meio = (p1 + p2)/2;
      if (vetor->elementos[meio].cod < cod) p1 = meio;
      else p2 = meio; 
   }
   return (vetor->elementos[p2].cod == cod)?p2:-1;
}

// ----------------------------------------

//PILHA
void Pilha_Push(){
	int val;
	printf("Insira o info desejado: ");
	scanf("%d", &val);
	Elementos *n_topo = (Elementos*)malloc(sizeof(Elementos));
	n_topo -> info = val;
	n_topo -> proximo = principal;
	principal  = n_topo;
	printf("\nValor inserido!\n");
    getchar();
}
void Pilha_Pop(){
	Elementos *aux = (Elementos*)malloc(sizeof(Elementos));
	aux = principal -> proximo;
	free(principal);
	principal = aux;
	printf("\nRemovido!\n");
	getchar();
}
void Pilha_Top(){
	printf("\nTopo: %d\n", principal -> info);
}
void Pilha_Show(){
	int pos = 0;
	Elementos *aux = principal;
	printf("\n");
	while (aux != NULL){
		pos++;
		printf("Posicao: %d - info: %d\n", pos, aux->info);
		aux = aux -> proximo;
	}
}

// ----------------------------------------

//LISTA ENCADEADA
void Lista_Percorrer(Lista* lista) {
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

Elemento* Lista_criarElemento(int cod, float val) {
	Elemento* novoElemento;
	novoElemento = (Elemento*) malloc ( sizeof(Elemento) );
	novoElemento->codigo = cod;
	novoElemento->valor = val;
	novoElemento->p_prox = NULL;
	return novoElemento;
}

void Lista_InserirInicio(Lista* lista, int cod, float val) {
	Elemento* novoElemento = Lista_criarElemento(cod, val);
	novoElemento->p_prox = lista->p_inicio;
	lista->p_inicio = novoElemento;
}

void Lista_InserirFinal(Lista* lista, int cod, float val) {
	if (lista->p_inicio == NULL)
		Lista_InserirInicio(lista, cod, val);
	else {
		Elemento* novoElemento = Lista_criarElemento(cod, val);
		Elemento *p_aux = lista->p_inicio;
		while (p_aux->p_prox != NULL) {
			p_aux = p_aux->p_prox;
		}
		p_aux->p_prox = novoElemento;
	}
}

void Lista_Remover(Lista *lista, int cod) {
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

void Lista_Procurar(Lista *lista, int cod) {
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

// ----------------------------------------

//ARVORE
Arvore* Arvore_Inicializar() {
	Arvore* pAux;
	pAux = (Arvore*) malloc (sizeof(Arvore));
	pAux->raiz = NULL;
	return pAux;
}

Folha* Arvore_Inserir(Folha* subRaiz, int id){
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
		subRaiz->pMenor = Arvore_Inserir(subRaiz->pMenor, id);
		subRaiz->pMenor->pPai = subRaiz;
	} else {
		subRaiz->pMaior = Arvore_Inserir(subRaiz->pMaior, id);
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

Folha* buscarPai(Folha* subRaiz, int id) {
    if (subRaiz == NULL || subRaiz->id == id)
       return subRaiz->pPai;
    if (subRaiz->id > id)
       return buscarPai (subRaiz->pMenor, id);
    else
       return buscarPai (subRaiz->pMaior, id);
}

Folha* Arvore_Remover(Folha* subRaiz, int id) {
	Folha* pai = buscarPai(subRaiz, id);
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
