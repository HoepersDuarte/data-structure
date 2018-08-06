#include <stdio.h>

void InsertSort(int v[], int n);

int main(){
	int v[5] = {8,1,9,4,2};
	InsertSort(v,5);
	for (int i = 0; i<5; ++i) {
		printf("%d\n", v[i]);
	}
	return 0;
}

void InsertSort(int v[], int n){
	int i, auxi, j;
	for (i=1; i<n; ++i) {
		auxi = v[i];
		j = i-1;
		while(j>=0 && v[j]>auxi){
			v[j+1] = v[j];
			j -= 1;
		}
		v[j+1] = auxi;
	}
}
