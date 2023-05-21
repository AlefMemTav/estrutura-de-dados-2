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


void em_ordem(no* raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    no* pilha[100];
    int topo = -1;

    no* noAtual = raiz;
    bool feito = false;

    while (!feito)
    {
        if (noAtual != NULL)
        {

            pilha[++topo] = noAtual;
            noAtual = noAtual->esq;
        }
        else
        {
            if (topo >= 0)
            {

                noAtual = pilha[topo--];
                printf("%d ", noAtual->dado);


                noAtual = noAtual->dir;
            }
            else
            {
                feito = true;
            }
        }
    }
}
