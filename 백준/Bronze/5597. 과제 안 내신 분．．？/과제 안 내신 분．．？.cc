#include <cstdio>
int chk[35];

int main()
{
    int i, p;
    for (i = 1; i <= 28; ++i)
    {
        scanf(" %d", &p);
        chk[p] = 1;
    }
    for (i = 1; i <= 30; ++i)
    {
        if (!chk[i])
            printf("%d\n", i);
    }
    return 0;
}