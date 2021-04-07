#include <bits/stdc++.h>
using namespace std;
 
const int N = 200010;
const int M = 2 * N;
 
int hh[N], nn[M], tt[M], ei = 0;
 
inline void link(int i, int j) {
	nn[++ei] = hh[i], hh[i] = ei, tt[ei] = j;
}
 
long long bit[N];
 
long long query(int i) {
	long long ans = 0;
	while (i > 0) {
		ans += bit[i];
		i -= i & (-i);
	}
	return ans;
}
 
void update(int i, int x) {
	while (i < N) {
		bit[i] += x;
		i += i & (-i);
	}
}
 
int n, q, v[N], ss[N], ee[N], ti = 0;
 
void dfs(int x, int p) {
	ss[x] = ++ti;
	for (int j = hh[x], y; j; j = nn[j])
		if ((y = tt[j]) != p)
			dfs(y, x);
	ee[x] = ti;
}
 
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", v + i);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		link(x, y); link(y, x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i)
		update(ss[i], v[i]), update(ee[i] + 1, -v[i]);
	int t, a, b;
	while (q--) {
		scanf("%d%d", &t, &a);
		if (t == 1) {
			scanf("%d", &b);
			update(ss[a], b - v[a]);
			update(ee[a] + 1, v[a] - b);
			v[a] = b;
		} else {
			printf("%lld\n", query(ss[a]));
		}
	}
}