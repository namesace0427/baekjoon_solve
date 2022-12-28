#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int in[10005];

int main() {
	int i,j, a;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf(" %d", &a);
		++in[a];
	}

	for (i = 1; i <= 10000; ++i) {
		for (j = 1; j <= in[i]; ++j) {
			printf("%d\n", i);
		}
	}
	return 0;
}