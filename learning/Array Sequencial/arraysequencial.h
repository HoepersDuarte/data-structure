//Definições de estruturas

typedef struct
{
	int x;
	int y;
}ponto;

typedef struct {
	int capacidade; //capacidade total de armazenamento do array
	int quantidade; //Número de elementos no array
	ponto *pontos;
	
}arraySeq;

//Prototipação de funcao
arraySeq* inicializar();
int getCapacidade(arraySeq*);
int getQuantidade(arraySeq*);
void adicionaCoordenada(arraySeq*, int, int);
int getUltimoX(arraySeq*);
int getUltimoY(arraySeq*);
void adicionaCoordenadak(arraySeq*, int, int, int);