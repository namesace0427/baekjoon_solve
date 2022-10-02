#include<cstdio>

int n;
int sum[505], in[505], dy[505][505];

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int p;
	int i, j, k;
	scanf(" %d", &p);
	for (; p >= 1; --p) {
		scanf(" %d", &n);
		for (i = 1; i <= n; ++i) {
			scanf(" %d", in + i);
			sum[i] = sum[i - 1] + in[i];
		}

		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n - i; ++j) {
				dy[j][i + j] = 1987654321;
				for (k = j; k < i + j; ++k) {
					dy[j][i + j] = min(dy[j][i + j], dy[j][k] + dy[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}

		printf("%d\n", dy[1][n]);
	}
	return 0;
}