#include <stdio.h>

int main()
{
    int n, ai, count, majority;
    while (scanf("%d", &n) == 1 && n != 0)
    {
        count = 0;
        while (n--)
        {
            scanf("%d", &ai);
            if (count == 0)
            {
                majority = ai;
                count = 1;
            }
            else if (ai == majority)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        printf("%d\n", majority);
    }
    return 0;
}
