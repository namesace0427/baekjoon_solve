#include<cstdio>
int n, m;
int in[105];
int dy[10005];

int main() {
	int i,j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; ++i) {
		scanf(" %d", in + i);
	}
	dy[0] = 1;
	for (i = 1; i <= n; ++i) {
		for (j = in[i]; j <= m; ++j) {
			dy[j] += dy[j - in[i]];
		}
	}
	printf("%d", dy[m]);
	return 0;
}