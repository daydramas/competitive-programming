#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int MAXK = 1000010;
const int M = 2 * MAXN;
const int inf = 0x3f3f3f3f;

int hd[MAXN], nx[M], to[M], wt[M], ei = 0;
 
inline void link(int i, int j, int kk) {
	nx[++ei] = hd[i], wt[ei] = kk, hd[i] = ei, to[ei] = j;
}
 
int n, k, ss[MAXN], dep, cc[MAXK], ans;
bool vv[MAXN];
 
int subtree(int x, int p = 0) {
	ss[x] = 1;
	for (int j = hd[x], y; j; j = nx[j])
		if (!vv[y = to[j]] && y != p)
			ss[x] += subtree(y, x);
	return ss[x];
}
 
int centroid(int dd, int x, int p = 0) {
	for (int j = hd[x], y; j; j = nx[j])
		if (!vv[y = to[j]] && y != p && ss[y] > dd)
			return centroid(dd, y, x);
	return x;
}

void _fill(int x, int p, int w, int d) {
	if (w > k) return;
	cc[w] = min(cc[w], d);
	dep = max(dep, w);
	for (int j = hd[x], y; j; j = nx[j])
		if (!vv[y = to[j]] && y != p)
			_fill(y, x, w + wt[j], d + 1);
}

void _count(int x, int p, int w, int d) {
	if (w > k) return;
	ans = min(ans, d + cc[k - w]);
	for (int j = hd[x], y; j; j = nx[j])
		if (!vv[y = to[j]] && y != p)
			_count(y, x, w + wt[j], d + 1);
}
 
void decomp(int x = 1) {
	int c = centroid(subtree(x) / 2, x);
	dep = 0, vv[c] = 1;
	for (int j = hd[c], y; j; j = nx[j])
		if (!vv[y = to[j]]) {
			_count(y, c, wt[j], 1);
			_fill(y, c, wt[j], 1);
		}
	for (int i = 1; i <= dep; ++i) cc[i] = inf;
	for (int j = hd[c], y; j; j = nx[j])
		if (!vv[y = to[j]])
			decomp(y);
}


int best_path(int N, int K, int H[][2], int L[]){
	n = N, k = K;
	memset(vv, 0, sizeof(vv));
	memset(hd, 0, sizeof(hd));
	ans = inf, ei = 0;
	for (int i = 0; i + 1 < n; ++i) {
		++H[i][0], ++H[i][1];
		link(H[i][0], H[i][1], L[i]);
		link(H[i][1], H[i][0], L[i]);
	}
	memset(cc, 0x3f, sizeof(cc)); cc[0] = 0;
	decomp();
	return (ans == inf ? -1 : ans);
}

/**

int main() {
	scanf("%d%d", &n, &k);
	memset(vv, 0, sizeof(vv));
	memset(hd, 0, sizeof(hd));
	ans = inf, ei = 0;
	for (int i = 1, x, y, z; i < n; ++i) {
		scanf("%d%d%d", &x, &y, &z); ++x, ++y;
		link(x, y, z), link(y, x, z);
	}
	memset(cc, 0x3f, sizeof(cc)); cc[0] = 0;
	decomp();
	printf("%d\n", (ans == inf ? -1 : ans));
}

**/