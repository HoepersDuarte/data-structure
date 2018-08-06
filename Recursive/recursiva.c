# include <stdio.h>

int funcao(int, int);

int main (){
	int n, valor, cont = 0;
	n = 25;
	valor = funcao(n, cont);
	printf("Valor = %d;\n", valor);
	return 0;
}


int funcao(int n, int cont){
	if (n==1) {
		return 0;
	}
	else {
		cont += 1;
		printf("cont - %d\n", cont);
		return funcao((n/2), cont) +1;
	}
}