#include <stdio.h>

int multiplicacao(int m, int n);

int main(){
	printf("M: 5, N: 3 - %d\n", multiplicacao(5,3));
	return 0;
}

int multiplicacao(int m, int n){
	if (n==0){
		return 0;
	}
	else {
		return (m + multiplicacao(m,n-1));
	}
}