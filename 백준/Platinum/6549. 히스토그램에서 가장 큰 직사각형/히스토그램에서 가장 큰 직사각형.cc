#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
int n;
ll in[100005];
vector<ll> s;
ll ans;

ll max(ll a, ll b) {
	return a > b ? a : b;
}


int main() {
	int i;
	int p;
	while (1) {
		scanf(" %d", &n);
		if (n == 0) break;

		for (i = 1; i <= n; ++i) scanf(" %d", in + i);
		in[n + 1] = 0;
		s.push_back(0);
		for (i = 1; i <= n + 1; ++i) {
			while (!s.empty() && in[s.back()] > in[i]) {
				p = s.back();
				s.pop_back();
				ans = max(ans, ll(in[p]) * (i - s.back() - 1));
			}
			s.push_back(i);
		}
		printf("%lld\n", ans);

		s.clear();
		ans = 0;
	}
	return 0;
}