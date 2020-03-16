#include <stdio.h>

int main(int argc, char const *argv[])
{
    int l, i, x, y, c;
    char linhas[1000][1000], comando;

    scanf("%d", &l);

    for (i = 0; i < l; i++)
    {
        scanf(" %[^\n]", linhas[i]);
    }

    scanf("%d %d", &x, &y);

    while ((scanf(" %c", &comando)) == 1)
    {
        if (comando == 'k')
        {
            if (x > 1)
            {
                x--;
            }

            if (linhas[x - 1][y - 1] != '\0')
            {
                printf("%d %d %c\n", x, y, linhas[x - 1][y - 1]);
            }
            else
            {
                c = 0;
                while (linhas[x - 1][c] != '\0')
                {
                    c++;
                }
                printf("%d %d %c\n", x, c, linhas[x - 1][c - 1]);
            }
        }
        else if (comando == 'j')
        {
            if (x < l)
            {
                x++;
            }

            if (linhas[x - 1][y - 1] != '\0')
            {
                printf("%d %d %c\n", x, y, linhas[x - 1][y - 1]);
            }
            else
            {
                c = 0;
                while (linhas[x - 1][c] != '\0')
                {
                    c++;
                }
                printf("%d %d %c\n", x, c, linhas[x - 1][c - 1]);
            }
        }
    }

    return 0;
}