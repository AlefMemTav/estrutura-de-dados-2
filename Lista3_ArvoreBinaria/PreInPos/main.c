#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

no* criarNo(int dado)
{
    no* novoNo = (no*) malloc(sizeof(no));
    novoNo->dado = dado;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

no* inserirNo(no* raiz, int dado)
{
    if (raiz == NULL)
    {
        return criarNo(dado);
    }
    else
    {
        if (dado < raiz->dado)
        {
            raiz->esq = inserirNo(raiz->esq, dado);
        }
        else
        {
            raiz->dir = inserirNo(raiz->dir, dado);
        }
        return raiz;
    }
}

void pre_ordem(no* raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    printf("%d ", raiz->dado);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}

void em_ordem(no* raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    em_ordem(raiz->esq);
    printf("%d ", raiz->dado);
    em_ordem(raiz->dir);
}

void pos_ordem(no* raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d ", raiz->dado);
}

int main()
{
    no* raiz = NULL;
    int numero;

    while (scanf("%d", &numero) != EOF)
    {
        raiz = inserirNo(raiz, numero);
    }

    pre_ordem(raiz);
    printf(".");
    printf("\n");

    em_ordem(raiz);
    printf(".");
    printf("\n");

    pos_ordem(raiz);
    printf(".");
    printf("\n");

    return 0;
}

