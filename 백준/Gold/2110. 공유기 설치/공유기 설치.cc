#include<cstdio>
#include<algorithm>
int n, m;
int in[200005];

int main() {
	scanf("%d %d", &n, &m);
	int i;
	for (i = 1; i <= n; ++i) {
		scanf(" %d", in + i);
	}
	std::sort(in + 1, in + 1 + n);
	int l, r, t, mid, cnt, ans;
	l = 0;
	r = in[n];

	while (l <= r) {
		cnt = 1;
		mid = (l + r) / 2;
		t = 1;
		for (i = 2; i <= n; ++i) {
			if (in[i] - in[t] >= mid) {
				++cnt;
				t = i;
			}
		}

		if (cnt >= m) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%d", ans);

	return 0;
}