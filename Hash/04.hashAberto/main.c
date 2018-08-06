#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    int matricula;
    char nome;
    struct aluno *p_prox;
} Aluno;

typedef struct hash
{
    int qtd, TamanhoTabela;
    Aluno **itens;
} Hash;

Hash *criaHash(int);
void liberaHash(Hash *);
int criaPos(int, int);
int insereHashSemTratamentoColisao(Hash *, Aluno);
int buscaHashSemTratamentoColisao(Hash *, Aluno *, int);
int removeHashSemTratamentoColisao(Hash *, Aluno *, int);
int main();

int main()
{
    Hash *ha = criaHash(608);
    Aluno al;
    al.matricula = 231;
    insereHashSemTratamentoColisao(ha, al);
    buscaHashSemTratamentoColisao(ha, &al, 123);
    buscaHashSemTratamentoColisao(ha, &al, 231);
    removeHashSemTratamentoColisao(ha, &al, 231);
    buscaHashSemTratamentoColisao(ha, &al, 231);
    liberaHash(ha);
    return 0;
}

int criaPos(int key, int tamanho)
{
    int chave = key % tamanho;
    return chave;
}

Hash *criaHash(int tamanho)
{
    Hash *ha = (Hash *)malloc(sizeof(Hash));
    if (ha != NULL)
    {
        int i;
        ha->TamanhoTabela = tamanho;
        ha->itens = (Aluno **)malloc(tamanho * sizeof(Aluno *));
        if (ha->itens == NULL)
        {
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for (i = 0; i < tamanho; i++)
        {
            ha->itens[i] = NULL;
        }
        return ha;
    }
    return 0;
}

void liberaHash(Hash *ha)
{
    if (ha != NULL)
    {
        int i;
        for (i = 0; i < ha->TamanhoTabela; i++)
        {
            if (ha->itens[i] != NULL)
            {
                free(ha->itens[i]);
            }
        }
        free(ha->itens);
        free(ha);
    }
}

int insereHashSemTratamentoColisao(Hash *ha, Aluno al)
{
    if (ha == NULL || ha->qtd == ha->TamanhoTabela)
    {
        return 0;
    }
    int chave = al.matricula;
    int pos = criaPos(chave, ha->TamanhoTabela);
    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));
    if (novo == NULL)
        return 0;
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int buscaHashSemTratamentoColisao(Hash *ha, Aluno *al, int matricula)
{
    if (ha != NULL)
    {
        int pos = criaPos(matricula, ha->TamanhoTabela);
        if (ha->itens[pos] != NULL)
        {
            *al = *(ha->itens[pos]);
            return 1;
        }
    }
    return 0;
}

int removeHashSemTratamentoColisao(Hash *ha, Aluno *al, int matricula)
{
    if (buscaHashSemTratamentoColisao(ha, al, matricula) == 1)
    {
        int pos = criaPos(matricula, ha->TamanhoTabela);
        al = ha->itens[pos];
        free(al);
        ha->itens[pos] = NULL;
        return 1;
    }
    return 0;
}