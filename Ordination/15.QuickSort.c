#include <stdio.h>
#include <stdlib.h>

int Partition(int *, int , int );
void QuickSort(int *, int , int );

int main(){
	int v[8] = {45,56,12,43,95,19,8,67};
	int qtd = 8;
	QuickSort(v,0,qtd-1);
	for (int i = 0; i<qtd; ++i) {
		printf("%d\n", v[i]);
	}
	return 0;
}

void QuickSort(int v[], int inicio, int fim){
	int pivot;
	if (inicio<fim) {
		pivot = Partition(v,inicio, fim);
		QuickSort(v, inicio, pivot);
		QuickSort(v, pivot+1, fim);
	}
	else
		return;
}

int Partition(int v[], int inicio, int fim){
	int pivo, i, j, auxi;
	pivo = v[inicio];
	i = inicio - 1;
	j = fim +1 ;
	for (;;){
		do { j--; } while (v[j]>pivo);
		do { i++; } while (v[i]<pivo);

		if (i < j) {
			auxi = v[i];
			v[i] = v[j];
			v[j] = auxi;
		}
		else
			return j;
	}
}