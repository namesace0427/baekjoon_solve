#include<cstdio>
#include<vector>
using namespace std;
int n, m;
int cnt[32005];
vector<int> graph[32005];
int que[32005];

int main() {
	scanf("%d %d", &n, &m);
	int i, size, a, b;
	for (i = 1; i <= m; ++i) {
		scanf(" %d %d", &a, &b);
		graph[a].push_back(b);
		++cnt[b];
	}
	int h = 1, r = 0;
	for (i = 1; i <= n; ++i) {
		if (cnt[i] == 0) que[++r] = i;
	}

	while (h <= r) {
		size = graph[que[h]].size();
		for (i = 0; i < size; ++i) {
			--cnt[graph[que[h]][i]];
			if (cnt[graph[que[h]][i]] == 0) {
				que[++r] = graph[que[h]][i];
			}
		}
		++h;
	}
	for (i = 1; i <= n; ++i) {
		printf("%d ", que[i]);
	}
	return 0;
}