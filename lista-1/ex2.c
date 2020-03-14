#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int num;
    struct Lista *proximo;
} Lista;

int main(int argc, char const *argv[])
{
    int num, soma = 0;
    Lista *lista = NULL;

    while ((scanf("%d", &num)) == 1)
    {
        if (verifica(&num, &lista))
        {
            soma += num;
        }
    }

    printf("%d\n", soma);

    return 0;
}
