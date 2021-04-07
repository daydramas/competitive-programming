#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, p[N], dd[N], aa[N], ll[N], rr[N];

struct P {
	int x, i;
} t[N];

int get(int x) {
	return dd[x] < 0 ? x : dd[x] = get(dd[x]);
}

int merge(int x, int y) {
	x = get(x), y = get(y);
	if (x != y) {
		dd[x] += dd[y], dd[y] = x;
		return -dd[x];
	}
	else
		return 0;
}

int main() {
	int x;
	scanf("%d%d", &x, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
		t[i] = {p[i], i};
	}
	t[n] = {0, -1}, t[n + 1] = {x, n};
	sort(t, t + n + 2, [&](const P& i, const P& j) {
		return i.x < j.x;
	});;
	rr[0] = 1;
	for (int i = 1; i <= n + 1; ++i) {
		ll[i] = rr[i - 1];
		rr[i] = ll[i] + 1;
		dd[ll[i]] = -(t[i].x - t[i - 1].x);
		aa[n - 1] = max(aa[n - 1], t[i].x - t[i - 1].x);
		p[t[i].i] = i;
	}
	for (int i = n - 1; i >= 1; --i) {
		aa[i - 1] = max(aa[i], merge(ll[p[i]], rr[p[i]]));
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", aa[i]);
	printf("\n");
}