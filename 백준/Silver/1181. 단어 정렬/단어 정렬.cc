#include<cstdio>
#include<cstring>
#include<algorithm>

struct data {
	char str[55];
	int len;
} in[20005];
int n;

bool compare(data& l, data& r) {
	if (l.len == r.len) {
		return strcmp(l.str + 1, r.str + 1) < 0;
	}
	return l.len < r.len;
}

int main() {

	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf(" %s", in[i].str + 1);
		in[i].len = strlen(in[i].str + 1);
	}
	std::sort(in + 1, in + 1 + n, compare);
	for (i = 1; i <= n; ++i) {
		printf("%s\n", in[i].str + 1);
		if (strcmp(in[i].str + 1, in[i + 1].str + 1) == 0) {
			for (; i <= n; ++i) {
				if (strcmp(in[i].str + 1, in[i + 1].str + 1) != 0) break;
			}
		}
	}
	return 0;
}