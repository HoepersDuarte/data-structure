typedef struct aluno {
	int mat;
	char nome;
	Aluno *prox;
}Aluno;

typedef struct hash {
	int qtd, TABLE_SIZE;
	Aluno **itens; 
}Hash;

Hash* criaHash(int);
int chaveDivisao(int, int);
int buscaHash(Hash*, int);
int insereHash(Hash*, Aluno);
int liberaHash(Hash*);