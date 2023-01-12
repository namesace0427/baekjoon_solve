#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int in[1000005];

int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf(" %d", in + i);
	}

	make_heap(in + 1, in + 1 + n);
	sort_heap(in + 1, in + 1 + n);
	for (i = 1; i <= n; ++i) {
		printf("%d\n", in[i]);
	}
	return 0;
}