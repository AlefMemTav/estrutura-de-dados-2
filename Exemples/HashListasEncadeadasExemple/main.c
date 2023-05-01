#include <stdio.h>
#include <stdlib.h>

#define M 19

/**
* The type Person
*/
typedef struct
{
    int matricula; // key of hash table
    char nome[50]; // name
} Pessoa;

/**
* Represents a element (node) of the linked list
*/
typedef struct node
{
    Pessoa pessoa;
    struct node *next;
} Node;

/**
* The linked list
*/
typedef struct
{
    Node *head; // the first node in the list
    int tam;
} List;

/**
* The hash table of linked list
*/
List *hash_table[M];

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
* Prints a person
*/
void print_person(Pessoa p)
{
    printf("\t%d \t %s", p.matricula, p.nome);
}

/**
* Creates the linked list
*/
List* create_list()
{
    List *lis = malloc(sizeof(List));
    lis->head = NULL;
    lis->tam = 0;
    return lis;
}

/**
* Inserts a new element in the head of the list
*/
void insert_head(Pessoa p, List *list)
{
    Node *node = malloc(sizeof(Node));
    node->pessoa = p;
    node->next = list->head; // points the new node to the current head in the list
    list->head = node; // insert the new node in the first node (no longer the current head)
    list->tam++;
}

/**
* Finds a element in the list
*/
Node* find_node(int key, Node *head)
{
    while(head != NULL)
    {
        if(head->pessoa.matricula == key)
        {
            return head;
        }
        else
        {
            head = head->next; // search in the next node
        }

    }
    return NULL; // matricula not found
}

/**
* Prints the list
*/
void print_list(Node *head)
{
    while(head != NULL)
    {
        print_person(head->pessoa);
        head = head->next; // increments the node
    }
}

void initialize_table()
{
    for(int i = 0; i < M; i++)
    {
        hash_table[i] = create_list(); // sets all heads of the lists in the table to NULL
    }

}

int espalhamento(int key)
{
    return key%M;
}

void insert_pessoa()
{
    Pessoa p = create_pessoa();
    int i = espalhamento(p.matricula);
    insert_head(p, hash_table[i]);
}

Pessoa* search_pessoa(int key)
{
    int i = espalhamento(key);
    Node *node = find_node(key, hash_table[i]->head);
    if(node)
        return &node->pessoa;
    else
        return NULL; // person not found
}

// imprimir tabela
void print_table()
{
    int i;
    for(i = 0; i < M; i++)
    {
        printf("List %2d tam: %d\n", i, hash_table[i]->tam);
        print_list(hash_table[i]->head);
    }
}

void clear()
{
    system("cls || clear"); // clears the user's screen.
}

void menu()
{
    int op, mat;
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
            insert_pessoa();
            getchar();
            break;
        case 2:
            printf("Chave \t");
            scanf("%d", &mat);
            p = search_pessoa(mat);
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
            fflush(stdin);
            getchar(); // waits for a character from the user
            break;
        default:
            printf("Opcao incorreta.\n");
        }
    }
    while(op != 0);
}

void clear_memory()
{
    int i;
    for(i = 0; i < M; i++)
    {
        Node *node = hash_table[i]->head;
        while (node != NULL)
        {
            Node *temp = node;
            node = node->next;
            free(temp);
        }
        free(hash_table[i]);
    }
}


int main()
{
    menu();
    clear_memory();
    return 0;
}
