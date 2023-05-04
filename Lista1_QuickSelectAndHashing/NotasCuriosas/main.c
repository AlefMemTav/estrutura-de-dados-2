#include <stdio.h>

int main()
{
    int n, i, nota, max_nota = 0, max_freq = 0;
    int freq[1001] = {0};

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &nota);
        freq[nota]++;
        if (freq[nota] > max_freq || (freq[nota] == max_freq && nota > max_nota))
        {
            max_freq = freq[nota];
            max_nota = nota;
        }
    }

    printf("%d\n", max_nota);

    return 0;
}
