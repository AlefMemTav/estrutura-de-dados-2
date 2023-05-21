#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


void pre_ordem(no* raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    no* pilha[100];
    int topo = -1;

    pilha[++topo] = raiz;

    while (topo >= 0)
    {

        no* noAtual = pilha[topo--];
        printf("%d ", noAtual->dado);


        if (noAtual->dir != NULL)
        {
            pilha[++topo] = noAtual->dir;
        }


        if (noAtual->esq != NULL)
        {
            pilha[++topo] = noAtual->esq;
        }
    }
}
