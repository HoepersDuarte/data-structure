#include <stdio.h>
#include <stdlib.h>

//Definições de estruturas
typedef struct {
	int key; 
	int cod; 
}vetor;

typedef struct {
	int capacidade; //capacidade total de armazenamento do array
	int quantidade; //Número de elementos no array
	vetor *elementos;
}array;

//Prototipação de funcao
array* Vetor_inicializar();
int Vetor_getCapacidade(array*);
int Vetor_getQuantidade(array*);
void Vetor_adicionaCoordenada(array*, int, int);
int Vetor_getUltimokey(array*);
int Vetor_getUltimoY(array*);
void Vetor_adicionaCoordenadak(array*, int, int, int);

//Prototipação de funções
int menu();

//Inicio do programa principal
int main()
{
	array* coordenadas;
	int key, cod, posicao;
	do
	{
		switch(menu()){
			case 0:
				return 1;
			case 1:
				coordenadas = Vetor_inicializar();
				printf("Vetor_inicializar...\n");
				break;
			case 2:
				printf("Capacidade total: %d.\n", Vetor_getCapacidade(coordenadas));
				break;
			case 3:
				printf("Quantidade de elementos: %d.\n", Vetor_getQuantidade(coordenadas));
				break;
			case 4:
				printf("Informe coordenadas: ");
				scanf("%d", &key);
				scanf("%d", &cod);
				Vetor_adicionaCoordenada(coordenadas, key, cod);
				break;
			case 5:
				printf("Informe coordenadas: ");
				scanf("%d", &key);
				scanf("%d", &cod);
				printf("Infome a posicao: ");
				scanf("%d", &posicao);
				Vetor_adicionaCoordenadak(coordenadas, key, cod, posicao);
				break;
			case 6:
				for (int i=0; i<coordenadas->quantidade; i++){
					printf("(%d, %d) ", coordenadas->elementos[i].key, coordenadas->elementos[i].cod );
				}
				printf("\n");
				break;
			default:
				break;

		}
	} while (1==1);
	return 0;
}
//Fim do programa principal

//Inicio das funções
int menu(){
	int op;
	printf("1 - Vetor_Inicializar\n");
	printf("2 - Capacidade de elementos\n");
	printf("3 - Quantidade de elementos\n");
	printf("4 - Adicionar coordenadas - FIM\n");
	printf("5 - Adicionar coordenadas - KEY\n");
	printf("6 - Mostrar array\n");
	printf("\n0 - Sair\n");	
	printf("Opcao: ");
	scanf("%d", &op);
	return (op);

}
//Fim das funções


array* Vetor_inicializar(){
	array* novoArray;
	novoArray = (array*) malloc(sizeof(array));
	novoArray -> capacidade = 3;
	novoArray -> quantidade = 0;
	novoArray -> elementos = (vetor*) malloc(sizeof(vetor)*3);
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
// int Vetor_getUltimokey(array* array){
// 	return array->elementos[array->quantidade-1].key;
// }
// int Vetor_getUltimoY(array* array){
// 	return array->elementos[array->quantidade-1].cod;
// }

