#include<cstdio>
int dy[205][205];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i <= n; ++i) {
		dy[1][i] = 1;
	}
	for (i = 1; i <= m; ++i) {
		dy[i][0] = 1;
		for (j = 1; j <= n; ++j) {
			dy[i][j] = (dy[i - 1][j] + dy[i][j - 1]) % 1000000000;
		}
	}
	printf("%d", dy[m][n]);
	return 0;
}