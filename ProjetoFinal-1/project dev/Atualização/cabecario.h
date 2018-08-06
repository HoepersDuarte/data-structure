# include <stdio.h>
# include <stdlib.h>

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

//LISTA ENCADEADA
typedef struct elemento {
	int codigo;
	float valor;
	struct elemento *p_prox;
} Elemento;

typedef struct {
	Elemento *p_inicio;
} Lista;

//PILHA 
typedef struct pilha {
    int info;
    struct pilha *proximo;
} Elementos;

//VETOR
typedef struct {
	int cod;
	float velor;
}vetor;

typedef struct {
	int capacidade;		// Capacidade total de armazenamento do array
	int quantidade;		// Numeros de elementos no array
	vetor *elementos;
}array;

//----------------------------------------------

//PROTOTIPAÇÃO

//ARVORE
Arvore* Arvore_Inicializar();
Folha* Arvore_Inserir(Folha*, int);
void inOrder(Folha*);
Folha* Arvore_removerSubRaiz(Folha*);
Folha* Arvore_Remover(Folha*, int);

//LISTAENCADEADA
Elemento* Lista_criarElemento(int, float);
void Lista_Percorrer(Lista*);
void Lista_InserirInicio(Lista*, int, float);
void Lista_InserirFinal(Lista*, int, float);
void Lista_Remover(Lista*, int);
void Lista_Procurar(Lista*, int); // Mostrar o valor do código correspondente

//PILHA
void Pilha_Push();
void Pilha_Pop();
void Pilha_Top();
void Pilha_Show();

Elementos *principal = NULL;

//VETOR
array* Vetor_Inicializar();
void Vetor_Inserir(array*, int, float);
int Vetor_BuscaSequencial(array*, int);
int Vetor_BuscaBinaria(array*, int);