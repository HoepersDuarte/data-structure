#include <stdio.h>

void ShellSort(int v[], int n);

int main(){
	int qtd = 8;
	int v[8] = {45,56,12,43,95,19,8,67};
	ShellSort(v,qtd);
	for (int i = 0; i<qtd; ++i) {
		printf("%d\n", v[i]);
	}
	return 0;
}

void ShellSort(int v[], int n){
	int i, j, h = 1;
	int auxi;
	do {
		h = h*3 + 1;
	} while (h<n);
	
	do {
		h = (h - 1) / 3;
		for (i = h; i < n; ++i) {
			auxi = v[i];
			j = i;
			while(v[j-h]>auxi){
				v[j] = v[j-h];
				j -= h;
				if (j<h){
					break;
				}
			}
			v[j]=auxi;	
		}	
	} while (h>0);
}

