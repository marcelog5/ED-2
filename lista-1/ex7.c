#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Fila
{
    char cidade[26];
    struct Fila *proximo;
} Fila;

typedef struct Dados
{
    struct Fila *calda;
} Dados;

void enfileira(char linha[], Fila *fila, Dados *dados)
{
    Fila *aux, *novo;

    novo = (Fila *)malloc(sizeof(Fila));
    novo->proximo = NULL;
    strcpy(novo->cidade, linha);

    dados->calda->proximo = novo;
    dados->calda = novo;
}

int main(int argc, char const *argv[])
{
    char linha[26];
    Dados dados;
    Fila *fila, *aux;

    fila = (Fila *)malloc(sizeof(Fila));
    scanf("%s", fila->cidade);
    fila->proximo = NULL;

    dados.calda = fila;

    while (scanf("%s", linha) == 1)
    {
        enfileira(linha, fila, &dados);
    }

    aux = fila;

    while (fila->proximo != NULL)
    {
        aux = fila;
        if (fila->cidade[strlen(fila->cidade) - 1] == (fila->proximo->cidade[0] + 32))
        {
            printf("%s\n", fila->cidade);
            fila = fila->proximo;
            free(aux);

            enfileira(fila->cidade, fila, &dados);
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
