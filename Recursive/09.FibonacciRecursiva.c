#include <stdio.h>
#include <time.h>

int fibonacci(int n);

int main(){
	printf("n: 20 - %d\n", fibonacci(30));
	return 0;
}

/*
// Teste de tempo
time_t t_inicial, t_final;
t_inicial = time( NULL );
*/
int fibonacci(int n){
	if (n==0)
		return 0;
	else if (n==1)
		return 1;
	else
		return fibonacci(n-1)+fibonacci(n-2);
}	
/*
t_final = time( NULL );
printf("Tempo = %f \n", difftime(t_final, t_inicial));
*/