#include<cstdio>
int dy[1000005];
int n;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; ++i) {
		dy[i] = 10000000;
	}
	dy[n] = 0;
	for (i = n; i >= 1; --i) {
		dy[i - 1] = min(dy[i - 1], dy[i] + 1);
		if (i % 2 == 0) dy[i / 2] = min(dy[i / 2], dy[i] + 1);
		if (i % 3 == 0) dy[i / 3] = min(dy[i / 3], dy[i] + 1);
	}
	printf("%d", dy[1]);
	return 0;
}
