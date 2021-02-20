/**
 * 
 * Created on 2021-02-17
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 19) // 2e5

int n, dist[N], cnt[N], rcnt[N], lca[N][20];
vector<int> adj[N];
int ss[N], en[N], timer = 0;

void dfs(int cur, int par = -1) {
	ss[cur] = ++timer; 
	for(int chi : adj[cur]) if(chi != par) {
		dist[chi] = dist[cur] + 1;
		lca[chi][0] = cur;
		dfs(chi, cur);
	}
	en[cur] = timer;
}
int jmp(int a, int d) {
		for(int i=19; i>=0; i--) if(d&(1<<i))
			a = lca[a][i]; return a; }
int LCA(int a, int b) {
		if(dist[a] < dist[b]) swap(a,b);
		a = jmp(a, dist[a]-dist[b]);
		for(int i=19; i>=0; i--) if(lca[a][i] != lca[b][i]) {
			a=lca[a][i]; b=lca[b][i];  }
		if(a!=b) a=lca[a][0], b=lca[b][0]; return a; }

template<class T, int SZ> struct LazySegTree {
	T tree[SZ * 2], lazy[SZ * 2];
	void update(int L, int R, T inc) {
		update(L, R, inc, 1, 0, SZ - 1);
	}
	T query(int L, int R) {
		return query(L, R, 1, 0, SZ - 1);
	}
	void push(int id, int lo, int hi) {
		tree[id] += (hi - lo + 1) * lazy[id];
		if(lo != hi) {
			lazy[id * 2] += lazy[id];
			lazy[id * 2 + 1] += lazy[id];
		}
		lazy[id] = 0;
	}
	void update(int L, int R, T inc, int id, int lo, int hi) {
		push(id, lo, hi);
		if(L > hi || R < lo) return;
		if(L <= lo && hi <= R) { lazy[id] += inc; push(id, lo, hi); return; }
		if(lo == hi) return; int mi = (lo + hi) / 2;
		update(L, R, inc, id * 2, lo, mi);
		update(L, R, inc, id * 2 + 1, mi + 1, hi);
		tree[id] = tree[id * 2] + tree[id * 2 + 1];
	}
	T query(int L, int R, int id, int lo, int hi) {
		push(id, lo, hi);
		if (L <= lo && hi <= R) return tree[id];
		if (L > hi || R < lo) return 0;
		int mi = (lo + hi) / 2;
		return query(L, R, id * 2, lo, mi) + query(L, R, id * 2 + 1, mi + 1, hi);
	}
};
LazySegTree<int, N> st;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for(int i=1; i<n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dist[1] = 0; dfs(1);
	for(int d=1; d<20; d++)
	for(int i=1; i<=n; i++)
		lca[i][d] = lca[lca[i][d-1]][d-1];
	int m; cin >> m;
	long long ans = 0;
	while(m--) {
		int x, y; cin >> x >> y;
		int z = LCA(x, y);
		if(x == y) {
			st.update(ss[x], en[x], 1);
			ans += cnt[x];
			cnt[x]++;
			continue;
		}
		ans += st.query(ss[x], ss[x]) + st.query(ss[y], ss[y]);
		if(z != 1) ans -= st.query(ss[lca[z][0]], ss[lca[z][1]]);
		if(z == x) {
			ans += cnt[x];
			ans += rcnt[y];
			cnt[y]++;
			rcnt[x]++;
		} else if (z == y) {
			ans += rcnt[x];
			ans += cnt[y];
			cnt[x]++;
			rcnt[y]++;
		} else {
			// ans += cnt[x];
			// ans += cnt[y];
			ans += cnt[z];
			cnt[x]++;
			cnt[y]++;
		}
	}
	cout << ans << '\n';
}