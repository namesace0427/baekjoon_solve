#include<cstdio>
#include<cstring>
#include<memory.h>
int dy[1000005];
int n;
char in[1000005];

int main() {
	int i, p;
	while (1) {
		scanf(" %s", in);
		if (in[0] == '.') break;
		n = strlen(in);
		memset(dy, 0, sizeof(dy));
		p = 0;
		for (i = 1; i < n; ++i) {
			while (p > 0 && in[i] != in[p]) p = dy[p - 1];
			if (in[i] == in[p]) dy[i] = ++p;
		}

		if (n % (n - dy[n - 1])) printf("1\n");
		else printf("%d\n", n / (n - dy[n - 1]));
	}
	return 0;
}