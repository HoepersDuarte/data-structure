#include <stdio.h>

void SelectSort(int v[], int n);

int main(){
	int v[5] = {8,1,9,4,2};
	SelectSort(v,5);
	for (int i = 0; i<5; ++i) {
		printf("%d\n", v[i]);
	}
	return 0;
}

void SelectSort(int v[], int n){
	int i, j, auxi, minimo;
	for (i=0; i<n-1; ++i){
		minimo = i;
		for (j = i+1; j<n ; ++j){
			if (v[j]<v[minimo]){
				minimo = j;
			}
		}
		auxi = v[i];
		v[i] = v[minimo];
		v[minimo] = auxi;		
	}
}
