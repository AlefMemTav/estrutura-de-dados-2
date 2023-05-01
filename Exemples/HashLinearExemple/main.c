#include <stdio.h>
#include <stdlib.h>

#define M 19

/**
* The type Person
*/
typedef struct
{
    int matricula; // key of hash table
    char nome[50]; // name of the person
} Pessoa;

/**
* The hash table
*/
Pessoa hash_table[M]; // a hash table of Person

/**
* Initializes the hash table keys with -1
*/
void initialize_table()
{
    int i= 0;
    for(i; i < M; i++)
    {
        hash_table[i].matricula = -1; // initializes the hash table with -1
    }
}

int espalhamento(int key)
{
    return key%M;
}

/**
* Creates a new person
*/
Pessoa create_pessoa()
{
    Pessoa p;
    printf("Matricula \t");
    scanf("%d", &p.matricula);
    fflush(stdin); // clear keyboard buffer
    printf("Nome \t");
    fgets(p.nome, 50, stdin);
    return p;
}

/**
* Inserts a person on the hash table
*/
void insert_pessoa()
{
    Pessoa p = create_pessoa();
    int i = espalhamento(p.matricula);
    while(hash_table[i].matricula != -1)
    {
        i = espalhamento(i+1);
    }
    hash_table[i] = p;
}

/**
* Searches for a person
*/
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

/**
* Prints the hash table with all key-values
*/
void print_table()
{
    int i = 0;
    for(i; i < M; i++)
    {
        if(hash_table[i].matricula != -1)
        {
            printf("%1d = %3d \t %s", i, hash_table[i].matricula, hash_table[i].nome);
        }
        else
        {
            printf("%d = \n", i);
        }
    }
}

void clear()
{
    system("cls || clear"); // clears the user's screen.
}

void menu()
{
    int op, key;
    Pessoa *p;
    initialize_table();
    do
    {
        clear();
        printf("1 - Inserir \t 2 - Buscar \t 3 - Imprimir \t 0 - Sair \n");
        scanf("%d", &op);
        clear();
        switch(op)
        {
        case 0:
            printf("Finalizado.\n");
            break;
        case 1:
            insert_pessoa(); // on the hash table
            getchar(); // waits for a character from the user.
            break;
        case 2:
            printf("Chave \t");
            scanf("%d", &key);
            p = search_pessoa(key);
            if(p)
            {
                printf("%d \t %s", p->matricula, p->nome);
            }
            else
            {
                printf("Nenhuma pessoa achada.\n");
            }
            fflush(stdin); // clear keyboard buffer
            getchar(); // waits for a character from the user
            break;
        case 3:
            print_table();
            fflush(stdin); // clear keyboard buffer
            getchar(); // waits for a character from the user
            break;
        default:
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
