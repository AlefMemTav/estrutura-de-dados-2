#include <stdio.h>
#include <stdlib.h>

#define M 19

typedef struct
{
    int matricula; // key of hash table
    char nome[50];
} Pessoa;

Pessoa hash_table[M];

void initialize_table()
{
    int i= 0;
    for(i; i < M; i++)
    {
        hash_table[i].matricula = -1;
    }
}

int espalhamento(int key)
{
    return key%M;
}

Pessoa create_pessoa()
{
    Pessoa p;
    printf("Matricula \t");
    scanf("%d", &p.matricula);
    scanf("%c");
    printf("Nome \t");
    fgets(p.nome, 50, stdin);
    return p;
}

void insert_table()
{
    Pessoa p = create_pessoa();
    int i = espalhamento(p.matricula);
    while(hash_table[i].matricula != -1)
    {
        i = espalhamento(i+1);
    }
    hash_table[i] = p;
}

Pessoa* search_pessoa(int key)
{
    int i = espalhamento(key);
    while(hash_table[i].matricula != -1)
    {
        if(hash_table[i].matricula == key)
        {
            return &hash_table[i];
        }
        else
        {
            i = espalhamento(i+1);
        }
    }
    return NULL;
}

void print_table()
{
    int i = 0;
    for(i; i < M; i++)
    {
        if(hash_table[i].matricula != -1)
        {
            printf("\n%2d = %3d \t %s", i, hash_table[i].matricula, hash_table[i].nome);
        }
        else
        {
            printf("%d = \n", i);
        }
    }
}

void clear()
{
    system("cls || clear");
}

void limpa_buffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Lê e descarta caracteres do buffer até encontrar uma nova linha ou o fim do arquivo
    }
}

void menu()
{
    int op, key;
    Pessoa *p;
    initialize_table();
    do
    {
        printf("1 - Inserir \t 2 - Buscar \t 3 - Imprimir \t 0 - Sair \n");
        scanf("%d", &op);
        switch(op)
        {
        case 0:
            printf("Finalizado.\n");
            break;
        case 1:
            insert_table();
            getchar();
            clear();
            break;
        case 2:
            printf("Chave \t");
            scanf("%d", &key);
            p = search_pessoa(key);
            if(p)
            {
                printf("%d \t %s \n", p->matricula, p->nome);
            }
            else
            {
                printf("Nenhuma pessoa achada.\n");
            }
            limpa_buffer();
            getchar();
            clear();
            break;
        case 3:
            print_table();
            limpa_buffer();
            getchar();
            clear();
            break;
        default:
            clear();
            break;
        }
    }
    while(op != 0);
}

int main()
{
    menu();
    return 0;
}
