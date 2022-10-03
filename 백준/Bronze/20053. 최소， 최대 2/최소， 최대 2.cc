#include <cstdio>
int n;

int main()
{
    int t, max, min, a, i;
    scanf(" %d", &t);
    for (; t >= 1; --t)
    {
        scanf(" %d", &n);
        scanf(" %d", &a);
        max = min = a;
        for (i = 2; i <= n; ++i)
        {
            scanf(" %d", &a);
            max = max > a ? max : a;
            min = min < a ? min : a;
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}