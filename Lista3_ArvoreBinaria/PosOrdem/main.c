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


void pos_ordem(no* raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    no* pilha1[100];
    no* pilha2[100];
    int topo1 = -1;
    int topo2 = -1;

    pilha1[++topo1] = raiz;

    while (topo1 >= 0)
    {

        no* noAtual = pilha1[topo1--];


        pilha2[++topo2] = noAtual;


        if (noAtual->esq != NULL)
        {
            pilha1[++topo1] = noAtual->esq;
        }


        if (noAtual->dir != NULL)
        {
            pilha1[++topo1] = noAtual->dir;
        }
    }


    while (topo2 >= 0)
    {
        no* noVisitado = pilha2[topo2--];
        printf("%d ", noVisitado->dado);
    }
}
