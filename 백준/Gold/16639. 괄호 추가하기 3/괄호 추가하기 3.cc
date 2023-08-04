#include<cstdio>
#include<algorithm>
char in[100005];
int dy_max[25][25], dy_min[25][25];
int n;

int calc(int a, int b,char oper) {
	if (oper == '+') {
		return a + b;
	}
	else if (oper == '-') {
		return a - b;
	}
	return a * b;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	scanf(" %d", &n);
	scanf(" %s", in + 1);

	int i, j, k, l;
	int c[5];
	for (i = 1; i <= n / 2 + 1; ++i) {
		for (j = 1; j <= n / 2 + 1; ++j) {
			dy_max[i][j] = -2147483647;
			dy_min[i][j] = 2147483647;
		}
		dy_max[i][i] = dy_min[i][i] = in[i * 2 - 1] - '0';
	}

	for (k = 2; k <= n / 2 + 1; ++k) {
		for (l = 1; l <= n / 2 + 1 - k + 1; ++l) {
			for (i = 1, j = k; i < k; ++i, --j) {
				c[1] = calc(dy_max[l][l + k - j], dy_max[l + i][l + k - 1], in[(k + l - j) * 2]);
				c[2] = calc(dy_max[l][l + k - j], dy_min[l + i][l + k - 1], in[(k + l - j) * 2]);
				c[3] = calc(dy_min[l][l + k - j], dy_max[l + i][l + k - 1], in[(k + l - j) * 2]);
				c[4] = calc(dy_min[l][l + k - j], dy_min[l + i][l + k - 1], in[(k + l - j) * 2]);

				std::sort(c + 1, c + 1 + 4);
				dy_max[l][l + k - 1] = max(dy_max[l][l + k - 1], c[4]);
				dy_min[l][l + k - 1] = min(dy_min[l][l + k - 1], c[1]);
			}
		}
	}

	printf("%d", dy_max[1][n / 2 + 1]);
	return 0;
}