#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int in[55], in2[55];

int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf(" %d", in + i);
	}
	for (i = 1; i <= n; ++i) {
		scanf(" %d", in2 + i);
	}
	sort(in + 1, in + 1 + n);
	sort(in2 + 1, in2 + 1 + n);
	int sum = 0;
	for (i = 1; i <= n; ++i) {
		sum += in[i] * in2[n - i + 1];
	}
	printf("%d", sum);

	return 0;
}