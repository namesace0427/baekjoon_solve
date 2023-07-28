#include<cstdio>

int in[505][5];
int dy[505][505];
int n;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int i, j, k;
	scanf(" %d", &n);
	for (i = 1; i <= n; ++i) {
		scanf(" %d %d", in[i], in[i] + 1);
	}
	for (i = 1; i < n; ++i) {
		for (j = 1; i + j <= n; ++j) {
			dy[j][i + j] = 2147483647;
			for (k = j; k <= i + j; ++k) {
				dy[j][i + j] = min(dy[j][i + j], dy[j][k] + dy[k + 1][i + j] + in[j][0] * in[k][1] * in[i + j][1]);
			}
		}
	}
	printf("%d", dy[1][n]);
	return 0;
}