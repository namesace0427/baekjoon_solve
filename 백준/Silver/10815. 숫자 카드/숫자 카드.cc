#include<cstdio>

int n, m;
int in[20000005];

int main() {
	scanf("%d", &n);
	int i, a;
	for (i = 1; i <= n; ++i) {
		scanf(" %d", &a);
		in[a + 10000000] = 1;
	}
	scanf(" %d", &m);
	for (i = 1; i <= m; ++i) {
		scanf(" %d", &a);
		if (in[a + 10000000]) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}
	return 0;
}