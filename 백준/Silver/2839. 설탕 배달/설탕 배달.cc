#include<cstdio>

int n;
int dy[5001];

int main() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; ++i) dy[i] = 99999;
	dy[3] = dy[5] = 1;


	for (i = 6; i <= n; ++i) {
		if (dy[i - 3] != 99999) {
			dy[i] = dy[i] < dy[i - 3] + 1 ? dy[i] : dy[i - 3] + 1;
		}
		
		if (dy[i - 5] != 99999) {
			dy[i] = dy[i] < dy[i - 5] + 1 ? dy[1] : dy[i - 5] + 1;
		}
	}

	printf("%d", dy[n] == 99999 ? -1 : dy[n]);

	return 0;
}