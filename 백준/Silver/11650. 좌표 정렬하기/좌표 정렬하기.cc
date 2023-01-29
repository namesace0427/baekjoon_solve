#include<cstdio>
#include<algorithm>

struct data {
	int x, y;
} in[100005];
int n;

bool compare(data& l, data& r) {
	if (l.x == r.x) {
		return l.y < r.y;
	}
	return l.x < r.x;
}

int main() {

	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf(" %d %d", &in[i].x, &in[i].y);
	}
	std::sort(in + 1, in + 1 + n, compare);
	for (i = 1; i <= n; ++i) {
		printf("%d %d\n", in[i].x, in[i].y);
	}
	return 0;
}