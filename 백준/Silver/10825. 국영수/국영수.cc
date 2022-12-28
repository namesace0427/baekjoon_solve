#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct data2 {
	int kor, mat, eng;
	char name[15];
} in[100005];
int n;

bool compare(const data2& l, const data2& r) {
	if (l.kor != r.kor) {
		return l.kor > r.kor;
	}
	else if (l.eng != r.eng) {
		return l.eng < r.eng;
	}
	else if (l.mat != r.mat) {
		return l.mat > r.mat;
	}
	return strcmp(l.name + 1, r.name + 1) < 0;
}

int main() {
	scanf(" %d", &n);
	int i;
	for (i = 1; i <= n; ++i) {
		scanf(" %s %d %d %d", in[i].name + 1, &in[i].kor, &in[i].eng, &in[i].mat);
	}
	sort(in + 1, in + 1 + n, compare);
	for (i = 1; i <= n; ++i) {
		printf("%s\n", in[i].name + 1);
	}
	return 0;
}