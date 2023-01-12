#include<cstdio>

int dy[10005];
int in[105];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	int i;
	for (i = 1; i <= n; ++i) {
		scanf(" %d", in + i);
	}
	for (i = 1; i <= m; ++i) dy[i] = 99999;
	dy[0] = 0;
	int j;
	for (i = 1; i <= n; ++i) {
		for (j = in[i]; j <= m; ++j) {
			dy[j] = dy[j] < dy[j - in[i]] + 1 ? dy[j] : dy[j - in[i]] + 1;
		}
	}
	if (dy[m] == 99999) printf("-1");
	else printf("%d", dy[m]);
	return 0;
}