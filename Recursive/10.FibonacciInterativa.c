#include <stdio.h>

int fibonacci(int n);

int main(){
	printf("n: 6 - %d\n", fibonacci(30));
	return 0;
}
/*
// Teste de tempo

time_t t_inicial, t_final;
t_inicial = time( NULL );
*/
int fibonacci(int n){
	int i,aux,x=0,y=1;
	for (int i = 1; i < n; ++i){
		aux = x+y;
		x = y;
		y = aux;
	}
	return y;
}	
/*
t_final = time( NULL );
printf("Tempo = %f \n", difftime(t_final, t_inicial));
*/