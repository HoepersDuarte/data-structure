#include <stdio.h>

int maior(int v[], int n);

int main(){
	int v[5] = {8,1,9,4,2}; 
	printf("%d\n", maior(v,5));
	return 0;
}

int maior(int v[], int n){
	int m;
	if (n==1)
		return 0;
	else {
		m = maior(v,n-1);
		if (m>v[n-1])
			return m;
		else 
			return v[n-1];
	}
}