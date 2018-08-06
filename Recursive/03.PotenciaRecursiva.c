#include <stdio.h>

int potencia(int base, int expoente);

int main(){
	printf("base 2, expoente 5 = %d\n", potencia(2,5));
	return 0;
}

int potencia(int base, int expoente){
	if (expoente == 0)
		return 1;
	else
		return (base * potencia(base, expoente - 1));
}