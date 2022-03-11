#include<cstdio>
int n;
int dy[1005];

int main() {
	int i;
	scanf("%d", &n);
	dy[1] = 1;
	dy[2] = 2;
	for (i = 3; i <= n; ++i) {
		dy[i] = (dy[i - 1] + dy[i - 2]) % 10007;
	}
	printf("%d", dy[n]);
	return 0;
}