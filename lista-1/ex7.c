#include <stdio.h>
#include <stdlib.h>

typedef struct Fila
{
    char cidade[26];
    struct Fila *proximo;
} Fila;

char ultima_letra(char linha[])
{
    int i = 0;

    while (linha[i] != '\0')
    {
        i++;
    }

    return linha[--i];
}

void enfileira(char linha[],Fila *fila)
{
    Fila *aux, *novo;

    novo = (Fila *)malloc(sizeof(Fila));
    novo->proximo = NULL;
    int i = 0;
    while (linha[i] != '\0')
    {
        novo->cidade[i] = linha[i];
        i++;
    }
    novo->cidade[i] = '\0';

    aux = fila;
    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }
    aux->proximo = novo;
}

int main(int argc, char const *argv[])
{
    char linha[26];
    Fila *fila, *aux, *novo;

    fila = (Fila *)malloc(sizeof(Fila));
    scanf("%s", fila->cidade);
    fila->proximo = NULL;

    while ((scanf("%s", linha)) == 1)
    {
        enfileira(linha,fila);
    }

    aux = fila;

    while (fila->proximo != NULL)
    {
        aux = fila;
        if (ultima_letra(fila->cidade) == (fila->proximo->cidade[0] + 32))
        {
            printf("%s\n", fila->cidade);
            fila = fila->proximo;
            free(aux);

            enfileira(fila->cidade,fila);
            aux = fila;
            fila = fila->proximo;
            free(aux);
        }
        else
        {
            printf("%s\n", fila->cidade);
            fila = fila->proximo;
            free(aux);
        }
    }

    printf("%s\n", fila->cidade);

    return 0;
}
