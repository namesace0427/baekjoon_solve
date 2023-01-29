#include<cstdio>
#include<algorithm>

int n;
int in[10005];

int main() {
	int t;
	scanf("%d", &t);
	int i, j;
	int ans;
	for (; t >= 1; --t) {
		scanf("%d", &n);
		for (i = 1; i <= n; ++i) {
			scanf(" %d", in + i);
		}
		std::sort(in + 1, in + 1 + n);
		ans = 0;
		for (i = 3; i <= n; ++i) {
			ans = ans > in[i] - in[i - 2] ? ans : in[i] - in[i - 2];
		}
		printf("%d\n", ans);
	}
	return 0;
}