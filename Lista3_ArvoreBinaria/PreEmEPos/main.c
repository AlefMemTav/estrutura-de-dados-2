#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char valor;
    struct no* esq;
    struct no* dir;
} No;

No* criarNo(char valor)
{
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

int buscarPosicao(char* sequencia, int inicio, int fim, char valor)
{
    for (int i = inicio; i <= fim; i++)
    {
        if (sequencia[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

No* reconstruirArvore(char* preOrdem, char* emOrdem, int inicio, int fim, int* indice)
{
    if (inicio > fim)
    {
        return NULL;
    }

    No* no = criarNo(preOrdem[*indice]);
    (*indice)++;

    if (inicio == fim)
    {
        return no;
    }

    int posicao = buscarPosicao(emOrdem, inicio, fim, no->valor);

    no->esq = reconstruirArvore(preOrdem, emOrdem, inicio, posicao - 1, indice);
    no->dir = reconstruirArvore(preOrdem, emOrdem, posicao + 1, fim, indice);

    return no;
}

void percursoPosOrdem(No* raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    percursoPosOrdem(raiz->esq);
    percursoPosOrdem(raiz->dir);
    printf("%c", raiz->valor);
}

int main()
{
    int casos;
    scanf("%d", &casos);

    for (int i = 0; i < casos; i++)
    {
        int numNos;
        scanf("%d", &numNos);

        char preOrdem[53], emOrdem[53];
        scanf("%s %s", preOrdem, emOrdem);

        int indice = 0;
        No* raiz = reconstruirArvore(preOrdem, emOrdem, 0, numNos - 1, &indice);

        percursoPosOrdem(raiz);
        printf("\n");
    }

    return 0;
}
