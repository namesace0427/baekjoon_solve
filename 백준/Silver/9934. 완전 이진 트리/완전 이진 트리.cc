#include <cstdio>
#include <vector>
using namespace std;
int n;
int in[20000];
vector<int> tree[15];

void back(int len, int st, int en)
{
    if (st > en)
        return;
    int mid = (st + en) / 2;
    tree[len].push_back(in[mid]);
    back(len + 1, st, mid - 1);
    back(len + 1, mid + 1, en);
}

int main()
{
    scanf("%d", &n);
    int i, j;
    for (i = 1; i < 1 << n; ++i)
    {
        scanf(" %d", in + i);
    }
    back(1, 1, 1 << n);
    for (i = 1; i <= n; ++i)
    {
        for (j = 0; j < tree[i].size(); ++j)
        {
            printf("%d ", tree[i][j]);
        }
        printf("\n");
    }
    return 0;
}