#include<cstdio>

typedef long long ll;
int n, l, r;
ll dy[105][105][105];

int main() {
	scanf(" %d %d %d", &n, &l, &r);
	dy[1][1][1] = 1;
	int i, j, k;
	for (i = 2; i <= n; ++i) {
		for (j = 1; j <= l; ++j) {
			for (k = 1; k <= r; ++k) {
				dy[i][j][k] = (dy[i - 1][j][k] * (i - 2) + dy[i - 1][j][k - 1] + dy[i - 1][j - 1][k]) % 1000000007;
			}
		}
	}
	printf("%lld", dy[n][l][r]);
	return 0;
}