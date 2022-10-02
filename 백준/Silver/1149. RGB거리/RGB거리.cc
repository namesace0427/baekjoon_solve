#include<cstdio>

int dy[1005][5];
int in[1005][5];
int n;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; ++i) {
		scanf(" %d %d %d", in[i] + 1, in[i] + 2, in[i] + 3);
	}
	dy[1][1] = in[1][1];
	dy[1][2] = in[1][2];
	dy[1][3] = in[1][3];
	for (i = 2; i <= n; ++i) {
		dy[i][1] = min(dy[i - 1][2], dy[i - 1][3]) + in[i][1];
		dy[i][2] = min(dy[i - 1][1], dy[i - 1][3]) + in[i][2];
		dy[i][3] = min(dy[i - 1][1], dy[i - 1][2]) + in[i][3];
	}
	printf("%d", min(min(dy[n][1], dy[n][2]), dy[n][3]));
	return 0;
}