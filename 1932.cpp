#include<cstdio>
int dy[505][505];
int in[505][505];
int n;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	scanf("%d", &n);
	int i, j;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= i; ++j) {
			scanf(" %d", in[i] + j);
		}
	}
	dy[1][1] = in[1][1];
	for (i = 2; i <= n; ++i) {
		for (j = 1; j <= i; ++j) {
			dy[i][j] = max(dy[i - 1][j - 1], dy[i - 1][j]) + in[i][j];
		}
	}
	int MAX = 0;
	for (i = 1; i <= n; ++i) {
		MAX = max(MAX, dy[n][i]);
	}
	printf("%d", MAX);
	return 0;
}