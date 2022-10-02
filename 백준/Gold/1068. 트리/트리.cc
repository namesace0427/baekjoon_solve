#include <cstdio>
int in[55][55];
int n, m, root;
int ans;

void back(int p)
{
    if (p == m)
        return;
    if (in[p][0] == 0 || (in[p][0] == 1 && in[p][1] == m))
    {
        ++ans;
        return;
    }
    int i;
    for (i = 1; i <= in[p][0]; ++i)
    {
        back(in[p][i]);
    }
}

int main()
{
    scanf(" %d", &n);
    int i, a;
    for (i = 0; i < n; ++i)
    {
        scanf(" %d", &a);
        if (a == -1)
            root = i;
        else
        {
            in[a][++in[a][0]] = i;
        }
    }
    scanf(" %d", &m);
    back(root);
    printf("%d\n", ans);
    return 0;
}