#include<cstdio>

int in[1005][1005];
int n, m, v;

int chk[1005], chk2[1005];
int Que[1005];

void DFS(int p) {
	printf("%d ", p);
	int i;
	for (i = 1; i <= n; ++i) {
		if (chk[i] || !in[p][i]) continue;

		chk[i] = 1;
		DFS(i);
	}
}

void BFS(int p) {
	int h = 0, r = 1,i;
	Que[h] = v;
	printf("%d ", p);
	while (h < r) {
		for (i = 1; i <= n; ++i) {
			if (chk2[i] || !in[Que[h]][i]) continue;
			Que[r++] = i;
			printf("%d ", i);
			chk2[i] = 1;
		}
		++h;
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &v);

	int i, a, b;
	for (i = 1; i <= m; ++i) {
		scanf("%d %d", &a, &b);
		in[a][b] = in[b][a] = 1;
	}
	chk[v] = chk2[v] = 1;
	DFS(v);
	printf("\n");
	BFS(v);

	return 0;
}