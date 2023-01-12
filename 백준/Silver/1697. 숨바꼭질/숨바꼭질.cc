#include<cstdio>
struct data {
	int t, v;
} Que[100005];
int n, m;
int chk[100005];

int main() {
	scanf("%d %d", &n, &m);
	int h = 0, r = 1;
	chk[n] = 1;
	Que[h].v = n;
	Que[h].t = 0;
	while (h < r) {
		if (Que[h].v == m) {
			break;
		}
		if (Que[h].v + 1 >= 0 && Que[h].v + 1 <= 100000 && !chk[Que[h].v + 1]) {
			chk[Que[h].v + 1] = 1;
			Que[r].v = Que[h].v + 1;
			Que[r].t = Que[h].t + 1;
			r++;
		}
		if (Que[h].v - 1 >= 0 && Que[h].v - 1 <= 100000 && !chk[Que[h].v - 1]) {
			chk[Que[h].v - 1] = 1;
			Que[r].v = Que[h].v - 1;
			Que[r].t = Que[h].t + 1;
			r++;
		}
		if (Que[h].v * 2 >= 0 && Que[h].v * 2 <= 100000 && !chk[Que[h].v * 2]) {
			chk[Que[h].v * 2] = 1;
			Que[r].v = Que[h].v * 2;
			Que[r].t = Que[h].t + 1;
			r++;
		}
		++h;
	}
	printf("%d", Que[h].t);
	return 0;
}