#include <cstdio>
#include <memory.h>
int n;
int in[10005];
int chk[10005];

int main()
{
    int t, i, p, a, b;
    scanf(" %d", &t);
    for (; t >= 1; --t)
    {
        memset(in, 0, sizeof(in));
        memset(chk, 0, sizeof(chk));
        scanf(" %d", &n);
        for (i = 1; i < n; ++i)
        {
            scanf(" %d %d", &a, &b);
            in[b] = a;
        }
        scanf(" %d", &p);
        while (1)
        {
            if (in[p] == 0)
                break;
            chk[p] = 1;
            p = in[p];
        }
        scanf(" %d", &p);
        while (1)
        {
            if (in[p] == 0)
                break;
            if (chk[p] == 1)
                break;
            p = in[p];
        }
        printf("%d\n", p);
    }
    return 0;
}