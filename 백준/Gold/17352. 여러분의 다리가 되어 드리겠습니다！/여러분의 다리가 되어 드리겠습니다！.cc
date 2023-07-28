#include<cstdio>

int in[300005];
int n;

int root(int a) {
	if (in[a] == a) return a;
	return in[a]=root(in[a]);
}

int main() {
	scanf(" %d", &n);
	int i, j, a, b, root_a, root_b;
	for (i = 1; i <= n; ++i) {
		in[i] = i;
	}
	for (i = 1; i < n - 1; ++i) {
		scanf(" %d %d", &a, &b);
		root_a = root(a);
		root_b = root(b);
		in[root_b] = root_a;
		
	}
	for (i = 2; i <= n; ++i) {
		if (root(in[1]) != root(in[i])) break;
	}
	printf("1 %d", i);
	return 0;
}