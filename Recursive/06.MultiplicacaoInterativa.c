#include <stdio.h>

int multiplicacao(int m, int n);

int main(){
	printf("M: 5, N: 3 - %d\n", multiplicacao(5,3));
	return 0;
}

int multiplicacao(int m, int n){
	int valor = m;
	for (int i = 1; i < n; ++i) {
		valor = valor+m;
	}
	return valor;
}