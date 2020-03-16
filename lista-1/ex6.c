#include <stdio.h>

void insercao(int v[], int n)
{
    int j, x, i;

    for (j = 1; j < n; ++j)
    {
        x = v[j];
        for (i = j - 1; i >= 0 && v[i] > x; --i)
        {
            v[i + 1] = v[i];
        }
        v[i + 1] = x;
    }
}

int main(int argc, char const *argv[])
{
    int i, n = 0, num, v[999];

    while ((scanf("%d", &num)) == 1)
    {
        v[n++] = num;
    }

    insercao(v, n);

    for (i = 0; i < n-1; i++)
    {
        printf("%d ",v[i]);
    }
    printf("%d\n",v[i]);
    
    return 0;
}
