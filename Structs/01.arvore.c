#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct folha {
	int id;
	struct folha* pMenor;
	struct folha* pMaior;
	struct folha* pPai;
}Folha;

typedef struct {
	Folha* raiz;
}Arvore;

Arvore* Arvore_inicializar();
Folha* Arvore_inserir(Folha*, int);
void inOrder(Folha*);
void preOrder(Folha*);
void posOrder(Folha*);
Folha* Arvore_removerSubRaiz(Folha*);
Folha* Arvore_remover(Folha*, int);
int Arvore_pesquisa (Folha *subRaiz, int id);


int main() {
	Arvore* minhaArvore;
	int i, aleatorio;
	minhaArvore = Arvore_inicializar();
	for (i=0;i<10;i++){
		aleatorio = rand() % 1000;
		printf("aleatorio: %d\n", aleatorio); 
		minhaArvore->raiz = Arvore_inserir(minhaArvore->raiz, aleatorio);		
	}
	printf("\n");
	printf("\n");
	printf("in ordem\n");
	inOrder(minhaArvore->raiz);
	printf("\n");
	printf("pre ordem\n");
	preOrder(minhaArvore->raiz);
	printf("\n");
	printf("pos ordem\n");
	posOrder(minhaArvore->raiz);
	printf("\n");
	


	printf("procurar %d\n", aleatorio);
	Arvore_pesquisa(minhaArvore->raiz, aleatorio);
	printf("\n");
	minhaArvore->raiz = Arvore_remover(minhaArvore->raiz, aleatorio);
	inOrder(minhaArvore->raiz);
}

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
	if (subRaiz->id == id) // achou
		printf("%d\n", subRaiz->id);
	else if (id < subRaiz->id) {
		printf("%d\n", subRaiz->id);
		Arvore_pesquisa(subRaiz->pMenor, id);
	}
	else {
		printf("%d\n", subRaiz->id);
		Arvore_pesquisa(subRaiz->pMaior, id);
	}
} 