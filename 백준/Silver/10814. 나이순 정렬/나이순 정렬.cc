#include<cstdio>
#include<algorithm>
int n;
struct data {
	int age;
	char name[105];
	int num;
}in[100005];

bool compare(data& l, data& r) {
	if (l.age != r.age) {
		return l.age < r.age;
	}
	return l.num < r.num;
}

int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf(" %d %s", &in[i].age, in[i].name + 1);
		in[i].num = i;
	}
	std::sort(in + 1, in + 1 + n, compare);
	for (i = 1; i <= n; ++i) {
		printf("%d %s\n", in[i].age, in[i].name + 1);
	}
	return 0;
}