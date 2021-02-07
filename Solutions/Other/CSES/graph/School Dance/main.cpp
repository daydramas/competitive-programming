#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rsz resize

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

int n, m, k;

/* source: bqi343 */
struct Dinic {
	using F = ll; // flow type
	struct Edge { int to, rev; F flo, cap; };
	int N; vector<vector<Edge>> adj;
	void init(int _N) { N = _N; adj.rsz(N); }
	/// void reset() { F0R(i,N) trav(e,adj[i]) e.flo = 0; }
	void ae(int a, int b, F cap, F rcap = 0) { assert(min(cap,rcap) >= 0);
		adj[a].pb({b,sz(adj[b]),0,cap});
		adj[b].pb({a,sz(adj[a])-1,0,rcap});
	}
	vi lev, ptr;
	bool bfs(int s, int t) { // level = shortest distance from source
		lev = ptr = vi(N);
		lev[s] = 1; queue<int> q({s});
		while (sz(q)) { int u = q.front(); q.pop();
			trav(e,adj[u]) if (e.flo < e.cap && !lev[e.to])
				q.push(e.to), lev[e.to] = lev[u]+1;
		}
		return lev[t];
	}
	F dfs(int v, int t, F flo) {
		if (v == t) return flo;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i]; F dif = e.cap-e.flo;
			if (lev[e.to]!=lev[v]+1||!dif) continue;
			if (F df = dfs(e.to,t,min(flo,dif))) {
				e.flo += df; adj[e.to][e.rev].flo -= df;
				return df; } // saturated >=1 one edge
		}
		return 0;
	}
	F maxFlow(int s, int t) {
		F tot = 0; while (bfs(s,t)) while (F df =
			dfs(s,t,numeric_limits<F>::max())) tot += df;
		return tot;
	}
};

int main() {
    cin >> n >> m >> k;
    Dinic mf; mf.init(n+m+2);
    FOR(i,1,k) {
        int a, b; cin >> a >> b;
        mf.ae(a,b+n,1,0);
    }
    FOR(i,1,n) mf.ae(0,i,1,0);
    FOR(i,1,m) mf.ae(i+n,n+m+1,1,0);
    cout << mf.maxFlow(0, n+m+1) <<"\n";
    FOR(i,1,n) trav(t,mf.adj[i]) if (t.flo > 0) cout<<i<<" "<<t.to-n<<"\n";
}