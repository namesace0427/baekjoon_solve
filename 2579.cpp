#include<cstdio>

int in[305];
int dy[305];
int n;
int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	scanf(" %d", &n);
	int i;
	for (i = 1; i <= n; ++i) {
		scanf(" %d", in + i);
	}
	dy[1] = in[1];
	dy[2] = in[1] + in[2];
	dy[3] = max(in[1] + in[3], in[2] + in[3]);
	for (i = 4; i <= n; ++i) {
		dy[i] = max(dy[i - 2] + in[i], dy[i - 3] + in[i - 1] + in[i]);
	}
	printf("%d", dy[n]);
	return 0;
}