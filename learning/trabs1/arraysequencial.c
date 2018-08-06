#include <stdlib.h>
#include	"arraysequencial.h"


arraySeq* inicializar(){
	arraySeq* novoArray;
	novoArray = (arraySeq*) malloc(sizeof(arraySeq));
	novoArray -> capacidade = 10;
	novoArray -> quantidade = 0;
	novoArray -> pontos = (ponto*) malloc(sizeof(ponto)*10);
	return novoArray;

};
int getCapacidade(arraySeq* array){
	return array ->capacidade;
}
int getQuantidade(arraySeq* array){
	return array ->quantidade;
}
void adicionaCoordenada(arraySeq* array, int pontoX, int pontoY){
	array ->pontos[array->quantidade].x = pontoX;
	array ->pontos[array->quantidade].y = pontoY;
	array -> quantidade++;

}
void adicionaCoordenadak(arraySeq* array, int pontoX, int pontoY, int posicao){
	if (posicao >= array -> quantidade)
	{
		adicionaCoordenada(array, pontoX, pontoY);
	}else{
		for (int i = array -> quantidade; i > posicao; i--){
			array -> pontos[i] = array -> pontos[i-1];
		}
		array -> pontos[posicao].x = pontoX;
		array -> pontos[posicao].y = pontoY;
		array -> quantidade++;

	}
}

int busca(arraySeq* array, int indice){
	for (int i = 0; i < array -> quantidade; ++i)
	{
		if (array -> pontos[i].x == indice)
		{
			return array -> pontos[i].y;
		}
	}
}

// int getUltimoX(arraySeq* array){
// 	return array->pontos[array->quantidade-1].x;
// }
// int getUltimoY(arraySeq* array){
// 	return array->pontos[array->quantidade-1].y;
// }

