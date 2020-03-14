#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int num, soma = 0;

    while ((scanf("%d", &num)) == 1)
    {
        soma++;
    }

    printf("%d\n", soma);

    return 0;
}