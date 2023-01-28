#include<cstdio>
#include<algorithm>
int n;
int in[1005];

int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf(" %d", in + i);
	}
	std::sort(in + 1, in + 1 + n);
	int sum = 0;
	int ans = 0;
	for (i = 1; i <= n; ++i) {
		sum += in[i];
		ans += sum;
	}
	printf("%d", ans);
	return 0;
}