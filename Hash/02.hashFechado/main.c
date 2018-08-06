#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    int matricula;
    char nome;
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
    printf("Criar Tabelha Hash\n");
    Hash *ha = criaHash(608);
    Aluno al;
    al.matricula = 231;
    printf("\ninserir matricula 231\n");
    insereHashSemTratamentoColisao(ha, al);

    printf("\nbusca numero 1\n");
    buscaHashSemTratamentoColisao(ha, &al, 123);

    printf("\nbusca numero 2\n");
    buscaHashSemTratamentoColisao(ha, &al, 231);

    printf("\nremove matricula 231\n");
    removeHashSemTratamentoColisao(ha, &al, 231);

    printf("\nbusca numero 3\n");
    buscaHashSemTratamentoColisao(ha, &al, 231);

    printf("\nlibera tabela \n");
    liberaHash(ha);
    return 0;
}

int criaPos(int key, int tamanho)
{
    int chave = key % tamanho;
    printf("acha/cria a chave/pos: %d\n", chave);
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
            printf("erro linha 65\n");
            return NULL;
        }
        ha->qtd = 0;
        for (i = 0; i < tamanho; i++)
        {
            ha->itens[i] = NULL;
        }
        printf("criaHash ok\n");
        return ha;
    }
    printf("erro linha 76\n");
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
        printf("LiberaHash ok\n");
    }
}

int insereHashSemTratamentoColisao(Hash *ha, Aluno al)
{
    if (ha == NULL || ha->qtd == ha->TamanhoTabela)
    {
        printf("erro linha 102\n");
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
    printf("inserirHash ok\n");
    return 1;
}

int buscaHashSemTratamentoColisao(Hash *ha, Aluno *al, int matricula)
{
    if (ha != NULL)
    {
        int pos = criaPos(matricula, ha->TamanhoTabela);
        printf("valor de ha->intens[pos]: %d \n", ha->itens[pos]);
        if (ha->itens[pos] != NULL)
        {
            *al = *(ha->itens[pos]);
            printf("achou na pos: %d \n", pos);
            return 1;
        }
    }
    printf("nao achou\n");
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
        printf("removeHash ok \n");
        return 1;
    }
    printf("erro linha 145 \n");
    return 0;
}