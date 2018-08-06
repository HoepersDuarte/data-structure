#include <stdio.h>

int maior(int v[], int n);

int main(){
	int v[5] = {8,1,9,4,2}; 
	printf("%d\n", maior(v,5));
	return 0;
}

int maior(int v[], int n){
	int m = v[0];
	for (int i=0; i<n ; ++i){
		if (m<v[i]){
			m = v[i];
		}
	}
	return m;
}