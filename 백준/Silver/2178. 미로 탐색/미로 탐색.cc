#include<cstdio>
int in[105][105];
int n, m;
struct data {
	int r, c;
} q[10005];
int chk[105][105];
int row[] = { 0,+1,0,-1 }, col[] = { +1,0,-1,0 };

int main() {
	scanf("%d %d", &n, &m);
	int i, j;
	char a[105];
	for (i = 1; i <= n; ++i) {
		scanf(" %s", a + 1);
		for (j = 1; j <= m; ++j) {
			in[i][j] = a[j] - '0';
		}
	}
	chk[1][1] = 1;
	q[0].r = 1;
	q[0].c = 1;
	int f = 0, r = 1;

	int ro, co;
	while (f < r) {
		for (i = 0; i < 4; ++i) {
			ro = q[f].r + row[i];
			co = q[f].c + col[i];
			if (ro<1 || ro>n || co<1 || co>m || chk[ro][co] != 0 || in[ro][co] == 0) continue;
			q[r].r = ro;
			q[r].c = co;
			chk[ro][co] = chk[q[f].r][q[f].c] + 1;
			r++;
		}
		++f;
	}
	printf("%d", chk[n][m]);
	return 0;
}