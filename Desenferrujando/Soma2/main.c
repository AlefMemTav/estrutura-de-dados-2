#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, soma;
    scanf("%d %d", &num1, &num2);
    if(num1 <= 600000 && num2 <= 600000)
    {
        soma = num1 + num2;
        printf("%d\n", soma);
    }

    return 0;
}
