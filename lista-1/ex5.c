#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha
{
    int num;
    struct Pilha *proximo;
} Pilha;

Pilha *empilha(Pilha *pilha, int num)
{
    Pilha *novo;
    novo = (Pilha *)malloc(sizeof(Pilha));
    novo->num = num;
    novo->proximo = pilha;
    pilha = novo;
    return pilha;
}

int main(int argc, char const *argv[])
{
    int i = 0, num, v[1000000], lim, j, som = 0;
    Pilha *pilha = NULL, *aux;

    while ((scanf("%d", &num)) == 1 && num != 0)
    {
        v[i] = num;
        i++;
    }

    scanf("%d", &lim);

    for (j = 0; j < i; j++)
    {
        som += v[j];
        if (som > lim)
        {
            pilha = empilha(pilha, v[j]);
            som = 0;
        }
    }
    
    while (pilha != NULL)
    {
        printf("%d\n",pilha->num);
        aux = pilha;
        pilha = pilha->proximo;
        free(aux);
    }

    return 0;
}
