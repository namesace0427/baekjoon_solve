#include<cstdio>

int n,ans;
int in[105][105];
int min_h=1987654321, max_h;
int chk[105][105];
int row[] = { 0,+1,0,-1 }, col[] = { +1,0,-1,0 };

void back(int r, int c, int h);

int main() {
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			scanf(" %d", in[i] + j);
			min_h = min_h < in[i][j] ? min_h : in[i][j];
			max_h = max_h > in[i][j] ? max_h : in[i][j];
		}
	}

	ans = 0;
	int cnt;
	for (k = 0; k <= 101; ++k) {
		for (i = 1; i <= n; ++i) for (j = 1; j <= n; ++j) chk[i][j] = 0;
		cnt = 0;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				if (in[i][j] > k && !chk[i][j]) {
					back(i, j, k);
					++cnt;
				}
			}
		}
		ans = ans > cnt ? ans : cnt;
	}
	printf("%d", ans);
	return 0;
}

void back(int r, int c, int h) {
	chk[r][c] = 1;
	int ro, co;
	int i;

	for (i = 0; i < 4; ++i) {
		ro = r + row[i];
		co = c + col[i];
		if (in[ro][co] > h && !chk[ro][co]) {
			back(ro, co, h);
		}
	}
}