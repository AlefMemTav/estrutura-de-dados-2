#include <stdio.h>
#include <stdlib.h>

/**
* Ler a quantidade de restaurantes em um dia e ler o cod e nota de cada restaurante.
* Em seguida, deve-se armazenar o cod do restaurante com a maior nota.
* Quando for chamado EOF, deve-se imprimir os cod dos restaurantes com a maior nota por
* dia de viagem, a partir do Dia 1.
* Return 0 ao final.
*/
int main()
{
    int r, cod = 0, menor_cod = 0, nota, maior_nota, dia = 1;
    int* cod_restaurante = NULL;

    while (scanf("%d", &r) == 1)
    {
        maior_nota = -1;
        for (int i = 0; i < r; i++)
        {
            scanf("%d %d", &cod, &nota);

            if (nota > maior_nota || (nota == maior_nota && cod < menor_cod))
            {
                menor_cod = cod;
                maior_nota = nota;
            }
        }
        if(dia == 1)
        {
            cod_restaurante = (int*) malloc(sizeof(int));
        }
        else
        {
            cod_restaurante = (int*) realloc(cod_restaurante, dia * sizeof(int));
        }
        cod_restaurante[dia-1] = menor_cod;
        dia++;
    }

    for(int j = 1; j < dia; j++)
    {
        printf("Dia %d\n%d\n\n", j, cod_restaurante[j-1]);
    }
    free(cod_restaurante);
    return 0;
}
