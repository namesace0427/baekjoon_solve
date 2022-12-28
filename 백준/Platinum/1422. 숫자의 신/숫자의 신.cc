#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<string> ans;
int n, m;

bool compare(string l, string r) {
	return l + r > r + l;
}

int main() {
	scanf("%d %d", &n, &m);
	int i;
	string str = "";
	string temp = "";
	char in[15];
	for (i = 1; i <= n; ++i) {
		scanf(" %s", in + 1);
		temp = in + 1;
		if (str.size() < temp.size() || (str.size() == temp.size() && str < temp)) str = temp;
		ans.push_back(temp);
	}

	for (i = 0; i < m - n; ++i) {
		ans.push_back(str);
	}

	sort(ans.begin(), ans.end(), compare);
	for (i = 0; i < ans.size(); ++i) {
		printf("%s", ans[i].c_str());
	}

	return 0;
}