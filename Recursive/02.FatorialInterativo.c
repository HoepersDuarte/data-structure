#include <stdio.h>

int fat(int n);

int main(){
	printf("Fatorial de 5 : %d\n", fat(5));
	return 0;
}

int fat(int n){
	int i, x;
	x = 1;
	for (i = 2; i<=n; ++i)
		x = x*i;
	return x;
}