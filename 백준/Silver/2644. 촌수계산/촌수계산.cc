#include<cstdio>

int chk[105];
int in[105][105];
int n,m;
int st_n, en_n;

int back(int p, int cnt);

int main() {
	int i;
	int a, b;
	scanf("%d", &n);
	scanf("%d %d", &st_n, &en_n);
	scanf("%d", &m);
	for (i = 1; i <= m; ++i) {
		scanf("%d %d", &a, &b);
		in[a][b] = in[b][a] = 1;
	}
	if (!back(st_n, 0))
		printf("-1");
	return 0;
}

int back(int p, int cnt) {
	chk[p] = 1;
	if (p == en_n) {
		printf("%d", cnt);
		return 1;
	}
	int i;
	for (i = 1; i <= n; ++i) {
		if (in[p][i] && !chk[i]) {
			if (back(i, cnt + 1)) return 1;
		}
	}
	return 0;
}