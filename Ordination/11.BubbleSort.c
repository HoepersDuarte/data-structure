#include <stdio.h>

void BubbleSort(int v[], int n);
void BubbleSortInvertido(int v[], int n);

int main(){
	int v[5] = {8,1,9,4,2};
	BubbleSort(v,5);
	for (int i = 0; i<5; ++i) {
		printf("%d\n", v[i]);
	}
	/*
	BubbleSortInvertido(v,5);
	for (int i = 0; i<5; ++i) {
		printf("%d\n", v[i]);
	}
	*/
	return 0;
}

void BubbleSort(int v[], int n){
	int fim, i;
	for (fim=n-1; fim>0; --fim){
		for (i=0; i<fim; ++i) {
			if (v[i]<v[i+1]){
				int auxi = v[i];
				v[i] = v[i+1];
				v[i+1] = auxi;
			}
		}
	}
}

void BubbleSortInvertido(int v[], int n){
	int fim, i;
	for (fim=0; fim<n; ++fim){
		for (i=n-1; i>fim; --i) {
			if (v[i]>v[i-1]){
				int auxi = v[i];
				v[i] = v[i-1];
				v[i-1] = auxi;
			}
		}
	}
}
