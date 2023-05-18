#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if(root == NULL)
    {
        return root = createNode(value);
    }
    else
    {
        if(value < root->value)
        {
            root->left = insert(root->left, value);
        }
        if(value > root->value)
        {
            root->right = insert(root->right, value);
        }
        return root;
    }
    return NULL;
}

void printBtree(Node* root)
{
    if(root != NULL)
    {
        printBtree(root->left);
        printf("%d ", root->value);
        printBtree(root->right);
    }
}

int main()
{
    int op, valor;
    Node* root = NULL;

    do
    {
        printf("\n\t 0 - SAIR \t 1 - INSERIR \t 2 - IMPRIMIR \n");
        scanf("%d", &op);

        switch(op)
        {
        case 0:
            printf("Finalizado.\n");
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            root = insert(root, valor);
            break;
        case 2:
            printf("\t Arvore binaria:\n");
            printBtree(root);
            break;
        default:
            printf("Invalido\n");

        }
    }
    while(op != 0);

    return 0;
}
