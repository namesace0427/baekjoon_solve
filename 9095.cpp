#include<cstdio>
int dy[15];
int n;

int main() {
	int t, i;
	scanf(" %d", &t);
	dy[1] = 1; dy[2] = 2; dy[3] = 4;
	for (i = 4; i <= 11; ++i) {
		dy[i] = dy[i - 1] + dy[i - 2] + dy[i - 3];
	}
	for (; t >= 1; --t) {
		scanf(" %d", &n);
		printf("%d\n", dy[n]);
	}
	return 0;
}