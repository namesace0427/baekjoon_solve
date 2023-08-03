#include<cstdio>
#include<queue>
using namespace std;
priority_queue <int, vector<int>, greater<int>> q;
int n;

int main() {
	scanf(" %d", &n);
	int i, a;
	for (i = 1; i <= n; ++i) {
		scanf(" %d", &a);
		q.push(a);
	}
	int ans = 0;
	int b;
	while (q.size() >= 2) {
		a=q.top();
		q.pop();
		b = q.top();
		q.pop();
		ans += a + b;
		q.push(a + b);
	}
	printf("%d", ans);
	return 0;
}

