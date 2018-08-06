#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    int mat;
    char name;
}Aluno;


int hash(int, int);
int main();

int main() {
    int chave = 212, tamanho = 97;
    
    printf("%d", hash(chave, tamanho));
    return 1;
}

int hash(int key, int m){
    return key % m;
}