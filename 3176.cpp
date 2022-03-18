#include<cstdio>
#include<memory.h>
int n;
int in[25][25];
int dy[25][1 << 21];

int min(int a, int b) {
	return a < b ? a : b;
}

int dfs(int p, int visited) {
	if (visited == (1 << n) - 1) return 0;
	if (dy[p][visited] != -1) return dy[p][visited];

	dy[p][visited] = 1987654321;
	int i;
	for (i = 0; i < n; ++i) {
		if (visited & (1 << i)) continue;

		dy[p][visited] = min(dy[p][visited],
			dfs(p + 1, visited | (1 << i)) + in[p][i]);
	}
	return dy[p][visited];
}

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			scanf(" %d", in[i] + j);
		}
	}
	memset(dy, -1, sizeof(dy));
	printf("%d", dfs(0, 0));
	return 0;
}