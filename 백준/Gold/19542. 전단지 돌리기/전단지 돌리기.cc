#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, p;
vector<int> in[100005];
int chk[100005], ans[100005];
int dap;

void input();
void proc();

int _max(int a, int b) { return a > b ? a : b; }

int main() {
	input();
	proc();
	printf("%d", dap);
	return 0;
}

void input() {
	scanf(" %d %d %d", &n, &m, &p);
	int i, a, b;
	for (i = 1; i < n; ++i) {
		scanf(" %d %d", &a, &b);
		in[a].push_back(b);
		in[b].push_back(a);
	}
}

int dfs(int node) {
	chk[node] = 1;
	int i, max = 0;
	int s = in[node].size();
	for (i = 0; i < s; ++i) {
		if (chk[in[node][i]]) continue;
		max = _max(max, dfs(in[node][i]) + 1);
	}
	ans[node] = max;
	return max;
}

void search(int node) {
	chk[node] = 1;
	int i;
	int s = in[node].size();
	for (i = 0; i < s; ++i) {
		if (chk[in[node][i]]) continue;
		if (ans[in[node][i]] >= p) {
			dap += 2;
			search(in[node][i]);
		}
	}
}

void proc() {
	dfs(m);
	int i;
	for (i = 1; i <= n; ++i) chk[i] = 0;
	search(m);
}