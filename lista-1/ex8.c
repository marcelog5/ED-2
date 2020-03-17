#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha
{
    int num;
    struct Pilha *proximo;
} Pilha;

Pilha *empilha(Pilha *pilha, int valor)
{
    Pilha *novo;
    novo = (Pilha *)malloc(sizeof(Pilha));
    novo->num = valor;
    novo->proximo = pilha;
    return pilha = novo;
}

int ordenada(Pilha *pilha)
{
    if (pilha != NULL)
    {
        while (pilha->proximo != NULL)
        {
            if (pilha->num > pilha->proximo->num)
            {
                return 0;
            }
            pilha = pilha->proximo;
        }
    }
        return 1;
    }

    int main(int argc, char const *argv[])
    {
        int n;

        while ((scanf("%d", &n)) == 1 && n != 0)
        {

            Pilha *pilha = NULL, *aux;
            int v[n], i;

            for (i = 0; i < n; i++)
            {
                scanf("%d", &v[i]);
            }

            for (i = 0; i < n; i++)
            {
                while (pilha != NULL && pilha->num < v[i] && pilha->num >= v[i - 1] && pilha->num == v[i - 1] + 1)
                {
                    aux = pilha;
                    v[i - 1] = pilha->num;
                    pilha = pilha->proximo;
                    free(aux);
                }

                if (v[i] > v[i + 1] && i < n - 1)
                {
                    pilha = empilha(pilha, v[i]);
                }
            }

            if (ordenada(pilha))
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
        return 0;
    }
