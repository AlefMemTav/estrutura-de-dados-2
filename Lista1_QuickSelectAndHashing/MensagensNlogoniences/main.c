#include <stdio.h>
#include <stdlib.h>

int main()
{
    char b[1<<21+2] = {0};
    int min = 0, cod, offset;
    char m;
    char *c = &b[1<<20];
    scanf("%d %c", &cod, &m);
    c[0] = m;
    offset = cod;

    while(scanf("%d %c", &cod, &m) == 2)
    {
        c[cod-offset] = m;
        if(cod-offset < min)
            min = cod - offset;
    }
    printf("%s\n", &c[min]);

    return 0;
}
