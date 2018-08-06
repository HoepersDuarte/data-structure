#include <stdio.h>

int potencia(int base, int expoente);

int main(){
	printf("base 2, expoente 5 = %d\n", potencia(2,5));
	return 0;
}

int potencia(int base, int expoente) {
	int i, valor = base;
	for (i=1; i<expoente; ++i) {
		valor = valor * base;
	}
	return valor;
}