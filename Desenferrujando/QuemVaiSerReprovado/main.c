#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno
{
    char nome[21];
    int problemas;
};

void swap(struct Aluno *a, struct Aluno *b)
{
    struct Aluno temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct Aluno alunos[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (alunos[j].problemas < alunos[j + 1].problemas)
            {
                swap(&alunos[j], &alunos[j + 1]);
            }
            else if (alunos[j].problemas == alunos[j + 1].problemas &&
                     strcmp(alunos[j].nome, alunos[j + 1].nome) > 0)
            {
                swap(&alunos[j], &alunos[j + 1]);
            }
        }
    }
}


int main()
{
    int n, i = 1;

    while (scanf("%d", &n) == 1)
    {
        struct Aluno alunos[100];


        for (int i = 0; i < n; i++)
        {
            scanf("%s %d", alunos[i].nome, &alunos[i].problemas);
        }

        bubbleSort(alunos, n);

        printf("Instancia %d\n", i);
        printf("%s\n\n", alunos[n - 1].nome);
        i++;
    }

    return 0;
}
