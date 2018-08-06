#include <stdio.h>
#include <stdlib.h>

void MergeSort(int v[], int n);
int criaHeap(int v[], int inicio , int final);

int main(){
	int v[8] = {45,56,12,43,95,19,8,67};
	int qtd = 8;
	MergeSort(v,qtd);
	for (int i = 0; i<qtd; ++i) {
		printf("%d\n", v[i]);
	}
	return 0;
}

void MergeSort(int v[], int n){

}

int criaHeap(int v[], int inicio, int final){

}