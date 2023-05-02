#include <stdio.h>
#include <stdlib.h>

// Estrutura para um elemento na fila de prioridades
typedef struct
{
    int value;
    int priority;
} Item;

// Estrutura para a fila de prioridades
typedef struct
{
    Item *itens;
    int size;
    int capacity;
} QueueHeap;

// Função para criar um novo elemento na fila de prioridades
Item create_item(int value, int priority)
{
    Item i;
    i.value = value;
    i.priority = priority;
    return i;
}

// Função para criar uma nova fila de prioridades
QueueHeap create_priority_queue(int capacity)
{
    QueueHeap q;
    q.size = 0;
    q.capacity = capacity;
    q.itens = malloc(sizeof(Item) * capacity);
    return q;
}

// Função para liberar a memória alocada pela fila de prioridades
void free_priority_queue(QueueHeap q)
{
    free(q.itens);
}

// Função para trocar dois elementos na fila de prioridades
void swap(Item *itens, int i, int j)
{
    Item temp = itens[i];
    itens[i] = itens[j];
    itens[j] = temp;
}

// Função para mover um elemento para cima na árvore de prioridades até sua posição correta
void sift_up(Item *itens, int indice)
{
    while (indice > 0 && itens[indice].priority > itens[(indice - 1) / 2].priority)
    {
        swap(itens, indice, (indice - 1) / 2);
        indice = (indice - 1) / 2;
    }
}

// Função para mover um elemento para baixo na árvore de prioridades até sua posição correta
void sift_down(Item *itens, int tamanho, int indice)
{
    while (indice * 2 + 1 < tamanho)
    {
        int filhoEsquerdo = indice * 2 + 1;
        int filhoDireito = indice * 2 + 2;
        int maiorFilho = filhoEsquerdo;
        if (filhoDireito < tamanho && itens[filhoDireito].priority > itens[filhoEsquerdo].priority)
        {
            maiorFilho = filhoDireito;
        }
        if (itens[indice].priority < itens[maiorFilho].priority)
        {
            swap(itens, indice, maiorFilho);
            indice = maiorFilho;
        }
        else
        {
            break;
        }
    }
}

// Função para adicionar um elemento à fila de prioridades
void add_item(QueueHeap *q, Item i)
{
    if (q->size >= q->capacity)
    {
        printf("Fila de prioridades cheia.\n");
        return;
    }

    // Adiciona o elemento ao final da fila
    q->itens[q->size] = i;
    q->size++;

    // Move o novo elemento para cima na árvore até sua posição correta
    sift_up(q->itens, q->size - 1);

}

// Função para remover e retornar o elemento de maior prioridade da fila de prioridades
Item remove_item(QueueHeap *q)
{
    if (q->size <= 0)
    {
        printf("Fila de prioridades vazia.\n");
        return create_item(0, 0);
    }

    // Remove o elemento de maior prioridade (raiz da árvore)
    Item i = q->itens[0];
    q->size--;

    // Move o último elemento da árvore para a raiz e o desce até sua posição correta
    q->itens[0] = q->itens[q->size];

    sift_down(q->itens, q->size, 0);

    return i;
}

int main()
{
    QueueHeap q = create_priority_queue(10);

    add_item(&q, create_item(5, 2));
    add_item(&q, create_item(7, 1));
    add_item(&q, create_item(3, 3));

    while (q.size > 0)
    {
        Item item = remove_item(&q);
        printf("Valor: %d, Prioridade: %d\n", item.value, item.priority);
    }

    free_priority_queue(q);

    return 0;
}
