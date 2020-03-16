#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, num, soma;

    scanf("%d", &i);

    for (soma = 0; i > 0; i--)
    {
        scanf("%d", &num);
        soma += num;
    }

    printf("%d\n",soma);

    return 0;
}
