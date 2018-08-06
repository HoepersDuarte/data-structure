#include <stdio.h>
#include <stdlib.h>

void heapSort(int v[], int n);
int criaHeap(int v[], int inicio , int final);

int main(){
	int v[8] = {45,56,12,43,95,19,8,67};
	int qtd = 8;
	heapSort(v,qtd);
	for (int i = 0; i<qtd; ++i) {
		printf("%d\n", v[i]);
	}
	return 0;
}

void heapSort(int v[], int n){
	int i, auxi;
	for (i=(n-1)/2; i>=0; --i){
		criaHeap(v,i,n-1);
	}

	for (i=n-1; i>=1; --i){
		auxi = v[0];
		v[0] = v[i];
		v[i] = auxi;
		criaHeap(v, 0, i-1);
	}
}

int criaHeap(int v[], int inicio, int final){
	int auxi, filho;
	auxi = v[inicio];
	filho = inicio * 2 +1;
	while (filho<=final) {
		if (filho<final) {
			if (v[filho]<v[filho+1]) {
				filho = filho + 1;
			}
		}
		if (auxi<v[filho]){
			v[inicio] = v[filho];
			inicio = filho;
			filho = inicio*2+1;
		}
		else {
			filho = final +1;
		}
	}
	v[inicio]= auxi;
}