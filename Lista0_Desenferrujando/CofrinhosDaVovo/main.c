#include <stdio.h>
#include <stdlib.h>

struct Dif
{
    int quant;
    int* j;
    int* z;
    int* dif;
};

int main()
{
    int n, j, z, i = 1, size = 0;
    struct Dif *diff = NULL;
    while (scanf("%d", &n) != 0)
    {
        if (n == 0 && size == 0) return 0;
        if(n == 0)
        {
            for(int k = 0; k < i-1; k++)
            {
                printf("Teste %d\n", k+1);
                for(int z = 0; z < diff[k].quant; z++)
                {
                    printf("%d\n", diff[k].dif[z]);
                }
                printf("\n");
            }
            free(diff);
            return 0;
        }
        size += n;
        if(i == 1)
        {
            diff = (struct Dif*) malloc(size * sizeof(struct Dif));
        }
        else
        {
            diff = (struct Dif*) realloc(diff, size * sizeof(struct Dif));
        }
        diff[i-1].j = (int*) malloc(n * sizeof(int));
        diff[i-1].z = (int*) malloc(n * sizeof(int));
        diff[i-1].dif = (int*) malloc(n * sizeof(int));
        for (int k = 0; k < n; k++)
        {
            scanf("%d %d", &j, &z);
            diff[i-1].j[k] = j;
            diff[i-1].z[k] = z;
            if(k == 0)
            {
                diff[i-1].dif[k] = j - z;
            }
            else
            {
                diff[i-1].dif[k] = diff[i-1].dif[k-1] + j - z;
            }
        }
        diff[i-1].quant = n;
        i++;
    }
    return 0;
}
