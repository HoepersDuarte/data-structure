#include <stdio.h>

int fat(int n);

int main(){
	printf("Fatorial de 5 : %d\n", fat(5));
	return 0;
}

int fat(int n){
	if (n==0)
		return 1;
	else 
		return n*fat(n-1);
}