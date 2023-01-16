#include<cstdio>

int in[20000005], n, m;

int main() {
	int i, a;
	scanf("%d", &n);

	for (i = 1; i <= n; ++i) {
		scanf(" %d", &a);
		++in[a + 10000000];
	}

	scanf("%d", &m);
	for (i = 1; i <= m; ++i) {
		scanf(" %d", &a);
		printf("%d ", in[a + 10000000]);
	}

	return 0;
}