#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n >= 1 && n <= 100)
    {
        while(n--)
        {
            char str[101];
            scanf("%s", str);
            int len = strlen(str);
            if(len >= 1 && len <= 100)
            {
                int sum = 0;
                for (int i = 0; i < len; i++)
                {
                    if (str[i] >= '0' && str[i] <= '9')
                    {
                        sum += str[i] - '0';
                    }
                }
                printf("%d\n", sum);
            }
        }
    }
    return 0;
}
