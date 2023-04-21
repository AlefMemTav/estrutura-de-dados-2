#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *registros = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &registros[i]);
    }

    qsort(registros, n, sizeof(int), comparar);

    int alunosPresentes = 1;
    for (int i = 1; i < n; i++)
    {
        if (registros[i] != registros[i-1])
        {
            alunosPresentes++;
        }
    }

    printf("%d\n", alunosPresentes);

    free(registros);

    return 0;
}
