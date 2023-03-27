#include<cstdio>
#include<cstring>
#include<algorithm>
struct data {
	int len, sum;
	char s[55];
} in[1005];
int n;

bool compare(data& l, data& r) {
	if (l.len != r.len) {
		return l.len < r.len;
	}
	if (l.sum != r.sum) {
		return l.sum < r.sum;
	}
	return strcmp(l.s + 1, r.s + 1) < 0;
}

int main() {
	int i, j;

	scanf(" %d", &n);

	for (i = 1; i <= n; ++i) {
		scanf(" %s", in[i].s + 1);
		in[i].len = strlen(in[i].s + 1);
		for (j = 1; j <= in[i].len; ++j) {
			if (in[i].s[j] >= '0' && in[i].s[j] <= '9') {
				in[i].sum += in[i].s[j] - '0';
			}
		}
	}

	std::sort(in + 1, in + 1 + n, compare);

	for (i = 1; i <= n; ++i) {
		printf("%s\n", in[i].s + 1);
	}
	return 0;
}