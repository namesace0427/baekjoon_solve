#include<cstdio>

int n, m;
int ans[10];
int chk[10];
void back(int len);

int main() {
	scanf(" %d %d", &n,&m);
	back(1);
	return 0;
}

void back(int len) {
	int i;
	if (len == m + 1) {
		for (i = 1; i <= m; ++i) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	for (i = 1; i <= n; ++i) {
		if (chk[i]) continue;
		chk[i] = 1;
		ans[len] = i;
		back(len + 1);
		chk[i] = 0;
	}
}