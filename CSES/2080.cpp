#include <bits/stdc++.h>
using namespace std;
 
const int N = 200010;
const int M = 2 * N;
 
int hd[N], nx[M], to[M], ei = 0;
 
inline void link(int i, int j) {
	nx[++ei] = hd[i], hd[i] = ei, to[ei] = j;
}
 
int n, k, ss[N], dep, cc[N]{1};
bool vv[N];
long long ans = 0;
 
int subtree(int x, int p = 0) {
	ss[x] = 1;
	for (int j = hd[x], y; j; j = nx[j])
		if (!vv[y = to[j]] && y != p)
			ss[x] += subtree(y, x);
	return ss[x];
}
 
int centroid(int dd, int x, int p = 0) {
	for (int j = hd[x], y; j; j = nx[j])
		if (!vv[y = to[j]] && y != p && ss[y] >= dd)
			return centroid(dd, y, x);
	return x;
}
 
void _count(int x, int p, int d = 1) {
	if (d > k) return;
	dep = max(dep, d);
	ans += cc[k - d];
	for (int j = hd[x], y; j; j = nx[j])
		if (!vv[y = to[j]] && y != p)
			_count(y, x, d + 1);
}
 
void _fill(int x, int p, int d = 1) {
	if (d > k) return;
	cc[d]++;
	for (int j = hd[x], y; j; j = nx[j])
		if (!vv[y = to[j]] && y != p)
			_fill(y, x, d + 1);
}
 
void decomp(int x = 1) {
	int c = centroid(subtree(x) / 2, x);
	vv[c] = 1;
	dep = 0;
	for (int j = hd[c], y; j; j = nx[j])
		if (!vv[y = to[j]]) {
			_count(y, c);
			_fill(y, c);
		}
	fill(cc + 1, cc + dep + 1, 0);
	for (int j = hd[c], y; j; j = nx[j])
		if (!vv[y = to[j]])
			decomp(y);
}
 
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		link(x, y), link(y, x);
	}
	decomp();
	printf("%lld\n", ans);
}