#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x, sum = 0;
    scanf("%d", &n);
    if(n >= 0 && n <= 50)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            if(abs(x) <= 5000)
            {
                sum += x;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
